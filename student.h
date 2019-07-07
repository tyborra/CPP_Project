#pragma once
#include "degree.h"
#include <string>
using std::string;


class Student{

public:	
	Student(string id, string fn, string ln, string ea, int a, int* nd, Degree dt); //Constructor	
	~Student(); //Deconstructor
	virtual void print(); //Print student data
	virtual Degree getDegreeProgram(); //Empty function
	string getEnum(Degree deg); // get enumerated data type as string

	//Accesors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int * getNumDays();
	Degree getDegree();
	
	//Mutators
	void setStudentID(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string emailAddress);
	void setAge(int age);
	void setNumDays(int * numDays);
	void setDegreeProgram(Degree degreeType);

private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDays[3] ={0, 0, 0};
	Degree degreeType;
};

