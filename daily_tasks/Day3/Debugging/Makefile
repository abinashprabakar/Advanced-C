CC = gcc
CFLAGS = -g -O0 -pthread

all : deadlock

%.o : %.c
	$(CC) $(CFLAGS) -o $^

valgrind :
	valgrind --tool=memcheck --leak-check=full ./deadlock

clean:
	rm -rf *.o deadlock
