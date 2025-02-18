from fastapi import FastAPI, Depends, UploadFile, File
from contextlib import asynccontextmanager
from typing import Optional
from sqlmodel import Session
from db.database import engine, create_db_and_tables
from db.models import Submission
from pydantic import BaseModel
import uuid
import zipfile
import os
import shutil

from grader.grading import Grader
ai_grader = Grader()

FILE_UPLOAD_DIR = "uploaded_files"

# On startup and on shutdown
@asynccontextmanager
async def lifespan(app: FastAPI):
    create_db_and_tables()
    yield
    engine.dispose()

app = FastAPI(lifespan=lifespan)

@app.get("/health")
def health_check():
    return {"status": "ok"}

# Dependency
def get_session():
    with Session(engine) as session:
        yield session

class GradeCodeRequest(BaseModel):
    code_zip_filename: str
    marking_scheme_filename: Optional[str] = None
    student_id: str
    language: str
    compiler: str
    commands: Optional[str] = None


@app.post("/uploadfile")
async def upload_file(file: UploadFile = File(...)):
    try:
        # Define the folder to save the uploaded file
        os.makedirs(FILE_UPLOAD_DIR, exist_ok=True)
        
        # Save the uploaded file
        unique_filename = f"{uuid.uuid4()}_{file.filename}"
        file_location = os.path.join(FILE_UPLOAD_DIR, unique_filename)
        with open(file_location, "wb+") as file_object:
            shutil.copyfileobj(file.file, file_object)
        return {
            "info": f"file '{unique_filename}' saved at '{file_location}'",
            "filename": unique_filename
            }
    except Exception as e:
        return {"error": str(e)}


@app.post("/grade")
async def grade_code(req: GradeCodeRequest, session: Session = Depends(get_session)):
    # Extract the student code zip file uploaded before, and then grade the code
    try:
        # Define the folder to extract the zip file
        os.makedirs("temp/extracted", exist_ok=True)

        file_location = os.path.join(FILE_UPLOAD_DIR, req.code_zip_filename)
        # Extract the zip file
        with zipfile.ZipFile(file_location, 'r') as zip_ref:
            zip_ref.extractall("temp/extracted")
        
        # Read the extracted code files
        extracted_files = os.listdir("temp/extracted")
        code_files = []
        for filename in extracted_files:
            code_file_path = os.path.join("temp/extracted", filename)
            with open(code_file_path, "r") as code_file:
                code_files.append(code_file.read())
        
        # Combine the code files into a single string (or handle them as needed)
        combined_code = "\n".join(code_files)

        # Get the marking scheme if provided
        if req.marking_scheme_filename:
            marking_scheme_file_path = os.path.join(FILE_UPLOAD_DIR, req.marking_scheme_filename)
            with open(marking_scheme_file_path, "r") as marking_scheme_file:
                marking_scheme = marking_scheme_file.read()
        else:
            marking_scheme = ""
        
        # Grade the code
        grade, feedback = ai_grader.grade(combined_code, marking_scheme)
    except Exception as e:
        return {"error": str(e)}
    finally:
        # Clean up temporary files
        shutil.rmtree("temp/extracted")
        os.remove(file_location)
    
    # Save to database
    submission = Submission(student_id=req.student_id,
                            code_zip_path=file_location,
                            marking_scheme_path=marking_scheme_file_path,
                            grade=grade,
                            feedback=feedback)
    session.add(submission)
    session.commit()
    session.refresh(submission)
    
    return {"grade": submission.grade, "feedback": submission.feedback}