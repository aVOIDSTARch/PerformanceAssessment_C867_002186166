#pragma once

#include "roster.h"

//Default Construstor
Roster::Roster() {
	Student* nPtr;
	Student emptyStudent;
	nPtr = &emptyStudent;
	this->classRosterArray = {};
	for (Student* p : this->classRosterArray) p = nPtr;
};


void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

};
void Roster::remove(std::string studentID) {

};
void Roster::printAll() {

};
void Roster::printAverageDaysInCourse(std::string studentID) {

};
void Roster::printInvalidEmails() {

};