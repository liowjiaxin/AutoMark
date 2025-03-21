import os
import PyPDF2
from typing import Tuple


def read_code(directory: str, language: str) -> Tuple[str, int]:
    """Read all code files in a directory and concatenate into one string."""
    extensions = {"C": [".c", ".h"], "Python": [".py"], "Java": [".java"]}[language]

    code = []
    file_count = 0
    for root, _, files in os.walk(directory):
        for file in files:
            if any(file.endswith(ext) for ext in extensions):
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, "r", encoding="utf-8") as f:
                        code.append(f"// File: {file}\n{f.read()}\n")
                    file_count += 1
                except UnicodeDecodeError:
                    print(f"Warning: Could not read {file_path} - binary file?")

    if not code:
        raise ValueError(f"No {language} code files found in {directory}")

    return "\n".join(code), file_count


def read_pdf(pdf_path: str) -> str:
    """Extract text content from a PDF marking scheme."""
    text = []
    try:
        with open(pdf_path, "rb") as f:
            reader = PyPDF2.PdfReader(f)
            for page in reader.pages:
                text.append(page.extract_text())
    except Exception as e:
        raise RuntimeError(f"Failed to read PDF: {str(e)}")

    return "\n".join(text)
