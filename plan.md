# Automated Marking

## Planning
```
Use Docker to run everything (web app + ai model)
Frontend html + vanilla css and js (jia xin)
Backend FastAPI with Python
AI model (plan) to use FastAPI to expose API to backend

Preprocessing student code (metadata for llm):
  1. unzip
  2. check duplication rate and where
  3. check comments density
  4. check code style (cases consistency, tab spaces consistency)?

LLM Prompt:
  1. code
  2. language
  3. metadata
  4. rubrics
  5. assignment requirements
```

## Todos
- [ ] create repo
- [ ] design ui
- [ ] frontend
  - [ ] upload zip
  - [ ] input assignment info (language, compiler, standard output...)
- [ ] backend server
  - [ ] unzip
  - [ ] parse files
  - [ ] styles checking
    - [ ] cases consistency
    - [ ] lines duplication
    - [ ] ...
  - [ ] store student scores
    - [ ] code
    - [ ] marks
    - [ ] comments
- [ ] AI
  - [ ] local LLM run with ollama and openwebui
  - [ ] fine tune deepseek r1 (?)
- [ ] Docker compose
  - [ ] web app
  - [ ] db
  - [ ] AI (with a REST API server)
