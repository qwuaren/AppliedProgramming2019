#include <cmath>
#include "CalculateExponential.hpp"
#include "ComplexNumber.hpp"

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res);
void printMatrix(ComplexNumber **A, int rows, int cols);

//6_1_7
/* Write matrix to calculate exponential of 3x3 matrix of
complex numbers. */
void CalculateExponential(ComplexNumber **A,
                                         int nMax,
                                         ComplexNumber **res)
{
  /*FUNCTION THAT CALCULATES THE MATRIX EXPONENTIAL OF A COMPLEX
  3X3 MATRIX. IN GENERAL, THE MATRIX EXPONENTAIL OF A MATRIX A
  IS GIVEN BY:

        exp(A) = SUM [N=0, Nmax] {A^n/n!}

               = I + A + AA/2! + AAA/3! + ...

  */
  //Make a matrix of complex numbers where we can change values accordingly
  ComplexNumber **A_copy;
  //God knows why I can't define this on the line above
  A_copy = new ComplexNumber *[3];
  for (int i=0; i<3; i++)
  {
    A_copy[i] = new ComplexNumber[3];
  }

  //Copy A to A_copy
  for (int i=0; i<3; i++)
  {
    //And God said there should be columns
    // A_copy[i] = new *ComplexNumber[3];
    for (int j=0; j<3; j++)
    {
      A_copy[i][j] = A[i][j];
    }
  }

  //Initialise factorial that will be a complex number
  ComplexNumber fact_me_up_scotty(1.0);

  //First iteration is the identity matrix
  for (int i=0; i<3; i++)
  {
    res[i][i] = fact_me_up_scotty;
  }

  //For as many times as you want:
  for (int i=1; i<nMax; i++)
  {
    //Multiply to fact_me_up_scotty
    ComplexNumber dumber_than_hot_spaghett(i);
    fact_me_up_scotty = fact_me_up_scotty * dumber_than_hot_spaghett;

    //matrix multiplication, only for 2nd iteration or above
    //was easier to do directly than split into more functions
    if(i>1)
    {
      for (int j=0; j<3; j++)
      {
        for (int k=0; k<3; k++)
        {
          ComplexNumber lars(0.0);
          for (int l=0; l<3; l++)
          {
            lars = lars + A_copy[j][l] * A[l][k];
          }
          A_copy[j][k] = lars; //couldn't shorten this to write directly to A_copy , don't know why
        }
      }
    }

    //Add every iteration / factorial to resulting vector
    for (int j=0; j<3; j++)
    {
      for (int k=0; k<3; k++)
      {
        res[j][k] = res[j][k] + A_copy[j][k]*fact_me_up_scotty.CalculatePower(-1);
      }
    }
  }

  //Delete A_copy
  for (int i=0; i<3; i++)
  {
    delete[] A_copy[i];
  }
  delete[] A_copy;
}

void PrintMatrix(ComplexNumber **A, int rows, int cols)
{
  for (int i=0; i<rows; i++)
  {
    for (int j=0; j<cols; j++)
    {
      std::cout << A[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
