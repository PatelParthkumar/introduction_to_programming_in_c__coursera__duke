#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * fid = fopen(fname, "r");
  if (fid == NULL) {
    fprintf(stderr, "The file (%s) could not be opened\n", fname);
    exit(EXIT_FAILURE);
  }

  char * line = NULL;
  size_t sz = 0;
  ssize_t len = 0;
  char *peq = NULL;

  //  kvpair_t * kvpair = NULL;

  kvarray_t *kvarray = malloc(sizeof(*kvarray));
  kvarray->kvpairs = malloc(sizeof(*kvarray->kvpairs));
  kvarray->num_in_array = malloc(sizeof(*kvarray->num_in_array));
  int counter = 0;
  int ieq = -1;
  int nchars_key = 0;
  int nchars_value = 0;
  
  while((len = getline(&line, &sz, fid)) != -1) {
    // peq is pointer to first equal sign
    printf("length read = %d\n", (int)len);
    
    peq = strchr(line, '=');
    ieq = peq - line;

    nchars_key = ieq;
    nchars_value = len - ieq - 2;

    // reallocate memory based on sz and ipos_eq (allow room for the \0 terminator)
    kvpair_t * kvpair = malloc(sizeof(*kvpair));
    kvpair->key = malloc((nchars_key + 1)*sizeof(*kvpair->key));
    kvpair->value = malloc((nchars_value + 1)*sizeof(*kvpair->value));

    // read key
    for (int ipos = 0; ipos < nchars_key; ++ipos) {
      kvpair->key[ipos] = line[ipos];
    }  // loop key chars
    kvpair->key[nchars_key] = '\0';

    // read value
    for (int ipos = ieq + 1; ipos < len-1; ++ipos) {
      kvpair->value[ipos - ieq - 1] = line[ipos];
    }  // loop value
    kvpair->value[nchars_value] = '\0';
    
    // add kvpair to kvarray
    *kvarray->num_in_array = counter + 1;
    kvarray->kvpairs = realloc(kvarray->kvpairs, (counter+1)*sizeof(*kvarray->kvpairs));

    // after reallocation add kvpair
    kvarray->kvpairs[counter] = kvpair;

    ++counter;
  } // loop all lines until -1

  free(line);
  fclose(fid);

  if (counter == 0) {
    free(kvarray->num_in_array);
    free(kvarray->kvpairs);
    free(kvarray);
    exit(EXIT_FAILURE);
  }
  return kvarray;
}

void freeKVs(kvarray_t * pairs) {

  for (size_t ipair = 0; ipair < *pairs->num_in_array; ++ipair) {
    free(pairs->kvpairs[ipair]->key);
    free(pairs->kvpairs[ipair]->value);
    free(pairs->kvpairs[ipair]);
  }  // loop all pairs
  free(pairs->num_in_array);
  free(pairs->kvpairs);
  free(pairs);
  
}

void printKVs(kvarray_t * pairs) {
  for (size_t ipair = 0; ipair < *pairs->num_in_array; ++ipair) {
    printf("key = '%s' value = '%s'\n", pairs->kvpairs[ipair]->key,
	                                pairs->kvpairs[ipair]->value);
  }  // loop all pairs
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  char * fnd_key = NULL;
  for (size_t ipair = 0; ipair < *pairs->num_in_array; ++ipair) {
    fnd_key = pairs->kvpairs[ipair]->key;

    if (strcmp(fnd_key, key) == 0) {
      return pairs->kvpairs[ipair]->value;
    }  // match found
  }  // loop pairs

  return NULL;
}
