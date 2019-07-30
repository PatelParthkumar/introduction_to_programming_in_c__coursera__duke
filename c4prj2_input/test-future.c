#include <stdio.h>
#include <stdlib.h>
#include "future.h"
#include "deck.h"
#include "cards.h"

int main() {
  fprintf(stdout, "This is my test script for future.c functions\n");

  future_cards_t * fc = malloc(sizeof(*fc));
  fc->n_decks = 0;
  fc->decks = NULL;

  size_t index = 0;

  card_t * ptr = malloc(sizeof(*ptr));
  ptr->value = 14;
  ptr->suit = 2;

  
  add_future_card(fc, index, ptr);

  add_future_card(fc, 10, ptr);
  
  printf("nof cards in placeholders: %d\n", (int)fc->n_decks);

  for (size_t i = 0; i < fc->n_decks; ++i) {
    printf("  unknown card %d has %d placeholders\n", (int)i, (int)fc->decks[i].n_cards);
    if (fc->decks[i].n_cards > 0) {
      //for (size_t j = 0; j < fc->decks[i].n_cards; j++) {
      //free(fc->decks[i].cards[j]);
      //}
      //    free(fc->decks[i].cards);
    }
  }

  //  free(fc->decks);
  //  free(fc);
  //  free(ptr);

  //  return 0;
  //============= TEST FUTURE CARDS FROM DECK ===========================
  printf("=========== TEST FUTURE CARDS FROM DECK ================\n");
  // init deck
  deck_t * deck = malloc(sizeof(*deck));
  deck->n_cards = 0;
  deck->cards = NULL;
  card_t c = {.value = 2, .suit = 11};

  add_card_to(deck, c);
  printf("new card %d, %d\n", (int)deck->cards[0]->value, (int)deck->cards[0]->suit);

  //c.value = 1;
  //c.suit = 1;
  //add_card_to(deck, c);

  deck_t ** hands = malloc(sizeof(*hands));
  hands[0] = deck;

   deck_t * drem = build_remaining_deck(hands, 1);

   printf("The following cards are remaining:\n");
  for (size_t i = 0; i < drem->n_cards; i++) {
    print_card(*drem->cards[i]);
  }
  printf("\n");
  
  future_cards_from_deck(drem, fc);

  printf("nof placeholder decks: %d\n", (int)fc->n_decks);
  
  free_deck(deck);
  free_deck(drem);
  free(hands);
  
  return 0;
}
