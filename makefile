CC = gcc
FLAGS = -Wall -g
OBJECTS_MAIN = text_main.o
OBJECTS_SORT_MAIN = sort_main.o

all: isort txtfind

isort: $(OBJECTS_SORT_MAIN) methods.o
	$(CC) $(FLAGS) -o isort $(OBJECTS_SORT_MAIN) methods.o

txtfind: $(OBJECTS_MAIN) methods.o
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_MAIN) methods.o

text_main.o: text_main.c methods.h
	$(CC) $(FLAGS) -c text_main.c

sort_main.o: sort_main.c methods.h
	$(CC) $(FLAGS) -c sort_main.c

methods.o: methods.c methods.h
	$(CC) $(FLAGS) -c methods.c

.PHONY: clean all

clean:
	rm -f *.o isort txtfind
	