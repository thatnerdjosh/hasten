IDIR=include
CC=gcc
CFLAGS=-I$(IDIR) -g -Wall
SDL_FLAGS=$(shell sdl2-config --cflags --libs) -lSDL2_image

SRCDIR=./src

LIB_SRC:=$(wildcard $(SRCDIR)/*.c)
LIB_OBJ_SRC:=$(LIB_SRC:.c=.o)
LIB_OBJ=$(subst src/,bin/,$(LIB_OBJ_SRC))

all: build

bin/%.o: $(SRCDIR)/%.c
	@mkdir -p bin
	@$(CC) -c $(SDL_FLAGS) $(CFLAGS) -o $@ $^

build: $(LIB_OBJ)
	@$(CC) $(SDL_FLAGS) $(CFLAGS) -o bin/main $^

clean:
	@rm -rf bin/

run: build
	@./bin/main
