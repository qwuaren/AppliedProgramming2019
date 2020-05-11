#include <iostream>

#define LOG(x) std::cout << x << std::endl

void ChangeValue(int* a)
{
  *a *= 2;
}

int main()
{
  int i = 5.0;

  LOG(i);

  ChangeValue(&i);

  LOG(i);

  return 0;
}
