#include <iostream>

// //Matrices of given sizes
void Multiply(double **res,
              double **A,
              double **B,
              int ARows,
              int ACols,
              int BRows,
              int BCols);

int main()
{
  int n = 3;

  double** A = new double* [n];
  double** B = new double* [n];
  double** res = new double* [n];

  for (int i=0; i<n; i++)
  {
    A[i] = new double[n];
    B[i] = new double[n];
    res[i] = new double[n];
  }

  A[0][0] = 1.0; A[0][1] = 5.0; A[0][2] = 0.0;
  A[1][0] = 7.0; A[1][1] = 1.0; A[1][2] = 2.0;
  A[2][0] = 0.0; A[2][1] = 0.0; A[2][2] = 1.0;

  B[0][0] = -2.0; B[0][1] = 0.0; B[0][2] = 1.0;
  B[1][0] = 1.0; B[1][1] = 0.0; B[1][2] = 0.0;
  B[2][0] = 4.0; B[2][1] = 1.0; B[2][2] = 0.0;

  Multiply(res,A,B,n,n,n,n);

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      std::cout << "Det [" << i << "][" << j << "] element i res er = " << res[i][j] << "\n";
    }
  }

  for (int i=0; i<n; i++)
  {
    delete[] A[i];
    delete[] B[i];
    delete[] res[i];
  }
  delete[] A;
  delete[] B;
  delete[] res;

  return 0;
}

//Matrices of given sizes
void Multiply(double **res,
              double **A,
              double **B,
              int ARows,
              int ACols,
              int BRows,
              int BCols)
{
  assert(ARows == BCols);

  for (int i=0; i<ARows; i++)
  {
    for (int j=0; j<BRows; j++)
    {
      res[j][i] = 0;

      for (int k=0; k<BCols; k++)
      {
        res[j][i] += A[j][k] * B[k][i];
      }
    }
  }
}
