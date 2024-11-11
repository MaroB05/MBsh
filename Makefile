compile:
	gcc src/main.c -c #utils/*.h -c 
	gcc *.o -o ./build/MBsh.out

debug:
	gcc src/main.c utils/*.c -c 
	gcc *.o -o ./build/MBsh.out
	gdb ./build/MBsh.out

clean:
	rm *.o

run:
	./build/MBsh.out
