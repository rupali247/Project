project: data.o main.o
	cc data.o main.o -o project
main.o: main.c data.h
	cc -c main.c 
data.o: data.c data.h
	cc -c data.c 






















