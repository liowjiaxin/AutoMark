import docker
import os

# Initialize the Docker client
client = docker.from_env()

SUPPORTED_LANGUAGES_LIST = ["python", "c", "cpp", "java"]
SUPPORTED_PYTHON_VERSIONS = ["3.9", "3.10", "3.11", "3.12", "3.13"]
BUFFER_SIZE = 1024


def execute_code_isolated(
    language: str, version: str | None, code_dir: str, run_commands: list[str]
):
    """
    Run code in a sandbox container.

    Returns:
      A generator yielding output lines from the container.
    """
    language = language.lower()

    if language == "python":
        if version not in SUPPORTED_PYTHON_VERSIONS:
            raise ValueError(
                f"Unsupported python version. Use {' '.join(SUPPORTED_PYTHON_VERSIONS)}"
            )
        # Use pyenv to set the desired python version
        run_commands.insert(0, f"bash -c 'source ~/.bashrc && pyenv global {version}")

    if language not in SUPPORTED_LANGUAGES_LIST:
        raise ValueError("Unsupported language. Use 'python', 'c', 'cpp', or 'java'.")

    container_workdir = "/app"
    volumes = {os.path.abspath(code_dir): {"bind": container_workdir, "mode": "rw"}}
    run_commands.insert(0, f"cd {container_workdir}")

    cmd_string = " && ".join(run_commands)
    cmd = f"/bin/sh -c '{cmd_string}'"

    # Create and start the container using the prebuilt sandbox image.
    container = client.containers.run(
        image="code-runner",  # Name/tag of code_runner image.
        command=cmd,
        user="sandboxuser",  # Run as non-root.
        detach=True,
        stdout=True,
        stderr=True,
        volumes=volumes,
        network_disabled=True,  # Disable network for added security.
        remove=True,  # Auto-remove container on exit.
        stream=True,
    )

    try:
        # Get streaming logs
        buffer = ""

        for chunk in container.logs(stream=True, follow=True, stdout=True, stderr=True):
            chunk_str = chunk.decode("utf-8", errors="replace")
            buffer += chunk_str
            if len(buffer) >= BUFFER_SIZE:
                yield buffer
                buffer = ""

        if buffer:
            yield buffer

        result = container.wait()  # Wait for the container to finish and get the result
        exit_code = result["StatusCode"]

        # TODO: handle timeout
    except Exception as e:
        # If there's an error, try to get any remaining output
        try:
            remaining_logs = container.logs()
            if remaining_logs:
                return remaining_logs.decode("utf-8")
        except Exception:
            pass
        return str(e)
    finally:
        # Ensure container is stopped and removed if still exists
        try:
            container.stop(timeout=1)
        except Exception:
            pass
