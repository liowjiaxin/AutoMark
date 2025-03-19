from fastapi import APIRouter, Depends, HTTPException, Query
from db.models import Submission
from api.dependencies import get_db
from sqlmodel import Session, select, asc, desc

router = APIRouter(prefix="/api")

ALLOWED_ORDER_BY_FIELDS = ["student_id", "marks"]

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
async def get_results(
    page: int = Query(default=1, ge=1),
    limit: int = Query(default=10, ge=1),
    order_by: str = Query(default=None),
    order_direction: str = Query(default="asc", regex="^(asc|desc)$"),
    session: Session = Depends(get_db),
):
    # Base query
    statement = select(Submission)

    # Apply sorting
    if order_by:
        if order_by not in ALLOWED_ORDER_BY_FIELDS:
            raise HTTPException(
                status_code=400,
                detail=f"Invalid order_by field. Allowed fields: {ALLOWED_ORDER_BY_FIELDS}",
            )
        sort_column = getattr(Submission, order_by)
        statement = statement.order_by(desc(sort_column) if order_direction == "desc" else asc(sort_column))

    # Get total count after filters
    total_results = session.exec(statement).count()
    total_pages = (total_results + limit - 1) // limit

    # Apply pagination
    statement = statement.offset((page - 1) * limit).limit(limit)
    results_list = session.exec(statement).all()

    return {
        "results": results_list,
        "current_page": page,
        "total_pages": total_pages,
        "total_results": total_results,
    }
