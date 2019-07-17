#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10]) {

  char matrot[10][10] = {0};

  for (int i0 = 0; i0 < 10; i0++) {
    for (int i1 = 0; i1 < 10; i1++) {
      matrot[i1][9-i0] = matrix[i0][i1];
    }  // for: dimension 1
  }  // for: dimension 0

  // change pointer to new data matrot
  //  matrix = matrot;  // does not work because the address is vacated again
  for (int i=0; i < 10; i++) {
    for (int j=0; j < 10; j++) {
      matrix[i][j] = matrot[i][j];
    }
  }
}  // main
