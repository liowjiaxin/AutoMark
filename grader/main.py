from fastapi import FastAPI
from pydantic import BaseModel
import ollama

app = FastAPI()

class CodeInput(BaseModel):
    code: str

@app.post("/grade")
async def grade_code(input: CodeInput):
    response = ollama.generate(
        model=os.getenv('OLLAMA_MODEL'),
        prompt=f"Grade this code: {input.code}"
    )
    return {"grade": response['response']}
