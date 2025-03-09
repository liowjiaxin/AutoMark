import docker
import os
from typing import Coroutine, Callable, Any

# Initialize the Docker client
client = docker.from_env()

SUPPORTED_LANGUAGES_LIST = ["python", "c", "cpp", "java"]
SUPPORTED_PYTHON_VERSIONS = ["3.9", "3.10", "3.11", "3.12", "3.13"]


async def container_run_code_stream(
    language: str,
    version: str | None,
    code_dir: str,
    run_commands: list[str],
    send_output: Callable[[str], Coroutine[Any, Any, None]],
):
    """
    Run code in a sandbox container.
    """
    language = language.lower()

    if language == "python":
        if version not in SUPPORTED_PYTHON_VERSIONS:
            raise ValueError(
                f"Unsupported python version. Use {' '.join(SUPPORTED_PYTHON_VERSIONS)}"
            )
        # Use pyenv to set the desired python version
        run_commands.insert(0, f"bash -c 'source ~/.bashrc && pyenv global {version}'")

    if language not in SUPPORTED_LANGUAGES_LIST:
        raise ValueError("Unsupported language. Use 'python', 'c', 'cpp', or 'java'.")

    container_workdir = "/app"
    volumes = {os.path.abspath(code_dir): {"bind": container_workdir, "mode": "rw"}}
    run_commands.insert(0, f"cd {container_workdir}")

    cmd_string = " && ".join(run_commands)
    cmd = f'/bin/sh -c "{cmd_string}"'

    # TODO: support stdin

    try:
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
            stream=True,
        )

        for chunk in container.logs(stream=True, follow=True, stdout=True, stderr=True):
            chunk_str = chunk.decode("utf-8", errors="replace")
            print("output:", chunk_str)
            await send_output(chunk_str)

        result = container.wait()
        exit_code = result["StatusCode"]
        print(f"Exit code: {exit_code}")
        container.remove()

        if exit_code == 0:
            return True  # Container finished successfully
        else:
            return False  # Container finished with an error.
    except docker.errors.APIError as e:
        await send_output(f"Docker API error: {e}")
        return False
    except Exception as e:
        await send_output(f"An unexpected error occurred: {e}")
        return False
