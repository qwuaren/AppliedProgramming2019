#include <iostream>
#include "FileNotOpenException.hpp"

//Constructor
FileNotOpenException::FileNotOpenException(std::string prob)
{
  mTag = "File not open";
  mProblem = prob;
}
