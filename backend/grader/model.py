from langchain_google_genai import ChatGoogleGenerativeAI
from langchain_core.prompts import ChatPromptTemplate
import os

STYLE_ANALYZER_MODEL_NAME = os.environ.get(
    "STYLE_ANALYZER_MODEL_NAME", "gemini-1.5-flash"
)
GRADER_MODEL_NAME = os.environ.get("GRADER_MODEL_NAME", "gemini-1.5-flash")

style_analyser_prompt = """
You are a code style analyst for programming assignments. Your task is to evaluate the submitted code based on the provided rubrics and generate feedback on various style aspects.

**Submission Details:**
- **Code:** 
{code}

- **Language:**
{language}

- **Rubrics:** 
1. **Comment Quality:** Assess clarity, relevance, and detail of comments.
2. **Code Coverage:** Determine whether the code is sufficiently tested or explained to cover edge cases.
3. **Modularity:** Evaluate the structure of the code regarding reuse, separation of concerns, and overall organization.

**Instructions:**
1. Analyze the code with the above rubrics in mind.
2. Provide a detailed evaluation of the comment quality.
3. Comment on the code coverage, indicating any missing tests or explanations.
4. Assign a modularity score on a scale from 0 (poorly modular) to 1 (highly modular).
5. Include any additional observations regarding duplication or stylistic issues if applicable.

**Output Format:**
Please return your response as a JSON object with the following keys:
- `"comments_quality_feedback"`: string
- `"code_coverage_feedback"`: string
- `"modularity"`: float

Example:
{
  "comments_quality_feedback": "The comments are clear but could be more descriptive in critical sections.",
  "code_coverage_feedback": "Some edge cases are not covered, and additional tests are recommended.",
  "modularity": 0.75
}
"""

grader_prompt = """
You are an expert grader for programming assignments. Using all available data, please assign a final grade and provide detailed feedback on the submission.

**Submission Details:**
- **Original Code:** 
{code}

- **Language:**
{language}

- **Grading Rubrics:** 
{rubrics}

- **Style Analysis Results:**
  - **Comments Quality Feedback:** <INSERT COMMENTS_QUALITY_FEEDBACK>
  - **Code Coverage Feedback:** <INSERT CODE_COVERAGE_FEEDBACK>
  - **Modularity Score:** <INSERT MODULARITY>

- **Additional Metadata:**
  - **Lines of Code:** {lines_of_code}
  - **Number of Files:** {num_files}
  - **Duplicated Lines:** {dup_lines}
  - **Compilation Output:** {compilation_output}
  - **Program Output:** <program_output>

**Instructions:**
1. Review the original code, rubrics, style analysis, and additional metadata.
2. Consider all factors (code correctness, style, testing, and execution behavior).
3. Provide a final grade (for example, a percentage or score out of 100).
4. Offer comprehensive feedback that highlights strengths, identifies weaknesses, and suggests areas for improvement.

**Output Format:**
Return your evaluation as a JSON object with the following keys:
- `"final_grade"`: number
- `"detailed_feedback"`: string

Example:
{
  "final_grade": 85,
  "detailed_feedback": "The code is well-organized with clear comments. However, some edge cases in testing are missing and modularity could be improved by refactoring repeated code segments."
}
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

    def analyze_and_grade(self, input: dict):
        style_analyser = StyleAnalyserLLM()
        style_analysis_result = style_analyser.invoke(input)
        
        input.update(style_analysis_result)
        
        grader = GraderLLM()
        grading_result = grader.invoke(input)
        
        return grading_result


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
