NAME = inception

start: run

run:
	mkdir -p ~/data/mariadb
	mkdir -p ~/data/wordpress
	docker compose -f srcs/docker-compose.yml up -d --build
stop:
	docker compose -f srcs/docker-compose.yml  down