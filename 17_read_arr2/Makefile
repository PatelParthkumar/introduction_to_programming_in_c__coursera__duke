CFLAGS=-std=gnu99 -pedantic -Wall -Werror
test: test.o
	gcc -o test test.o
%.o: %.c
	gcc $(CLFAGS) -c $<
.PHONY: clean
clean:
	rm -f test *.o *.c~
