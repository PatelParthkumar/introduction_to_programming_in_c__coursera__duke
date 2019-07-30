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

void add_card_to(deck_t * deck, card_t c) {
  // add memory for one more card
  size_t ncards_now = deck->n_cards;
  deck->cards = realloc(deck->cards, (ncards_now + 1)*sizeof(*deck->cards));

  // add new card
  deck->cards[ncards_now] = malloc(sizeof(*deck->cards[ncards_now]));
  *deck->cards[ncards_now] = c;
  //  deck->cards[ncards_now]->value = c.value;
  deck->n_cards++;
}

card_t * add_empty_card(deck_t * deck) {

  card_t c_empty = {.value = 0,
		    .suit = 0};

  add_card_to(deck, c_empty);

  return deck->cards[deck->n_cards - 1];
}

deck_t * make_deck_exclude(deck_t * excluded_cards) {

  deck_t * df = malloc(sizeof(*df));
  df->n_cards = 0;
  df->cards = NULL;
  for (int i = 0; i < 52; ++i) {
    card_t c = card_from_num(i);
    if (deck_contains(excluded_cards, c) == 0) {
      add_card_to(df, c);

    }  // is in excluded list
  }  // loop all 52 cards
  return df;
}


deck_t * build_remaining_deck(deck_t **hands, size_t n_hands) {

  deck_t * d_ex = malloc(sizeof(*d_ex));
  d_ex->n_cards = 0;
  d_ex->cards = NULL;
  for (size_t i = 0; i < n_hands; i++) {
    for (size_t j = 0; j < hands[i]->n_cards; j++) {
      card_t c = *hands[i]->cards[j];
      if (deck_contains(d_ex, c) == 0) {
	add_card_to(d_ex, c);
      }  // if card is not in deck already
    }  // loop all cards in the hand
  }  // loop all hands

  // make deck excluding the d_ex deck
  deck_t * d_rem = make_deck_exclude(d_ex);

  // free d_ex
  free_deck(d_ex);
  
  return d_rem;
}

void free_deck(deck_t * deck) {
  for (int i = 0; i < deck->n_cards; i++) {
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}
