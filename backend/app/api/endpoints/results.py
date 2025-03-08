from fastapi import APIRouter, HTTPException, Query
from typing import List
from db.models import Submission

router = APIRouter(prefix="/api")

@router.get("/results")
def get_results(student_id: int = Query(None, description="ID of the student to filter results")):
    # TODO: sort
    results = Submission.filter(student_id=student_id).all()
    if not results:
        raise HTTPException(status_code=404, detail="Results not found")

    return {"results": results}