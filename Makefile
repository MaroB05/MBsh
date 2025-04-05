compile:
	mkdir -p build
	gcc src/main.c -o build/MBsh.out

debug:
	gcc src/main.c -g -o ./build/MBsh.out
	gdb ./build/MBsh.out

memdebug:
	gcc src/main.c -g -o ./build/MBsh.out
	valgrind --leak-check=full --show-leak-kinds=all ./build/MBsh.out

clean:
	rm *.o

run:
	./build/MBsh.out
