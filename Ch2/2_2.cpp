#include <iostream>

int main(int argc, char* argv[])
{
  double p, q, x=0.1, y;
  int j;

  int caseID;
  std::cin >> caseID;

  if (caseID == 1)
  {
    /* FIRST CASE */

    std::cout << "\n\nFIRST CASE\n\n";

    std::cout << "Feed double(p), double(q), int(j)\n";

    std::cin >> p >> q >> j;

    if ((p >= q) || (j != 10))
    {
      //One or both conditions have been met
      x = 0.0;
      std::cout << "Either p is larger than or equal to q, or j is different from 20. \nx is therefore = " << x << "\n";
    }
    else
    {
      std::cout << "Neither is p greater than or equal to q, or j is 20. \nx is = " << x << "\n";
    }
  }
    else if (caseID == 2)
    {
    /* SECOND CASE */

    std::cout << "\n\nSECOND CASE\n\n";

    std::cout << "Feed double(p), double(q), int(j), double(y)\n";
    std::cin >> p >> q >> j >> y;

    if ((y >= q) && (j==20))
    {
      x = 5.0;
      std::cout << "y is larger than or equal to q AND j is 20, so \nx is then = " << x << "\n";
    }
    else
    {
      x = p;
      std::cout << "Either y is not larger than or equal to q, or j is not 20. \nx is therefore = " << x << "\n";
    }
  }
  else
  {
    /* THIRD CASE */

    std::cout << "\n\nTHIRD CASE \n\n";

    std::cout << "Feed double(p), double(q), int(j)\n";
    std::cin >> p >> q >> j;

    if (p > q)
    {
      x = 0.0;
      std::cout << "p is greater than q, \nx is therefore = " << x << "\n";
    }
    else if ((p <= q) && (j == 10))
    {
      x = 1.0;
      std::cout << "p is less than or equal to q AND j is 10, so \nx is = " << x << "\n";
    }
    else
    {
      //p !> q
      x = 2.0;
      std::cout << "p was not greater than q, so \nx is = " << x << "\n";
    }
  }

  return 0;
}
