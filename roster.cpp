#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

using std::istringstream;
using std::cout;
using std::endl;
using std::regex;


Roster::Roster(){ //constructor
}

Roster::~Roster(){ //destructor
}

//**** ADD STUDENT****
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree deg) {
	
	if (rosterIterator < numStudents) {
		int allDays[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
		switch (deg) {
		case Degree::SECURITY:
			classRosterArray[rosterIterator] = new securityStudent(studentID, firstName, lastName, emailAddress, age, allDays, deg);
			rosterIterator++;
			break;
		case Degree::NETWORKING:
			classRosterArray[rosterIterator] = new networkStudent(studentID, firstName, lastName, emailAddress, age, allDays, deg);
			rosterIterator++;
			break;
		case Degree::SOFTWARE:
			classRosterArray[rosterIterator] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, allDays, deg);
			rosterIterator++;
			break;
		}
	}
}

//**** REMOVE STUDENT****
void Roster::remove(string studentID){
	bool studentRemoved = false;
	cout << "\n\n Attempting to remove student " << studentID << " ... ";

	for (int i = 0; i < numStudents; i++) {
		
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			studentRemoved = true;
			cout << "\n Student: " << studentID << " removed \n";
			break;
		}
	}

	if (studentRemoved == false) {
		cout << "\n ERROR: Student ID " << studentID << " was not found" << endl;
	}
}

//**** PRINT ALL STUDENTS ****
void Roster::printAll(){
	cout << "Printing All Student Data...\n";

	for (int i = 0; i < numStudents; i++) {
		classRosterArray[i]->print();
	}
}

//*** PRINT AVERAGE  DAYS PER COURSE ****
void Roster::printAverageDaysInCourse(string studentID){
	int avg = 0;	
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int* tempDays = classRosterArray[i]->getNumDays();
			avg = (tempDays[0] + tempDays[1] + tempDays[2]) / 3;

			cout << "Student " << classRosterArray[i]->getStudentID() << " average number of days: " << avg << endl;
			break;
		}
	}
}

//**** PRINT INVALID EMAILS ****
void Roster::printInvalidEmails(){
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	cout << "\nChecking for valid email address...\n";
	for (int i = 0; i < numStudents; i++) {
		string tempEmail = classRosterArray[i]->getEmail();
		bool hasSpace = false;
		bool hasSymbols = std::regex_match(tempEmail, pattern);
		
		if (tempEmail.find(" ") != string::npos) {
			hasSpace = true;
		}

		if (hasSymbols == 0 || hasSpace == 1) {
			cout << tempEmail << "\t is not a valid email address \n" ;
		}
	}
	cout << endl;
}

//**** PRINT ALL STUDENTS OF DEGREE PLAN ****
void Roster::printByDegreeProgram(int degreeProgram){
	
	string printDeg;
	switch (degreeProgram){
	    case 0: printDeg = "SECURITY"; break;
		case 1: printDeg = "NETWORKING"; break;
		case 2: printDeg = "SOFTWARE"; break;
		default:	printDeg = "NONE"; break;
	}
	cout << "\n\nStudents with degree program " << printDeg<< ": \n";

	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getDegree() == degreeProgram) {                              
			classRosterArray[i]->print();
		}
	}
}

//**** ADD STUDENT DATA ****
void Roster::addStudentData(){
	for (int i = 0; i < numStudents; i++) {
		string sdInput;
		istringstream iss(studentData[i]);
		char comma = ',';
		string tempString ;
		string tempArray[9];
		Degree tempDeg;

		int j = 0;
		while (getline(iss, tempString, comma)) {
			tempArray[j] = tempString;			
			j++;
		}	
		
		string tempDegree = tempArray[8];
		if (tempDegree == "SECURITY") {
			tempDeg = Degree::SECURITY;
		}
		else if (tempDegree == "NETWORKING") {
			tempDeg = Degree::NETWORKING;
		}
		else if (tempDegree == "SOFTWARE") {
			tempDeg = Degree::SOFTWARE;
		}
		else tempDeg = Degree::NONE;		
		
		add( tempArray[0], tempArray[1], tempArray[2], tempArray[3], stoi(tempArray[4]), stoi(tempArray[5]), stoi(tempArray[6]), stoi(tempArray[7]), tempDeg);		
	}
}


//********		MAIN	********//
int main() {
	
	//**** Print info ****
	cout << "\n Course Title: Scripting and Programming Applications  C867\n" 
		 << " Programming Language: C++\n" 
		 << " Student ID: 001131227\n" 
		 << " Name: Tyler Borras\n" << endl;
	
	Roster classRoster;

	//**** Add Data ****
	classRoster.addStudentData();

	//**** Final function calls ****
	classRoster.printAll();
	classRoster.printInvalidEmails();
	
	cout << "\nAverage days per course:\n";
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	
	classRoster.printByDegreeProgram(Degree::SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");

	//**** Destructor ****
	cout << "\n \n";
	classRoster.~Roster();

	return 0;
}