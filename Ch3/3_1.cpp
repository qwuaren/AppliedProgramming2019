#include <iostream>
#include <cassert>
#include <fstream>

int main(int argc, char* argv[])
{
  /* HAR FÅET LØST ALT, UNDTAGEN AT OVERWRITE/APPENDE
     SPÆNDENDE DATA ALT EFTER BRUGER INPUT. */
  double x[4] = {0.0, 1.0, 1.0, 0.0};
  double y[4] = {0.0, 0.0, 1.0, 1.0};

  std::ifstream read_file("Output.dat");
  if (read_file.is_open())
  {
    read_file.close();
    std::cout << "The file already exists";
  }

  std::cout << "\n Would you like to erase the file, or append?\n";
  std::cout << "Type '1' to erase file, or '2' to append.\n";

  int whattodo;
  std::cin >> whattodo;
  //
  // if (whattodo == 1)
  // {
  std::ofstream write_output("x_and_y.dat");
  // }
  // else if (whattodo == 2)
  // {
  //   std::ofstream write_output("x_and_y.dat", std::ios::app);
  // }

  // if (whattodo == 1)
  // {
  //   std::ofstream write_output("x_and_y.dat", std::ios::app);
  // }

  assert (write_output.is_open());

  write_output.setf(std::ios::scientific);
  write_output.setf(std::ios::showpos);
  write_output.precision(11);

  for (int i=0; i<4; i++)
  {
    //write all x entries on the first line
    write_output << x[i] << " ";
  }
  write_output.flush();

  //make next line
  write_output << "\n";

  for (int i=0; i<4; i++)
  {
    //write all y entries on second line
    write_output << y[i] << " ";
  }
  write_output.flush();

  write_output.close();

  return 0;
}
