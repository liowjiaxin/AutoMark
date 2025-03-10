from fastapi import APIRouter, Depends, HTTPException, Query
from typing import List
from db.models import Submission
from api.dependencies import get_db
from sqlmodel import Session, select

router = APIRouter(prefix="/api")


@router.get("/result/{student_id}")
async def get_student_result(student_id: int, session: Session = Depends(get_db)):
    statement = select(Submission).where(Submission.student_id == student_id)
    results = session.exec(statement).all()
    if not results:
        raise HTTPException(
            status_code=404, detail=f"Result for student id {student_id} not found"
        )

    return {"results": results}


@router.get("/results/")
async def get_results(session: Session = Depends(get_db)):
    # TODO: use query param to do pagination and sorting
    statement = select(Submission)
    results_list = session.exec(statement).all()
    return {"results": results_list}
