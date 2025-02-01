from typing import Optional
from fastapi import FastAPI
import httpx
from pydantic import BaseModel
from model_formatter import format_input, format_output

app = FastAPI()

class GradingRequest(BaseModel):
    code: str
    rubric: Optional[str] = ""

@app.post("/grade")
async def grade_submission(request: GradingRequest):
    # Format input for Llama3.2
    prompt = format_input(request.code, request.rubric)
    
    # Send to Ollama
    try:
        async with httpx.AsyncClient() as client:
            response = await client.post(
                "http://localhost:11434/api/generate",
                json={
                    "model": "llama3.2",
                    "prompt": prompt,
                    "stream": False
                }
            )
    except Exception as e:
        return {
            "grade": "AI grading server not ready yet."
        }
    
    # Format output for the client
    result = format_output(response.json()["response"])
    return {"grade": result}