#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{
  for (long int i=0; i<1e9; i++)
  {
    double* A[2];
    double* B[2];
    double* C[2];

    for (int i=0; i<2; i++)
    {
      A[i] = new double[2];
      B[i] = new double[2];
      C[i] = new double[2];
    }

    for (int i=0; i<2; i++)
    {
      for (int j=0; j<2; j++)
      {
        A[i][j] = i+j;
        B[i][j] = i+j+3;
        C[i][j] = A[i][j]+B[i][j];

        // LOG(C[i][j]); //DO NOT PRINT IN 1e6 TEST!
      }
    }

    for (int i=0; i<2; i++)
    {
      delete[] A[i];
      delete[] B[i];
      delete[] C[i];
    }
  }

  std::cout << "I'm done\n";

  return 0;
}
