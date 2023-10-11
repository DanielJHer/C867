#include <string>
#include <array>
#include <iostream>

#include "student.hpp"
#include "roster.hpp"
#include "degree.h"

using namespace std;

int main() {
    // introductory greeting
    cout << "Scripting and Programming - Applications\n";
    cout << "Written in C++\n";
    cout << "Student ID: 011118163\n";
    cout << "by Daniel Her\n";
    cout << endl;
    
    // array of student data
    const string studentData[] = {
         "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
         "A5,Daniel,Her,dher5@wgu.edu,30,30,60,90,SOFTWARE"
     };
    
    // constructing the roster object and parsing student data
    Roster * classRoster = new Roster(5);
    for (int i = 0; i <5; i++) {
        classRoster->parse(studentData[i]);
    };
    
    // printing all student data
    classRoster->printAll();
    cout << endl;
    
    // printing students with invalid emails
    classRoster->printInvalidEmails();
    cout << endl;
    
    // printing average days in course;
    for (int i = 0; i <5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->GetStudentID(i));
    }
    cout << endl;
    
    // printing student by degree program
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    // removing A3 student
    classRoster->remove("A3");
    cout << endl;
    
    // printing updated student data
    classRoster->printAll();
    cout << endl;
    
    // attempting to remove A3 student again and printing error
    classRoster->remove("A3");
    cout << endl;
    
    // deleting student data
    classRoster->~Roster();
    delete classRoster;
    
}

