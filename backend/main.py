from fastapi import FastAPI, Depends
from contextlib import asynccontextmanager
from sqlmodel import Session
from db.database import engine, create_db_and_tables
from db.models import Submission
from pydantic import BaseModel

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
    code: str

@app.post("/grade")
async def grade_code(req: GradeCodeRequest, session: Session = Depends(get_session)):
    # Call AI model
    try:
        # TODO: call gemini model
        pass
    except Exception as e:
        return {"error": str(e)}
    
    # Save to database
    submission = Submission(code=req.code, grade=grade)
    session.add(submission)
    session.commit()
    session.refresh(submission)
    
    return {"grade": submission.grade, "submission_id": submission.id}