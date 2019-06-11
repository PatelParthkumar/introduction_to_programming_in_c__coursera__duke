#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// declare maxSeq
size_t maxSeq(int *array, size_t n);

// do_test function
int do_test(int *array, size_t n, size_t max_seq_correct) {
  int test_passed = 0;
  size_t max_seq_fnd = maxSeq(array, n);
  if (max_seq_fnd == max_seq_correct) {
    test_passed = 1;
  }  // if: sequence found is correct
  
  return test_passed;
}  // fcn: do test

int main(void) {
  // initialize some vars
  int retflag = EXIT_FAILURE;
  int all_passed = 1;

  // create a set of test vectors
  all_passed *= do_test(NULL, 0, 0);
  int testvec1[] = {0};
  all_passed *= do_test(testvec1, 1, 1);
  int testvec2[] = {0, -1, -2, -3};
  all_passed *= do_test(testvec2, 4, 1);
  int testvec3[] = {100, 200, -5, -4, -1, 20, 3, -900, -800, -700, -699, -697, 81, 4};
  all_passed *= do_test(testvec3, 14, 6);
  int testvec4[] = {10, 0, 1, 3, -5};
  all_passed *= do_test(testvec4, 5, 3);
  int testvec5[] = {0, 0, 1, 1};
  all_passed *= do_test(testvec5, 4, 2);

  // check if all_passed is true
  if (all_passed == 1) {
    retflag = EXIT_SUCCESS;
  }
  
  return retflag;
}  // fcn: main
