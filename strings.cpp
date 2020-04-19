#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  std::string city; //note std::
  city = "Oxford"; //note double quot marks

  std::cout << "String length = " << city.length() << "\n";
  std::cout << "Third char = " << city.at(2) << "\n";
  std::cout << "Third char = " << city[2] << "\n";

  /* The 2 following lines both print the string, but
  the second line does so by converting from a C++ to a
  C string, which is an array type of char*/
  std::cout << city << "\n"; //Prints string in city
  std::cout << city.c_str() << "\n"; //Also prints city

  std::string name;
  std::cout << "Enter your name and then hit RETURN\n";
  std::getline(std::cin, name);
  std::cout << "Your name is " << name << "\n";

  return 0;
}
