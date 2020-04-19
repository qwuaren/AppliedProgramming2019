#include <iostream>
#include <cmath>
int main(int argc, char* argv[])
{
  double x = 1.0, y = 2.0, z;

  z = x/y; //division
  std::cout << z << "\n";

  z = x*y; //multiplication
  std::cout << z << "\n";

  z = sqrt(x); //square root
  std::cout << z << "\n";

  z = exp(x); //exponential function
  std::cout << z << "\n";

  z = pow(x,y); //x to the power of y
  std::cout << z << "\n";
  
  z = M_PI; //store value of pi
  std::cout << z << "\n";

  /* You can similarly to sqrt and exp use cos,
  sin, tan, acos, asin, atan, cosh, sinh, tanh,
  log10, ceil, floor */

  double a = 7.8, b = 1.65, u = -3.4;

  z = fmod(a,b); //remainder when x is divided by y
  std::cout << z << "\n";

  z = atan2(a,b); //inverse tangent in radians of
                  //angle between vector (x,y) and
                  //pos x-axis. Note order of x,y
  std::cout << z << "\n";

  z = fabs(u); //absolute value of u. Not to be
               //confused with abs (integer equiv)
  std::cout << z << "\n";

  /* Many shorthand operands:
      a = a+b; a+=b
      a = a-b; a-=b
      a = a*b; a*=b
      a = a/b; a/=b
      a = a%b; a%=b; if a and b are integers (a mod b)
      a = a+1; a++; if a is an integer
      a = a-1; a--; if a is an integer
  */

  return 0;
}
