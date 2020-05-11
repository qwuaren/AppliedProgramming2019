#include <iostream>
#include <cmath>

#define LOG(x) std::cout << x << std::endl

//PROTOTYPE FUNCTIONS
double calc_std(double a[], int length);
double calc_mean(double a[], int length);

int main()
{
  double a[5] = {1.00, 2.00, 3.00, 4.00, 5.00};
  int length = 5;

  double std = calc_std(a,length);
  LOG(std);

  return 0;
}

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
