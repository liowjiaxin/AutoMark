import os
import uuid
import zipfile
import shutil
from fastapi import UploadFile

from core.config import settings


def save_upload_file(upload_file: UploadFile) -> str:
    """Save uploaded file and return unique filename"""
    unique_filename = f"{uuid.uuid4()}_{upload_file.filename}"
    file_location = os.path.join(settings.FILE_UPLOAD_DIR, unique_filename)

    with open(file_location, "wb+") as file_object:
        shutil.copyfileobj(upload_file.file, file_object)

    return unique_filename


def extract_zip_file(filename: str) -> list:
    """Extract zip file and return list of file contents"""
    file_location = os.path.join(settings.FILE_UPLOAD_DIR, filename)

    # Extract the zip file
    with zipfile.ZipFile(file_location, "r") as zip_ref:
        zip_ref.extractall(settings.TEMP_EXTRACT_DIR)

    # Read the extracted code files
    extracted_files = os.listdir(settings.TEMP_EXTRACT_DIR)
    code_files = []

    for filename in extracted_files:
        code_file_path = os.path.join(settings.TEMP_EXTRACT_DIR, filename)
        with open(code_file_path, "r") as code_file:
            code_files.append(code_file.read())

    return code_files


def read_file_content(filename: str) -> str:
    """Read file content from the upload directory"""
    file_path = os.path.join(settings.FILE_UPLOAD_DIR, filename)
    with open(file_path, "r") as f:
        return f.read()


def cleanup_temp_files(filename: str):
    """Clean up temporary files"""
    shutil.rmtree(settings.TEMP_EXTRACT_DIR)
    file_location = os.path.join(settings.FILE_UPLOAD_DIR, filename)
    if os.path.exists(file_location):
        os.remove(file_location)
