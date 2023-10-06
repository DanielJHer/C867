//
//  student.hpp

#ifndef student_hpp
#define student_hpp
#include <stdio.h>
#include <iostream>
#include "degree.h"
using namespace std;
using std::string;
using std::cout;


class Student {
    
private:
    
    // class attributes
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    // parameterless constructor that sets to default values
    Student();
    
    // the constructor using all input variables
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
    
    // accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();
    
    // setters
    void setID (string studentID);
    void setFirstName (string firstName);
    void setLastName (string lastName);
    void setEmailAddress (string emailAddress);
    void setAge (int studentAge);
    void setDaysInCourse (int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram (DegreeProgram degreeProgram);
    
    // printers
    void printID();
    void printFirstName();
    void printLastName();
    void printEmailAddress();
    void printAge();
    void printDaysToComplete();
    void printDegreeProgram();
    void printAll();
    
};

#endif /* student_hpp */
