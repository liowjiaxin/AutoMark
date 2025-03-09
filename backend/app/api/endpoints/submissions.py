from fastapi import APIRouter, Depends, UploadFile, File, HTTPException
from sqlmodel import Session
import os
from api.models.requests import GradeCodeRequest
from db.models import CodeRunResult, Submission
from api.dependencies import get_db, get_grader
from core.utils import (
    save_upload_file,
    extract_zip_file,
    read_file_content,
    cleanup_extracted_files,
)
from grader.grading import Grader

router = APIRouter(prefix="/api")


@router.post("/upload")
async def upload_file(file: UploadFile = File(...)):
    try:
        unique_filename = save_upload_file(file)
        return {
            "info": f"file '{unique_filename}' saved successfully",
            "filename": unique_filename,
        }
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


@router.post("/grade")
async def grade_code(
    req: GradeCodeRequest,
    session: Session = Depends(get_db),
    grader: Grader = Depends(get_grader),
):
    try:
        if req.code_zip_filename == "":
            raise HTTPException(status_code=400, detail="Empty code zip file path")

        # Extract and read code files
        code_files, extract_path = extract_zip_file(req.code_zip_filename)

        # Get marking scheme if provided
        marking_scheme = ""
        marking_scheme_path = ""
        if req.marking_scheme_filename:
            marking_scheme_path = req.marking_scheme_filename
            marking_scheme = read_file_content(req.marking_scheme_filename)

        code_run_output = ""
        if req.code_run_result_id:
            code_run_result = session.get(CodeRunResult, req.code_run_result_id)
            if not code_run_result:
                raise HTTPException(
                    status_code=400, detail="Invalid code run result id"
                )
            code_run_output = code_run_result.output if code_run_result.output else ""

        # Grade the code
        marks, feedback = grader.grade(
            extract_path,
            code_files,
            req.language,
            marking_scheme,
            code_run_output=code_run_output,
        )

        # Save to database
        file_location = os.path.join("uploaded_files", req.code_zip_filename)
        submission = Submission(
            student_id=req.student_id,
            code_zip_path=file_location,
            marking_scheme_path=marking_scheme_path,
            marks=marks,
            feedback=feedback,
        )

        session.add(submission)
        session.commit()
        session.refresh(submission)

        cleanup_extracted_files(extract_path)
        return {"marks": submission.marks, "feedback": submission.feedback}
    except HTTPException as e:
        raise e
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))
