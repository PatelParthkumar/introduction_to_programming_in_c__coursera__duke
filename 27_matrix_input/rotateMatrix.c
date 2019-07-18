#include <stdio.h>
#include <stdlib.h>

// declaration of rotate
void rotate(char matrix[10][10]) {
  char matrot[10][10] = {0};

  for (int i0 = 0; i0 < 10; i0++) {
    for (int i1 = 0; i1 < 10; i1++) {
      matrot[i1][9-i0] = matrix[i0][i1];
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      matrix[i][j] = matrot[i][j];
    }
  }
}

void print_matrix(char matrix[10][10]) {

  for (int irow = 0; irow < 10; irow++) {
    for (int icol = 0; icol <10 ; icol++) {
      printf("%c", matrix[irow][icol]);
    }
    printf("\n");
  }
}  // print function


// int
int main(int argc, char **argv) {
  // check number of input arguments
  if (argc != 2) {
    fprintf(stderr, "Wrong number of input arguments (%d)\n", argc);
    fprintf(stderr, "Usage: rotateMatrix <filename>\n");
    return EXIT_FAILURE;
  }
  char* filename = argv[1];

  // open file and check the status
  FILE* fin = fopen(filename, "r");
  if (fin == NULL) {
    fprintf(stderr, "File *%s* could not be opened\n", filename);
    return EXIT_FAILURE;
  }  // file not opened correctly
  
  // loop all characters
  char matin[10][10];
  int ichar = -1;
  int c;
  int os = 0;
  int irow = 0;
  int icol = 0;
  while ((c = fgetc(fin)) != EOF) {
    ichar++;
    if (c == '\n') {
      if ((ichar - os)%10 != 0) {
	fprintf(stderr, "The row was not 10 columns long (newline at %d)\n", ichar-os);
	return EXIT_FAILURE;
      }  // newline not on a 10
      os++;
    }
    else {
      irow = (ichar - os)/10;
      icol = (ichar - os)%10;
      matin[irow][icol] = c;
    }
    if (ichar > 109) {
      fprintf(stderr, "Content of file (%d) is greater than expected (109)\n", ichar);
      return EXIT_FAILURE;
    }
  } // loop content until EOF (-1)

  // check if there were 110 characters
  if (ichar != 109) {
    fprintf(stderr, "Content of file is not exactly as required. Expected 109 found (%d)\n", ichar);
    return EXIT_FAILURE;
  }
  
  // close up shop
  int stat = fclose(fin);
  if (stat != 0) {
    fprintf(stderr, "File *%s* could not be closed (status: %d)\n", filename, stat);
    return EXIT_FAILURE;
  }  // file not closed correctly

  // rotate
  rotate(matin);

  // print the matrix
  print_matrix(matin);

  return EXIT_SUCCESS;
}
