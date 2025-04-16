import os
import json
import time
import requests
import csv
from tqdm import tqdm
from pathlib import Path

# Configuration
BASE_URL = "http://localhost:8080"
UPLOAD_URL = f"{BASE_URL}/api/upload"
GRADE_URL = f"{BASE_URL}/api/grade"
MARKING_SCHEME_PDF = "marking_scheme_lab3.pdf"  # Lab 3 marking scheme
DELAY_BETWEEN_UPLOADS = 1  # seconds
TEST_MODE = False  # Set to False to process all students
MAX_MARKS = 15  # Maximum marks for the assignment

def extract_student_id(zip_filename):
    """Extract student ID from zip filename."""
    # Assuming format is "student_id.zip" or similar
    return os.path.splitext(zip_filename)[0]

def process_submission(zip_path, marking_scheme_path):
    """Submit files to the API and get grading results."""
    try:
        # Step 1: Upload files
        with open(zip_path, 'rb') as zip_file, open(marking_scheme_path, 'rb') as pdf_file:
            files = {
                'file': ('submission.zip', zip_file, 'application/zip'),
                'marking_scheme': ('marking_scheme.pdf', pdf_file, 'application/pdf')
            }
            data = {
                'student_id': extract_student_id(os.path.basename(zip_path)),
                'language': 'C'
            }
            print(f"\nUploading submission for student {data['student_id']}...")
            print(f"Using files: {os.path.basename(zip_path)} and {os.path.basename(marking_scheme_path)}")
            
            upload_response = requests.post(UPLOAD_URL, files=files, data=data)
            upload_response.raise_for_status()
            upload_data = upload_response.json()
            
            print(f"Upload successful: {upload_data.get('info')}")
            
            # Step 2: Grade the submission
            grade_data = {
                "student_id": data['student_id'],
                "code_zip_filename": upload_data.get('filename'),
                "marking_scheme_filename": os.path.basename(marking_scheme_path),
                "language": "C"
            }
            
            print(f"Requesting grading for student {data['student_id']}...")
            grade_response = requests.post(GRADE_URL, json=grade_data)
            grade_response.raise_for_status()
            grade_result = grade_response.json()
            
            print(f"Grading complete for student {data['student_id']}")
            print("Grade Response:", json.dumps(grade_result, indent=2))
            
            return True, {
                'upload_response': upload_data,
                'grade_result': grade_result
            }
            
    except requests.exceptions.RequestException as e:
        error_msg = f"API Error: {str(e)}"
        if hasattr(e.response, 'text'):
            error_msg += f"\nResponse: {e.response.text}"
        return False, error_msg
    except Exception as e:
        return False, f"Unexpected error: {str(e)}"

def convert_to_15(marks_100):
    """Convert marks from 100 to 15 scale."""
    return round((marks_100 / 100) * MAX_MARKS, 1)

def save_results_to_csv(results, output_file='evaluation_results.csv'):
    """Save results to CSV file."""
    with open(output_file, 'w', newline='', encoding='utf-8') as csvfile:
        fieldnames = ['student_id', 'marks_15', 'marks_100', 'feedback', 'error']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        
        for result in results['successful']:
            student_id = extract_student_id(os.path.basename(result['file']))
            grade_result = result.get('response', {}).get('grade_result', {})
            marks_100 = grade_result.get('marks', 0)
            marks_15 = convert_to_15(marks_100)
            
            writer.writerow({
                'student_id': student_id,
                'marks_15': marks_15,
                'marks_100': marks_100,
                'feedback': grade_result.get('feedback', 'N/A'),
                'error': 'N/A'
            })
        
        for result in results['failed']:
            student_id = extract_student_id(os.path.basename(result['file']))
            writer.writerow({
                'student_id': student_id,
                'marks_15': 'N/A',
                'marks_100': 'N/A',
                'feedback': 'N/A',
                'error': result['error']
            })

def main():
    # Check if marking scheme exists
    if not os.path.exists(MARKING_SCHEME_PDF):
        print(f"Error: Marking scheme PDF not found at {MARKING_SCHEME_PDF}")
        print("Please place your marking scheme PDF in the same directory as this script")
        return
    
    # Get all zip files
    zip_files = list(Path('zipped_submissions').glob('*.zip'))
    
    if not zip_files:
        print("No zip files found in zipped_submissions folder!")
        print("Please place student ZIP files in the zipped_submissions directory")
        return
    
    print(f"Found {len(zip_files)} student submissions to process")
    print(f"Using marking scheme: {MARKING_SCHEME_PDF}")
    print(f"Upload API: {UPLOAD_URL}")
    print(f"Grade API: {GRADE_URL}")
    
    # Track results
    results = {
        'successful': [],
        'failed': []
    }
    
    # Process each file
    for zip_path in tqdm(zip_files, desc="Processing submissions"):
        success, response = process_submission(zip_path, MARKING_SCHEME_PDF)
        
        if success:
            results['successful'].append({
                'file': str(zip_path),
                'response': response
            })
        else:
            print(f"\nFailed to process {os.path.basename(zip_path)}: {response}")
            results['failed'].append({
                'file': str(zip_path),
                'error': response
            })
        
        time.sleep(DELAY_BETWEEN_UPLOADS)
    
    # Save results to both JSON and CSV
    with open('upload_results.json', 'w', encoding='utf-8') as f:
        json.dump(results, f, indent=2, ensure_ascii=False)
    
    save_results_to_csv(results)
    
    # Print summary
    print(f"\nBatch processing complete!")
    print(f"Total submissions processed: {len(zip_files)}")
    print(f"Successful: {len(results['successful'])}")
    print(f"Failed: {len(results['failed'])}")
    print(f"Results saved to upload_results.json and evaluation_results.csv")
    
    # Show progression of marks
    if results['successful']:
        print("\nMarks Progression (out of 15):")
        successful_results = sorted(
            results['successful'],
            key=lambda x: convert_to_15(x['response'].get('grade_result', {}).get('marks', 0))
        )
        for result in successful_results:
            student_id = extract_student_id(os.path.basename(result['file']))
            marks_100 = result['response'].get('grade_result', {}).get('marks', 0)
            marks_15 = convert_to_15(marks_100)
            print(f"Student {student_id}: {marks_15}/15 ({marks_100}/100)")

if __name__ == "__main__":
    main() 