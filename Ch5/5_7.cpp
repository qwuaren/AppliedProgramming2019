#include <cmath>

double CalculateNorm(double* x, int s, int p = 2)
{
  double a = 0.0;
  for (int i=0; i<s; i++)
  {
    double temp = fabs(x[i]);
    a += pow(temp,p);
  }

  return pow(a,1.0/p);
}
