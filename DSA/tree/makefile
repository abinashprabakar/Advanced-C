CC = gcc
FLAGS = -g -O0 -o
SOURCES = binary_search_tree avl_tree binary tree

all : $(SOURCES)

%.o : %.c
	$(CC) $(FLAGS) $^
clean:
	rm -rf *.o SOURCES
