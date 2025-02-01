from fastapi import FastAPI, Depends
from sqlmodel import Session
from database import engine, create_db_and_tables
from models import Submission
from pydantic import BaseModel
import httpx
import os

app = FastAPI()

@app.on_event("startup")
def on_startup():
    create_db_and_tables()

# Dependency
def get_session():
    with Session(engine) as session:
        yield session

class GradeCodeRequest(BaseModel):
    code: str

@app.post("/grade")
async def grade_code(req: GradeCodeRequest, session: Session = Depends(get_session)):
    # Call AI model
    try:
        async with httpx.AsyncClient() as client:
            response = await client.post(
                f"{os.getenv('GRADER_URL')}/grade",
                json={"code": req.code}
            )
        grade = response.json()['grade']
    except Exception as e:
        print(e)
        grade = "TEST"
    
    # Save to database
    submission = Submission(code=req.code, grade=grade)
    session.add(submission)
    session.commit()
    session.refresh(submission)
    
    return {"grade": submission.grade, "submission_id": submission.id}