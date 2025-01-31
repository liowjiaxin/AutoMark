# Automated Marking

## Planning
```
Use Docker to run everything (web app + ai model)
Frontend html + vanilla css and js (jia xin)
Backend FastAPI with Python
AI model (plan) to use FastAPI to expose API to backend
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
