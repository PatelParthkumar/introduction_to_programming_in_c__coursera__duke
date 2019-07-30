CLFAGS = -Wall -Werror -pedantic -std=gnu99 -Wmissing-prototypes
test-input: test-input.o input.o deck.o cards.o eval.o
	gcc -o test-input test-input.o input.o deck.o cards.o eval.o
test-future: test-future.o future.o deck.o cards.o eval.o
	gcc -o test-future test-future.o future.o deck.o cards.o eval.o
test-input.o: test-input.c
	gcc $(CFLAGS) -c test-input.c
test-future.o: test-future.c future.h deck.h
	gcc $(CFLAGS) -c test-future.c
future.o: future.c future.h deck.h
	gcc $(CFLAGS) -c future.c
deck.o: deck.c deck.h cards.h eval.h
	gcc $(CFLAGS) -c deck.c
cards.o: cards.c cards.h
	gcc $(CFLAGS) -c cards.c
eval.o: eval.c eval.h
	gcc $(CFLAGS) -c eval.c

clean:
	rm *.o test-future 
