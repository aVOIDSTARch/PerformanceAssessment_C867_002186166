#pragma once

#include <iostream>
#include "degree.h"
#include <string>
#include <array>


class Student {
private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	std::array<int, 3> daysToCompleteThreeClasses;
	DegreeProgram degreeProgram;
	
public:
	//Default Construtor - no inputs
	Student();
	//Constructer with all parameters using array for class lengths
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
		int age, std::array<int, 3> &daysForClasses, DegreeProgram degProgram);
	//Constructor with all parameters using individual ints for each class length
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
		int age, int daysForClass1, int daysForClass2, int daysForClass3, DegreeProgram degProgram);
	//Destructor
	~Student();

	//Mutators
	void setStudentID(std::string student_ID);
	void setFirstName(std::string fName);
	void setLastName(std::string lName);
	void setEmailAddress(std::string email);
	void setAge(int age);
	void setDaysToCompleteThreeClasses(int class1, int class2, int class3);
	void setDaysToCompleteThreeClasses(std::array<int, 3>);
	void setDegreeProgram(DegreeProgram program);

	//Accessors
	std::string getStudentID();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmail();
	int getAge();
	int getTimeToCompleteClassAtIndex(int index);
	DegreeProgram getProgram();

	//Member Functions
	void print();
	int avgClassLength();

	//Static Functions
	static DegreeProgram programStringToEnum(std::string program);
	static std::string enumToString(DegreeProgram d);
	static bool hasValidEmailAddress(std::string email);
};
