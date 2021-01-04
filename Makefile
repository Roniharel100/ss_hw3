CC = gcc
FLAGS = -Wall -g

all: isort txtfind

isort: isort
	$(CC) $(FLAGS) -o isort isort.c

txtfind: txtfind
	$(CC) $(FLAGS) -o txtfind txtfind.c

.PHONY: clean all

clean:
	rm -f *.o isort txtfind