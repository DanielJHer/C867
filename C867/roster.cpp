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

// finding student ID through index
string Roster::GetStudentID(int ind) {
    string sID = classRosterArray[ind]->getStudentID();
    return sID;
}

// parse method
void Roster::parse(string studentData) {
    string sID, firstName, lastName, emailAddress;
    int studentAge, daysInCourse1, daysInCourse2, daysInCourse3;
    
    if (ind < classSize) {
        
        classRosterArray[ind] = new Student();
        
        long i = studentData.find(",");
        sID = studentData.substr(0, i);
        classRosterArray[ind]-> setID(sID);
        
        long j = i + 1;
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

// adding student object in roster class
void Roster::add(string studentID, string firstName, string lastName, string email, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

    int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    classRosterArray[classSize] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeprogram);
};

// removing student object in roster class
void Roster::remove(string id) {

    bool foundStudent = false;
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i] == nullptr) {
            continue;
        }
        else if (id == classRosterArray[i]->getStudentID()) {
            classRosterArray[i] = nullptr;
            foundStudent = true;
            break;
        }
    }
    if (foundStudent == false) {
        cout << "Error: Student " << id << " Not Found." << endl;
    }
    else if (foundStudent == true) {
        cout << "Student " << id << " removed." << endl;
    }
    return;
}

// printing all student objects
void Roster::printAll() {
    cout << "All Students: " << endl;
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i] == nullptr) {
            continue;
        } else {
            classRosterArray[i]->print();
        }
    }
    return;
}

// printing the average number of days for courses
void Roster::printAverageDaysInCourse(string id) {
    for (int i = 0; i < classSize; i++) {
        if (id == classRosterArray[i]->getStudentID()) {
                cout << id << "'s average days in course: " <<
                    ((classRosterArray[i]->getDaysInCourse()[0] +
                        classRosterArray[i]->getDaysInCourse()[1] +
                        classRosterArray[i]->getDaysInCourse()[2]) / 3)
                    << endl;
        }
    }
    return;
}

// printing invalid emails from roster
void Roster::printInvalidEmails() {
    for (int i = 0; i < classSize; ++i) {
        string emailAd = classRosterArray[i]->getEmailAddress();
        if ((emailAd.find('@') == string::npos) || (emailAd.find(' ') != string::npos) || (emailAd.find('.') == string::npos)) {
            cout<< "Invalid Email Address: " << emailAd << endl;
        }
    }
    return;
}

// printing by specific degree program
void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
    string degreeString;
    if (degreeprogram == SECURITY) {
        degreeString = "SECURITY";
    } else if (degreeprogram == NETWORK) {
        degreeString = "NETWORK";
    } else if (degreeprogram == SOFTWARE) {
        degreeString = "SOFTWARE";
    } else if (degreeprogram == NOTHING) {
        degreeString = "NOTHING";
    } else {
        degreeString = "ERROR";
    }
    
    cout << "Student(s) with degree program: " << degreeString << endl;
    int numStudents = 0;
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeprogram) {
            classRosterArray[i]->print();
            ++numStudents;
        }
    }
    
    if (numStudents == 0) {
        cout << "ERROR" << endl;
    }
    return;
}

// destructor that releases memory for Roster
Roster::~Roster() {
    for (int i = 0; i < 5; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    };

    
}
