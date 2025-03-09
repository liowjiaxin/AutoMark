#!/bin/bash
# Start Docker daemon
dockerd-entrypoint.sh &

# Wait for Docker daemon to start
until docker info > /dev/null 2>&1; do
    echo "Waiting for Docker to start..."
    sleep 1
done

echo "Docker started successfully!"

# Build the inner image
# docker build -t code-runner -f /app/code_runner/inner/Dockerfile.code-runner /app/code_runner/inner &

# load the code-runner image
docker load -i /code-runner.tar

# Execute the command passed to docker run
exec "$@"
