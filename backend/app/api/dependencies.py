from fastapi import Depends
from sqlmodel import Session

from db.database import get_session
from grader.grading import Grader


def get_grader():
    return Grader()


def get_db(session: Session = Depends(get_session)):
    return session
