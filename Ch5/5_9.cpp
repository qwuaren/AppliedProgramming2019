#include <iostream>
#include <cmath>

// Solve Au = b, for non singular A
void solve3by3(double** A,
          double* b,
          double* u);

//Calculate determinant of matrix of given size
double CalcDeterminant(double **matrix,
                       int size);


//Matrix and vector of given size
void Multiply(double *res,
             double **A,
             double *B,
             int ARows,
             int ACols,
             int BCols);


int main()
{
  double **A = new double* [3];
  for (int i=0; i<3; i++)
  {
    A[i] = new double[3];
  }

  //Determinant = -21
  A[0][0] = 1.0; A[0][1] = 1.0; A[0][2] = 1.0;
  A[1][0] = 0.0; A[1][1] = 2.0; A[1][2] = 5.0;
  A[2][0] = 2.0; A[2][1] = 5.0; A[2][2] = -1.0;


  double *b = new double[3];

  //Should give res {5,3,-2}
  b[0] = 6; b[1] = -4; b[2] = 27;

  double *res = new double[3];

  solve3by3(A, b, res);

  // Test results
  for (int i=0; i<3; i++)
  {
    std::cout << res[i] << "\n";
  }

  for (int i=0; i<3; i++)
  {
    delete[] A[i];
  }
  delete[] A;
  delete[] b;
  delete[] res;

  return 0;
}

void solve3by3(double** A, double* b, double* u)
{
  /* Solve system by finding inverse, as
     Au=b has the solution u = A^(-1) b.
     I made this solution by combining w/
     5.6 (multiply vector and matrices)
     and 5.8 (find determinant of matrix). */
  
  double determinant = CalcDeterminant(A,3);

  assert(determinant != 0);

  //Allocate space for matrix of cofactors
  double **CoFacMatrix = new double* [3];
  for (int i=0; i<3; i++)
  {
    CoFacMatrix[i] = new double[3];
  }

  for (int i=0; i<3; i++)
  {
    //Allocate space for sub matrices
    double **SubM = new double* [3-1];

    for (int i=0; i<(3-1); i++)
    {
      SubM[i] = new double[3-1];
    }

    for (int j=0; j<3; j++)
    {
      int i_jump=0;

      for (int sub_i=0; sub_i<(3-1); sub_i++)
      {
        int j_jump=0;

        if (sub_i == i)
        {
          i_jump++;
        }

        for (int sub_j=0; sub_j<(3-1); sub_j++)
        {
            if (sub_j == j)
            {
              j_jump++;
            }

          SubM[sub_i][sub_j] = A[sub_i+i_jump][sub_j+j_jump];
        }
      }

      double SubDeterminant = CalcDeterminant(SubM, (3-1));

      CoFacMatrix[j][i] = SubDeterminant * pow(-1,(i+j));

      // std::cout << j << " " << i << " " << CoFacMatrix[j][i] << "\n";
    }

    //De-allocate memory for sub matrix
    for (int i=0; i<(3-1); i++)
    {
      delete[] SubM[i];
    }
    delete[] SubM;
  }

  //Multiply cofactor matrix by 1/determinant
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      CoFacMatrix[i][j] *= 1/determinant;
    }
  }

  //Write results to u, using multiply function from 5.6
  Multiply(u,CoFacMatrix,b,3,3,3);

  //De-allocate space for matrix of cofactors
  for (int i=0; i<3; i++)
  {
    delete[] CoFacMatrix[i];
  }
  delete[] CoFacMatrix;
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

//Matrix and vector of given size
void Multiply(double *res,
              double **A,
              double *B,
              int ARows,
              int ACols,
              int BCols)
{
  assert(ARows == BCols);

  for (int i=0; i<BCols; i++)
  {
    res[i] = 0;

    for (int j=0; j<ARows; j++)
    {
      res[i] += A[i][j] * B[j];
    }
  }
}
