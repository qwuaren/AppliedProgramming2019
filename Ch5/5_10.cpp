#include <iostream>
#include <cmath>
#include <cassert>

void guassian_elimination(double **A,
                          double *b,
                          // double *u,
                          int n);

double CalcDeterminant(double **matrix,
                       int size);

int main()
{
  //test matrice
  double **A = new double* [3];
  for (int i=0; i<3; i++)
  {
    A[i] = new double[3];
  }

  //Determinant = -21
  A[0][0] = 5.0; A[0][1] = -6.0; A[0][2] = -7.0;
  A[1][0] = 3.0; A[1][1] = -2.0; A[1][2] = 5.0;
  A[2][0] = 2.0; A[2][1] = 4.0; A[2][2] = -3.0;

  double *b = new double[3];

  //Should give res {2,4,-3}
  b[0] = 7; b[1] = -17; b[2] = 29;

  guassian_elimination(A,b,3); //result is printed in function while debugging

  for (int i=0; i<3; i++)
  {
    delete[] A[i];
  }
  delete[] A;

  return 0;
}

void guassian_elimination(double **A, double *b, int n) //double *b, double *u,
{
  /* Function for Gaussian elimination with pivoting,
     solving an nxn linear system. */

  //Make sure, matrix isn't singular
  // assert(CalcDeterminant(A,n) != 0);

  //MAKE A COPY TO MANIPULATE MATRIX IN, nxn+1
  double **A_copy = new double* [n+1];

  for (int i=0; i<(n+1); i++)
  {
    A_copy[i] = new double[n];
    for (int j=0; j<n; j++)
    {
      //copy contents of A
      A_copy[i][j] = A[i][j];
    }
  }

  double *b_copy = new double[3];

  for (int i=0; i<n; i++)
  {
    b_copy[i] = b[i];
  }

  //Pivoting after largest absolute value of entries to
  //reduce numerical errors - both matrix and vector
  for (int k=0; k<n; k++) //loop over cols
  {
    for (int i=k+1; i<n; i++) //loop over next rows, across matrix
    {
      if (abs(A[k][k]) < abs(A[i][k]))
      {
        //swap rows
        for (int j=0; j<n; j++) //loop over cols to get all elems
        {
          //swap element col-wise
          double matrix_holder = A_copy[k][j];
          A_copy[k][j] = A_copy[i][j];
          A_copy[i][j] = matrix_holder;

          double vec_holder = b_copy[k];
          b_copy[k] = b_copy[i];
          b_copy[i] = vec_holder;

        }
      }
    }
  }

  //Copy swapped b to A_copy last col
  for (int i=0; i<n; i++)
  {
    A_copy[i][n] = b_copy[i];
  }

  //Print check
  for (int j=0; j<n; j++)
  {
    for (int i=0; i<(n+1); i++)
    {
      std::cout << A_copy[j][i] << "\t";
    }
    std::cout << b_copy[j] << "\n";
  }

  std::cout << "\n\n";

  //Reduce
  // for (int k=0; k<n; k++) //Over rows, and to fix cols
  // {
  //   double divisor = A_copy[k][k];
  //
  //   for (int i=0; i<n; i++) //Over rows
  //   {
  //     double multiplier = A_copy[i][k] / divisor;
  //
  //     for (int j=0; j<(n+1); j++) //Over cols
  //     {
  //       if (j == k)
  //       {
  //         A_copy[i][j] /= divisor;
  //       }
  //       else
  //       {
  //         A_copy[i][j] -= A_copy[k][j] * multiplier;
  //       }
  //       // b_copy[i] -= b_copy[k] * multiplier;
  //     }
  //   }
  // }

  const int nrows = n; // number of rows
  const int ncols = n+1; // number of columns

  // int lead = 0;

  // while (lead < nrows) {
  for (int lead=0; lead<nrows; lead++)
  {
      float d, m;

      for (int r = 0; r < nrows; r++) { // for each row ...
          /* calculate divisor and multiplier */
          d = A_copy[lead][lead];
          m = A_copy[r][lead] / A_copy[lead][lead];

          for (int c = 0; c < ncols; c++) { // for each column ...
              if (r == lead)
                  A_copy[r][c] /= d;               // make pivot = 1
              else
                  A_copy[r][c] -= A_copy[lead][c] * m;  // make other = 0
          }
      }
  }


    // for (int i=0; i<n; i++)
    // {
    //   std::cout << A_copy[i][n] << "\n";
    // }


  for (int j=0; j<n; j++)
  {
    for (int i=0; i<n+1; i++)
    {
      std::cout << A_copy[j][i] << "\t";
    }
    std::cout << "\n";
  }

  for (int i=0; i<n+1; i++)
  {
    delete[] A_copy[i];
  }
  delete[] A_copy;
  delete[] b_copy;
}

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
