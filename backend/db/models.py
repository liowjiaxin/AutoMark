from sqlmodel import SQLModel, Field, Column, Text, String
from typing import Optional
from datetime import datetime

class Submission(SQLModel, table=True):
    id: int = Field(default=None, primary_key=True)
    student_id: str = Field(sa_column=String)
    code: str = Field(sa_column=Column(Text))  # Use Column(Text) to store long text
    rubrics: str = Field(sa_column=Column(Text))
    feedback: Optional[str] = Field(sa_column=Column(Text))
    grade: str = Field(default='C')  # Fixed default assignment
    created_at: datetime = Field(default_factory=datetime.utcnow)
