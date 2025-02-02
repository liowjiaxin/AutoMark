from model import chain
from dataclasses import dataclass

"""
Pipeline:

1. Preprocessing
	- Compute lines of code
	- Compute number of files
	- Detect duplicated lines with algorithm into the duplicated code + occurrences
	- Setup environment to compile and run the code
2. Code style analysing
	- Pass extracted metadata to the code style analyser
	- Ask LLM to assess comment quality, code coverage, and modularity
3. Grading
	- Get all the metadata and the code style analysis
	- Fit into the grading prompt template with the original code, rubris, and metadata
	- Get the grade and comments from LLM
	- Return to frontend

# Can consider making a progress bar
"""

@dataclass
class Metadata:
	lines_of_code: int
	number_of_files: int
	duplicated_lines: dict[str, int] # map from duplicated lines to occurrences
	compilation_output: str


class Preprocessor:
	pass


class Grader:
	def __init__(self):
		self.chain = chain

	def grade(self, code: str, rubrics: str, metadata: Metadata) -> str:
		return self.chain(code)