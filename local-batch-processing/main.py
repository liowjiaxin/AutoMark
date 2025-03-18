import argparse
from typing import Dict, Any
from helper import read_code, read_pdf
from grader import GraderRAG  # Import your actual grader class
import os


def parse_arguments():
    parser = argparse.ArgumentParser(description="Automated Code Grader")
    parser.add_argument("-c", "--codedir", required=True, help="Path to code directory")
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
    return parser.parse_args()


def validate_inputs(args):
    if not os.path.isdir(args.codedir):
        raise FileNotFoundError(f"Code Directory not found: {args.codedir}")

    if not args.marking_scheme.endswith(".pdf"):
        raise ValueError("Marking scheme must be a PDF file")

    if not os.path.isfile(args.marking_scheme):
        raise FileNotFoundError(f"PDF not found: {args.marking_scheme}")

    if not os.path.isdir(args.dataset):
        raise FileNotFoundError(f"Dataset not found: {args.dataset}")


def main():
    args = parse_arguments()
    validate_inputs(args)

    # Read inputs
    try:
        code_str, num_files = read_code(args.codedir, args.language)
        rubrics = read_pdf(args.marking_scheme)
    except Exception as e:
        print(f"Error processing inputs: {str(e)}")
        return

    # Prepare grading context
    grading_context = {
        "code": code_str,
        "language": args.language,
        "lines_of_code": len(code_str.split("\n")),
        "num_files": num_files,
        "rubrics": rubrics,
    }

    # Initialize and run grader
    try:
        grader = GraderRAG(args.dataset)
        result = grader.grade(grading_context)
        print("\nGrading Results:")
        print(f"Score: {result['marks']}/100")
        print(f"Feedback:\n{result['feedback']}")
    except Exception as e:
        print(f"Grading failed: {str(e)}")


if __name__ == "__main__":
    main()
