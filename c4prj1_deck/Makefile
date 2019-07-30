CFLAGS=-Wall -Werror -std=gnu99 -pedantic -ggdb3
test: test.o deck.o cards.o eval.o
	gcc -o test test.o deck.o cards.o eval.o
test.o: test.c eval.c eval.h
	gcc $(CFLAGS) -c test.c
deck.o: deck.c deck.h
	gcc $(CFLAGS) -c deck.c
cards.o: cards.c cards.h
	gcc $(CFLAGS) -c cards.c
eval.o: eval.c eval.h
	gcc $(CFLAGS) -c eval.c
clean:
	rm -f *.o test
