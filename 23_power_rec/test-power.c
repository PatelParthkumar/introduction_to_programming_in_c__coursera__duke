#include <stdio.h>
#include <stdlib.h>

// prototype `power`
unsigned power(unsigned x, unsigned y);

void do_test(unsigned x, unsigned y, unsigned expected_ans) {
  unsigned ans = power(x, y);
  if (ans != expected_ans) {
    printf("Test with x**y = %d**%d = %d, gave failed answer of %d", x, y, expected_ans, ans);
    exit(EXIT_FAILURE);
  }  // if: check against expected answer
}  // do_test function (recursively called)

// main function
int main(void) {
  // TEST CASES FOR unsigned power(unsigned x, unsigned y)
  //  unsigned x=1, y=1, exans=1;
  do_test(0, 1, 0);
  do_test(0, 0, 1);
  do_test(1, 1, 1);
  do_test(-1, 1, -1);
  do_test(10, 1, 10);
  do_test(2, 2, 4);
  do_test(2.0, 3.0, 8.0);
  printf("all tests are passed!\n");
  return EXIT_SUCCESS;
}  // mainOA
