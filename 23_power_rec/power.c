#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y) {
  if (x == 0) {
    // special case 0^0=1... do they know this??
    if (y == 0) {
      return 1;
    }  // if: x=0=y => x^y = 1
    else {
      return 0;
    }  // else: y not 0
  }
  else {
    if (y == 1) {
      return x;
    }  // if: y == 1
    else {
      return x*power(x, y-1);
    }  // if y > 1
  }  // else: x >0
} // power function
