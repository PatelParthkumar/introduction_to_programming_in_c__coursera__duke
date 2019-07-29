#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  counts_t * c = createCounts();

  // read line by line
  char * line = NULL;
  size_t sz = 0;
  FILE * f = fopen(filename, "r");
  while (getline(&line, &sz, f) > 0) {
    // cut of \n
    line[strlen(line)-1] = '\0';
    char * value = lookupValue(kvPairs, line);
    //    printf("key %s -> %s\n", line, value);
    addCount(c, value);
  }  // loop all lines
  fclose(f);
  free(line);
  
  return c;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if (argc < 3) {
    fprintf(stderr, "call requires a 'kv' filename and one or more 'values' filenames\n");
    return EXIT_FAILURE;
  }
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  //counts_t * c = createCounts();
  kvarray_t * kv = readKVs(argv[1]);
  
 //count from 2 to argc (call the number you count i)
  for (int i = 2; i < argc; ++i) {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    counts_t * c = countFile(argv[i], kv);
    //   (call this result c)

    //compute the output file name from argv[i] (call this outName)
    char * outName = computeOutputFileName(argv[i]);

    //open the file named by outName (call that f)
    FILE * f = fopen(outName, "w");
    //print the counts from c into the FILE f
    printCounts(c, f);
    //close f
    fclose(f);
    //free the memory for outName and c
    freeCounts(c);
    free(outName);
    c = NULL;
  }

 //free the memory for kv
  freeKVs(kv);

  return EXIT_SUCCESS;
}
