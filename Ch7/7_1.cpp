#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "PhdStudent.hpp"

int main()
{
  Student S1 = Student("Karl", -2, 3);
  // Student S1 = Student();

  S1.SetLibraryFines(-2);

  std::cout << S1 << std::endl;

  GraduateStudent S2 = GraduateStudent("Karen", 3,4,1);

  std::cout << S2 << std::endl;

  PhdStudent S3 = PhdStudent("Korl", 5,4,0);

  std::cout << S3 << std::endl;

  return 0;
}
