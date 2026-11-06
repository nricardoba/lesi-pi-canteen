all: run

helpers.o: helpers.c helpers.h
	gcc -c helpers.c

prog: main.c helpers.o helpers.h
	gcc main.c helpers.o -o prog

run: prog
	./prog

clean:
	rm *.o prog
