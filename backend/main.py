from fastapi import FastAPI, Depends
from contextlib import asynccontextmanager
from sqlmodel import Session
from db.database import engine, create_db_and_tables
from db.models import Submission
from pydantic import BaseModel

from grader.grading import Grader
ai_grader = Grader()

# On startup and on shutdown
@asynccontextmanager
async def lifespan(app: FastAPI):
    create_db_and_tables()
    yield
    engine.dispose()

app = FastAPI(lifespan=lifespan)

@app.get("/health")
def health_check():
    return {"status": "ok"}

# Dependency
def get_session():
    with Session(engine) as session:
        yield session

class GradeCodeRequest(BaseModel):
    student_id: str
    code: str
    rubrics: str
    # TODO: receive more args like language, compiler, etc.
    # custom_run_commands: list[str]

# TODO: user upload zip, now is plain code string

@app.post("/grade")
async def grade_code(req: GradeCodeRequest, session: Session = Depends(get_session)):
    try:
        grade, feedback = ai_grader.grade(req.code, req.rubrics)
    except Exception as e:
        return {"error": str(e)}
    
    # Save to database
    submission = Submission(student_id=req.student_id,
                            code=req.code,
                            rubrics=req.rubrics,
                            grade=grade,
                            feedback=feedback)
    session.add(submission)
    session.commit()
    session.refresh(submission)
    
    return {"grade": submission.grade, "feedback": submission.feedback}
