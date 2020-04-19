#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[])
{
  // WRITING ALL OUTPUT TO ONE FILE, RUN ./file > file.txt
  // double x, y;
  //
  // x=1;
  // y=2;
  // if (y == 0)
  // {
  //   /* In case of error, this will be printed to
  //   the console instead of making a file. When
  //   console output is not redirected to a file,
  //   there is no diff between this and std::cout.
  //   But, when making a file, only std::cout content
  //   will be printed to the file. */
  //   std::cerr << "Error - division by zero\n";
  // }
  // else
  // {
  //   //y not zero
  //   std::cout << x/y << "\n";
  // }


  // /* WRITING VARIOUS PARTS TO VARIOUS FILES */
  // double x[3] = {0.0, 1.0, 0.0};
  // double y[3] = {0.0, 0.0, 1.0};
  //
  // std::ofstream write_output("Output.dat", std::ios::app); //append data by adding std::ios::app
  // assert (write_output.is_open());
  //
  // for (int i=0; i<3; i++)
  // {
  //   write_output << x[i] << " " << y[i] << "\n";
  // }
  //
  // write_output.close();

  // /* SETTING PRECISION OF OUTPUT */
  // double x = 1.234567890;
  //
  // std::ofstream write_output("PrecisionOutput.dat");
  //
  // write_output.precision(3); // 3 sig figs
  // write_output << x << "\n";
  //
  // write_output.precision(5); // 5 sig figs
  // write_output << x << "\n";
  //
  // write_output.precision(10); // 10 sig figs
  // //given a lower precision, the precision is only given to that. The rest is redundant.
  // write_output << x << "\n";
  // write_output.close();

  // /* READING FROM FILES WE KNOW LENGTH OF*/
  // double x[6], y[6];
  // std::ifstream read_file("Output.dat");
  // assert(read_file.is_open());
  //
  // for (int i=0; i<6; i++)
  // {
  //   read_file >> x[i] >> y[i];
  //   std::cout << x[i] << " " << y[i] << "\n";
  // }
  //
  // read_file.close();

  // /* READING FROM FILES OF UNKNOWN LENGTH */
  // //assume we know it's shorter than 100 entries
  //
  // double x[100], y[100];
  //
  // std::ifstream read_file("Output.dat");
  // assert(read_file.is_open());
  //
  // int i = 0;
  // while (!read_file.eof())
  // {
  //   read_file >> x[i] >> y[i];
  //
  //   std::cout << x[i] << " " << y[i] << "\n";
  //   i++;
  // }
  //
  // read_file.close();

  //Reset reading with read_file.clear();
  //followed by
  //read_file.seekg(std::ios:beg);

  // /* CHECKING INPUT/OUTPUT IS SUCCESSFUL */
  // std::ofstream write_output("OutputVerified.dat");
  //
  // assert(write_output.is_open());
  //
  // for (int i=0; i<100; i++)
  // {
  //   write_output << i << "\n";
  //   //make sure, we're still writing to a file,
  //   //and everything is going as planned.
  //   assert(write_output.good());
  // }

  // std::cout << "Number of command line arguments = "
  //           << argc << "\n";
  // for (int i=0; i<argc; i++)
  // {
  //   std::cout << "Argument " << i << " = " << argv[i];
  //   std::cout << "\n";
  // }
  //
  // std::string program_name = argv[0];
  // //atoi and atof requires header cstdlib
  // int number_of_nodes = atoi(argv[1]);
  // double conductivity = atof(argv[2]);
  //
  // std::cout << "Program name = " << program_name << "\n";
  // std::cout << "Number of nodes = " << number_of_nodes;
  // std::cout << "\n";
  // std::cout << "Conductivity = " << conductivity << "\n";

  /* CONTROLLING OUTPUT FORMAT */
  /*
  SCIENTIFIC FORMAT:
  std::ios::scientific, requires header fstream

  ALWAYS SHOW +/- (DEFAULT IS TO NOT DO SO)
  std::ios::showpos, requires header fstream

  PRECISION OF OUTPUT
  Works slightly different than previouly used, if
  scientific format is used - then, it is the number
  of digits after the decimal point. Also in sci.
  zeros are added after the decimal point at lower
  precision to ensure all output is of exactly
  same width.

  Demonstration below.

  */

  std::ofstream write_file("OutputFormatted.dat");
  // Write numbers as +x<13digits>e+00 (width 20)

  write_file.setf(std::ios::scientific);
  write_file.setf(std::ios::showpos);
  write_file.precision(13);

  double x = 3.4, y = 0.0000855, z = 984.424;

  write_file << x << " " << y << " " << z << "\n";

  write_file.close();


  return 0;
}
