#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h" // notice the syntax changed from the <x.h> files


void assert_card_valid(card_t c) {
  // checks if the card c has valid values
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);
  // no return: void type
}  // fcn: assert card validity

const char * ranking_to_string(hand_ranking_t r) {
  switch (r) {
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
  case FULL_HOUSE:
    return "FULL_HOUSE";
  case FLUSH:
    return "FLUSH";
  case STRAIGHT:
    return "STRAIGHT";
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
  case TWO_PAIR:
    return "TWO_PAIR";
  case PAIR:
    return "PAIR";
  case NOTHING:
    return "NOTHING";
  } // switch: ranking enum
  return "NOTHING";
 
}  // fcn: ranking_to_string

char value_letter(card_t c) {
  /*
  returns the character from the value. Thus 0 -> '0', 14 -> 'A'
  */
  if (c.value <= 10) {
    return '0' + c.value%10;
  }  // if: value below 10
  else if (c.value == VALUE_JACK) {
    return 'J';
  }
  else if (c.value == VALUE_QUEEN) {
    return 'Q';
  }
  else if (c.value == VALUE_KING) {
    return 'K';
  }
  else if (c.value == VALUE_ACE) {
    return 'A';
  } // ifelse

  return '?';
}  // fcn: value_letter


char suit_letter(card_t c) {
  // return the letter from the enum
  switch (c.suit) {
  case SPADES:
    return 's';
  case HEARTS:
    return 'h';
  case DIAMONDS:
    return 'd';
  case CLUBS:
    return 'c';
  case NUM_SUITS:
    return '?';
  }  // switch: enums of suits

  return '-';
}  // fcn:suit letter

void print_card(card_t c) {
  // prints out the card according to <value><suit> in letters. E.g., As is the ace of spades
  char valchar = value_letter(c);
  char suitchar = suit_letter(c);
  printf("%c%c\n", valchar, suitchar); 
}  // fcn: print_card

card_t card_from_letters(char value_let, char suit_let) {
  // make a card struct from ltters for value and suit
  card_t temp;
  switch (value_let) {
  case '0':
    temp.value = 10;
    break;
  case '2':
    temp.value = 2;
    break;
  case '3':
    temp.value = 3;
    break;
  case '4':
    temp.value = 4;
    break;
  case '5':
    temp.value = 5;
    break;
  case '6':
    temp.value = 6;
    break;
  case '7':
    temp.value = 7;
    break;
  case '8':
    temp.value = 8;
    break;
  case '9':
    temp.value = 9;
    break;
  case 'J':
    temp.value = VALUE_JACK;
    break;
  case 'Q':
    temp.value = VALUE_QUEEN;
    break;
  case 'K':
    temp.value = VALUE_KING;
    break;
  case 'A':
    temp.value = VALUE_ACE;
    break;
  default:
    temp.value = 1;
  } // switch: value letter

  switch (suit_let) {
  case 's':
    temp.suit = SPADES;
    break;
  case 'h':
    temp.suit = HEARTS;
    break;
  case 'd':
    temp.suit = DIAMONDS;
    break;
  case 'c':
    temp.suit = CLUBS;
    break;
  default:
    temp.suit = NUM_SUITS;
  }  // switch: suit char

  // assert the validity, using previously defined function
  assert_card_valid(temp);
  
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;

  // pick a suit
  temp.value = 2 + c%13;
  temp.suit = c/13;
  return temp;
}
