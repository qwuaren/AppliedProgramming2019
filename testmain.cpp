#include <iostream>
#include "CalculateExponential.hpp"

int main()
{
  ComplexNumber **A[3];
  for (int i=0; i<3; i++)
  {
    A[i] = new *ComplexNumber[3];
    for (int j=0; j<3; j++)
    {
      A[i][j] = ComplexNumber((double)(i),(double)(j));
    }
  }

  ComplexNumber **res[3];
  for (int i=0; i<3; i++)
  {
    res[i] = new *ComplexNumber[3];
  }

  CalculateExponential(A,3,res);
}
