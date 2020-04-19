#include <iostream>
{
  //we can declare arrays simply as follows
  int array1[2];
  double array2[2][3];

  //and fill them in manually
  array1[0] = 1;
  array1[1] = 10;

  array2[0][0] = 6.4;
  array2[0][1] = -3.1;
  array2[0][2] = 55.0;
  array2[1][0] = 63.0;
  array2[1][1] = -100.9;
  array2[1][2] = 50.8;

  //we can perform operations
  array1[0]++; //increment value of this entry by 1
  array2[1][2] = array2[0][1] + array2[1][0];

  /*we can initialise as we declare them with curly
  brackets, but only as we declare them */
  double array3[3] = {5.0, 1.0, 2.0}; //3x1
  int array4[2][3] = { {1, 6, 4}, {2, 2, 2}}; // 2x3

  return 0;
}
