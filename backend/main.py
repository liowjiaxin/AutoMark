from fastapi import FastAPI, Depends
from sqlmodel import Session
from .database import engine, create_db_and_tables
from .models import Submission
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

@app.post("/grade")
async def grade_code(code: str, session: Session = Depends(get_session)):
    # Call AI model
    async with httpx.AsyncClient() as client:
        response = await client.post(
            f"{os.getenv('AI_MODEL_URL')}/grade",
            json={"code": code}
        )
    
    # Save to database
    submission = Submission(code=code, grade=response.json()['grade'])
    session.add(submission)
    session.commit()
    session.refresh(submission)
    
    return {"grade": submission.grade, "submission_id": submission.id}