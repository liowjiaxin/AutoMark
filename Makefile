all: up

up:
	docker compose up -d

down:
	docker compose down

build-up:
	docker compose up --build -d

restart:
	docker compose restart

rebuild: down build-up

logs:
	docker compose logs -f

.PHONY: all up down build-up restart rebuild
