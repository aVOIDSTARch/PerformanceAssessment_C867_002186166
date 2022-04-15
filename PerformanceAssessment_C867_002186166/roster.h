#pragma once

#include <iostream>
#include <string>
#include "Student.h"
#include "degree.h"
#include <array>

class Roster {
private:
	std::array<Student*, 5> classRosterArray;
	int findFirstEmpty
public:
	Roster();
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
};