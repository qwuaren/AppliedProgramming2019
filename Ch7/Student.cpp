#include "Student.hpp"
#include <cmath>

Student::Student()
{
  //should I set variables here?
  name = "Undefined";
  tuition_fees = 0.0;
  library_fines = 0.0;
}

Student::Student(std::string fame, double fines, double fees)
{
    name = fame;
    tuition_fees = fees;
    library_fines = fines;
}

void Student::SetLibraryFines(double amount)
{
  library_fines = abs(amount); //unsure, if I should assert, just decided to take abs of any input
}

double Student::GetLibraryFines() const
{
  return library_fines;
}

double Student::MoneyOwed() const
{
  return (library_fines + tuition_fees);
}

//MY OWN PRINTING FUNCTION,
// std::ostream& operator<<(std::ostream& output,
//                                 const Student& s)
// {
//   output << "[STUDENT]" << std::endl;
//   output << "Student's name is: " << s.name << std::endl; //won't print name?
//   output << "Tuition fees: " << s.tuition_fees << std::endl;
//   output << "Library fines: " << s.library_fines;
//
//   return output;
// }
