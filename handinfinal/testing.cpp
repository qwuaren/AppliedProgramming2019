#include "armadillo.hpp"
#include <iostream>

int main()
{
  arma::vec dataY;
  dataY.load("dataY.dat");
  arma::vec dataYLog;
  dataYLog.load("LogReg.dat");

  int succes = 0;
  for (int i=0; i<dataY.n_rows; i++)
  {
    if (dataY(i) == dataYLog(i))
    {
      succes++;
    }
  }

  std::cout << succes/2 << '\n';
}
