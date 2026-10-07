CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -I./include

SRC = src/main.c src/liste.c src/pile.c src/hachage.c
OBJ = $(SRC:.c=.o)
EXEC = prog_structures

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f src/*.o $(EXEC)# Makefile du projet
