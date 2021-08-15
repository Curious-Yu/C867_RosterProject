/*B.Create a C++ project in your integrated development environment(IDE) with the following files : roster.cpp*/

#include "roster.h"
#include "student.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


Roster::Roster(const string studentData[], int sizeofStudentData, int maxCapacity) {
    /* E1. Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”*/
    this->studentCount = sizeofStudentData;
    this->classRosterArray = new Student * [maxCapacity];
    this->maxCapacity = maxCapacity;

    /*E2a. Parse each set of data identified in the “studentData Table.”*/
    int records = 0;
    while (records < sizeofStudentData) {
        /* Vector of string to save tokens*/
        vector <string> tokens;
        /*A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin)*/
        stringstream streamInput(studentData[records]);
        string nextToken;

        while (getline(streamInput, nextToken, ',')) {
            tokens.push_back(nextToken);
        }

        /*convert strings to int*/ 
        int daysToComplete[3] = { std::stoi(tokens[5]), std::stoi(tokens[6]), std::stoi(tokens[7]) };
        int age = std::stoi(tokens[4]);

        /*convert string to enum*/ 
        DegreeProgram program = UNKNOWN;
        if (tokens[8].compare("SECURITY") == 0) {
            program = SECURITY;
        }
        else if (tokens[8].compare("NETWORK") == 0) {
            program = NETWORK;
        }
        else if (tokens[8].compare("SOFTWARE") == 0) {
            program = SOFTWARE;
        }
        else {
            program = UNKNOWN;
        }

        /*E2b.Add each student object to classRosterArray.*/
        classRosterArray[records] = new Student(tokens[0], tokens[1], tokens[2], tokens[3], age, daysToComplete, program);
        records++;
    }
}

/*F5.Implement the destructor to release the memory that was allocated dynamically in Roster.*/
Roster::~Roster() {
    delete[] classRosterArray;
}

/*E3a. public void add*/ 
void Roster::add(string studentID, string firstName, string lastName, string eMail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program) {
    int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[studentCount] = new Student(studentID, firstName, lastName, eMail, age, daysToComplete, program);
    studentCount++;
}


/*E3b. public void remove*/ 
void Roster::remove(string studentID) {
    bool studentIDFound = false;
    for (int i = 0; (i < studentCount) && !studentIDFound; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            classRosterArray[i] = classRosterArray[studentCount - 1];
            --studentCount;
            studentIDFound = true;
        }
    }
    if (studentIDFound) {
        cout << "Student ID " << studentID << " found and removed." << endl;
    }
    else {
        cout << "Error: student ID A3 not found." << endl;
    }
}

/*E3c. public void printAll()*/ 
void Roster::printAll() {
    for (int i = 0; i < studentCount; ++i) {
        classRosterArray[i]->print();
    }
}

/*E3d. public void printAverageDaysInCourse*/ 
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            cout << "Student ID " << classRosterArray[i]->getStudentID() << ": ";
            int* days = classRosterArray[i]->getDaysComplete();
            cout << "Average number of days in courses: " << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
}


/*E3e. public void printInvalidEmails()*/ 
void Roster::printInvalidEmails()
{
    for (int i = 0; i <= studentCount; i++)
    {
        bool any = false;
        string invalidEmail = classRosterArray[i]->getEmail();
        for (int j = 0; j < classRosterArray[i]->getEmail().length(); j++)
        {
            if (invalidEmail[j] == ' ')
            {
                cout << '"' << invalidEmail << '"' << " is an invalid email!\n";
            }
        }
        if (invalidEmail.find("@") == string::npos)
        {
            cout << '"' << classRosterArray[i]->getEmail() << '"' << " is an invalid email!\n";
        }
        else if (invalidEmail.find(".") == string::npos)
        {
            cout << '"' << classRosterArray[i]->getEmail() << '"' << " is an invalid email!\n";
        }
    }
}

/*E3f.  public void printByDegreeProgram*/ 
void Roster::printByDegreeProgram(DegreeProgram program)
{
    for (int i = 0; i <= studentCount; i++)
    {
        if (this->classRosterArray[i]->getProgram() == program)
        {
            this->classRosterArray[i]->print();
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}