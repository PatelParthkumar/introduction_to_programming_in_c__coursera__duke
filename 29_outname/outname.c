#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  // malloc outputfilename buffer (add 1 for \0 (NULL terminator))
  char * outputName = malloc((strlen(inputName) + 7 + 1)*sizeof(inputName[0]));

  // copy filename to new buffer (note: 5 spaces left
  strcpy(outputName, inputName);
  strcat(outputName, ".counts");
  return outputName;
}
