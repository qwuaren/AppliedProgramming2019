#include "ComplexNumber.hpp"
#include <cmath>

// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
   mRealPart = 0.0;
   mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
   mRealPart = x;
   mImaginaryPart = y;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
   return sqrt(mRealPart*mRealPart+
               mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
   return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n
// using De Moivre's theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
   double modulus = CalculateModulus();
   double argument = CalculateArgument();
   double mod_of_result = pow(modulus, n);
   double arg_of_result = argument*n;
   double real_part = mod_of_result*cos(arg_of_result);
   double imag_part = mod_of_result*sin(arg_of_result);
   ComplexNumber z(real_part, imag_part);
   return z;
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::
               operator=(const ComplexNumber& z)
{
   mRealPart = z.mRealPart;
   mImaginaryPart = z.mImaginaryPart;
   return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
   ComplexNumber w;
   w.mRealPart = -mRealPart;
   w.mImaginaryPart = -mImaginaryPart;
   return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::
              operator+(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart + z.mRealPart;
   w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
   return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::
              operator-(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart - z.mRealPart;
   w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
   return w;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output,
                         const ComplexNumber& z)
{
   // Format as "(a + bi)" or as "(a - bi)"
   output << "(" << z.mRealPart << " ";
   if (z.mImaginaryPart >= 0.0)
   {
      output << "+ " << z.mImaginaryPart << "i)";
   }
   else
   {
      // z.mImaginaryPart < 0.0
      // Replace + with minus sign
      output << "- " << -z.mImaginaryPart << "i)";
   }
   return output;
}
//Code from Chapter06.tex line 986 save as ComplexNumber.cpp

/*
===============================================
===========OPGAVER TIL KAPITEL 6===============
===============================================
*/

//6_1_1
/* Methods to access corresponding private members */

double ComplexNumber::GetRealPart() const
{
  return mRealPart;
}

double ComplexNumber::GetImaginaryPart() const
{
  return mImaginaryPart;
}

/*
===============================================
*/

// 6_1_2
/* Friend functions, so one may either write
z.GetImaginaryPart() og ImaginaryPart() */

double RealPart(const ComplexNumber& z)
{
  return z.mRealPart;
}

double ImaginaryPart(const ComplexNumber& z)
{
  return z.mImaginaryPart;
}

// /*
// ===============================================
// */

// 6_1_3
/* Overridden copy constructor */
ComplexNumber::ComplexNumber(const ComplexNumber& z)
{
  mRealPart = z.mRealPart;
  mImaginaryPart = z.mImaginaryPart;
}

// /*
// ===============================================
// */

// 6_1_4
/* Specify real number in complex form through a
constructor that takes one double as input and
sets the real part to that and im part to zero. */

ComplexNumber::ComplexNumber(double real)
{
  mRealPart = real;
  mImaginaryPart = 0.0;
}

// /*
// ===============================================
// */

// 6_1_5
/* Calculate conjugate x - iy of compl num x + iy. */
ComplexNumber ComplexNumber::CalculateConjugate() const
{
  ComplexNumber w;

  w.mRealPart = mRealPart;
  w.mImaginaryPart = mImaginaryPart * -1;

  return w;
}

// /*
// ===============================================
// */

//6_1_6
/* Method, SetConjugate which sets complex number
x + iy to complex conj x - iy. */

void ComplexNumber::SetConjugate()
{
  mImaginaryPart = mImaginaryPart * -1.0;
}

// /*
// ===============================================
// */

/*Ekstra assignment - chaning * operator, probably
to calculate product of two complex numbers. */

ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const
{
  ComplexNumber w;

  w.mRealPart = mRealPart * z.mRealPart - mImaginaryPart * z.mImaginaryPart;
  w.mImaginaryPart = mImaginaryPart * z.mRealPart + mRealPart * z.mImaginaryPart;
  return w;
}

// /*
// ===============================================
// */

//6_1_7
/* Write matrix to allocate memory for 3x3 matrix of
complex numbers. */
void ComplexNumber::CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
  
}
