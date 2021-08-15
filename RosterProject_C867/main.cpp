/* RosterProject_C867.cpp : This file contains the 'main' function. Program execution begins and ends there.
*/

/*B.Create a C++ project in your integrated development environment(IDE) with the following files : main.cpp*/

#include <iostream>
#include <string>

#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;


int main()
{
    /*A.  Modify the “studentData Table” to include your personal information as the last item.*/
    const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Wen,Yu,wyu4@wgu.edu,31,10,20,32,SOFTWARE"
    };

    /*F1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.*/
    cout << "C867: Scripting and Programming Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 001109626" << endl;
    cout << "Name: Wen Yu" << endl;
    cout << endl;

    /*2.  Create an instance of the Roster class called classRoster.*/
    Roster* classRoster = new Roster(studentData, 5, 20);

    /*classRoster.printAll();*/
    cout << "Print all students: " << endl;
    classRoster->printAll();
    cout << endl;


    /*loop through classRosterArray and for each element: classRoster.printAverageDaysInCourse*/
    cout << "Average number of days spent in courses: " << endl;
    classRoster->printAverageDaysInCourse("A1");
    classRoster->printAverageDaysInCourse("A2");
    classRoster->printAverageDaysInCourse("A3");
    classRoster->printAverageDaysInCourse("A4");
    classRoster->printAverageDaysInCourse("A5");
    cout << endl;

    /*classRoster.remove("A3");*/
    classRoster->remove("A3");

    /*classRoster.printAll(); second time*/ 
    classRoster->printAll();

    /*classRoster.remove("A3"); second time*/
    classRoster->remove("A3");
    cout << endl;
    //expected: the above line should print a message saying such a student with this ID was not found.

    /*classRoster.printInvalidEmails();*/;
    cout << "Print invalid emails:" << endl;
    classRoster->printInvalidEmails();
    cout << endl;

    /*classRoster.printByDegreeProgram;*/
    cout << "Print roster by SOFTWARE program: " << endl;
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl << "Print roster by NETWORK program:" << endl;
    classRoster->printByDegreeProgram(NETWORK);
    cout << endl << "Print roster by SECURITY program:" << endl;
    classRoster->printByDegreeProgram(SECURITY);
    cout << endl << endl;




    /*return 0;*/
}


