from langchain_google_genai import ChatGoogleGenerativeAI
from langchain_core.prompts import ChatPromptTemplate

llm = ChatGoogleGenerativeAI(
    model="gemini-1.5-pro",
    temperature=0,
    max_tokens=None,
    timeout=None,
    max_retries=2,
    # other params...
)

unified_prompt_template = """

"""

prompt_template = ChatPromptTemplate.from_messages([
    ("system", "You are an expert in marking and giving comments to code assignments."),
    ("user", unified_prompt_template),
])

chain = prompt_template | llm
