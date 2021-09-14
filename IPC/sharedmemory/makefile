CC = gcc
FLAGS = -f -O0

all : memory_creation memory_delete memory_process memory_read

%.o : %.c
	$(CC) $(FLAGS) -o $^

clean :
	rm -r*.o memory_creation memory_delete memory_process memory_read
