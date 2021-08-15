/*B.Create a C++ project in your integrated development environment(IDE) with the following files : student.cpp*/



#include "student.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::left;
using std::setw;
using std::endl;

/*D2d.empty constructor*/
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->eMail = "";
	this->age = age;
	for (int i = 0; i < 3; i++) this->daysComplete[i] = daysComplete[i];
	this->program = DegreeProgram::UNKNOWN;
};

/*D2d.the constructor*/
Student::Student(string studentID, string firstName, string lastName, string eMail, int age, int daysComplete[], DegreeProgram program)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->eMail = eMail;
	this->age = age;
	for (int i = 0; i < 3; i++) this->daysComplete[i] = daysComplete[i];
	this->program = program;
}

/*D2a&c. getter*/
string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return eMail;
}

int Student::getAge()
{
	return age;
}

int* Student::getDaysComplete()
{
	return daysComplete;
}

DegreeProgram Student::getProgram() const 
{
	return program;
}

/*D2b&c. setter*/
void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string eMail)
{
	this->eMail = eMail;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDaysComplete(int daysComplete[])
{

	for (int i = 0; i < 3; i++) this->daysComplete[i] = daysComplete[i];

}

void Student::setProgram(DegreeProgram program)
{
	this->program = program;
}

/*D2e. print*/
void Student::print()
{
	cout << left << "Student ID: " << setw(5) << studentID;
	cout << left << "\tFirst Name: " << setw(5) << firstName;
	cout << left << "\tLast Name: " << setw(5) << lastName;
	cout << left << "\tEmail: " << setw(5) << eMail;
	cout << left << "\tAge: " << setw(5) << age;
	cout << left << "\tDays In Course: {" << daysComplete[0] << ", ";
	cout << left << daysComplete[1] << ", ";
	cout << left << daysComplete[2] << "} " << setw(5);
	
	cout << "\tDegree Program: ";

	switch (program) {
	case SECURITY:
		cout << "SECURITY";
		break;
	case NETWORK:
		cout << "NETWORK";
		break;
	case SOFTWARE:
		cout << "SOFTWARE";
		break;
	case UNKNOWN:
		cout << "UNKNOWN";
		break;
	}
	cout << endl;
	return;
}

Student::~Student() {

};