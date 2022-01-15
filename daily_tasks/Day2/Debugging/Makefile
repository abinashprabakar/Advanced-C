CC = gcc
CFLAGS = -g -O0

all : memory_leak

%.o : %.c
	$(CC) $(CFLAGS) -o $^

valgrind :
	valgrind --tool=memcheck --leak-check=full ./memory_leak

asan:
	$(CC) $(CFLAGS) -fsanitize=address memory_leak.c -o asan

clean:
	rm -rf *.o memory_leak asan
