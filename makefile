all: inspect.c
	gcc inspect.c
run: all
	./a.out
