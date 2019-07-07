#pragma once
#include "student.h"

class networkStudent : public Student {

public:
	virtual Degree getDegreeProgram() override;
	using Student::Student;

private:
	Degree degreeType = NETWORKING;	
};
