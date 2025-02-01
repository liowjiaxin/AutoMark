#!/bin/bash

# Start Ollama in the background.
/bin/ollama serve &
# Record Process ID.
pid=$!

# Pause for Ollama to start.
sleep 5

# Pull the Llama3.2 model
ollama pull llama3.2

exec "$@"