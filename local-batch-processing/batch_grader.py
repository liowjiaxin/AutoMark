import os
import argparse
import logging
import pandas as pd
import time
import signal
import sys
import random
from typing import Dict, Any, List, Set
from helper import read_code, read_pdf
from grader import GraderRAG
from tqdm import tqdm

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

# Global variables for handling interruption
results = []
existing_results = {}
output_file = "grading_results.csv"

def signal_handler(signum, frame):
    """Handle interruption signals by saving current results"""
    logger.info("\nInterruption received. Saving current results...")
    if results:
        all_results = list(existing_results.values()) + results
        df = pd.DataFrame(all_results)
        df.to_csv(output_file, index=False)
        logger.info(f"Saved {len(results)} results to {output_file} before exiting")
    sys.exit(0)

# Register the signal handler
signal.signal(signal.SIGINT, signal_handler)
signal.signal(signal.SIGTERM, signal_handler)

def exponential_backoff(attempt: int, base_delay: float = 10, max_delay: float = 120) -> float:
    """Calculate delay with exponential backoff and jitter."""
    delay = min(base_delay * (2 ** attempt), max_delay)
    jitter = random.uniform(0, 0.1 * delay)  # 10% jitter
    return delay + jitter

def parse_args():
    parser = argparse.ArgumentParser(description='Batch grade student submissions')
    parser.add_argument('-s', '--source-dir', required=True, help='Directory containing source code')
    parser.add_argument('-m', '--marking-scheme', required=True, help='Path to marking scheme PDF')
    parser.add_argument('-d', '--dataset', required=True, help='Dataset directory')
    parser.add_argument('--modelname', default='models/gemini-1.5-pro', help='Model name to use')
    parser.add_argument('--batch-size', type=int, default=1, help='Number of submissions to process in each batch')
    parser.add_argument('--delay-between-files', type=float, default=5.0, help='Delay between processing files (seconds)')
    parser.add_argument('--delay-between-batches', type=float, default=30.0, help='Delay between batches (seconds)')
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

def grade_submission(grader, student_id: str, q_file: str, code: str, rubrics: str, max_retries: int = 3) -> tuple:
    """Grade a single submission with retries"""
    result = {
        'student_id': student_id,
        'marks': 0.0,
        'feedback': [],
        'total_mark': 0.0
    }
    
    attempt = 0
    consecutive_successes = 0
    
    while attempt < max_retries:
        try:
            # Get lines of code
            lines_of_code = len(code.splitlines())
            
            # Grade the submission
            grade_result = grader.grade(
                code=code,
                language="C",
                lines_of_code=lines_of_code,
                num_files=1,
                rubrics=rubrics
            )
            
            # Handle the result properly
            if isinstance(grade_result, dict):
                # Extract feedback and marks from the dictionary
                feedback = grade_result.get('feedback', '')
                marks = grade_result.get('marks', 0.0)
                total_mark = grade_result.get('total_mark', 0.0)
                
                # Add to result
                result['feedback'].append(f"{q_file}: {feedback}")
                result['marks'] = marks
                result['total_mark'] = total_mark
                
                # Success
                consecutive_successes += 1
                break
            else:
                # Handle unexpected result type
                logger.error(f"Unexpected result type from grader: {type(grade_result)}")
                result['feedback'].append(f"{q_file}: Error grading submission: Unexpected result type")
                break
        except Exception as e:
            attempt += 1
            consecutive_successes = 0  # Reset on any error
            if "429" in str(e) or "quota" in str(e).lower():
                delay = exponential_backoff(attempt)
                logger.warning(f"Rate limit hit. Waiting {delay:.1f} seconds before retry {attempt}/{max_retries}")
                time.sleep(delay)
            else:
                logger.error(f"Error processing {q_file}: {str(e)}")
                break
    
    if attempt == max_retries:
        logger.error(f"Max retries ({max_retries}) reached for {q_file}, student {student_id}")
        result['feedback'].append(f"{q_file}: Failed to grade after {max_retries} attempts")
    
    return result, consecutive_successes

def load_rubrics(marking_scheme_path: str) -> Dict[str, str]:
    """Load rubrics from marking scheme PDF"""
    # For now, return a simple rubric for each question
    # TODO: Implement proper PDF parsing
    return {
        'Q1.c': "Standard C programming rubric for Q1",
        'Q2.c': "Standard C programming rubric for Q2",
        'Q3.c': "Standard C programming rubric for Q3"
    }

def get_submissions(dataset_path: str) -> List[str]:
    """Get list of student submission directories"""
    return [d for d in os.listdir(dataset_path) 
            if os.path.isdir(os.path.join(dataset_path, d)) 
            and not d.startswith('__')]

def load_existing_results() -> List[Dict]:
    """Load existing grading results from CSV"""
    results_file = 'grading_results.csv'
    if not os.path.exists(results_file):
        return []
        
    df = pd.read_csv(results_file)
    return df.to_dict('records')

def save_result(student_id: str, total_mark: float, feedback: List[str]):
    """Save grading result to CSV"""
    result = {
        'student_id': student_id,
        'marks': total_mark,
        'feedback': '\n'.join(feedback),
        'total_mark': total_mark
    }
    
    results_file = 'grading_results.csv'
    df = pd.DataFrame([result])
    
    if os.path.exists(results_file):
        df.to_csv(results_file, mode='a', header=False, index=False)
    else:
        df.to_csv(results_file, index=False)

def main():
    args = parse_args()
    
    # Initialize grader
    grader = GraderRAG(dataset_path=args.dataset)
    
    # Load rubrics
    rubrics = load_rubrics(args.marking_scheme)
    
    # Get list of submissions
    submissions = get_submissions(args.source_dir)
    total_submissions = len(submissions)
    logger.info(f"Found {total_submissions} submissions to grade")
    
    # Load existing results
    existing_results = load_existing_results()
    graded_students = set(result['student_id'] for result in existing_results)
    
    # Filter out already graded submissions
    submissions = [s for s in submissions if s not in graded_students]
    logger.info(f"{len(submissions)} submissions remaining to grade")
    
    # Process submissions in batches
    batch_size = args.batch_size
    delay_between_files = args.delay_between_files
    delay_between_batches = args.delay_between_batches
    
    for i in range(0, len(submissions), batch_size):
        batch = submissions[i:i + batch_size]
        logger.info(f"\nProcessing batch {i//batch_size + 1} ({len(batch)} submissions)")
        
        for student_id in batch:
            submission_path = os.path.join(args.source_dir, student_id)
            if not os.path.exists(submission_path):
                logger.warning(f"Submission directory not found: {submission_path}")
                continue
                
            logger.info(f"\nProcessing student {student_id}")
            
            # Process each question
            total_mark = 0.0
            feedback = []
            
            for q_num in range(1, 4):
                q_file = f'Q{q_num}.c'
                q_path = os.path.join(submission_path, q_file)
                
                if not os.path.exists(q_path):
                    logger.warning(f"File {q_file} not found for student {student_id}")
                    continue
                    
                try:
                    with open(q_path, 'r', encoding='utf-8') as f:
                        code = f.read()
                        
                    result, _ = grade_submission(
                        grader=grader,
                        student_id=student_id,
                        q_file=q_file,
                        code=code,
                        rubrics=rubrics[q_file]
                    )
                    
                    total_mark += result['total_mark']
                    feedback.extend(result['feedback'])
                    
                    # Add delay between files
                    if delay_between_files > 0:
                        time.sleep(delay_between_files)
                        
                except Exception as e:
                    logger.error(f"Error processing {q_file}: {str(e)}")
                    feedback.append(f"{q_file}: Error processing submission")
            
            # Save results
            save_result(student_id, total_mark, feedback)
            
        # Add delay between batches
        if delay_between_batches > 0 and i + batch_size < len(submissions):
            logger.info(f"Waiting {delay_between_batches} seconds before next batch...")
            time.sleep(delay_between_batches)
    
    logger.info("\nGrading completed!")

if __name__ == "__main__":
    main() 