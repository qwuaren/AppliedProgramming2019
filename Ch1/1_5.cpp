#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  std::string name, family_name;
  std::cout << "Enter your name and family name and then hit RETURN\n";
  std::getline(std::cin, name);
  std::getline(std::cin, family_name);
  std::cout << "Your name is " << name << " " << family_name << "\n";

  return 0;
}
