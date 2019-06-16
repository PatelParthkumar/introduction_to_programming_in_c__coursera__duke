#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  // print the content of a hand
  for (int n = 0; n < hand->n_cards; n++) {
    print_card(*hand->cards[n]);
  }  // for: all cards in hand
}

int deck_contains(deck_t * d, card_t c) {
  for (int ipos=0; ipos < d->n_cards; ipos++) {
    suit_t suit_ut = d->cards[ipos]->suit;
    int val_ut = d->cards[ipos]->value;
    if (suit_ut == c.suit && val_ut == c.value) {
      return 1;
    }  // if card found
  }  // for: all cards in deck
  return 0;
}

void shuffle(deck_t * d){
  // shuffle via function `rand`
  for (int ipos=0; ipos < d->n_cards; ipos++) {
    int inewpos = rand()%d->n_cards;

    // switch cards with new position
    card_t *tmp = d->cards[ipos];
    d->cards[ipos] = d->cards[inewpos];
    d->cards[inewpos] = tmp;
  }  // loop all cards in a deck
}

void assert_full_deck(deck_t * d) {
  for (int ipos=0; ipos < d->n_cards; ipos++) {
    assert_card_valid(*d->cards[ipos]);
  }
}
