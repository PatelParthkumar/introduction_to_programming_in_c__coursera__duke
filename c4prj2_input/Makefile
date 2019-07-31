CLFAGS = -Wall -Werror -pedantic -std=gnu99
test-input: test-input.o input.o deck.o cards.o eval.o future.o
	gcc -o test-input test-input.o input.o cards.o eval.o future.o deck.o
%.o: %.c
	gcc $(CFLAGS) -c $<
.PHONY: clean
clean:
	rm -f *.o *.c~ *.h~ test-input
