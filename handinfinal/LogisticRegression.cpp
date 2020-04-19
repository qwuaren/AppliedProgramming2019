#include "armadillo.hpp"
// #include <iostream>
#include <cmath>
#include <fstream>

int main()
{
  arma::mat dataX, dataXtest;
  arma::vec dataY;

  //load data and test data
  dataX.load("dataX.dat");
  dataY.load("dataY.dat");
  dataXtest.load("dataXtest.dat");

  arma::vec dataYtest(dataXtest.n_rows);

  int N = dataX.n_rows;
  double tolerance = 1E-7;

  double alpha = 0.3; //learning rate

  arma::rowvec sum;

  arma::rowvec w; w.zeros(34);

  sum = dataY(0) * (( 1.0 / ( 1 + exp( dataY(0) * (double)(arma::dot(w, dataX.row(0))) ) ) ) * dataX.row(0));

  // std::cout << arma::norm(sum) << '\n';

  // int count = 1000;
  // int count = 0;
  while (arma::norm(sum)>tolerance)
  {
    for (int i=1; i<N; i++)
    {
      sum += dataY(i) * (( 1.0 / ( 1 + exp( dataY(i) * (double)(arma::dot(w, dataX.row(i))) ) ) ) * dataX.row(i));
    }

    sum *= (double)(-1.0/N);

    w = w - alpha * sum;

    // std::cout << arma::norm(sum) << '\n';

    // count--;
    // count++;
  }

  // std::cout << count << '\n';
  // w.print();

  arma::rowvec f;
  for (int i=0; i<dataXtest.n_rows; i++)
  {
    double f = dot(w,dataXtest.row(i));

    if (f>0)
    {
      dataYtest(i) = 1;
    }
    else
    {
      dataYtest(i) = -1;
    }
  }

  // dataYtest.print();

  std::ofstream outputfile("LogReg.dat");

    for(auto x : dataYtest)
    {
        outputfile << std::fixed << x << std::endl;
    }
    outputfile.close();
}
