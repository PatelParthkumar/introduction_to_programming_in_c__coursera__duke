#include <stdio.h>
#include <stdlib.h>
#include "future.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr) {

  // check if index already exists, then add card to existing deck
  if (index >= fc->n_decks) {
    size_t ndecks = fc->n_decks;
    for (size_t i = ndecks; i < (index + 1); i++) {
      fc->decks = realloc(fc->decks, (i+1)*sizeof(*fc->decks));

      // set empty deck
      fc->decks[fc->n_decks].n_cards = 0;
      fc->decks[fc->n_decks].cards = NULL;

      fc->n_decks++;
    }  // loop all new placeholder decks
  }  // if new decks have to be created

  // add the new card pointer to the index (newly created or not
  fc->decks[index].cards = realloc(fc->decks[index].cards,
				   (fc->decks[index].n_cards + 1)*sizeof(*fc->decks[index].cards));
  fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
  fc->decks[index].n_cards++;
}


void future_cards_from_deck(deck_t * deck, future_cards_t * fc) {

  for (size_t i = 0; i < fc->n_decks; ++i) {
    //    printf("future card %d: ", (int)i);
    // which card_t* to take
    //    card_t * c = deck->cards[i];
    //    deck_t d = fc->decks[i];
    //    print_card(*(deck->cards[i]));
    //printf("\n");
    // get pointer for this placeholder
    for (size_t j = 0; j < fc->decks[i].n_cards; ++j) {
      *(fc->decks[i].cards[j]) = *(deck->cards[i]);
    }  // loop all placeholders for this card
  }  // loop all placeholders
  
}
