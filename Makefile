CC = gcc
FLAGS = -Wall -g

all: isort txtfind

isort: isort
	$(CC) $(FLAGS) isort.c -o isort 

txtfind: txtfind
	$(CC) $(FLAGS) txtfind.c -o txtfind

.PHONY: clean all

clean:
	rm -f *.o isort txtfind