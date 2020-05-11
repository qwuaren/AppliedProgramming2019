#include "5_6.h"
#include <cassert>

/* I CANNOT MAKE THIS WORK WITH THE CODE CHECKER,
BUT I SEEM TO GET A FINE RESULT WITH THE MAIN FUNCTION BELOW */

// #include <iostream>
// int main()
// {
//   int n = 3; //testing with 3x3 matrices
//
//   double** A = new double* [n];
//   double** B = new double* [n];
//   double** resm = new double* [n];
//   double* v = new double [n];
//   double* resv = new double[n];
//
//   for (int i=0; i<n; i++)
//   {
//     A[i] = new double[n];
//     B[i] = new double[n];
//     resm[i] = new double[n];
//   }
//
//   //MATRIX A
//   A[0][0] = 1.0; A[0][1] = 5.0; A[0][2] = 0.0;
//   A[1][0] = 7.0; A[1][1] = 1.0; A[1][2] = 2.0;
//   A[2][0] = 0.0; A[2][1] = 0.0; A[2][2] = 1.0;
//
//   std::cout << "Matrix A:\n";
//
//   for (int i=0; i<n; i++)
//   {
//     for (int j=0; j<n; j++)
//     {
//       std::cout << A[i][j] << "\t";
//     }
//     std::cout << std::endl;
//   }
//   std::cout << std::endl;
//
//   //MATRIX B
//   B[0][0] = -2.0; B[0][1] = 0.0; B[0][2] = 1.0;
//   B[1][0] = 1.0; B[1][1] = 0.0; B[1][2] = 0.0;
//   B[2][0] = 4.0; B[2][1] = 1.0; B[2][2] = 0.0;
//
//   std::cout << "Matrix B:\n";
//
//   for (int i=0; i<n; i++)
//   {
//     for (int j=0; j<n; j++)
//     {
//       std::cout << A[i][j] << "\t";
//     }
//     std::cout << std::endl;
//   }
//   std::cout << std::endl;
//
//   // VECTOR v
//   v[0] = 1.0, v[1] = 2.0; v[2] = 3.0;
//
//   std::cout << "Vector v:\n";
//
//   for (int j=0; j<n; j++)
//   {
//     std::cout << v[j] << std::endl;
//   }
//   std::cout << std::endl;
//
//   //A*B
//   /*should give
//   3   0  1
//   -5  2  7
//   4   1  0
//   */
//   Multiply(resm,A,B,n,n,n,n);
//
//   std::cout << "A*B" << std::endl;
//
//   for (int i=0; i<n; i++)
//   {
//     for (int j=0; j<n; j++)
//     {
//       std::cout << resm[i][j] << "\t";
//     }
//     std::cout << std::endl;
//   }
//   std::cout << std::endl;
//
//   //v*A
//   /* should give
//   11
//   15
//   3
//   */
//   Multiply(resv,v,A,n,n,n);
//
//   std::cout << "v*A\n";
//
//   for (int j=0; j<n; j++)
//   {
//     std::cout << resv[j] << std::endl;
//   }
//   std::cout << std::endl;
//
//   //A*v
//   /* should give
//   11
//   15
//   3
//   */
//   Multiply(resv,A,v,n,n,n);
//
//   std::cout << "A*v\n";
//
//   for (int j=0; j<n; j++)
//   {
//     std::cout << resv[j] << std::endl;
//   }
//   std::cout << std::endl;
//
//   // scalar * matrix
//   /* should give
//   2   10  0
//   14  2   4
//   0   0   2
//   */
//   double scal = 2.00;
//
//   Multiply(resm,scal,A,n,n);
//
//   std::cout << "scalar * A" << std::endl;
//
//   for (int i=0; i<n; i++)
//   {
//     for (int j=0; j<n; j++)
//     {
//       std::cout << resm[i][j] << "\t";
//     }
//     std::cout << std::endl;
//   }
//   std::cout << std::endl;
//
//   //matrix * scalar
//   Multiply(resm,A,scal,n,n);
//
//   std::cout << "scalar * A" << std::endl;
//
//   for (int i=0; i<n; i++)
//   {
//     for (int j=0; j<n; j++)
//     {
//       std::cout << resm[i][j] << "\t";
//     }
//     std::cout << std::endl;
//   }
//   std::cout << std::endl;
//
//   for (int i=0; i<n; i++)
//   {
//     delete[] A[i];
//     delete[] B[i];
//     delete[] resm[i];
//   }
//   delete[] A;
//   delete[] B;
//   delete[] resm;
//   delete[] resv;
//   delete[] v;
//
//   return 0;
// }

//Matrices of given sizes
void Multiply(double **res,
              double **A,
              double **B,
              int ARows,
              int ACols,
              int BRows,
              int BCols)
{
  // assert(ARows == BCols);

  for (int i=0; i<ARows; i++)
  {
    for (int j=0; j<BRows; j++)
    {
      res[i][j] = 0;

      for (int k=0; k<ACols; k++)
      {
        res[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

//Vector and matrix of given size
void Multiply(double *res,
              double *A,
              double **B,
              int ACols,
              int BRows,
              int BCols)
{
  for (int i=0; i<BCols; i++)
  {
    res[i] = 0;

    for (int j=0; j<BRows; j++)
    {
      res[i] += B[j][i] * A[j];
    }
  }
}

//Matrix and vector of given size
void Multiply(double *res,
              double **A,
              double *B,
              int ARows,
              int ACols,
              int BCols)
{
  for (int i=0; i<ARows; i++)
  {
    res[i] = 0;

    for (int j=0; j<ACols; j++)
    {
      res[i] += A[i][j] * B[j];
    }
  }
}

//A scalar and a matrix of given size
void Multiply(double **res,
              double scalar,
              double **B,
              int BRows,
              int BCols)
{
  for (int i=0; i<BRows; i++)
  {
    for (int j=0; j<BCols; j++)
    {
      res[i][j] = B[i][j] * scalar;
    }
  }
}

//A matrix of given size and a scalar
void Multiply(double **res,
              double **B,
              double scalar,
              int BRows,
              int BCols)
{
  //res = B*scalar -- same as scalar*B

  for (int i=0; i<BRows; i++)
  {
    for (int j=0; j<BCols; j++)
    {
      res[i][j] = B[i][j] * scalar;
    }
  }
}
