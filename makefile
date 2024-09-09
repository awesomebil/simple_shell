build: shell.c shell.h
	gcc -g -Wall shell.c -o shell.out
clean:
	rm -rf *.out *.out.dSYM
run:
	./shell.out