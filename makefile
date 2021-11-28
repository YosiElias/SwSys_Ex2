CC = gcc
CFLAGS = -Wall -g
AR=ar
OBJECTS_MAIN=main.o
OBJECT = advancedClassificationLoop.o basicClassification.o 
# C2COMPILE = try.c
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



#make maindloop:
maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) -o maindloop main.o ./libclassloops.so -lm
#make maindrec:
maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o maindrec main.o ./libclassrec.so -lm
#make loops:
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c -lm
loops:libclassloops.a
libclassloops.a: $(OBJECTS_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOP)
#make recursives:
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c -lm
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c -lm
recursives:libclassrec.a
libclassrec.a: $(OBJECTS_REC)
	$(AR) -rcs libclassrec.a $(OBJECTS_REC)
#make recursived:
recursived:libclassrec.so
libclassrec.so: $(OBJECTS_REC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_REC)
#make loopd:
loopd:libclassloops.so
libclassloops.so: $(OBJECTS_LOOP) NumClass.h
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOP)

.PHONY: clean all

clean:
	rm -f *.o *.a *.so connections