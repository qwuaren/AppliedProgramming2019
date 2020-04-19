#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"
// #include <iostream>

int main()
{
  ComplexNumber z1(3.0,4.0);

  std::cout << z1 << std::endl;

  ComplexNumber z2 = ComplexNumber(z1);

  std::cout << z2 << std::endl;

  ComplexNumber z3 = ComplexNumber(3);

  std::cout << z3 << std::endl;

  ComplexNumber z4 = z2.CalculateConjugate();

  std::cout << z4 << std::endl;

  z1.SetConjugate();

  std::cout << z1 << std::endl;

  ComplexNumber z6 = ComplexNumber(1,3);
  ComplexNumber z7 = ComplexNumber(2,1);

  std::cout << z6 * z7 << std::endl;

  return 0;
}
