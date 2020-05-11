#include <iostream>

// #define LOG(x) std::cout << x << std::endl

void PrintValue(int* a)
{
  std::cout << *a << std::endl;
}

int main()
{
  int i = 5.0;

  PrintValue(&i);

  return 0;
}
