from grader.llm import GraderLLM
from dataclasses import dataclass
import os
import json

"""
Pipeline:
1. Preprocessing
	- Compute lines of code
	- Compute number of files
    - Code style analysing
        - Pass extracted metadata to the code style analyser
        - Ask LLM to assess comment quality, code coverage, and modularity
2. Grading
	- Get all the metadata and the code style analysis
	- Fit into the grading prompt template with the original code, rubris, and metadata
	- Get the grade and feedback from LLM
	- Return to frontend
"""


@dataclass
class Metadata:
    lines_of_code: int
    num_files: int


class Grader:
    def __init__(self):
        self.grader_llm = GraderLLM()

    def _preprocess(self, extract_path: str, code_files: list) -> tuple[Metadata, str]:
        num_files = len(code_files)
        code = ""
        num_code_files = 0
        for filename in code_files:
            if not filename.lower().endswith((".py", ".c", ".java")):
                continue
            file_path = os.path.join(extract_path, filename)
            num_code_files += 1
            with open(file_path, "r") as file:
                code += f"///{filename}///\n{file.read()}"
        lines_of_code = code.count("\n") + 1 - num_code_files

        try:
            return Metadata(
                lines_of_code=lines_of_code,
                num_files=num_files,
            ), code
        except Exception as e:
            print(e)
            return Metadata(
                lines_of_code=lines_of_code,
                num_files=num_files,
            ), code

    def grade(
        self,
        extract_path: str,
        code_files: list,
        language,
        rubrics: str,
        code_run_output: str = "",
    ) -> tuple[int, str]:
        try:
            metadata, code = self._preprocess(extract_path, code_files)
            result = self.grader_llm.invoke({
                "code": code,
                "language": language,
                "rubrics": rubrics,
                "lines_of_code": metadata.lines_of_code,
                "num_files": metadata.num_files,
                "code_run_output": code_run_output,
            })

            marks = result.get("marks", 0)
            feedback = result.get("feedback", "No feedback available")

            # Ensure feedback is a string
            if not isinstance(feedback, str):
                feedback = str(feedback) if feedback is not None else "No feedback available"

            print(result)
            
            # Convert marks to int if it's a string
            if isinstance(marks, str):
                try:
                    marks = int(marks)
                except ValueError:
                    marks = 0

            return marks, feedback.strip()
        except Exception as e:
            print(f"Error in grading: {str(e)}")
            return 0, f"An error occurred during grading: {str(e)}"
