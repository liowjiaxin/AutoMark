from langchain_community.vectorstores import FAISS
from langchain_core.embeddings import Embeddings
from langchain_google_genai import GoogleGenerativeAIEmbeddings
from langchain_core.output_parsers import JsonOutputParser
from langchain_core.prompts import PromptTemplate
from pydantic import BaseModel
from langchain_google_genai import ChatGoogleGenerativeAI
from langchain_core.prompts import ChatPromptTemplate
from load_dataset import DatasetLoader
import pickle
import os

from dotenv import load_dotenv

load_dotenv()


GRADER_MODEL_NAME = os.environ.get("GRADER_MODEL_NAME", "gemini-1.5-flash")
VECTOR_STORE_PATH = "c_dataset_faiss.pkl"

system_prompt = """
**Role**: You are CodeGrader-ULTRA, an expert AI teaching assistant for programming courses.
Your task is to rigorously evaluate student submissions by combining software engineering best practices with pedagogical expertise.
"""

grader_prompt = """
You are an expert programming assignment grader with 20 years of experience. Conduct a comprehensive evaluation of the submission using the multi-dimensional rubric below.

**Submission Analysis Framework**

1. **Code Comprehension** (10%)
- Does the code demonstrate understanding of core concepts?
- Is there evidence of conceptual misunderstandings?

2. **Functional Correctness** (30%)
- Does the code solve the problem as specified?
- Test case coverage (basic, edge, stress cases)
- Error handling and robustness

3. **Code Quality** (25%)
- [Comments] Clarity, relevance, and density (aim for 20-30% comment ratio)
- [Modularity] Logical decomposition, function length (<30 lines), DRY principle
- [Readability] Naming conventions, spacing, structural organization

4. **Technical Implementation** (25%)
- Algorithm efficiency (time/space complexity)
- Language feature appropriateness
- Resource management (memory, files, connections)

5. **Testing & Verification** (10%)
- Test existence and quality (if required)
- Input validation
- Debugging evidence

**Evaluation Context**
- Submission Language: {language}
- Lines of Code: {lines_of_code}
- Number of Files: {num_files}
- Special Requirements: {rubrics}

**Analysis Protocol**
1. **Structural Scan**: Perform initial code structure evaluation
2. **Semantic Analysis**: Cross-reference requirements with implementation
3. **Defect Identification**: List technical and stylistic issues
4. **Strength Recognition**: Highlight exemplary practices
5. **Improvement Roadmap**: Create prioritized suggestions

**Scoring Guidelines**
- 90-100: Flawless implementation exceeding requirements
- 80-89: Minor issues with excellent fundamentals
- 70-79: Functional but needs quality improvements
- 60-69: Partial solution with significant gaps
- <60: Non-working or severely deficient

**Output Schema**
{{
  "marks": <0-100>,
  "feedback": str,
}} 

**Submission Code**
{code}

**Evaluation Process**
1. Analyze the code through multiple passes
2. Compare against language best practices
3. Generate scores using weighted rubric components
4. Maintain strict but fair academic standards

**Special Instructions**
- Penalize security risks severely (-10-20 points)
- Reward innovative but appropriate solutions (+5-10 bonus)
- Flag academic integrity concerns explicitly
- Consider lines/file ratios in quality assessment
"""


class GradeFeedback(BaseModel):
    marks: str
    feedback: str


class GraderRAG:
    def __init__(self, dataset_path: str):
        # Initialize embeddings and vector store
        self.embedder: Embeddings = GoogleGenerativeAIEmbeddings(
            model="models/embedding-001"
        )
        self.dataset_path = dataset_path
        self.vector_store = self._load_or_create_vector_store()

        self.llm = ChatGoogleGenerativeAI(
            model=GRADER_MODEL_NAME,
            temperature=0,
            max_tokens=None,
            timeout=None,
            max_retries=2,
        )

        # Initialize grader chain
        self.grader = self._create_grader_chain()

    def _load_or_create_vector_store(self) -> FAISS:
        if os.path.exists(VECTOR_STORE_PATH):
            print(f"Loading vector store from {VECTOR_STORE_PATH}")
            with open(VECTOR_STORE_PATH, "rb") as f:
                return pickle.load(f)
        else:
            print(f"Creating vector store from {self.dataset_path}")
            vector_store = self._initialize_vector_store(self.dataset_path)
            self._save_vector_store(vector_store)
            return vector_store

    def _initialize_vector_store(self, dataset_path: str) -> FAISS:
        # Load and preprocess C assignment dataset
        examples = self._load_examples(dataset_path)

        # Create embeddings for code + feedback pairs
        texts = [f"Code: {ex['code']}\nFeedback: {ex['feedback']}" for ex in examples]
        return FAISS.from_texts(texts, self.embedder)

    def _save_vector_store(self, vector_store: FAISS):
        return
        with open(VECTOR_STORE_PATH, "wb") as f:
            pickle.dump(vector_store, f)
        print(f"Vector store saved to {VECTOR_STORE_PATH}")

    def _load_examples(self, path: str) -> list:
        loader = DatasetLoader(path)
        return loader._load_examples()

    def _create_grader_chain(self):
        # Modified prompt with RAG instructions
        rag_prompt = (
            grader_prompt
            + """
        **Retrieved Reference Examples**
        {examples}

        **Revised Grading Instructions**
        1. Compare submission with similar historical examples
        2. Note patterns in feedback from reference cases
        3. Adjust scoring based on historical precedent
        """
        )

        # Define the enhanced prompt template
        prompt_template = ChatPromptTemplate.from_messages([
            ("system", system_prompt),
            ("human", rag_prompt),
        ])

        return (
            prompt_template | self.llm | JsonOutputParser(pydantic_object=GradeFeedback)
        )

    def _retrieve_examples(self, code: str, k: int = 3) -> str:
        # Retrieve similar code examples
        docs = self.vector_store.similarity_search(code, k=k)
        return "\n\n".join(
            f"Example {i + 1}:\n{d.page_content}" for i, d in enumerate(docs)
        )

    def grade(self, input_data: dict) -> dict:
        # Perform RAG retrieval
        examples = self._retrieve_examples(input_data["code"])

        # Add examples to input
        input_data["examples"] = examples

        # Invoke grading chain
        return self.grader.invoke(input_data)
