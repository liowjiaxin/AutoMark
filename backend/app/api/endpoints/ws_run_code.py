from fastapi import APIRouter, WebSocket, Depends, WebSocketDisconnect
from sqlmodel import Session
from api.dependencies import get_db
from core.utils import extract_zip_file, cleanup_extracted_files
from code_runner.runner import container_run_code_stream, client
from db.models import CodeRunResult
import json
import asyncio
from dataclasses import dataclass
from core.config import settings
import os


router = APIRouter(prefix="/ws")


@dataclass
class RunCodeInitialData:
    code_zip_filename: str
    language: str
    commands: list[str]
    version: str = ""
    stdin_input_filename: str = ""


@router.websocket("/run-code")
async def run_code(websocket: WebSocket, session: Session = Depends(get_db)):
    await websocket.accept()

    initial_data: None | RunCodeInitialData = None
    timeout_duration = 3
    extract_path = ""
    code_run_output = ""

    async def send_code_run_output(output: str):
        """Concat the output to the full code run output, and send the output to frontend through websocket"""
        nonlocal code_run_output
        code_run_output += output
        await websocket.send_text(json.dumps({"output": output}))

    # 1. get all the information needed from client
    # 2. Start executing, allow client to do stdin input, stop run
    # 3. line by line return the code run output
    try:

        async def receive_initial_data():
            nonlocal initial_data, extract_path
            data = await websocket.receive_text()
            try:
                message: dict = json.loads(data)
                initial_data = RunCodeInitialData(
                    code_zip_filename=message.get("code_zip_filename", ""),
                    language=message.get("language", ""),
                    commands=message.get("commands", []),
                    version=message.get("version", ""),
                    stdin_input_filename=message.get("stdin_input_filename", ""),
                )

                _, extract_path = extract_zip_file(initial_data.code_zip_filename)

                stdin_input_file_path = ""
                if initial_data.stdin_input_filename:
                    stdin_input_file_path = os.path.join(
                        settings.FILE_UPLOAD_DIR, initial_data.stdin_input_filename
                    )
                    if not os.path.exists(stdin_input_file_path):
                        stdin_input_file_path = ""

                # Start Docker container
                container_task = asyncio.create_task(
                    container_run_code_stream(
                        initial_data.language,
                        initial_data.version,
                        extract_path,
                        initial_data.commands,
                        stdin_input_file_path=stdin_input_file_path,
                        send_output=send_code_run_output,
                    )
                )
                return container_task

            except json.JSONDecodeError:
                await websocket.send_text(json.dumps({"error": "Invalid JSON format"}))
                raise WebSocketDisconnect(code=1003)
            except Exception as e:
                await websocket.send_text(
                    json.dumps({"error": f"Error processing initial data: {e}"})
                )
                raise WebSocketDisconnect(code=1011)

        container_task = await asyncio.wait_for(
            receive_initial_data(), timeout=timeout_duration
        )

        while True:
            if container_task.done():  # Check if container task has completed.
                break

            data = await websocket.receive_text()
            message = json.loads(data)

            if message.get("stop"):
                if container_task and not container_task.done():
                    client.containers.get(
                        container_task.get_coro().__self__.container.id
                    ).kill()
                    await container_task  # wait for the container task to finish.
                await websocket.send_text(json.dumps({"status": "Container stopped"}))
                break  # exit the websocket loop.

        code_run_result = CodeRunResult(output=code_run_output)
        session.add(code_run_result)
        session.commit()
        session.refresh(code_run_result)

        await websocket.send_text(
            json.dumps({"code_run_id": code_run_result.id, "status": "DONE"})
        )

        cleanup_extracted_files(extract_path)
    except Exception as e:
        print(f"WebSocket error: {e}")
    finally:
        await websocket.close()
