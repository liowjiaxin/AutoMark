#!/bin/bash
# Start Docker daemon
dockerd-entrypoint.sh &

# Wait for Docker daemon to start
until docker info > /dev/null 2>&1; do
    echo "Waiting for Docker to start..."
    sleep 1
done

echo "Docker started successfully!"

# pull the docker image from dockerhub
docker pull jiaxinliow/code-runner:1.0 && docker tag jiaxinliow/code-runner:1.0 code-runner:1.0 &

# Execute the command passed to docker run
exec "$@"
