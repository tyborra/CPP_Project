#pragma once
#include "student.h"

class securityStudent : public Student {

public:
	virtual Degree getDegreeProgram() override;
	using Student::Student;

private:
	Degree degreeType = SECURITY;	
};

