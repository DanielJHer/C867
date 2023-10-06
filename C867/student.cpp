//  student.cpp
#include <iostream>
#include <string>
#include "student.hpp"
#include "degree.h"
using namespace std;

// default constructor
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < 3; i++) this->daysInCourse[i] = 0;
    this->degreeProgram = DegreeProgram::NOTHING;
};

// parameter constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
    this->degreeProgram = degreeProgram;
}

// accessors
string Student::getStudentID() {
    return this->studentID;
}

string Student::getFirstName() {
    return this->firstName;
}

string Student::getLastName() {
    return this->lastName;
}

string Student::getEmailAddress() {
    return this->emailAddress;
}

int Student::getAge() {
    return this-> age;
}

int* Student::getDaysInCourse() {
    return this->daysInCourse;
}

DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram;
}

// setters
void Student::setID(string ID) {
    this->studentID = ID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[0] = daysInCourse1;
        this->daysInCourse[1] = daysInCourse2;
        this->daysInCourse[2] = daysInCourse3;
    }
}

void Student::setDegreeProgram(DegreeProgram degreeprogram) {
    this->degreeProgram = degreeprogram;
}

// printers
void Student::printID() {
    cout << studentID;
    return;
}

void Student::printFirstName() {
    cout << firstName << endl;
    return;
}

void Student::printLastName() {
    cout << lastName << endl;
    return;
}

void Student::printEmailAddress() {
    cout << emailAddress << endl;
    return;
}

void Student::printDaysToComplete() {
    cout << daysInCourse[0] << "," << daysInCourse[1] << "," <<daysInCourse[2] << endl;
    return;
}

void Student::printDegreeProgram() {
    string degreeString;
    if (degreeProgram == NOTHING) {
        degreeString = "NOTHING";
    } else if (degreeProgram == SECURITY) {
        degreeString = "SECURITY";
    } else if (degreeProgram == NETWORK) {
        degreeString = "NETWORK";
    } else if (degreeProgram == SOFTWARE) {
        degreeString = "SOFTWARE";
    }
    cout << degreeString << endl;
    return;
}

void Student::print(){
    string degreeString;
    if (degreeProgram == NOTHING) {
        degreeString = "NOTHING";
    } else if (degreeProgram == SECURITY) {
        degreeString = "SECURITY";
    } else if (degreeProgram == NETWORK) {
        degreeString = "NETWORK";
    } else if (degreeProgram == SOFTWARE) {
        degreeString = "SOFTWARE";
    } else {
        degreeString = "ERROR";
    }
    
    cout << "Student ID: " << getStudentID() << '\t';
    cout << "First Name: " << getFirstName() << '\t';
    cout << "Last Name: " << getLastName() << '\t';
    cout << "Age: " << getAge() << '\t';
    cout << "Days in courses: " << getDaysInCourse()[0] << "," << getDaysInCourse()[1] << "," << getDaysInCourse()[2] << '\t';
    cout << "Degree Program: " << degreeString << endl;
    return;

}
