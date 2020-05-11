#include <iostream>

//Matrices of given sizes
void Multiply(double **res,
              double **A,
              double **B,
              int ARows,
              int ACols,
              int BRows,
              int BCols);

//Vector and matrix of given size
void Multiply(double *res,
              double *A,
              double **B,
              int ACols,
              int BRows,
              int BCols);

//Matrix and vector of given size
void Multiply(double *res,
              double **A,
              double *B,
              int ARows,
              int ACols,
              int BCols);

//A scalar and a matrix of given size
void Multiply(double **res,
              double scalar,
              double **B,
              int BRows,
              int BCols);

//A matrix of given size and a scalar
void Multiply(double **res,
              double **B,
              double scalar,
              int BRows,
              int BCols);

int main()
{
  int n = 3;

  double** A = new double* [n];
  double** B = new double* [n];
  double** res = new double* [n];
  double* vec = new double [n];
  double* resvec = new double[n];

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

  vec[0] = 1.0, vec[1] = 2.0; vec[2] = 3.0;

  double scal = 2.00;

  Multiply(resvec,A,vec,n,n,n);

  // for (int i=0; i<n; i++)
  // {
  //   for (int j=0; j<n; j++)
  //   {
  //     std::cout << "Det [" << i << "][" << j << "] element i res er = " << res[i][j] << "\n";
  //   }
  // }

  for (int i=0; i<n; i++)
  {
    std::cout << "Det [" << i << "]'te element i resvec = " << resvec[i] << "\n";
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
  delete[] resvec;
  delete[] vec;

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

//Vector and matrix of given size
void Multiply(double *res,
              double *A,
              double **B,
              int ACols,
              int BRows,
              int BCols)
{
  assert(ACols == BRows);

  for (int i=0; i<BRows; i++)
  {
    res[i] = 0;

    for (int j=0; j<ACols; j++)
    {
      res[i] += B[i][j] * A[j];
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

//A scalar and a matrix of given size
void Multiply(double **res,
              double scalar,
              double **B,
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
