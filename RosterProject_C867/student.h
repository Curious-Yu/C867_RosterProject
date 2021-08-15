/*B.Create a C++ project in your integrated development environment(IDE) with the following files : student.h*/

#pragma once
#include "degree.h"
#include <string>
using std::string;

class Student {
	/*D1.Create the class Student*/
private:
	string studentID;
	string firstName;
	string lastName;
	string eMail;
	int age;
	int daysComplete[3];
	DegreeProgram program;

public:

	/*D2d.empty constructor*/
	Student();

	/*D2d.deconstructor*/
	~Student();

	/*D2d.the constructor*/
	Student(string studentID, string firstName, string lastName, string eMail, int age, int daysComplete[], DegreeProgram program);

	/*D2a&c. getter*/
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysComplete();
	DegreeProgram getProgram() const;

	/*D2b&c. setter*/
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string eMail);
	void setAge(int age);
	void setDaysComplete(int daysComplete[]);
	void setProgram(DegreeProgram program);

	/*D2e. print*/
	void print();

};