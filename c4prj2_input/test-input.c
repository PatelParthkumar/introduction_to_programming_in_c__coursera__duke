#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int main() {

  printf("My test program for input.c\n");

  char * filename = "test.txt";
  FILE * f = fopen(filename, "r");

  size_t n_hands = 0;
  future_cards_t * fc = malloc(sizeof(*fc));
  fc->n_decks = 0;
  fc->decks = NULL;
  
  deck_t ** decks = read_input(f, &n_hands, fc);

  for (size_t ih = 0; ih < n_hands; ih++) {
    printf("hand %d:\n", (int)ih);
    for (size_t ic = 0; ic < decks[ih]->n_cards; ic++) {
      print_card(*decks[ih]->cards[ic]);
    } // for all cards in hand
    printf("\n");
  }  // for: all hands
  
  
}
