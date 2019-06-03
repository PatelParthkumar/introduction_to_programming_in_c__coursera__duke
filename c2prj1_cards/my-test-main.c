#include <stdio.h>
#include "cards.h"

int main(void) {
  // test assert
  card_t c;
  for (unsigned int ic = 0; ic < 52; ic++) {
    c = card_from_num(ic);
    print_card(c);
  }  // for: all cards

  // test 2: wrong values
  printf("Test 2 suit errors\n");
  card_t c_hsuit = {
    .suit = -1,
    .value = 5
  };
  card_t c_lsuit = {
    .suit = 6,
    .value = 5
  };
 
  print_card(c_lsuit);
  print_card(c_hsuit);

  // test wrong letters
  printf("Test wrong letters\n");
  //  card_t c_wrong = card_from_letters('c', 'x');
  //  print_card(c_wrong);
  // assert_card_valid(c_lsuit);
  // assert_card_valid(c_hsuit);

  printf("Test from letters\n");
  printf("--> 'A', 's'\n");
  card_t cfl = card_from_letters('A', 'p');
  print_card(cfl);
}
