CC = gcc
CFLAGS = -c -fpic

all : print multiplication addition libabc.so

%.o : %.c
	$(CC) $(CFLAGS) $^

clean :
	rm -rf *.o print multiplication addition
