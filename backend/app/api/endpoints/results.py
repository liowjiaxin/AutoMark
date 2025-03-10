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
    offset: int = 0,
    limit: int = Query(default=10, le=10),
    order_by: str = Query(default=None),
    order_direction: str = Query(default="asc", regex="^(asc|desc)$"),
    session: Session = Depends(get_db),
):
    statement = select(Submission)
    if order_by:
        if order_by not in ALLOWED_ORDER_BY_FIELDS:
            raise HTTPException(
                status_code=400,
                detail=f"Invalid order_by field. Allowed fields: {ALLOWED_ORDER_BY_FIELDS}",
            )
        sort_column = getattr(Submission, order_by, None)
        if sort_column is None:
            raise ValueError(f"Invalid order_by field: {order_by}")

        if order_direction == "desc":
            statement = statement.order_by(desc(sort_column))
        else:
            statement = statement.order_by(asc(sort_column))

    statement = statement.offset(offset).limit(limit)
    results_list = session.exec(statement).all()
    return {"results": results_list}
