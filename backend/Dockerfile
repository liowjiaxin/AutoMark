FROM docker:dind

WORKDIR /app

RUN apk add --no-cache python3~=3.11 py3-pip

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY . .

# Build the inner code-runner image during the setup
RUN dockerd & \
  sleep 5 && \
  docker build -t code-runner -f Dockerfile.code-runner /app/inner && \
  pkill dockerd  # Stop temporary Docker daemon after building

CMD ["uvicorn", "main:app", "--host", "0.0.0.0", "--port", "8000"]
