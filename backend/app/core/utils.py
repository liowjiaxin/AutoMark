import os
import uuid
import zipfile
import shutil
from fastapi import UploadFile, HTTPException

from core.config import settings


def save_upload_file(upload_file: UploadFile) -> str:
    """Save uploaded file and return unique filename"""
    unique_filename = f"{uuid.uuid4()}_{upload_file.filename}"
    file_location = os.path.join(settings.FILE_UPLOAD_DIR, unique_filename)

    with open(file_location, "wb+") as file_object:
        shutil.copyfileobj(upload_file.file, file_object)

    return unique_filename


def extract_zip_file(filename: str) -> tuple[list, str]:
    """Extract zip file and return list of files and the extract path"""
    file_location = os.path.join(settings.FILE_UPLOAD_DIR, filename)

    if not os.path.exists(file_location):
        raise HTTPException(status_code=404, detail="File not found")

    try:
        unique_id = uuid.uuid4()
        extract_path = os.path.join(settings.TEMP_EXTRACT_DIR, str(unique_id))
        # Extract the zip file
        with zipfile.ZipFile(file_location, "r") as zip_ref:
            zip_ref.extractall(extract_path)

        extracted_files = os.listdir(extract_path)
        return extracted_files, extract_path
    except Exception:
        raise HTTPException(status_code=500, detail="Error unzipping files")


def read_file_content(filename: str) -> str:
    """Read file content from the upload directory"""
    file_path = os.path.join(settings.FILE_UPLOAD_DIR, filename)
    with open(file_path, "r") as f:
        return f.read()


def cleanup_extracted_files(extract_path: str):
    if os.path.exists(extract_path):
        shutil.rmtree(extract_path)
