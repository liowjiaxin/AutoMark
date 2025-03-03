import os
from pydantic_settings import BaseSettings


class Settings(BaseSettings):
    API_V1_STR: str = "/api/v1"
    PROJECT_NAME: str = "Code Grading API"
    FILE_UPLOAD_DIR: str = "uploaded_files"
    TEMP_EXTRACT_DIR: str = "temp/extracted"

    class Config:
        case_sensitive = True
        env_file = ".env"


settings = Settings()

# Ensure necessary directories exist
os.makedirs(settings.FILE_UPLOAD_DIR, exist_ok=True)
os.makedirs(settings.TEMP_EXTRACT_DIR, exist_ok=True)
