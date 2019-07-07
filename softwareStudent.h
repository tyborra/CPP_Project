#pragma once
#include "student.h"

class softwareStudent : public Student {

public:
	virtual Degree getDegreeProgram() override;
	using Student::Student;

private:
	Degree degreeType = SOFTWARE;
};

