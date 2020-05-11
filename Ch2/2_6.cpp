#include <iostream>
#include <cmath>

double func (double a)
{
  double f;

  f = exp(a) + pow(a,3) - 5;

  return f;
}

double der (double a)
{
  double fder;

  fder = exp(a) + 3*pow(a,2);

  return fder;
}

int main(int argc, char* argv[])
{
  // double x[100];
  //
  // double x0 = 0;
  //
  // x[0] = x0;
  //
  // std::cout << x[0] << "    " << func(x[0]) << "\n";
  //
  // x[1] = x[0] - (func(x[0])/der(x[0]));
  //
  // std::cout << x[1] << "    " << func(x[1]) << "\n";
  //
  // x[2] = x[1] - (func(x[1])/der(x[1]));
  //
  // std::cout << x[2] << "    " << func(x[2]) << "\n";
  //
  // for (int i=1; i<100; i++)
  // {
  //   x[i] = x[i-1] - (func(x[i-1])/der(x[i-1]));
  //
  //   std::cout << "x[" << i << "] is = " << x[i] << "\n";
  //   std::cout << "Function value for xi is =" << func(x[i-1]) << "\n";
  // }

  double eps = 0.00001;

  double x_prev, x_next;

  //initialise x-values
  x_prev = 0;

  x_next = x_prev - func(x_prev)/der(x_prev);

  while (abs(x_next-x_prev)>eps)
  {
    x_prev = x_next;
    x_next = x_prev - func(x_prev)/der(x_prev);

    std::cout << "Function value for current best x = " << x_next << "\n";
  }

  return 0;
}
