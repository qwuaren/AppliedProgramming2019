#include "Matrix2x2.hpp"
#include <cmath>
#include <cassert>
// Compile class to .o: g++ -Wall -O -c class.cpp

// /*
// ===============================================
// */

//6.2.1
//overridden contructor, sets everything to zero

Matrix2x2::Matrix2x2()
{
  val00 = 0.0;
  val01 = 0.0;
  val10 = 0.0;
  val11 = 0.0;
}

// /*
// ===============================================
// */

// 6.2.2
//overridden copy constructor

Matrix2x2::Matrix2x2(const Matrix2x2& other)
{
  val00 = other.val00;
  val01 = other.val01;
  val10 = other.val10;
  val11 = other.val11;
}

// /*
// ===============================================
// */

// 6.2.3
//constructor, sets elems to a,b,c,d

Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
  val00 = a;
  val01 = b;
  val10 = c;
  val11 = d;
}

// /*
// ===============================================
// */

// 6.2.4
//Method that returns determinant of matrix

double Matrix2x2::CalcDeterminant() const
{
  return (val00 * val11 - val01 * val10);
}

// /*
// ===============================================
// */

// 6.2.5
//Method that returns inverse of matrix (if it exists)

Matrix2x2 Matrix2x2::CalcInverse() const
{
  double invdet = 1.0;//1.0/(val00 * val11 - val01 * val10);
  double temp = val00;

  return Matrix2x2((invdet * val11), (invdet * -val01), (invdet * -val10), (invdet * temp));
}

// /*
// ===============================================
// */

// EKSTRA, PRINT FORMATTING
std::ostream& operator<<(std::ostream& output,
                         const Matrix2x2& z)
{
  //format as 2 lines, ab // cd
  output << z.val00 << "\t" << z.val01 << "\n" << z.val10 << "\t" << z.val11;

  return output;
}

// /*
// ===============================================
// */

//6.2.6
//Overload assignment operator, so we can write A = B
Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z)
{
  val00 = z.val00;
  val01 = z.val01;
  val10 = z.val10;
  val11 = z.val11;

  return *this;
}

// /*
// ===============================================
// */

// 6.2.7
//Overload unary subtraction

Matrix2x2 Matrix2x2::operator-() const
{
  Matrix2x2 w;

  w.val00 = -val00;
  w.val01 = -val01;
  w.val10 = -val10;
  w.val11 = -val11;

  return w;
}

// /*
// ===============================================
// */

//6.2.8
//Overload binary addition and subtraction

//addition
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const
{
  Matrix2x2 w;

  w.val00 = val00 + z.val00;
  w.val01 = val01 + z.val01;
  w.val10 = val10 + z.val10;
  w.val11 = val11 + z.val11;

  return w;
}

//subtraction
Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const
{
  Matrix2x2 w;

  w.val00 = val00 - z.val00;
  w.val01 = val01 - z.val01;
  w.val10 = val10 - z.val10;
  w.val11 = val11 - z.val11;

  return w;
}

// /*
// ===============================================
// */

//6.2.9
//Method for multplying matrix with doubel scalar

void Matrix2x2::MultScalar(double scalar)
{
  val00 *= scalar;
  val01 *= scalar;
  val10 *= scalar;
  val11 *= scalar;
}

// /*
// ===============================================
// */

//Non mandatory print function (saw this after my own)
void Matrix2x2::Print() const
{
  std::cout << val00 << "\t" << val01 << "\n" << val10 << "\t" << val11 << std::endl;
}
