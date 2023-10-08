//  roster.hpp

#ifndef roster_hpp
#define roster_hpp
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include "degree.h"
#include "student.hpp"

using namespace std;


class Roster {
public:
    Student* classRosterArray[5];
    Roster(int classSize);
    string GetStudentID(int index);
    
    //student info is passed through the add method which creates the student object
    void add(string studentID, string firstName, string lastName, string email, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void parse(string studentData);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    int classSize;
    int ind;
    ~Roster();
};

#endif /* roster_hpp */
