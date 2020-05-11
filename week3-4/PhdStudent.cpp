#include "PhdStudent.hpp"

PhdStudent::PhdStudent(std::string vname, double fines, double fees, bool vfullTime) : GraduateStudent()
{
  name = vname;
  tuition_fees = fees;
  SetLibraryFines(fines);
  fullTime = vfullTime;
}

double PhdStudent::MoneyOwed() const
{
  return 0.0; //although according to assignment, they owe tuition_fees?
}

// std::ostream& operator<<(std::ostream& output,
//                                 const PhdStudent& s)
// {
//   output << "[PHD STUDENT]" << std::endl;
//   output << "Student's name is: " << s.name << std::endl; //won't print name?
//   output << "Money owed: " << s.MoneyOwed() << std::endl;
//
//   if (s.fullTime == 1)
//   {
//     output << "Full time";
//   }
//   else
//   {
//     output << "Part time";
//   }
//
//   return output;
// }
