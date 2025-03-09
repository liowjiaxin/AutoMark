from fastapi import APIRouter

router = APIRouter()


@router.get("/health")
def health_check():
    return {"status": "ok"}


@router.get("/api/code-runner-image-healthy")
def run_code_in_container():
    import docker

    client = docker.from_env()
    try:
        images = client.images.list(name="code-runner")
        if not images:
            print("Error: code-runner image not found.")
            return {"found": False}
        return {"found": True}
    except Exception as e:
        print(e)
        return {"found": False}
