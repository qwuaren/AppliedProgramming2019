#include <iostream>
#include <cmath>

void guassian_elimination(double **A,
                          double *b,
                          // double *u,
                          int n);

int main()
{
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

  //Should give res {5,3,-2}
  b[0] = 7; b[1] = -17; b[2] = 29;

  guassian_elimination(A,b,3);

  for (int i=0; i<3; i++)
  {
    delete[] A[i];
  }
    delete[] A;

  return 0;
}

void guassian_elimination(double **A, double *b, int n) //double *b, double *u,
{
  int nrows = n;
  int ncols = n+1;

  //allocate space matrix to contain both A and b
  double **matrix = new double* [ncols];

  for(int i=0; i<ncols; i++)
  {
    matrix[i] = new double[nrows];
    for (int j=0; j<nrows; j++)
    {
      //Copy matrix elements
      matrix[i][j] = A[i][j];
    }
  }

  for (int i=0; i<nrows; i++)
  {
    //copy b to last column
    matrix[i][ncols] = b[i];
  }

  //Pivot elements
  // for (int k=0; k<(ncols-1); k++) //loop over A columns
  // {
  //   for (int i=k+1; i<nrows; i++) //loop over next rows, across matrix
  //   {
  //     if (abs(matrix[k][k]) < abs(matrix[i][k]))
  //     {
  //       //swap rows
  //       for (int j=0; j<ncols; j++) //loop over cols to get all elems
  //       {
  //         double holder = matrix[k][j];
  //         matrix[k][j] = matrix[i][j];
  //         matrix[i][j] = holder;
  //       }
  //     }
  //   }
  // }


  for (int i=0; i<nrows; i++)
  {
    for (int j=0; i<ncols; i++)
    {
      std::cout << matrix[j][i] << "\t";
    }
    std::cout << std::endl;
  }


  //de-allocate space for matrix element
  for (int i=0; i<ncols; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}
