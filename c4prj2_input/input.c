#include <stdio.h>
#include <stdlib.h>
#include "input.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc) {

  // initialize variable deck_t deck
  deck_t * d = malloc(sizeof(*d));
  d->n_cards = 0;
  d->cards = NULL;

  // split the string
  int i = 0;
  char c_str[3] = "xx";
  while (str[i] != '\0') {
    // loop 2 characters which are a card
    for (int j = 0; j < 2; j++) {
      c_str[j] = str[i+j];
    }

    // check if chard is future card
    if (c_str[0] == '?') {
      printf("%s is a future card\n", c_str);
      add_empty_card(d);
      size_t index = (size_t)(c_str[1] - '0');
      add_future_card(fc, index, d->cards[d->n_cards-1]);
    }
    else {
      printf("The card is '%s'\n", c_str);
      card_t c = card_from_letters(c_str[0], c_str[1]);
      add_card_to(d, c);
    }
    i += 3;
  }
  return d;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {

  printf("Entering *read_input* function\n");

  deck_t ** decks = NULL;
  char * line = NULL;
  size_t sz = 0;
  int len = 0;
  while ((len = getline(&line, &sz, f)) >= 0) {
    line[len-1] = '\0';
    printf("hand %d: '%s'\n", (int)*n_hands, line);

    // check 5 card requirement
    if (len < 14) {
      fprintf(stderr, "The hand has fewer than 5 cards. Function exit with failure\n");
      free(line);
      exit(EXIT_FAILURE);
    }

    // increase memory for decks with one
    decks = realloc(decks, (*n_hands+1)*sizeof(*decks));
    decks[*n_hands] = hand_from_string(line, fc);

    (*n_hands)++;
  } // loop all lines
  return decks;
}
