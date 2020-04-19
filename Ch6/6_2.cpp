// Compile file with class: g++ -Wall -O -o file file.cpp class.o

#include "Matrix2x2.hpp"
#include <iostream>

int main()
{
  Matrix2x2 a = Matrix2x2(1.0,2.0,3.0,4.0);

  // Matrix2x2 b = Matrix2x2(0.5,0.5,0.5,0.5);

  // Matrix2x2 c = a-b;

  // b.MultScalar(2.0);

  // std::cout << a.Getval11() << std::endl;

  a.Print();

  Matrix2x2 inva = a.CalcInverse();

  std::cout << a.CalcDeterminant() << '\n';

  inva.Print();
}
