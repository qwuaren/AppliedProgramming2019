#ifndef SUBMISSION_PHDSTUDENT_HPP_
#define SUBMISSION_PHDSTUDENT_HPP_

#include "GraduateStudent.hpp"

class PhdStudent : public GraduateStudent {
public:
	PhdStudent(std::string vname, double fines, double fees, bool vfullTime);
	virtual double MoneyOwed() const;

	// friend std::ostream& operator<<(std::ostream& output,
	// 																const PhdStudent& s); //my own

};



#endif /* SUBMISSION_PHDSTUDENT_HPP_ */
