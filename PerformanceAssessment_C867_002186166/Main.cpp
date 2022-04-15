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
#include <string>
#include <vector>
#include <sstream>
#include <format>
#include "Student.h"

/**
 To parse the student data strings in individual pieces of useable data in a string vector
 @param string that you wish to slice
 @param string that is the delimiter
 @return the vector of separate strings
*/
std::vector<std::string> parseStudentDataToVector(std::string stringToSlice, const std::string delim) {
    std::size_t indexStart = 0; //start position for search and substring extraction
    std::size_t indexEnd; //position of delimiter in current search
    std::size_t delimSize = delim.length(); //size of delimiter used to traverse for new substring start
    std::string tempString; //stores extracted substring 
    std::vector<std::string> outputVector; //vector that is returned by function

    while ((indexEnd = stringToSlice.find(delim, indexStart)) != std::string::npos) { // while there is a delimiter in the remaining characters
        tempString = stringToSlice.substr(indexStart, indexEnd - indexStart); //slice substring 
        indexStart = indexEnd + delimSize; //move start index to the other side of the delimiter
        outputVector.push_back(tempString); //place tempString in next vector starage
    }

    outputVector.push_back(stringToSlice.substr(indexStart)); //place the rest of the string in the vector after all delimiters are gone

    return outputVector; 
};

/**
    Create student instance from student vector<std::string>
    @param vector of student information in string format
    @return student object
*/

Student createStudentFromVector(const std::vector<std::string>& studVector) {
    //Create new student object out of stundent data string
    Student newStudent = Student::Student(studVector[0], studVector[1], studVector[2],
        studVector[3], std::stoi(studVector[4]), std::stoi(studVector[5]), std::stoi(studVector[6]), 
        std::stoi(studVector[7]), Student::programStringToEnum(studVector[8]));


    return newStudent;
}

int main()
{
    const std::string delimiter = ",";
    const std::string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Louis,Casinelli,lcasine@wgu.edu,45, 7,19,35,SOFTWARE"
    };
    std::vector<std::vector<std::string>> studentDataTable;

    for (std::string s : studentData) {
        std::vector<std::string> temp = parseStudentDataToVector(s, delimiter);
        studentDataTable.push_back(temp);
    };

    Student newStudent1 = createStudentFromVector(studentDataTable[0]);
    Student newStudent2 = createStudentFromVector(studentDataTable[1]);
    Student newStudent3 = createStudentFromVector(studentDataTable[2]); 
    Student newStudent4 = createStudentFromVector(studentDataTable[3]);
    Student newStudent5 = createStudentFromVector(studentDataTable[4]);

    
    
    
    
    
    
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


