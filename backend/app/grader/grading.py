from grader.llm import StyleAnalyserLLM, GraderLLM
from dataclasses import dataclass
from app.core.config import settings
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
    modularity_score: float
    # code_run_result: CodeRunResult


class Grader:
    def __init__(self):
        self.style_analyzer_llm = StyleAnalyserLLM()
        self.grader_llm = GraderLLM()

    def _preprocess(self, code_files: list, language: str) -> tuple[Metadata, str]:
        num_files = len(code_files)
        code = ""
        for filename in code_files:
            if not filename.lower().endswith((".py", ".c", ".java")):
                continue
            file_path = os.path.join(settings.TEMP_EXTRACT_DIR, filename)
            with open(file_path, "r") as file:
                code += f"///{filename}///\n{file.read()}"
        lines_of_code = code.count("\n") + 1

        style_analysis_result = self.style_analyzer_llm.invoke({
            code: code,
            language: language,
        })

        result_json = json.loads(str(style_analysis_result.content))

        return Metadata(
            lines_of_code=lines_of_code,
            num_files=num_files,
            comments_quality_feedback=result_json.get("comments_quality_feedback", ""),
            code_coverage_feedback=result_json.get("code_coverate_feedback", ""),
            modularity_score=result_json.get("modularity_score", ""),
        ), code

    def grade(
        self, code_files: list, language, rubrics: str, code_run_output: str = ""
    ) -> tuple[str, str]:
        metadata, code = self._preprocess(code_files, language)
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

        result_json = json.loads(str(result.content))
        marks = result_json.get("marks", 0)
        feedback = result_json.get("feedback", "no feedback")

        return marks, feedback.strip()
