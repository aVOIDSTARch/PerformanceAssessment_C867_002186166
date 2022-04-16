#pragma once

#include <iostream>
#include <string>
#include "Student.h"
#include "degree.h"
#include <array>
#include <vector>

class Roster {
private:
	//Private Member Variables
	std::array<Student*, 5> classRosterArray; //array of Student object pointers
	int classSize;
	//Private Member Functions
	int findNextAvailableIndex();
	

public:
	//Default Constructor
	Roster();
	//Destructor
	~Roster();

	//Public Member Functions
	int getClassSize();
	Student* getStudentByID(std::string student_ID);
	Student* getStudentByIndex(int index);
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void add(Student* sPtr, int index);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	
	//Static Functions
	
	static Student* createStudentFromArray(std::array<std::string, 9>& studentArray);
	static std::array<std::string, 9> parseStudentDataByDelimiter(std::string stringToSlice, const std::string delim);
};

