#ifndef SUBMISSION_GRADUATESTUDENT_HPP_
#define SUBMISSION_GRADUATESTUDENT_HPP_

#include "Student.hpp"

class GraduateStudent : public Student {
private:

public:
	GraduateStudent();
	GraduateStudent(std::string vname, double fines, double fees, bool vfullTime);
	bool fullTime;
	virtual double MoneyOwed() const;

	// friend std::ostream& operator<<(std::ostream& output,
	// 																const GraduateStudent& s); //my own

};



#endif /* SUBMISSION_GRADUATESTUDENT_HPP_ */
