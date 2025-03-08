import os
import uuid
import zipfile
import shutil
from fastapi import UploadFile, HTTPException
import PyPDF2

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

        def get_all_files(directory: str) -> list[str]:
            """Recursively get all files in a directory."""
            file_list = []
            for root, _, files in os.walk(directory):
                for file in files:
                    file_list.append(os.path.join(root, file))
            return file_list

        all_files = get_all_files(extract_path)
        relative_files = [os.path.relpath(file, extract_path) for file in all_files]

        return relative_files, extract_path
    except Exception:
        raise HTTPException(status_code=500, detail="Error unzipping files")


def read_file_content(filename: str) -> str:
    """Read file content from the upload directory, handling PDF and text files."""
    file_path = os.path.join(settings.FILE_UPLOAD_DIR, filename)
    try:
        with open(file_path, "rb") as f:  # Open in binary mode for both text and PDF
            if filename.lower().endswith(".pdf"):
                try:
                    pdf_reader = PyPDF2.PdfReader(f)
                    text = ""
                    for page_num in range(len(pdf_reader.pages)):
                        page = pdf_reader.pages[page_num]
                        text += (
                            page.extract_text() or ""
                        )  # Handle cases where extract_text returns None
                    return text
                except PyPDF2.errors.PdfReadError:
                    return "Error: Could not read PDF file."
                except Exception as e:
                    return f"Error reading PDF: {e}"

            else:  # Assume it's a text file
                return f.read().decode("utf-8")

    except FileNotFoundError:
        return "Error: File not found."
    except Exception as e:
        return f"An unexpected error occurred: {e}"


def cleanup_extracted_files(extract_path: str):
    if os.path.exists(extract_path):
        shutil.rmtree(extract_path)
