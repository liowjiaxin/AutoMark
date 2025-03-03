from fastapi import APIRouter, Depends, UploadFile, File, HTTPException
from fastapi.responses import StreamingResponse
from sqlmodel import Session
import os
import json
import asyncio

from api.models.requests import GradeCodeRequest, RunCodeRequest
from db.models import Submission, CodeRunResult
from api.dependencies import get_db, get_grader
from core.utils import (
    save_upload_file,
    extract_zip_file,
    read_file_content,
    cleanup_extracted_files,
)
from grader.grading import Grader
from code_runner.runner import execute_code_isolated

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


async def run_code_stream(req: RunCodeRequest, session: Session):
    code_files, extract_path = extract_zip_file(req.code_zip_filename)
    code_run_output = ""
    for output in execute_code_isolated(
        req.language, req.version, extract_path, req.commands
    ):
        code_run_output += output
        yield f"data: {json.dumps({'output': output})}\n\n"

    code_run_result = CodeRunResult(output=code_run_output)
    session.add(code_run_result)
    session.commit()
    session.refresh(code_run_result)

    cleanup_extracted_files(extract_path)
    yield f"data: {json.dumps({'state': 'RUN_CODE_FIN', 'code_run_id': code_run_result.id})}\n\n"


@api_router.post("/run_code")
async def run_code(req: RunCodeRequest, session: Session = Depends(get_db)):
    return StreamingResponse(
        run_code_stream(req, session),
        media_type="text/event-stream",
    )


@api_router.post("/grade")
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

        # TODO: check if code_run_result_id got anything
        # if yes then pass the code run result to grader

        # Grade the code
        marks, feedback = grader.grade(code_files, req.language, marking_scheme)

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
        return {"grade": submission.grade, "feedback": submission.feedback}
    except HTTPException as e:
        raise e
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))
