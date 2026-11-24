.PHONY all clean install unninstall

all: stack_input

clean:
	rm -rf hello *.o
main.o: main.c
	gcc -c -o main.o main.c
stack_input.o: stack_input.c
	gcc -c -o stack_input.o stack_input.c
