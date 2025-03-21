import os
import argparse
import logging
import pandas as pd
import time
from typing import Dict, Any
from helper import read_code, read_pdf
from grader import GraderRAG
from tqdm import tqdm

# Set up logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s',
    handlers=[
        logging.FileHandler('grading.log'),
        logging.StreamHandler()
    ]
)
logger = logging.getLogger(__name__)

# Constants for delays and retries
BASE_DELAY = 60  # Increased base delay between API calls
SUBMISSION_DELAY = 120  # Increased delay between submissions
MAX_RETRIES = 5  # Increased maximum number of retries per submission
RETRY_MULTIPLIER = 2  # Multiplier for exponential backoff

def exponential_backoff(retry_count: int) -> int:
    """Calculate delay with exponential backoff"""
    return BASE_DELAY * (RETRY_MULTIPLIER ** retry_count)

def parse_arguments():
    parser = argparse.ArgumentParser(description="Batch Automated Code Grader")
    parser.add_argument(
        "-s",
        "--source-dir",
        required=True,
        help="Path to directory containing all student submissions"
    )
    parser.add_argument(
        "-m",
        "--marking-scheme",
        required=True,
        help="Path to PDF marking scheme"
    )
    parser.add_argument(
        "-d",
        "--dataset",
        required=True,
        help="Path to dataset directory"
    )
    parser.add_argument(
        "--modelname",
        required=False,
        default="gemini",
        help="LLM Model (gemini or deepseek)"
    )
    parser.add_argument(
        "--start-from",
        required=False,
        help="Student ID to start from (skips all submissions before this ID)"
    )
    return parser.parse_args()

def validate_inputs(args):
    if not os.path.isdir(args.source_dir):
        raise FileNotFoundError(f"Source directory not found: {args.source_dir}")

    if not args.marking_scheme.endswith(".pdf"):
        raise ValueError("Marking scheme must be a PDF file")

    if not os.path.isfile(args.marking_scheme):
        raise FileNotFoundError(f"PDF not found: {args.marking_scheme}")

    if not os.path.isdir(args.dataset):
        raise FileNotFoundError(f"Dataset not found: {args.dataset}")

def grade_submission(student_id: str, submission_path: str, grader: GraderRAG, rubrics: Dict[str, str]) -> Dict:
    """Grade a single submission with improved error handling"""
    result = {
        'student_id': student_id,
        'total_mark': 0,
        'feedback': []
    }
    
    # Process each question file
    for q_num in range(1, 4):
        q_file = f'Q{q_num}.c'
        q_path = os.path.join(submission_path, q_file)
        
        if not os.path.exists(q_path):
            logger.warning(f"File {q_file} not found for student {student_id}")
            continue
            
        retry_count = 0
        while retry_count < MAX_RETRIES:
            try:
                logger.info(f"Grading {q_file} for student {student_id}")
                q_result = grader.grade_code(q_path, rubrics[q_file])
                result['total_mark'] += q_result['mark']
                result['feedback'].append(f"{q_file}: {q_result['feedback']}")
                break
            except Exception as e:
                retry_count += 1
                if retry_count > 0:
                    delay = exponential_backoff(retry_count - 1)
                    logger.warning(f"Attempt {retry_count}/{MAX_RETRIES} for {q_file}, waiting {delay} seconds...")
                    time.sleep(delay)
                if retry_count == MAX_RETRIES:
                    logger.error(f"Max retries ({MAX_RETRIES}) reached for {q_file}, student {student_id}")
                    result['feedback'].append(f"{q_file}: Failed to grade after {MAX_RETRIES} attempts")
    
    return result

def load_existing_results(output_file: str) -> Dict[str, Dict]:
    """Load existing results from CSV file if it exists"""
    if os.path.exists(output_file):
        df = pd.read_csv(output_file)
        return {str(row["student_id"]): row.to_dict() for _, row in df.iterrows()}
    return {}

def main():
    args = parse_arguments()
    validate_inputs(args)
    
    output_file = "grading_results.csv"
    
    # Load existing results
    existing_results = load_existing_results(output_file)
    logger.info(f"Loaded {len(existing_results)} existing results")
    
    # Read marking scheme
    logger.info("Reading marking scheme PDF...")
    rubrics = read_pdf(args.marking_scheme)
    
    # Initialize grader
    logger.info("Initializing grader...")
    grader = GraderRAG(
        dataset_path=args.dataset,
        model_type=args.modelname
    )
    
    # Get list of student submissions (handle nested source_code directory)
    submissions_dir = os.path.join(args.source_dir, "source_code")  # Handle the nested structure
    if not os.path.exists(submissions_dir):
        submissions_dir = args.source_dir  # Fallback to original path if nested doesn't exist
    
    student_dirs = [d for d in os.listdir(submissions_dir) if os.path.isdir(os.path.join(submissions_dir, d))]
    total_students = len(student_dirs)
    logging.info(f"Found {total_students} student submissions to process")
    
    # Filter out already graded students
    ungraded_students = [d for d in student_dirs if d not in existing_results]
    logger.info(f"Found {len(ungraded_students)} ungraded submissions")
    
    # Take the first 5 ungraded students
    student_dirs = ungraded_students[:5]
    if student_dirs:
        logger.info(f"Processing 5 student submissions: {', '.join(student_dirs)}")
    else:
        logger.info("No ungraded submissions found")
        return
    
    # Process each submission with progress bar
    results = []
    for idx, student_id in enumerate(tqdm(student_dirs, desc="Processing submissions"), 1):
        # Handle potential nested directories for each student
        base_submission_path = os.path.join(submissions_dir, student_id)
        
        # Look for Q*.c files in the base directory and subdirectories
        submission_path = base_submission_path
        if not any(f.endswith('.c') for f in os.listdir(base_submission_path)):
            # If no .c files in base directory, look in subdirectories
            subdirs = [d for d in os.listdir(base_submission_path) 
                      if os.path.isdir(os.path.join(base_submission_path, d)) 
                      and not d.startswith('__')]  # Skip __MACOSX directories
            if subdirs:
                submission_path = os.path.join(base_submission_path, subdirs[0])
        
        logger.info(f"\nProcessing student {student_id} ({idx}/{total_students})")
        result = grade_submission(student_id, submission_path, grader, rubrics)
        results.append(result)
        
        # Save intermediate results after each submission
        all_results = list(existing_results.values()) + results
        df = pd.DataFrame(all_results)
        df.to_csv(output_file, index=False)
        logger.info(f"Saved results to {output_file} ({len(results)} new submissions processed)")
        
        # Wait between submissions to avoid rate limits
        if idx < total_students:
            logger.info(f"Waiting {SUBMISSION_DELAY} seconds before next submission...")
            time.sleep(SUBMISSION_DELAY)

    logger.info("Batch grading completed!")
    logger.info(f"Total submissions processed: {len(results)}")
    logger.info(f"Results saved to {output_file}")

if __name__ == "__main__":
    main() 