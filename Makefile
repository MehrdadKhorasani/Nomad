CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Iinclude
LDFLAGS = -lncurses
SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,build/obj/%.o,$(SRC))
TARGET = build/bin/nomad

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p build/bin
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

build/obj/%.o: src/%.c
	@mkdir -p build/obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build

run: all
	./$(TARGET)
