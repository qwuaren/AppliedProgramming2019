#include <iostream>
#include "OutOfRangeException.hpp"

//Constructor
OutOfRangeException::OutOfRangeException(std::string prob)
  : Exception(std::string("File is out of range"), prob)
{
  return;
}
