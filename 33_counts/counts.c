#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

counts_t * createCounts(void) {
  // malloc space for aanswer of type counts_t
  counts_t * answer = malloc(sizeof(*answer));
  answer->nof_elms = 0;
  answer->carr = NULL;
  //  answer->carr = malloc(sizeof(*answer->carr));
  //  answer->carr[0]->count = 0;
  //  answer->carr[0]->name = malloc(strlen("<unknown>")*sizeof(char));
  //  strcpy(answer->carr[0]->name, "<unknown>");
  
  return answer;
}

void addCount(counts_t * c, const char * name) {
  //WRITE ME
  // corner case: name = NULL
  //  fprintf(stdout, "length of name: %d\n", (int)strlen(name));
  //  fprintf(stdout, "name: '%s'", name);
  char * name_w_null = NULL;
  if (name == NULL) {
    name_w_null = malloc(10*sizeof(char));  // fuck: ALWAYS INCLUDE THE /0
    strcpy(name_w_null, "<unknown>");
  }
  else {
    name_w_null = malloc((strlen(name)+1)*sizeof(char));  // ALWAYS INCLUDE THE NULL TERMI.
    strcpy(name_w_null, name);
  }
  //  fprintf(stdout, " --> %s", name_w_null);
  
  // loop all names in array and increment if name is the same
  for (int i = 0; i < c->nof_elms; ++i) {
    //    fprintf(stdout, "\n   name in array: %s\n", c->carr[i]->name);
    if (strcmp(name_w_null, c->carr[i]->name) == 0) {
      //      fprintf(stdout, "match found for name %s\n", name_w_null);
      c->carr[i]->count++;
      free(name_w_null);
      return;
    }  // strings match
  } // loop all in array

  //  fprintf(stdout, "\n --> not in array yet\n");

  // if loop finishes without updating, another key should be added
  one_count_t * cnew = malloc(sizeof(*cnew));
  cnew->name = malloc((strlen(name_w_null)+1)*sizeof(char));
  strcpy(cnew->name, name_w_null);
  free(name_w_null);
  cnew->count = 1;

  // add to carr and increment nof elms
  c->carr = realloc(c->carr, (c->nof_elms +1)*sizeof(*c->carr));
  c->carr[c->nof_elms] = cnew;
  c->nof_elms++;
}

void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  int is_unk_present = -1;
  for (int i = 0; i < c->nof_elms; ++i) {
    if (strcmp(c->carr[i]->name, "<unknown>") != 0) {
      fprintf(outFile, "%s: %d\n", c->carr[i]->name, c->carr[i]->count);
    }
    else {
      is_unk_present = i;
    }
  }  // loop all keys

  // add unknowns if present
  if (is_unk_present >= 0) {
    fprintf(outFile, "<unknown> : %d\n", c->carr[is_unk_present]->count);
  }
  //  fclose(outFile);
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for (int i = 0; i < c->nof_elms; ++i) {
    free(c->carr[i]->name);
    free(c->carr[i]);
  }  // all indices
  free(c->carr);
  free(c);
}
