from sqlmodel import SQLModel, Field
from sqlalchemy import Text
from typing import Optional
from datetime import datetime

class Submission(SQLModel, table=True):
    id: int = Field(default=None, primary_key=True)
    code: str = Field(sa_column=Text)
    grade: Optional[str] = None
    created_at: datetime = Field(default_factory=datetime.utcnow)