#include "3_3.h"
#include <cassert>
#include <fstream>
#include <cstdlib>

/* I CANNOT MAKE THIS WORK WITH THE CODE CHECKER,
BUT I SEEM TO GET A FINE RESULT WITH THE MAIN FUNCTION BELOW
+ I ALSO INCLUDED THE XY.DAT FILE I MADE WITH IT IN THE FOLDER */

// int main()
// {
//   implicit_Euler(100);
// }

void implicit_Euler(int n)
{
  assert(n>1);

  double h = 1/(double(n));

  double x = 0.0, y_old = 1.0, y_new;

  std::ofstream write_output("xy.dat");
  assert(write_output.is_open());

  for (int i=0; i<n; i++)
  {
    //calculate next y value
    y_new = y_old / (h + 1.0); //this is from isolating y_n from assignment description.
    write_output << x << "," << y_new << "\n";

    //increase x
    x = h*i;
    y_old = y_new;

  }

  write_output.close();
}
