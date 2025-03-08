from pydantic import BaseModel
from typing import Optional


class GradeCodeRequest(BaseModel):
    code_zip_filename: str
    marking_scheme_filename: Optional[str] = None
    student_id: str
    language: str
    code_run_result_id: Optional[int] = None
