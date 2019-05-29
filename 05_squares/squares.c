#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2) {
  if (num1 > num2) {
    return num1;
  } else {
    return num2;
  }  // ifelse: which is bigger
}  // fcn: max


/* 
 * Determines if coord is in range between
 * offset (INCLUSIVE) and offset + size (EXCLUSIVE)
 */
int isInRange(int coord, int offset, int size) {
  // if coord is in range, return 1
  // else, return 0
  if (coord >= offset && coord < offset + size) {
    return 1;
  } else {
    return 0;
  }  // ifelse: within range
}  // fcn: isInRange
/*
 * Determines if coord is at border of offset or
 * offset + size
 */
int isAtBorder(int coord, int offset, int size) {
  // if coord is equal to offest or offset + size
  // return 1, else return 0
  if (coord == offset || coord == offset + size) {
    return 1;
  } else {
    return 0;
  }  // ifelse: is at border
}  // fcn: isAtBorder

void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w
  int w = max(size1, x_offset + size2);
  //compute the max of size1 and (y_offset + size2).  Call this h
  int  h = max(size1, y_offset + size2);
  //count from 0 to h. Call the number you count with y
  for (int y = 0; y < h; y++) {
    //count from 0 to w. Call the number you count with x
    for (int x = 0; x < w; x++) {
      //check if  EITHER
      //    ((x is between x_offset  and x_offset +size2) AND 
      //     y is equal to either y_offset OR y_offset + size2 - 1 )
      //  OR
      //    ((y is between y_offset and y_offset + size2) AND
      //     x is equal to either x_offset OR x_offset + size2 -1)
      // if so, print a *
      int tf_y_at_border = isAtBorder(y, y_offset, size2 - 1);
      int tf_x_in_range = isInRange(x, x_offset, size2);
      int tf_y_in_range = isInRange(y, y_offset, size2);
      int tf_x_at_border = isAtBorder(x, x_offset, size2 - 1);

      int and11 = tf_x_in_range && tf_y_at_border;
      int and12 = tf_y_in_range && tf_x_at_border;
      if (and11 || and12) {
	printf("*");
      }  // if: print *?
      else {
	int and21 = (x < size1) && isAtBorder(y, 0, size1-1);
	int and22 = (y < size1) && isAtBorder(x, 0, size1-1);
	if (and21 || and22) {
	  printf("#");
	}  // if: print #
	else {
	  printf(" ");
	}  // else:  print <space>
      }  // else: print *, # or space
    }  // for: x to w
    printf("\n");
  }  // for: y to h
	  
	//if not,
      // check if EITHER
      //    x is less than size1 AND (y is either 0 or size1-1)
      // OR
      //    y is less than size1 AND (x is either 0 or size1-1)
      //if so, print a #
         //else print a space
    //when you finish counting x from 0 to w, 
    //print a newline

}
