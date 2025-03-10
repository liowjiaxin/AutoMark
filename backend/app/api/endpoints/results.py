from fastapi import APIRouter, Depends, HTTPException, Query
from typing import List
from db.models import Submission
from api.dependencies import get_db
from sqlmodel import Session, select

router = APIRouter(prefix="/api")


@router.get("/result/{student_id}")
async def get_student_result(student_id: int, session: Session = Depends(get_db)):
    statement = select(Submission).where(Submission.student_id == student_id)
    result = session.exec(statement).first()
    if not result:
        raise HTTPException(
            status_code=404, detail=f"Result for student id {student_id} not found"
        )

    return {"result": result}


@router.get("/results/")
async def get_results(session: Session = Depends(get_db)):
    # TODO: use query param to do pagination and sorting
    statement = select(Submission)
    results_list = session.exec(statement).first()
    return {"results": results_list}
