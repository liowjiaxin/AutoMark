from fastapi import APIRouter


router = APIRouter(prefix="/api")

@router.get("/results")
def get_results():
    # TODO: Implement this endpoint
    return {"message": "Hello World"}