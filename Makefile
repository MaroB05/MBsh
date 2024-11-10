compile:
	gcc src/main.c utils/functions.c -c 
	gcc main.o functions.o -o ./build/MBsh.out

debug:
	gcc src/main.c utils/functions.c -c -g 
	gcc main.o functions.o -o ./build/MBsh.out
	gdb ./build/MBsh.out

clean:
	rm *.o

run:
	./build/MBsh.out
