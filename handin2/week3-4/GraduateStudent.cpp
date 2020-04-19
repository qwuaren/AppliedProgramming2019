#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent() : Student()
{
  fullTime = 1; //assume fulltime?
}

GraduateStudent::GraduateStudent(std::string vname, double fines, double fees, bool vfullTime) : Student()
{
  fullTime = vfullTime;
  name = vname;
  SetLibraryFines(fines);
  tuition_fees = fees;
}

double GraduateStudent::MoneyOwed() const
{
  return GetLibraryFines();
}

// std::ostream& operator<<(std::ostream& output,
//                                 const GraduateStudent& s)
// {
//   output << "[GRADUATE STUDENT]" << std::endl;
//   output << "Student's name is: " << s.name << std::endl; //won't print name?
//   output << "Money owed: " << s.MoneyOwed() << std::endl;
//
//   if (s.fullTime == 1){ output << "Fulltime";}
//   else {output << "Parttime";}
//
//   return output;
// }
