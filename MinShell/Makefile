.PHONY:all
all:test minshell

test:test.c
	gcc -o test test.c
minshell:minshell.cc
	g++ -o $@ $^
.PHONY:clean
clean:
	rm -f test minshell
