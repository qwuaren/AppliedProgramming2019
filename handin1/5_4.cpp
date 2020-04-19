#include "5_4.h"
#include <cmath>

/* WORKS WITH CODE CHECKER */

double calc_mean(double a[], int length)
{
  double sum = 0;

  for (int i=0; i<length; i++)
  {
    sum += a[i];
  }

  sum /= length;

  return sum;
}

double calc_std(double a[], int length)
{
  //std = sqrt( sum(x_i - x)**2 / (N-1) )
  //where x_i is each element in a, and x
  //is the mean value of all N elems in a.

  double mean = calc_mean(a, length);
  double std = 0;

  for (int i=0; i<length; i++)
  {
    //calculate sum(x_i - x)**2
    std += pow((a[i] - mean),2);
  }

  //Then, divide by N-1
  if (length>1)
  {
    //make sure length>1 to not divide by zero
    std /= (length-1);
  }
  else
  {
    //If length == 1
    std /= length;
  }

  //Finally, take sqrt
  std = sqrt(std);

  return std;
}
