//  roster.cpp
#include <iostream>
#include <array>
#include <string>

#include "degree.h"
#include "student.hpp"
#include "roster.hpp"

using namespace std;

// class constructor
Roster::Roster(int classSize) {
    this->classSize = classSize;
    this->ind = 0;
    for (int i = 0; i < classSize; i++) {
        this->classRosterArray[i] = new Student;
    }
    return;
}

string Roster::GetStudentID(<#int index#>) {
    string sID = classRosterArray[ind]->getStudentID();
    return sID;
}

// parse method

void Roster::parse(string studentData) {
    string sID, firstName, lastName, emailAddress;
    int studentAge, daysInCourse1, daysInCourse2, daysInCourse3;
    
    if (ind < classSize) {
        
        classRosterArray[ind] = new Student();
        
        int i = studentData.find(",");
        sID = studentData.substr(0, i);
        classRosterArray[ind]-> setID(sID);
        
        int j = i + 1;
        i = studentData.find(",", j);
        firstName = studentData.substr(j, i-j);
        classRosterArray[ind]->setFirstName(firstName);
        
        j = i + 1;
        i = studentData.find(",", j);
        lastName = studentData.substr(j, i-j);
        classRosterArray[ind]->setLastName(lastName);
        
        j = i + 1;
        i = studentData.find(",", j);
        emailAddress = studentData.substr(j, i-j);
        classRosterArray[ind]->setEmailAddress(emailAddress);
        
        j = i + 1;
        i = studentData.find(",", j);
        studentAge = stoi(studentData.substr(j, i - j));
        classRosterArray[ind]->setAge(studentAge);
        
        j = i + 1;
        i = studentData.find(",", j);
        daysInCourse1 = stoi(studentData.substr(j, i - j));

        j = i + 1;
        i = studentData.find(",", j);
        daysInCourse2 = stoi(studentData.substr(j, i - j));

        j = i + 1;
        i = studentData.find(",", j);
        daysInCourse3 = stoi(studentData.substr(j, i - j));
        
        classRosterArray[ind]->setDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);

        j = i + 1;
        i = studentData.find(",", j);
        string type = studentData.substr(j, i - j);
        if (type == "SOFTWARE") {
            classRosterArray[ind]->setDegreeProgram(SOFTWARE);
        } else if (type == "SECURITY") {
            classRosterArray[ind]->setDegreeProgram(SECURITY);
        } else if (type == "NETWORK") {
            classRosterArray[ind]->setDegreeProgram(NETWORK);
        } else if (type == "NOTHING") {
            classRosterArray[ind]->setDegreeProgram(NOTHING);
        } else {
            cout << "NO DEGREE FOUND" << endl;
        }

        ind++;
    }
    return;
};

void Roster::add(<#string studentID#>, string firstName, <#string lastName#>, <#string email#>Address, <#int studentAge#>, <#int daysInCourse1#>, <#int daysInCourse2#>, <#int daysInCourse3#>, DegreeProgram degreeProgram) {
    int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[classSize] = new Student(studentID, firstName, lastName, emailAddress, studentAge, daysInCourse, degreeProgram);
};
