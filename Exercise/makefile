CC = gcc
FLAGS = -g -O0 -o

all : setupClass sort_reverse_dll test1 test2 wc_implementation_switch

%.o : %.c
	$(CC) $(FLAGS) $^
	
clean : 
	rm -rf *.o all
