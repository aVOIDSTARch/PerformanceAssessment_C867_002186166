/**
    Takes an array of student data and creates a class roster of student objects 
    and allows for manipulation and output to console
    @class C867 - Scripting and Programming - Applicaitons 
    @project Performance Assessment
    @file main.cpp
    @author Louis Casinelli
    @studentID 002186166
    @version 1.0 4/12/2022
*/

#include <iostream>
#include "roster.h"


int main()
{
    const std::string d = ","; //delimiter
    //Student Data Table
    std::string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Louis,Casinelli,lcasine@wgu.edu,45,7,19,35,SOFTWARE"
    };
   
    Roster* myClassRoster = new Roster;

    for (int i = 0; i < myClassRoster->getClassSize(); i++) {
        std::array<std::string, 9> tempArray = Roster::parseStudentDataByDelimiter(studentData[i], d);
        Student* tempStudent = Roster::createStudentFromArray(tempArray);
        myClassRoster->add(tempStudent, i );
    };

    myClassRoster->printAll();

    myClassRoster->printInvalidEmails();
    
    


    





};


void projectDetails(std::string courseTitle, std::string progLang, std::string ID, std::string devName) {
    std::cout << "This project is for " << courseTitle << ". " << std::endl <<
};