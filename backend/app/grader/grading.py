from typing import Literal
from grader.llm import StyleAnalyserLLM, GraderLLM
from dataclasses import dataclass
from core.config import settings
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
    comments_quality_feedback: str
    code_coverage_feedback: str
    modularity_score: float | Literal[""]
    # code_run_result: CodeRunResult


class Grader:
    def __init__(self):
        self.style_analyzer_llm = StyleAnalyserLLM()
        self.grader_llm = GraderLLM()

    def _process_llm_json_output(self, content: str) -> dict:
        import re

        json_pattern = r"```json\s*([\s\S]*?)\s*```"
        match = re.search(json_pattern, content)

        if match:
            json_string = match.group(1).strip()  # remove the ticks
            try:
                return json.loads(json_string)
            except json.JSONDecodeError:
                print("Error: Invalid JSON format.")
                return {}
        else:
            print("Error: JSON markers not found.")
            return {}

    def _preprocess(
        self, extract_path: str, code_files: list, language: str
    ) -> tuple[Metadata, str]:
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
            style_analysis_result = self.style_analyzer_llm.invoke({
                "code": code,
                "language": language,
            })

            result_json = self._process_llm_json_output(
                str(style_analysis_result.content)
            )

            return Metadata(
                lines_of_code=lines_of_code,
                num_files=num_files,
                comments_quality_feedback=result_json.get(
                    "comments_quality_feedback", ""
                ),
                code_coverage_feedback=result_json.get("code_coverate_feedback", ""),
                modularity_score=result_json.get("modularity_score", ""),
            ), code
        except Exception as e:
            print(e)
            return Metadata(
                lines_of_code=lines_of_code,
                num_files=num_files,
                comments_quality_feedback="",
                code_coverage_feedback="",
                modularity_score="",
            ), code

    def grade(
        self,
        extract_path: str,
        code_files: list,
        language,
        rubrics: str,
        code_run_output: str = "",
    ) -> tuple[int, str]:
        metadata, code = self._preprocess(extract_path, code_files, language)
        result = self.grader_llm.invoke({
            "code": code,
            "language": language,
            "rubrics": rubrics,
            "comments_quality_feedback": metadata.comments_quality_feedback,
            "code_coverage_feedback": metadata.code_coverage_feedback,
            "modularity_score": metadata.modularity_score,
            "lines_of_code": metadata.lines_of_code,
            "num_files": metadata.num_files,
            "code_run_output": code_run_output,
        })

        result_json = self._process_llm_json_output(str(result.content))
        marks = result_json.get("marks", 0)
        feedback = result_json.get("feedback", "no feedback")

        return marks, feedback.strip()
