#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{
  for (long int i=0; i<1000000000; i++)
  {
    double* ptr_vec1;
    ptr_vec1 = new double[3];
    double* ptr_vec2;
    ptr_vec2 = new double[3];

    double dot_prod = 0;

    for (int i=0; i<3; i++)
    {
      ptr_vec1[i] = i+1;
      ptr_vec2[i] = i+4;

      dot_prod += ptr_vec1[i] * ptr_vec2[i];

      // LOG(ptr_vec1[i]); //Do not print in 1e6 loop!
      // LOG(ptr_vec2[i]); //Do not print in 1e6 loop!
    }

    // LOG(dot_prod); //do not print in 1e6 for-loop.

    delete[] ptr_vec1;
    delete[] ptr_vec2;
  }

  std::cout << "I'm done\n";

  return 0;
}
