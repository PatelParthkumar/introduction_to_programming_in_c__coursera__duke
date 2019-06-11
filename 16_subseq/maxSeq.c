#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n) {
  size_t lseq_max = 0;
  if (n > 0) {
    size_t lseq = 1;  // single element is always sequence of 1
    lseq_max++;
    for (size_t i = 0; i < n-1; i++) {
      if (array[i] < array[i+1]) {
	lseq++;
      }  // if: element larger than previous
      else {
	if (lseq > lseq_max) {
	  lseq_max = lseq;
	}  // check if new lseq is larger
	lseq = 1;  // reset lseq to 1
      }  // else: element not strictly bigger
    }  // for: all elements in the array
  }  // if: there is an array
  return lseq_max;
}  // maxSeq
