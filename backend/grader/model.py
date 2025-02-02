from langchain_google_genai import ChatGoogleGenerativeAI
from langchain_core.prompts import ChatPromptTemplate
import os

STYLE_ANALYZER_MODEL_NAME = os.environ.get("STYLE_ANALYZER_MODEL_NAME", "gemini-1.5-flash")
GRADER_MODEL_NAME = os.environ.get("GRADER_MODEL_NAME", "gemini-1.5-flash")

# TODO: refine the prompt template
style_analyser_prompt = """
You are a code grading assistant. Evaluate the following code based on the provided rubric:

Code:
{code}

Rubric:
{rubrics}

Provide a grade and detailed feedback. Give the grade at the last line and prefix it with "Grade:".
Grades can only be from A to F.
"""

# TODO: refine the prompt template
grader_prompt = """
You are a code grading assistant. Evaluate the following code based on the provided rubric:

Code:
{code}

Rubric:
{rubrics}

Provide a grade and detailed feedback. Grades can only be from A to F.
Give the feedback first and then grade by putting an splitter '===SPLITTER==='.
"""

class LLM:
	def __init__(self, model_name: str, prompt_template: str, system_prompt: str):
		self.llm = ChatGoogleGenerativeAI(
            model=model_name,
            temperature=0,
            max_tokens=None,
            timeout=None,
            max_retries=2,
        )
		self.unified_prompt_template = prompt_template
		self.prompt_template = ChatPromptTemplate.from_messages([
            ("system", system_prompt),
            ("user", self.unified_prompt_template),
        ])
		self.chain = self.prompt_template | self.llm

	def invoke(self, input: dict):
		return self.chain.invoke(input)

class StyleAnalyserLLM(LLM):
    def __init__(self):
        model_name = STYLE_ANALYZER_MODEL_NAME
        system_prompt = "You are an expert in analysing code style and give feedback on comments quality, code coverage, and modularity."
        super().__init__(model_name, style_analyser_prompt, system_prompt)

class GraderLLM(LLM):
    def __init__(self):
        model_name = GRADER_MODEL_NAME
        system_prompt = "You are an expert in giving grade and feedback with the code and the code comments quality + code coverage + modularity information."
        super().__init__(model_name, grader_prompt, system_prompt)
