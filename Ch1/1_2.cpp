#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
  int int1, int2;
  std::cout << "Type two integers, and I will give you the product\n\n Follow each integer by hitting the RETURN button\n";
  std::cin >> int1 >> int2;

  std::cout << "The product between " << int1 << " and " << int2 << " is: " << int1*int2 << "\n";

  return 0;
}
