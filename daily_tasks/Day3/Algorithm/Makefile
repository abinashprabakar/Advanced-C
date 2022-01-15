CC = gcc
CFLAGS = -g -O0

all : encryption

%.o : %.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o encryption
