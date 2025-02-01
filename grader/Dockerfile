# Use the official Ollama image
FROM ollama/ollama:latest

# Install Python
RUN apt update && apt install -y python3-pip

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# Set up the application
WORKDIR /app
COPY . .

RUN chmod +x ./entrypoint.sh

# Start the FastAPI server
ENTRYPOINT ["/app/entrypoint.sh"]

CMD ["uvicorn", "main:app", "--host", "0.0.0.0", "--port", "8000"]
