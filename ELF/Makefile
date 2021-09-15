CC = gcc
FLAGS = -g -O0

all : elf_or_not

%.o : %.c
	$(CC) $(FLAGS) -o $^

clean :
	rm -rf *.o elf_or_not
