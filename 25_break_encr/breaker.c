#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: breaker <filename>\n");
    return EXIT_FAILURE;
  }  // nof inputs wrong

  char* filename = argv[1];

  //printf("filename = %s\n", filename);
  
  // open file
  FILE * fid = fopen(filename, "r");
  int c_enc;
  int d_enc;
  int ichar = 0;
  int occs[26] = {0};
  int nof_chars = 0;

  // loop the entire text
  while ((c_enc = fgetc(fid)) != EOF) {
    // printf("%c", c_enc);

    // check if it is an alphabetical character
    if (isalpha(c_enc)) {
      d_enc = tolower(c_enc);
      ichar = d_enc - 'a';
      occs[ichar]++;
      nof_chars++;
    } // is alpha numerical character
  }  // loop all encoced characters

  // close the file and print status
  fclose(fid);
  //printf("file close status: %d\n", statclosed);

  // print countying results and
  int imax = -1;
  int maxcount = - 1;
  //printf("character occurrences:\n");
  //printf("total characters found: %d\n", nof_chars);
  for (int ichar = 0; ichar < 26; ichar++) {
    //float perc_this_char = 100*((float) occs[ichar])/nof_chars;
    //printf("%c = %d (%0.1f%%)\n", 'a'+ichar, occs[ichar], perc_this_char);
    if (occs[ichar] > maxcount) {
      imax = ichar;
      maxcount = occs[ichar];
    }  // if new maximum character found
  }  // loop all characters

  // assuming max found = 'e' ('a' + 4)
  
  printf("%d\n", (26 + imax - 4)%26);

  return EXIT_SUCCESS;
}  // main
