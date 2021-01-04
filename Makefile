
CC = gcc
FLAGS = -Wall -g

all: isort txtfind

isort: isort.o
	$(CC) $(FLAGS) -o isort isort.o 

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c 

txtfind: txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.o

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c 

.PHONY: clean all

clean:
	rm -f *.o isort txtfind