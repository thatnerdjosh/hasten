all: build run

build:
	@mkdir -p bin
	@gcc -o bin/main main.c `sdl2-config --cflags --libs`

clean:
	@rm -rf bin/

run: build
	@./bin/main
