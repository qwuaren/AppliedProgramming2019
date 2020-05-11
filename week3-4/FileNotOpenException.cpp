#include <iostream>
#include "FileNotOpenException.hpp"

//Constructor
FileNotOpenException::FileNotOpenException(std::string prob)
  : Exception(std::string("File not open"), prob)
{
  return;
}
