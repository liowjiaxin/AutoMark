import argparse
from typing import Dict, Any
from helper import read_code, read_pdf
from grader import GraderRAG  # Import your actual grader class
import os
import logging
import time
import random
from google.api_core.exceptions import ResourceExhausted

# Set up logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def parse_arguments():
    parser = argparse.ArgumentParser(description="Automated Code Grader")
    parser.add_argument("-c", "--code", required=True, help="Path to code file or directory")
    parser.add_argument(
        "-l",
        "--language",
        required=True,
        choices=["C", "Python", "Java"],
        help="Programming language of submission",
    )
    parser.add_argument(
        "-m", "--marking-scheme", required=True, help="Path to PDF marking scheme"
    )
    parser.add_argument("-d", "--dataset", required=True, help="Path to dataset")
    parser.add_argument(
        "--modelname", required=False, help="LLM Model (gemini or deepseek)"
    )
    return parser.parse_args()

def validate_inputs(args):
    if not (os.path.isfile(args.code) or os.path.isdir(args.code)):
        raise FileNotFoundError(f"Code file or directory not found: {args.code}")

    if not args.marking_scheme.endswith(".pdf"):
        raise ValueError("Marking scheme must be a PDF file")

    if not os.path.isfile(args.marking_scheme):
        raise FileNotFoundError(f"PDF not found: {args.marking_scheme}")

    if not os.path.isdir(args.dataset):
        raise FileNotFoundError(f"Dataset not found: {args.dataset}")

def main():
    args = parse_arguments()
    logger.info("Arguments parsed successfully")
    validate_inputs(args)
    logger.info("Input validation passed")

    # Read inputs
    try:
        logger.info("Reading code files...")
        code_str, num_files = read_code(args.code, args.language)
        logger.info(f"Read {num_files} code files successfully")
        
        logger.info("Reading marking scheme PDF...")
        rubrics = read_pdf(args.marking_scheme)
        logger.info("PDF read successfully")
    except Exception as e:
        logger.error(f"Error processing inputs: {str(e)}")
        return

    # Prepare grading context
    grading_context = {
        "code": code_str,
        "language": args.language,
        "lines_of_code": len(code_str.split("\n")),
        "num_files": num_files,
        "rubrics": rubrics,
    }
    logger.info("Grading context prepared")

    try:
        model = args.modelname
    except Exception:
        model = "gemini"
    logger.info(f"Using model: {model}")

    # Initialize and run grader with retry logic
    try:
        logger.info("Initializing grader...")
        grader = GraderRAG(args.dataset, model_type=model)
        logger.info("Grader initialized, starting grading process...")
        
        max_retries = 5
        for attempt in range(max_retries):
            try:
                result = grader.grade(grading_context)
                print("\nGrading Results:")
                print(f"Score: {result['marks']}/100")
                print(f"Feedback:\n{result['feedback']}")
                break
            except ResourceExhausted as e:
                if attempt < max_retries - 1:
                    retry_delay = 15 * (2 ** attempt) + random.uniform(0, 1)
                    logger.warning(f"Quota exceeded. Retrying in {retry_delay:.2f} seconds...")
                    time.sleep(retry_delay)
                else:
                    logger.error("Max retries reached. Grading failed due to quota limits.")
                    raise e
    except Exception as e:
        logger.error(f"Grading failed: {str(e)}", exc_info=True)

if __name__ == "__main__":
    main()
