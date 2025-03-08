#!/bin/sh
# Start Docker daemon
dockerd-entrypoint.sh &

# Wait for Docker daemon to start
until docker info > /dev/null 2>&1; do
    echo "Waiting for Docker to start..."
    sleep 1
done

echo "Docker started successfully!"

# Build the inner image
docker build -t code-runner -f Dockerfile.code-runner /app/code_runner/inner

# Execute the command passed to docker run
exec "$@"
