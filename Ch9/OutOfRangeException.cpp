#include <iostream>
#include "OutOfRangeException.hpp"

//Constructor
OutOfRangeException::OutOfRangeException(std::string prob)
{
  mTag = "Out of range";
  mProblem = prob;
}
