#ifndef SUBMISSION_STUDENT_HPP_
#define SUBMISSION_STUDENT_HPP_

#include <string>
#include <iostream>

class Student {
public:
	Student();
	Student(std::string fame, double fines, double fees); //had to change name to other than same as variable

	std::string name;
	double tuition_fees;
	virtual double MoneyOwed() const;

	void SetLibraryFines(double amount);
	double GetLibraryFines() const;

private:
	double library_fines;

// public:
// 	friend std::ostream& operator<<(std::ostream& output,
// 																	const Student& s); //my own
};



#endif /* SUBMISSION_STUDENT_HPP_ */
