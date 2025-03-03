from pydantic import BaseModel
from typing import Optional


class GradeCodeRequest(BaseModel):
    code_zip_filename: str
    marking_scheme_filename: Optional[str] = None
    student_id: str
    language: str
    compiler: str
    commands: Optional[str] = None
    code_run_result_id: Optional[str] = None


class RunCodeRequest(BaseModel):
    language: str
    compiler: str
    commands: Optional[str] = None
    # stdin_input: str
    # timeout: int = 5  # seconds
