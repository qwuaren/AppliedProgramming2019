#include <iostream>
#include <cmath>

//global i, for part 2
// int i = 5;

//For part 3.
// double CalculateMinimum(double a, double b);

//For part 4.
// void PrintPassOrFail(int score, int passMark);

//For part 5.
// void HasNoEffect(double x);

//For part 6.
// double** ALlocateMatrixMemory(int numRows, int numCols);
// void FreeMatrixMemory(int numRows, double** matrix);

//For part 7.
// void CalculateRealAndImaginary(double r,
//                                double theta,
//                                double* pReal,
//                                double* pImaginary);

#define LOG(x) std::cout << x << std::endl

int main()
{
  // /* Part 1: SCOPE OF VARIABLES IS LIMITED TO EACH BLOCK*/
  // int i;
  // i = 5;
  //
  // LOG(i);
  //
  // {
  //   int j;
  //   i = 10;
  //   j = 10;
  //   LOG(i);
  //   LOG(j);
  // }
  // // j = 5; //j is not declared in this scope - error
  // LOG(i); //i is still 10, here.

  // /*Part 2: GLOBAL AND LOCAL VARIABLES */
  // //For this, I defined a global int i value after #include
  // int j = 7;
  // std::cout << i << "\n";
  // {
  //   int i = 10, j = 11;
  //   LOG(i); //local value of i is 10
  //   LOG(::i); //global value of i is 5
  //   LOG(j); //j is 11 here - the other value of j is inaccessible here
  // }
  // LOG(j); //here, j is 7.

  // /* Part 3: CALCULATE MINIMUM FUNCTION */
  // /* Convention in this book is to declare your function
  // before the main, and then write the function itself
  // after main */
  //
  // double x = 4.0, y = -8.0;
  // double minimum_value = CalculateMinimum(x, y);
  //
  // LOG(minimum_value);

  // /* Part 4: A void function with no return, only action */
  // int score = 31, passMark = 30;
  //
  // PrintPassOrFail(score, passMark);

  // /* Part 5: FUNCTION SCOPES SIMILAR TO BLOCKS*/
  // double x = 2.0;
  // HasNoEffect(x);
  // LOG(x); //wil print 2.0;

  // /* Part 6: RETURNING POINTER VARIABLES FROM FUNCTION */
  // /* This function allocates memory dynamically, and returns
  //    the pointer to the allocated memory. It can then be used
  //    as if declared in the main function.*/
  //
  // double** A;
  //
  // A = ALlocateMatrixMemory(5, 3);
  // A[0][1] = 2.0;
  // A[4][2] = 4.0;
  // FreeMatrixMemory(5, A);

  // /* Part 7: CHANING VALUES DIRECTLY USING POINTERS */
  //
  // double r = 3.4;
  // double theta = 1.23;
  // double x,y;
  //
  // CalculateRealAndImaginary(r, theta, &x, &y); //give addresses to x and y
  //
  // LOG(x);
  // LOG(y);

  return 0;
}

// double CalculateMinimum(double a, double b) //For part 3.
// {
//   double minimum;
//   if (a < b)
//   {
//     minimum = a;
//   }
//   else
//   {
//     // a >= b
//     minimum = b;
//   }
//
//   return minimum;
// }

// void PrintPassOrFail(int score, int passMark) //For part 4.
// {
//   if (score >= passMark)
//   {
//     std::cout << "Pass - congratulations!\n";
//   }
//   else
//   {
//     //score < passMark
//     std::cout << "Fail - better luck next time\n";
//   }
// }

// void HasNoEffect(double x) //For part 5.
// {
//   x += 1.0; //this has no effect outside function.
// }

// double** ALlocateMatrixMemory(int numRows, int numCols) //For part 6.
// {
//   double** matrix;
//   matrix = new double* [numRows];
//
//   for (int i=0; i<numRows; i++)
//   {
//     matrix[i] = new double [numCols];
//   }
//
//   return matrix;
// }
//
// void FreeMatrixMemory(int numRows, double** matrix) // For part 6.
// {
//   for (int i=0; i<numRows; i++)
//   {
//     delete[] matrix[i];
//   }
//   delete[] matrix;
// }

// void CalculateRealAndImaginary(double r,
//                                double theta,
//                                double* pReal,
//                                double* pImaginary)
// {
//   *pReal = r*cos(theta);
//   *pImaginary = r*sin(theta);
// }
