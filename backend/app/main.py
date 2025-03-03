from fastapi import FastAPI
from contextlib import asynccontextmanager

from db.database import engine, create_db_and_tables
from api.endpoints import health, submissions
from core.config import settings


@asynccontextmanager
async def lifespan(app: FastAPI):
    create_db_and_tables()
    yield
    engine.dispose()


def create_application() -> FastAPI:
    application = FastAPI(lifespan=lifespan)

    # Include routers
    application.include_router(health.router)
    application.include_router(submissions.api_router)
    application.include_router(submissions.ws_router)

    return application


app = create_application()

if __name__ == "__main__":
    import uvicorn

    uvicorn.run(app, host="0.0.0.0", port=8000)
