IDIR=include
CC=gcc
CFLAGS=-I$(IDIR) -g -Wall
SDL_FLAGS=$(shell sdl2-config --cflags --libs) -lSDL2_image

SRCDIR=./src
OBJECTDIR=build
BINDIR=bin

LIB_SRC:=$(wildcard $(SRCDIR)/*.c)
LIB_OBJ_SRC:=$(LIB_SRC:.c=.o)
LIB_OBJ=$(subst src/,$(OBJECTDIR)/,$(LIB_OBJ_SRC))

all: build

$(OBJECTDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJECTDIR)
	@$(CC) -c $(SDL_FLAGS) $(CFLAGS) -o $@ $^

build: $(LIB_OBJ)
	@mkdir -p $(BINDIR)
	@$(CC) $(SDL_FLAGS) $(CFLAGS) -o $(BINDIR)/main $^

clean:
	@rm -rf $(OBJECTDIR)
	@rm -rf $(BINDIR)

run: build
	@./$(BINDIR)/main

.PHONY: run clean
