#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

void proc_valid_card_token(char * token, deck_t * d) {
  // process valid card in format 'vs' (2 characters in string, 3 in token (NULL terminator)
  card_t c = card_from_letters(token[0], token[1]);
  add_card_to(d, c);
}

void proc_wildcard_token(char * token, deck_t * d, future_cards_t * fc) {
  // process anything with format '?xxx', the number of x's is undefined
  int index = atoi(&token[1]);
  add_empty_card(d);
  add_future_card(fc, (size_t)index, d->cards[d->n_cards-1]);
}

void proc_token(char * token, deck_t * d, future_cards_t *  fc) {
  if (token[0] == '?') {
    proc_wildcard_token(token, d, fc);
  }
  else {
    proc_valid_card_token(token, d);
  }
}


deck_t * hand_from_string(const char * str, future_cards_t * fc) {
  // init deck pointer
  deck_t * d = malloc(sizeof(*d));
  d->n_cards = 0;
  d->cards = NULL;

  // need copy, since str is const
  char * str_ = malloc((strlen(str) + 1)*sizeof(*str_));
  strcpy(str_, str);

  // pick first token and create static pointer (inside strtok)
  char * token = strtok(str_, " ");

  // check for other tokens, there should be at least one more
  while (token != NULL) {
    proc_token(token, d, fc);
    token = strtok(NULL, " ");
  }  // loop until token is NULL pointer

  free(str_);
  
  return d;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {

  deck_t ** decks = NULL;
  char * line = NULL;
  size_t sz = 0;
  int len = 0;
  while ((len = getline(&line, &sz, f)) >= 0) {
    line[len-1] = '\0';

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

  free(line);
  
  return decks;
}
