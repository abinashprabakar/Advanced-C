CC = gcc
FLAGS = -g -0O -o

SOURCES = dup2_operation dup_operation file_read_write

all : $(SOURCES)

%.o : %.c
	$(CC) $(FLAGS) $^

clean:
	rm -rf *.o SOURCES
