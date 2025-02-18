from sqlmodel import SQLModel, Field, Column, Text, String
from typing import Optional
from datetime import datetime

class Submission(SQLModel, table=True):
    id: int = Field(default=None, primary_key=True)
    student_id: str = Field(sa_column=String)
    code_zip_path: str = Field(sa_column=String)
    marking_scheme_path: Optional[str] = Field(sa_column=String)
    feedback: Optional[str] = Field(sa_column=Column(Text))
    grade: str = Field(default='C')
    created_at: datetime = Field(default_factory=datetime.utcnow)
