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
            # Read and validate Excel data
            df = pd.read_excel(self.excel_path, sheet_name="Lab Test 3")
            self._validate_excel(df)

            # Filter and process records
            valid_students = df[df["Score"] > 0]
            examples = []

            for _, row in valid_students.iterrows():
                try:
                    # avoid NaN values
                    int(row["ID"])
                except:
                    continue
                student_id = str(int(row["ID"]))
                feedback = str(row["Feedback"])
                code = self._get_student_code(student_id)

                if code:
                    examples.append({"code": code, "feedback": feedback})

            return examples

        except Exception as e:
            logger.error(f"Failed to load dataset: {str(e)}")
            raise

    def _validate_excel(self, df: pd.DataFrame):
        """Validate Excel structure"""
        required_columns = ["ID", "Feedback", "Score"]
        missing = [col for col in required_columns if col not in df.columns]
        if missing:
            raise ValueError(f"Excel missing required columns: {', '.join(missing)}")

    def _get_student_code(self, student_id: str) -> str:
        """Get code for a student"""
        student_dir = os.path.join(self.code_base, student_id)
        if not os.path.exists(student_dir):
            # logger.warning(f"No code directory for student {student_id}")
            return ""

        try:
            code, _ = read_code(student_dir, "C")
            return code
        except Exception as e:
            logger.warning(f"Failed to read code for {student_id}: {str(e)}")
            return ""
