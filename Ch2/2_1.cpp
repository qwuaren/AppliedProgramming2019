#include <iostream>

int main (int argc, char* argv[])
{
  double x, y, z;
  std::cin >> x >> y;
  //if ((x > y) || (x < 5.0)) //original line
  if ((x >= y) || (x < 5.0))
  {
    z = 4.0;
  }
  else
  {
    z = 2.0;
  }

  std::cout << z << "\n";
}
