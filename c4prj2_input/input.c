#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

void proc_valid_card(char * token, deck_t * d) {
  card_t c = card_from_letters(token[0], token[1]);
  add_card_to(d, c);
}

void proc_wildcard(char * token, deck_t * d, future_cards_t * fc) {
  int index = atoi(&token[1]);
  add_empty_card(d);
  add_future_card(fc, (size_t)index, d->cards[d->n_cards-1]);
}

void proc_token(char * token, deck_t * d, future_cards_t *  fc) {
  if (token[0] == '?') {
    proc_wildcard(token, d, fc);
  }
  else {
    proc_valid_card(token, d);
  }
}


deck_t * hand_from_string(const char * str, future_cards_t * fc) {
  deck_t * d = malloc(sizeof(*d));
  d->n_cards = 0;
  d->cards = NULL;

  char * str_ = malloc((strlen(str) + 1)*sizeof(*str_));
  strcpy(str_, str);
  //printf("original string: %s\n", str);
  //printf("copied string: %s\n", str_);

  // loop the string and until a point
  const char delim[2] = " ";
  size_t icard = 0;
  size_t index = 0;
  char * token = strtok(str_, " ");

  //  printf("  token: %s\n", token);

   while (token != NULL) {
    // check token
    proc_token(token, d, fc);
    token = strtok(NULL, " ");
    //    printf("  token: %s\n", token);
  }  // loop until token is NULL pointer

  return d;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {

  deck_t ** decks = NULL;
  char * line = NULL;
  size_t sz = 0;
  int len = 0;
  while ((len = getline(&line, &sz, f)) >= 0) {
    line[len-1] = '\0';
    //    printf("hand %d: '%s'\n", (int)*n_hands, line);

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
