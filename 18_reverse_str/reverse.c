#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaration and initialization in one
void reverse(char *str) {
  // count the number of chars in the string
  if (str != NULL) {
  int nof_chars = 0;
  while (str[nof_chars] != '\0') {
    nof_chars++;  // final loop will set to actual count since it starts at zero
  }  // while not encountered \0 char

  // copy str to oldstr
  char revstr[nof_chars+1];  // +1 to allow for the \0
  revstr[nof_chars] = '\0';
  
  // loop from back to front
  int irev = 0;
  for (int ibw = nof_chars-1; ibw >= 0; ibw--) {
    irev = nof_chars - ibw - 1;
    revstr[irev] = str[ibw];
  }  // for: all character indices from back to and including 0
  strncpy(str, revstr, nof_chars);
  }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
