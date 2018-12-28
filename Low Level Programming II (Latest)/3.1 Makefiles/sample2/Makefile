# CC represents the compiler to use
CC = gcc

# CFLAGS are the compiler options
CFLAGS = -Wall -c

hello: build
build: main.o hello_fn.o
	$(CC) main.o hello_fn.o -o newhello
main.o:
	$(CC) $(CFLAGS) main.c
hello_fn.o:
	$(CC) $(CFLAGS) hello_fn.c
clean:
	-rm *.o newhello