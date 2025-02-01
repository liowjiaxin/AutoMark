# Use the official Ollama image
FROM ollama/ollama:latest

# Install Python and FastAPI
RUN apk add --no-cache python3 py3-pip && \
    pip3 install fastapi uvicorn

# Set up the application
WORKDIR /app
COPY . .

# Preload Llama3.2 during build
RUN ollama pull llama3.2

# Expose ports
EXPOSE 8000  # FastAPI
EXPOSE 11434 # Ollama

# Start both Ollama and FastAPI
CMD sh -c "ollama serve & uvicorn app.main:app --host 0.0.0.0 --port 8000"