from sqlmodel import create_engine, SQLModel
import os

mysql_user = os.getenv('MYSQL_USER')
if mysql_user:
    DATABASE_URL = f"mysql+pymysql://{mysql_user}:{os.getenv('MYSQL_PASSWORD')}@db/{os.getenv('MYSQL_DATABASE')}"
else:
    DATABASE_URL = "sqlite:///./db.sqlite3"

engine = create_engine(DATABASE_URL, echo=True)

def create_db_and_tables():
    SQLModel.metadata.create_all(engine)