.PHONY:all
all:mysignal mykill

mykill:mykill.c
	gcc -o $@ $^
mysignal:mysignal.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f mysignal mykill
