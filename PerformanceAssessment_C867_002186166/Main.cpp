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
/**
Reusable function to display project details in the console
@param string course title
@param string program language 
@param string school name
@param string student ID
@param string developer name
@param sting email
@return void - output is sent to console
*/
void printProjectDetails(std::string courseTitle, std::string progLang, std::string school,
    std::string ID, std::string devName, std::string email) {
    //build and output formatted string with project details
    std::cout << "This project is for " << courseTitle << " at " << school << "." << std::endl <<
        "The solution is implemented in the " << progLang << " programming language by " << 
        devName << std::endl << "Student ID: " << ID << " EMail: " << email << "\n\r\n\r" << std::endl;
}

int main()
{
    //Project Details
    std::string course = "Scripting and Programming - Applications - C867";
    std::string lang = "C++";
    std::string school = "Western Governor's University";
    std::string name = "Louis Casinelli Jr";
    std::string ID = "002186166";
    std::string email = "lcasine@wgu.edu";

    //Print Project Details to Console
    printProjectDetails(course, lang, school, ID, name, email );
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
   //Initialize a New Roster Object to Hold the Student Data Table
    Roster* myClassRoster = new Roster;
    //Populate Roster with student pointers from the Student Data Table Array
    for (int i = 0; i < myClassRoster->getClassSize(); i++) {
        std::array<std::string, 9> tempArray = Roster::parseStudentDataByDelimiter(studentData[i], d);
        Student* tempStudent = Roster::createStudentFromArray(tempArray);
        myClassRoster->add(tempStudent, i );
    };
    //Print Current State of Roster
    myClassRoster->printAll();
    //Display Invalid Emails
    myClassRoster->printInvalidEmails();
    //Output average class length by student ID using the current object to retrieve the student ID
    std::cout << "\n\r\n\r" << "The average length per course for the following students is:" << "\n\r" << std::endl;
    for (int i = 0; i < 5; ++i) {
        myClassRoster->printAverageDaysInCourse((myClassRoster->getStudentByIndex(i))->getStudentID());
    };
    //Print Students in Roster with the Desired Degree Program
    myClassRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    //Remove Selected Student From Roster by StudentID
    myClassRoster->remove("A3");
    //Verify Removal
    myClassRoster->printAll();
    //Show Double Delete Not Possible
    myClassRoster->remove("A3");
    //release memory
    delete myClassRoster;
};


