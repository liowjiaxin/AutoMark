from fastapi import APIRouter, Depends, UploadFile, File, HTTPException, WebSocket
from sqlmodel import Session
import os

from api.models.requests import GradeCodeRequest, RunCodeRequest
from db.models import Submission
from api.dependencies import get_db, get_grader
from core.utils import (
    save_upload_file,
    extract_zip_file,
    read_file_content,
    cleanup_temp_files,
)

api_router = APIRouter(prefix="/api")
ws_router = APIRouter(prefix="/ws")


@api_router.post("/upload")
async def upload_file(file: UploadFile = File(...)):
    try:
        unique_filename = save_upload_file(file)
        return {
            "info": f"file '{unique_filename}' saved successfully",
            "filename": unique_filename,
        }
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


@ws_router.websocket("/run_code")
async def run_code(req: RunCodeRequest):
    # TODO: unzip and run the code by calling the code runner
    # TODO: stream the stdout and stderr to frontend with websocket
    # TODO: add timeout time limit
    # TODO: send a code "ATMK_RUN_CODE_FIN" to frontend when code finish running
    # TODO: save code run result to db (using file storage, and store file path in db)
    pass


@api_router.post("/grade")
async def grade_code(
    req: GradeCodeRequest,
    session: Session = Depends(get_db),
    grader=Depends(get_grader),
):
    try:
        if req.code_zip_filename == "":
            raise HTTPException(status_code=400, detail="Empty code zip file path")

        # Extract and read code files
        code_files = extract_zip_file(req.code_zip_filename)
        combined_code = "\n".join(code_files)

        # Get marking scheme if provided
        marking_scheme = ""
        marking_scheme_path = ""
        if req.marking_scheme_filename:
            marking_scheme_path = req.marking_scheme_filename
            marking_scheme = read_file_content(req.marking_scheme_filename)

        # Grade the code
        grade, feedback = grader.grade(combined_code, marking_scheme)

        # Save to database
        file_location = os.path.join("uploaded_files", req.code_zip_filename)
        submission = Submission(
            student_id=req.student_id,
            code_zip_path=file_location,
            marking_scheme_path=marking_scheme_path,
            grade=grade,
            feedback=feedback,
        )

        session.add(submission)
        session.commit()
        session.refresh(submission)

        return {"grade": submission.grade, "feedback": submission.feedback}
    except HTTPException as e:
        raise e
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))
    finally:
        # Clean up temporary files
        cleanup_temp_files(req.code_zip_filename)
