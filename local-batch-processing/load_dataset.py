import os
import pandas as pd
from typing import List, Dict
from helper import read_code  # From previous helper.py
import logging

logger = logging.getLogger(__name__)


class DatasetLoader:
    def __init__(self, dataset_path: str):
        self.dataset_path = dataset_path
        self.excel_path = os.path.join(dataset_path, "feedback.xlsx")
        self.code_base = os.path.join(dataset_path, "source_code")

        if not os.path.exists(self.excel_path):
            raise FileNotFoundError(f"Excel file not found at {self.excel_path}")
        if not os.path.exists(self.code_base):
            raise FileNotFoundError(f"Code directory not found at {self.code_base}")

    def _load_examples(self) -> List[Dict[str, str]]:
        """Load dataset from Excel and code folders"""
        try:
            # Read Excel data
            logger.info(f"Reading Excel file from {self.excel_path}")
            df = pd.read_excel(self.excel_path)
            logger.info(f"Excel file loaded with {len(df)} rows")
            
            # Get all code files from source_code directory
            logger.info("Reading code files...")
            code, num_files = read_code(self.code_base, "C")
            logger.info(f"Read {num_files} code files")
            
            if not code:
                logger.warning("No code files found in source_code directory")
                return []
                
            # Create examples from the first row of feedback
            examples = []
            for _, row in df.iterrows():
                if "Feedback" in row:
                    feedback = str(row["Feedback"])
                    examples.append({"code": code, "feedback": feedback})
                    logger.info("Created example with feedback")
                    break  # Only use the first row for now
            
            if not examples:
                logger.warning("No valid examples created from Excel data")
                return []
                
            logger.info(f"Successfully loaded {len(examples)} examples")
            return examples

        except Exception as e:
            logger.error(f"Failed to load dataset: {str(e)}", exc_info=True)
            raise

    def _validate_excel(self, df: pd.DataFrame):
        """Validate Excel structure"""
        required_columns = ["ID", "Feedback", "Score"]
        missing = [col for col in required_columns if col not in df.columns]
        if missing:
            raise ValueError(f"Excel missing required columns: {', '.join(missing)}")

    def _get_all_code(self) -> str:
        """Get all code from source_code directory"""
        try:
            code, _ = read_code(self.code_base, "C")
            return code
        except Exception as e:
            logger.warning(f"Failed to read code: {str(e)}")
            return ""
