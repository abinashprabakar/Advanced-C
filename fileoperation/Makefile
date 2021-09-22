CC = gcc
FLAGS = -g -0O

SOURCES = dup2_operation dup_operation file_read_write

all : $(SOURCES)

%.o : %.c
	$(CC) $(FLAGS) -o $^

clean:
	rm -rf *.o SOURCES
