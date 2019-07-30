#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "cards.h"
#include "eval.h"

void print_cards_in_deck(deck_t * d) {

  printf("cards in deck:\n");
  for (int i = 0; i < d->n_cards; i++) {
    print_card(*d->cards[i]);
  }
  printf("\n%d cards in this hand found\n", (int)d->n_cards);
}


int main() {
  printf("dit is mijn test_subs function\n");

  deck_t * d = malloc(sizeof(*d));
  d->n_cards = 0;
  d->cards = NULL;
  
  card_t c = {.value = 3,
	      .suit = SPADES};

  //  free(d->cards);
  //  free(d);
  
  printf("card in deck: ");
  print_card(c);
  printf("\n");

  
  add_card_to(d, c);
  printf("nof cards in deck: %d\n", (int)d->n_cards);

  add_card_to(d, c);
  printf("nof cards in deck: %d\n", (int)d->n_cards);

  //  free_deck(d);
  //  return 0;
  
  c.value = 12;
  c.suit = 1;
  add_card_to(d, c);

  add_empty_card(d);

  printf("The cards in the initial deck are:\n");
  print_cards_in_deck(d);

  //  free_deck(d);
  //  return 0;

  //==== test make deck exclude ==
  printf("<<<< Test *make_deck_exclude*>>>>\n");
  deck_t *dfull = make_deck_exclude(d);

  printf("kept cards:\n");
  for (int i = 0; i < dfull->n_cards; i++) {
    print_card(*dfull->cards[i]);
  }
  printf("\n");
  printf("nof in full deck: %d\n", (int)dfull->n_cards);

  //free_deck(d);
  //free_deck(dfull);
  //return 0;
  
  // ============ test build remaining deck =======================
  printf("============= test build_remaining_deck =====================\n");
  deck_t ** hfull = malloc(4*sizeof(*hfull));

  free_deck(dfull);
  hfull[0] = d;

  //free_deck(hfull[0]);
  //free(hfull);
  //return 0;
  
  deck_t * d1 = malloc(sizeof(*d1));
  d1->n_cards = d->n_cards;
  d1->cards = d->cards;

  //printf("lkjasdfoiuawer %d\n\n\n\n", (int)d1->n_cards);
  
  printf("d: %p, d1: %p, delta: %d\n", (void*)d, (void*)d1, (int)(d1 - d));
  c.value = 14;
  c.suit = 3;
  add_card_to(d1, c);

  printf("card added, now %d cards in d1, while d holds %d cards\n", (int)d1->n_cards,
	 (int)d->n_cards);
  hfull[1] = d1;

  
  //free_deck(hfull[0]);
  free_deck(hfull[1]);
  //free(hfull);
  return 0;
  
  deck_t * d_rem = build_remaining_deck(hfull, 1);
  printf("Remaining deck:\n");
  print_cards_in_deck(d_rem);
  printf("\n");

  //  free_deck(d);
  //free_deck(d1);
  //free(hfull);
  //return 0;
  
  //free(hfull[0]->d);
  //free(hfull[1]);

  printf("<<< check *get_match_counts* >>>\n");
  //  unsigned * array;
  unsigned * array = get_match_counts(d_rem);
  fprintf(stdout, "The match counts are:\n");
  for (int i = 0; i < d_rem->n_cards; i++) {
    printf("|%d", (int)array[i]);
  }  // loop all elements
  printf("|\n");
  
  return EXIT_SUCCESS;
}
