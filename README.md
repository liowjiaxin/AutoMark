# Automated Marking

## Run
1. Install [Docker](https://docs.docker.com/engine/install/)
2. Clone and cd into the repo
3. `docker compose up --build -d`
4. Open a web browser and go to [localhost:8080](http://localhost:8080)

## Grading Flow
1. Select language, version
2. Input code run commands (e.g. `python main.py`), and a timeout duration
3. Input student ID
4. Upload marking scheme and student code zip file
5. Click Run Code and wait for the result (or timeout), get the code run result id
6. Click Grade (will upload everything including the code run result id)
7. Show the grade and feedback
