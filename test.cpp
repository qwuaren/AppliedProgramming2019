#include <iostream>
#include <vector>
// #include "tick.hpp"

int main()
{
  std::vector<int> v;

  v.reserve(5);

  for (int i=0; i<5; i++)
  {
    v.push_back(i);
    std::cout << v[i] << std::endl;
  }

  // std::cout << "I work!" << std::endl;

  // tick<double> a(2);
  //
  // a[0] = 1; a[1] = 2;

  // std::cout << v[0] << std::endl;

  return 0;
}
