from langchain_community.vectorstores import FAISS
from langchain_core.embeddings import Embeddings
from langchain_google_genai import GoogleGenerativeAIEmbeddings
from langchain_core.output_parsers import JsonOutputParser
from langchain_core.prompts import PromptTemplate
from pydantic import BaseModel
from langchain_core.prompts import ChatPromptTemplate
from load_dataset import DatasetLoader
from typing import Literal
import os
import logging

from dotenv import load_dotenv

load_dotenv()

# Set up logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

GRADER_MODEL_NAME = "models/gemini-1.5-pro"  # Updated model name
VECTOR_STORE_PATH = "c_dataset_faiss"  # Directory for FAISS index

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


class GradingOutput(BaseModel):
    code_comprehension: float  # 10% of 15 = 1.5 marks
    functional_correctness: float  # 30% of 15 = 4.5 marks
    code_quality: float  # 25% of 15 = 3.75 marks
    technical_implementation: float  # 25% of 15 = 3.75 marks
    testing_verification: float  # 10% of 15 = 1.5 marks
    feedback: str
    total_mark: float  # Will be scaled to 15

    def calculate_total(self):
        # Scale each component to 15% total
        self.total_mark = (
            (self.code_comprehension * 0.015) +  # 10% of 15
            (self.functional_correctness * 0.045) +  # 30% of 15
            (self.code_quality * 0.0375) +  # 25% of 15
            (self.technical_implementation * 0.0375) +  # 25% of 15
            (self.testing_verification * 0.015)  # 10% of 15
        )
        return self.total_mark


class GraderRAG:
    def __init__(self, dataset_path: str, model_type: str = GRADER_MODEL_NAME):
        logger.info(f"Initializing GraderRAG with model_type={model_type}")
        self.model_type = model_type
        
        # Initialize embeddings
        logger.info("Initializing embeddings model...")
        self.embedder = GoogleGenerativeAIEmbeddings(
            model="models/embedding-001"
        )
        logger.info("Embeddings model initialized")
        
        # Load or create vector store
        logger.info("Loading vector store...")
        self.vector_store = self._load_or_create_vector_store()
        
        # Initialize LLM
        logger.info("Initializing LLM...")
        self.llm = self._initialize_llm()
        
        # Create grader chain
        logger.info("Creating grader chain...")
        self.grader = self._create_grader_chain()
        logger.info("Grader chain created")

    def _initialize_llm(self):
        """Initialize the LLM based on selected model type"""
        if "gemini" in self.model_type.lower():
            from langchain_google_genai import ChatGoogleGenerativeAI

            return ChatGoogleGenerativeAI(
                model=self.model_type if "models/" in self.model_type else GRADER_MODEL_NAME,
                temperature=0,
                max_tokens=None,
                max_retries=1,
                timeout=30,
            )
        elif self.model_type == "deepseek":
            from langchain_deepseek import ChatDeepSeek

            api_key = os.getenv("DEEPSEEK_API_KEY")
            if not api_key:
                raise ValueError("DEEPSEEK_API_KEY environment variable not set")

            return ChatDeepSeek(
                model_kwargs={"api_key": api_key},
                model_name="deepseek-coder-33b-instruct",
                temperature=0,
                max_tokens=4096,
                request_timeout=30
            )
        else:
            raise ValueError(f"Unsupported model type: {self.model_type}")

    def _load_or_create_vector_store(self) -> FAISS:
        try:
            if os.path.exists(VECTOR_STORE_PATH):
                logger.info(f"Loading vector store from {VECTOR_STORE_PATH}")
                return FAISS.load_local(VECTOR_STORE_PATH, self.embedder, allow_dangerous_deserialization=True)
            else:
                logger.info(f"Creating vector store from {self.dataset_path}")
                vector_store = self._initialize_vector_store(self.dataset_path)
                self._save_vector_store(vector_store)
                return vector_store
        except Exception as e:
            logger.warning(f"Failed to load vector store, creating new one: {str(e)}")
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
        try:
            vector_store.save_local(VECTOR_STORE_PATH)
            logger.info(f"Vector store saved to {VECTOR_STORE_PATH}")
        except Exception as e:
            logger.error(f"Failed to save vector store: {str(e)}")

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

    def _retrieve_examples(self, code: str, k: int = 5):
        logger = logging.getLogger(__name__)
        logger.info("Retrieving similar examples from vector store...")
        
        # Generate the query vector
        query_vector = self.embedder.embed_query(code)  # Replace with the correct embedding method
        logger.debug(f"Query vector dimension: {len(query_vector)}")
        logger.debug(f"FAISS index dimension: {self.vector_store.index.d}")
        
        # Perform similarity search
        try:
            docs = self.vector_store.similarity_search_by_vector(query_vector, k=k)
            return docs
        except AssertionError as e:
            logger.error("Dimensionality mismatch between query vector and FAISS index.")
            raise e

    def grade(self, code: str, language: str = "C", lines_of_code: int = 0, num_files: int = 1, rubrics: str = "") -> dict:
        logger.info("Starting grading process...")
        
        # Retrieve similar examples
        logger.info("Retrieving similar examples...")
        examples = self._retrieve_examples(code)
        logger.info("Examples retrieved")
        
        # Prepare input for grading
        input_data = {
            "code": code,
            "language": language,
            "lines_of_code": lines_of_code,
            "num_files": num_files,
            "rubrics": rubrics,
            "examples": examples
        }
        
        # Invoke grading chain
        logger.info("Invoking grading chain...")
        result = self.grader.invoke(input_data)
        logger.info("Grading completed")
        
        # Scale the total mark to 15%
        if isinstance(result, dict) and "total_mark" in result:
            result["total_mark"] = result["total_mark"] * 0.15
        
        return result
