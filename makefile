all: main.o construction.o
	gcc -o StructTest main.o construction.o

main.o: construction.h main.c
	gcc -c construction.h main.c

construction.o: construction.h construction.c
	gcc -c construction.c construction.h

run:
	./StructTest
