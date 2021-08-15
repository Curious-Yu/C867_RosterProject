/*B.Create a C++ project in your integrated development environment(IDE) with the following files : roster.h*/

#ifndef roster_h
#define roster_h

#include <stdio.h>
#include <iostream>
#include "student.h"
#include "degree.h"




/*E1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”*/

/*E2.  Create a student object for each student in the data table and populate classRosterArray.
a.  Parse each set of data identified in the “studentData Table.”
b.  Add each student object to classRosterArray.*/

class Roster {
public:
    Roster(const string studentData[], int sizeofStudentData, int maxCapacity);
    ~Roster();
    void ParseId(string data);

    //E3a through f Define the following functions:
    void add(string studentID, string firstName, string lastName, string eMail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram program);

    // assuming that there is a max capacity of students on the roster
private:
    int maxCapacity;
    int studentCount;
    Student ** classRosterArray;
};

#endif
