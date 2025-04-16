import os
import requests
import time
import json
from tqdm import tqdm  # For progress bar

# Configuration
API_URL = "http://localhost:3000/api/upload"  # Change to your API endpoint
UPLOAD_FOLDER = os.path.join(os.path.dirname(os.path.abspath(__file__)), "zipped_submissions")
MARKING_SCHEME_PATH = os.path.join(os.path.dirname(os.path.abspath(__file__)), "marking_scheme.json")  # Update this
DELAY_BETWEEN_UPLOADS = 1  # seconds

def upload_file(file_path, student_id):
    """Upload a single zip file to the API."""
    try:
        files = {
            'studentSubmission': (os.path.basename(file_path), open(file_path, 'rb'), 'application/zip'),
            'markingScheme': (os.path.basename(MARKING_SCHEME_PATH), open(MARKING_SCHEME_PATH, 'rb'), 'application/json')
        }
        
        data = {
            'studentId': student_id
        }
        
        response = requests.post(API_URL, files=files, data=data)
        
        if response.status_code == 200:
            return True, response.json()
        else:
            return False, f"Error: {response.status_code} - {response.text}"
            
    except Exception as e:
        return False, f"Exception: {str(e)}"

def batch_upload():
    """Upload all zip files in the folder."""
    if not os.path.exists(UPLOAD_FOLDER):
        print(f"Error: Upload folder not found: {UPLOAD_FOLDER}")
        return
        
    if not os.path.exists(MARKING_SCHEME_PATH):
        print(f"Error: Marking scheme not found: {MARKING_SCHEME_PATH}")
        return
    
    # Get all zip files
    zip_files = [f for f in os.listdir(UPLOAD_FOLDER) if f.endswith('.zip')]
    
    if not zip_files:
        print("No zip files found in the upload folder.")
        return
    
    print(f"Found {len(zip_files)} zip files to upload.")
    
    # Track results
    results = {
        "success": 0,
        "failed": 0,
        "details": []
    }
    
    # Process each file
    for zip_file in tqdm(zip_files, desc="Uploading files"):
        file_path = os.path.join(UPLOAD_FOLDER, zip_file)
        student_id = os.path.splitext(zip_file)[0]  # Assuming filename is student ID
        
        success, response = upload_file(file_path, student_id)
        
        if success:
            results["success"] += 1
        else:
            results["failed"] += 1
            
        results["details"].append({
            "student_id": student_id,
            "success": success,
            "response": response
        })
        
        # Add delay between uploads to avoid overwhelming the server
        time.sleep(DELAY_BETWEEN_UPLOADS)
    
    # Save results to a log file
    with open("upload_results.json", "w") as f:
        json.dump(results, f, indent=2)
    
    print(f"\nUpload complete: {results['success']} successful, {results['failed']} failed.")
    print(f"Detailed results saved to: upload_results.json")

if __name__ == "__main__":
    print("Starting batch upload...")
    batch_upload() 