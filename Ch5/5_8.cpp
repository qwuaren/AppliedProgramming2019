//s 268
#include <cmath>
#include <cassert>
#include <iostream>

double CalcDeterminant(double **matrix, int size)
{
  /* Determinant of square matrix is given by
  sum (-1)^(i+j) * a_ij * M_ij
  Where M is the submatrix, a is an nxn matrix. */
  double determinant = 0.0;

  if (size == 1)
  {
    determinant = matrix[0][0];
  }
  else if (size == 2)
  {
    determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  }
  else
  {
    //size > 2

    for (int i0=0; i0<size; i0++) //fixing col in row 0
    {
      //Allocate space for sub matrices
      double **SubM = new double* [size-1];

      for (int i=0; i<(size-1); i++)
      {
        SubM[i] = new double[size-1];
      }

      //Loop over submatrix elements
      for (int i=0; i<(size-1); i++)
      {
        int jump = 0;

        for (int j=0; j<(size-1); j++)
        {
          if (j == i0)
          {
            //To skip every column equal to a_ij = matrix[0,i0]
            jump++;
          }

          //Fills submatrix but skips row,col in matrix
          //equal to where we take a_ij
          SubM[i][j] = matrix[i+1][j+jump];
        }
      }

      //Calc determinant of sub matrix recursively
      double SubDet = CalcDeterminant(SubM, (size-1));

      //Add sub matrix determinant to determinant
      determinant += matrix[0][i0] * pow(-1,i0) * SubDet;

      //De-allocate memory for sub matrix
      for (int i=0; i<(size-1); i++)
      {
        delete[] SubM[i];
      }
      delete[] SubM;
    }
  }
  return determinant;
}

int main()
{
  int size = 3;

  double** A = new double* [size];

  for (int i=0; i<size; i++)
  {
    A[i] = new double [size];
  }

  // Det(A) = 0
  // A[0][0] = 1.0; A[0][1] = 1.0; A[0][2] = 1.0; A[0][3] = 1.0;
  // A[1][0] = 1.0; A[1][1] = 1.0; A[1][2] = 1.0; A[1][3] = 1.0;
  // A[2][0] = 1.0; A[2][1] = 1.0; A[2][2] = 1.0; A[2][3] = 1.0;
  // A[3][0] = 1.0; A[3][1] = 1.0; A[3][2] = 1.0; A[3][3] = 1.0;

  //Det(A) = 18
  // A[0][0] = -2.0; A[0][1] = 2.0; A[0][2] = -3.0;
  // A[1][0] = -1.0; A[1][1] = 1.0; A[1][2] = 3.0;
  // A[2][0] = 2.0; A[2][1] = 0.0; A[2][2] = -1.0;

  //Det(A) = -34
  // A[0][0] = 1.0; A[0][1] = 5.0; A[0][2] = 0.0;
  // A[1][0] = 7.0; A[1][1] = 1.0; A[1][2] = 2.0;
  // A[2][0] = 0.0; A[2][1] = 0.0; A[2][2] = 1.0;

  A[0][0] = 1.0; A[0][1] = 1.0; A[0][2] = 1.0;
  A[1][0] = 0.0; A[1][1] = 2.0; A[1][2] = 5.0;
  A[2][0] = 2.0; A[2][1] = 5.0; A[2][2] = -1.0;

  std::cout << CalcDeterminant(A,size) << "\n";

  for (int i=0; i<size; i++)
  {
    delete[] A[i];
  }
  delete[] A;

  return 0;
}
