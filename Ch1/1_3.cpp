#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
  double arr1[3] = {1.0, 2.0, 3.0}, arr2[3] = {4.0, 5.0, 6.0};

  /* Calculating scalar product */
  double dot_prod;
  dot_prod = arr1[0] * arr2[0] + arr1[1] * arr2[1] + arr1[2] * arr2[2];

  double norm2;
  norm2 = sqrt(dot_prod);

  std::cout << "The dot product of the two vectors is = " << dot_prod << " and the Euclidean norm is = " << norm2 << "\n";

  return 0;
}
