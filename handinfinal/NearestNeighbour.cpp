#include "armadillo.hpp"
#include <fstream>
// #include <iostream>

int main()
{
  arma::mat dataX, dataXtest;
  arma::vec dataY;

  //load data and test data
  dataX.load("dataX.dat");
  dataY.load("dataY.dat");
  dataXtest.load("dataXtest.dat");

  arma::vec dataYtest(dataXtest.n_rows);

  //check dimensions of files *for debug*
  // std::cout << "\tdataX\tdataY\tdataXtest\tdataYtest" << std::endl;
  // std::cout << "n_rows:\t" << dataX.n_rows << "\t" << dataY.n_rows << "\t" << dataXtest.n_rows << "\t\t" << dataYtest.n_rows << std::endl;
  // std::cout << "n_cols:\t" << dataX.n_cols << "\t" << dataY.n_cols << "\t" << dataXtest.n_cols << "\t\t" << dataYtest.n_cols << std::endl;

  //define number of neighbours
  int neighbours = 5;
  //keep track of goodness of algorithm
  double succes = 0;

  //For each point in dataXtest
  for (int i=0; i<dataXtest.n_rows; i++)
  {
    //save distances in a vector
    arma::vec Distances(dataX.n_rows);

    //Calculate distance to each point in dataX
    for (int j=0; j<dataX.n_rows; j++)
    {
      Distances(j) = arma::norm(dataX.row(j)-dataXtest.row(i));
    }

    //Use to find indices to nearest neighbours
    arma::vec sorted_distances = arma::sort(Distances, "ascend");

    //Keep sum of y's
    double sum = 0;

    //Investigate neighbours and add y's to sum
    for (int k=0; k<neighbours; k++)
    {
      //Find distance to index pointer equal to k
      auto idx_k = std::find(Distances.begin(), Distances.end(), sorted_distances(k));
      int dist = std::distance(Distances.begin(), idx_k);
      sum += dataY(dist);
      // std::cout << dist << "  " << std::endl;
    }
    // std::cout << std::endl;

    if (sum>0)
    {
      dataYtest(i) = 1;
    }
    else
    {
      dataYtest(i) = -1;
    }

    //How many are correct then?
    if(dataY(i) == dataYtest(i))
    {
      succes++;
    }
  }

  // std::cout << "\nIf dataXtest == dataX, \nthe succesrate was:\n\n" << succes/2 << " %" << "\n\n";
  // dataYtest.print();

  // dataYtest.save("NN.dat");
  std::ofstream outputfile("NN.dat");

    for(auto x : dataYtest)
    {
        outputfile << std::fixed << x << std::endl;
    }
    outputfile.close();

}
