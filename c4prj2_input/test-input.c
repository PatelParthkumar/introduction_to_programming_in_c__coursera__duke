#include <stdio.h>
#include <stdlib.h>
#include "input.h"



void print_deck(char * name, deck_t * d) {

  printf("cards in deck '%s': ", name);
  for (size_t i = 0; i < d->n_cards; ++i) {
    print_card(*d->cards[i]);
  }  // loop all cards in deck
  printf("\n");

}

void print_fc(future_cards_t * fc) {
  
  // show what is in fc
  printf("nof elms in fc: %d\n", (int)fc->n_decks);
  for (size_t i = 0; i < fc->n_decks; ++i) {
    printf("  deck %d contains %d placeholders\n", (int)i, (int)(fc->decks[i].n_cards));
    for (size_t j = 0; j < fc->decks[i].n_cards; ++j) {
      printf("    %p: ", fc->decks[i].cards[j]);
      print_card(*fc->decks[i].cards[j]);
    }
    printf("\n");
  }  // all wildcards

}

int main() {

  printf("My test program for input.c\n");

  char * filename = "test.txt";
  FILE * f = fopen(filename, "r");

  size_t n_hands = 0;
  future_cards_t * fc = malloc(sizeof(*fc));
  fc->n_decks = 0;
  fc->decks = NULL;

  printf("Reading hands in file\n");
  deck_t ** decks = read_input(f, &n_hands, fc);

  for (size_t ih = 0; ih < n_hands; ih++) {
    printf("hand %d: ", (int)ih);
    for (size_t ic = 0; ic < decks[ih]->n_cards; ic++) {
      print_card(*decks[ih]->cards[ic]);
    } // for all cards in hand
    printf("\n");
  }  // for: all hands

  //============== test the wildcards ======================
  printf("%d hands read\n", (int)n_hands);

  deck_t * d = decks[2];

  deck_t * stack = make_deck_exclude(d);

  // print stack
  print_deck("hand 2/2", d);
  print_deck("stack", stack);
	     
  // show what is in fc
  print_fc(fc);

  // ADD FUTURE CARDS
  future_cards_from_deck(stack, fc);

  print_fc(fc);

  print_deck("hand 2/2", d);
  
  return EXIT_SUCCESS;
  
}
