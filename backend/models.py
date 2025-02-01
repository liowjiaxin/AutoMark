from sqlmodel import SQLModel, Field
from typing import Optional
from datetime import datetime

class Submission(SQLModel, table=True):
    id: Optional[int] = Field(default=None, primary_key=True)
    code: str
    grade: Optional[str] = None
    created_at: datetime = Field(default_factory=datetime.utcnow)