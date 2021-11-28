CC = gcc
CFLAGS = -Wall -g
AR=ar
C2COMPILE = main.c
#make all
all: connections

#make main:
main.o: $(C2COMPILE) my_mat.h
	$(CC) $(CFLAGS) -c $(C2COMPILE) 
main: main.o
	$(CC) $(CFLAGS) -o main main.o

#make connections:
connections: main.o libmath.so
	$(CC) $(CFLAGS) -o connections main.o ./libmath.so -lm  

libmath.so: my_mat.o my_mat.h
	$(CC) -shared -o libmath.so my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c -lm



.PHONY: clean all

clean:
	rm -f *.o *.a *.so connections