/*B.Create a C++ project in your integrated development environment(IDE) with the following files : degree.h*/

#ifndef degree_h
#define degree_h

#pragma once
#include<iostream>
#include<iomanip>
#include<string>

using std::string;


/*C.  Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.*/

enum DegreeProgram {SECURITY, NETWORK, SOFTWARE, UNKNOWN};

static const string degreeProgramStrings[] = { "UNKNOWN", "SECURITY", "NETWORK", "SOFTWARE" };

#endif
