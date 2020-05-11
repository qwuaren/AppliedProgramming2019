#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>


int main(int argc, char* argv[])
{
  int N = atoi(argv[1]);
  assert(N>1);

  double h = 1/(double(N));

  double x = 0.0, y_old = 1.0, y_new;

  std::ofstream write_output("xy.dat");
  assert(write_output.is_open());

  for (int i=0; i<N; i++)
  {
    //calculate next y value
    // y_new = y_old + (h * (-y_old)); //read somewhere else that it should be y0 + h*dy/dx --> y0 + h*df(y), converges similarly to below, but not identically.
    y_new = y_old / (h + 1.0); //this is from isolating y_n from assignment description.
    write_output << x << "," << y_new << "\n";

    //increase x
    x = h*i;
    y_old = y_new;

  }

  // write_output << x << "," << y_new << "\n";

  write_output.close();

  return 0;
}
