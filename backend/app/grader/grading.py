from grader.llm import StyleAnalyserLLM, GraderLLM
from dataclasses import dataclass

"""
Pipeline:

1. Preprocessing
	- Compute lines of code
	- Compute number of files
	- Setup environment to compile and run the code (stream the code run output)
2. Code style analysing
	- Pass extracted metadata to the code style analyser
	- Ask LLM to assess comment quality, code coverage, and modularity
3. Grading
	- Get all the metadata and the code style analysis
	- Fit into the grading prompt template with the original code, rubris, and metadata
	- Get the grade and feedback from LLM
	- Return to frontend
"""


@dataclass
class Metadata:
    lines_of_code: int
    number_of_files: int
    duplicated_lines: dict[str, int]  # map from duplicated lines to occurrences
    comments_quality_feedback: str
    code_coverage_feedback: str
    modularity: float
    compilation_output: str
    program_output: str


# TODO: do preprocessing
class Preprocessor:
    pass


class Grader:
    def __init__(self):
        self.style_analyzer_llm = StyleAnalyserLLM()
        self.grader_llm = GraderLLM()

    def _preprocess(self, code: str) -> Metadata:
        pass

    def grade(self, code: str, rubrics: str) -> tuple[str, str]:
        """
        Pass in student's code, rubrics.
        Return grade, feedback
        """
        result = self.grader_llm.invoke({"code": code, "rubrics": rubrics})

        feedback, grade = result.content.split("===SPLITTER===")
        return grade.strip(), feedback.strip()
