#include "2_6.h"
#include <cmath>

/* I CANNOT MAKE THIS WORK WITH THE CODE CHECKER,
BUT I SEEM TO GET A FINE RESULT WITH THE MAIN FUNCTION BELOW */

// #include <iostream>
// double newton_Raphson(double initialGuess, double epsilon);
// double func (double a);
// double der (double a);

// int main(int argc, char const *argv[]) {
//   std::cout << newton_Raphson(0,0.0001) << '\n';
//   return 0;
// }
// int main()
// {
//   std::cout << newton_Raphson(0.0,0.00001) << std::endl;
// }

double newton_Raphson(double initialGuess, double epsilon)
{
  double x_prev, x_next;

  //initialise x-values
  x_prev = initialGuess;
  // x_next = x_prev - func(x_prev)/der(x_prev);
  x_next = x_prev - (exp(x_prev) + pow(x_prev,3) - 5)/(exp(x_prev) + 3*pow(x_prev,2));

  while (fabs(x_next-x_prev) > epsilon)
  {
    x_prev = x_next;
    x_next = x_prev - (double)(exp(x_prev) + pow(x_prev,3) - 5)/(double)(exp(x_prev) + 3*pow(x_prev,2));
  }

  return x_prev;
}

// double func (double a)
// {
//   double f;
//
//   f = exp(a) + pow(a,3) - 5;
//
//   return f;
// }
//
// double der (double a)
// {
//   double fder;
//
//   fder = exp(a) + 3*pow(a,2);
//
//   return fder;
// }
