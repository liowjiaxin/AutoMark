import docker
import shlex
from pathlib import Path

# Initialize the Docker client
client = docker.from_env()

SUPPORTED_PYTHON_VERSIONS = ["3.9", "3.10", "3.11", "3.12", "3.13"]


def run_code(language: str, version: str, code_dir_path: Path, run_commands: list[str]):
    """
    Run code in a sandbox container.

    Parameters:
      language: "python", "c", "cpp", or "java"
      version: For Python, a pyenv version string (e.g. "3.10.13").
               For C/C++ and Java, this parameter can be ignored or used to choose among compiler options.
      code: The source code to run.

    Returns:
      A generator yielding output lines (stdout/stderr) from the container.
    """
    language = language.lower()

    if language == "python":
        # Use pyenv to set the desired python version and run the code
        # Use shlex.quote to safely escape the code snippet.
        cmd = (
            "bash -c 'source ~/.bashrc && pyenv global {version} && python -c {code}'"
        ).format(version=version, code=shlex.quote(code))
    elif language in ("c", "cpp"):
        # For C/C++, write code to a temporary file, compile, then run.
        file_ext = "c" if language == "c" else "cpp"
        compiler = "gcc" if language == "c" else "g++"
        cmd = (
            "bash -c 'echo {code} > /sandbox/temp.{ext} && "
            "{compiler} /sandbox/temp.{ext} -o /sandbox/a.out && "
            "/sandbox/a.out'"
        ).format(code=shlex.quote(code), ext=file_ext, compiler=compiler)
    elif language == "java":
        # For Java, write code to Main.java, compile, then run.
        # Assume the user code has a public class Main with a main() method.
        cmd = (
            "bash -c 'echo {code} > /sandbox/Main.java && "
            "javac /sandbox/Main.java && "
            "java -cp /sandbox Main'"
        ).format(code=shlex.quote(code))
    else:
        raise ValueError("Unsupported language. Use 'python', 'c', 'cpp', or 'java'.")

    # Create and start the container using the prebuilt sandbox image.
    container = client.containers.run(
        image="code-runner",  # Name/tag of your prebuilt image.
        command=cmd,
        user="sandboxuser",  # Run as non-root.
        detach=True,
        stdout=True,
        stderr=True,
        network_disabled=True,  # Disable network for added security.
        remove=True,  # Auto-remove container on exit.
    )

    try:
        # Stream logs (both stdout and stderr) line by line.
        for out in container.logs(stream=True, stdout=True, stderr=True, demux=True):
            stdout_chunk, stderr_chunk = out
            if stdout_chunk:
                yield {"type": "stdout", "message": stdout_chunk.decode("utf-8")}
            if stderr_chunk:
                yield {"type": "stderr", "message": stderr_chunk.decode("utf-8")}
        # Optionally, wait for container to finish
        container.wait()
    except Exception as e:
        yield f"Error streaming logs: {e}"
