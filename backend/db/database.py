from sqlmodel import create_engine, SQLModel, Session
import os

mysql_user = os.getenv("MYSQL_USER")
if mysql_user:
    DATABASE_URL = f"mysql+pymysql://{mysql_user}:{os.getenv('MYSQL_PASSWORD')}@db/{os.getenv('MYSQL_DATABASE')}"
else:
    DATABASE_URL = "sqlite:///./db.sqlite3"

engine = create_engine(DATABASE_URL, echo=True)


def create_db_and_tables():
    SQLModel.metadata.create_all(engine)


def get_session():
    with Session(engine) as session:
        yield session
