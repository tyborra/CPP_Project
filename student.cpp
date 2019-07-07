#include "degree.h"
#include <string>
#include "student.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;


//**** Constructor ****
Student::Student(string id, string fn, string ln, string ea, int ag, int* nd, Degree dt) {
	studentId = id;
	firstName = fn;
	lastName = ln;
	emailAddress = ea;
	age = ag;
	setNumDays(nd);
	degreeType = dt;
};

//**** Destructor ****
Student::~Student() {};


//**** Virtual Functions ****
void Student::print() {

	cout << studentId ;
	cout << "\tFirst Name: " << firstName;
	cout << "\tLast Name: " << lastName;
	cout << "\tEmail: " << emailAddress;
	cout << "\tAge: " << age << "\t";
	cout << "\tDays in courses: {" << numDays[0] << ", " << numDays[1] << ", " << numDays[2] << "}";
	cout << "\tDegree Program: " << getEnum(degreeType);
	cout << endl;
}

Degree Student::getDegreeProgram(){
	return Degree();
}


//**** Get Enum String ****
string Student::getEnum(Degree deg){
	switch (deg) {
	    case Degree::SECURITY: return "SECURITY";
		case Degree::NETWORKING: return "NETWORKING";
		case Degree::SOFTWARE: return "SOFTWARE";
		default: return "NONE";
	}
}


//**** Accesors ****
string Student::getStudentID() {
	return studentId;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmail() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int* Student::getNumDays() {
	return numDays;
}

Degree Student::getDegree() {
	return degreeType;
}


//**** Mutators ****

void Student::setStudentID(string Id) {
	studentId = Id;
}

void Student::setFirstName(string fn) {
	firstName = fn;
}

void Student::setLastName(string ln) {
	lastName = ln;
}

void Student::setEmail(string email) {
	emailAddress = email;
}

void Student::setAge(int ag) {
	age = ag;
}

void Student::setNumDays(int* day) {
	for (int i = 0; i < 3; i++) {
		numDays[i] = day[i];
	}
}

void Student::setDegreeProgram(Degree degree) {
	degreeType = degree;
}