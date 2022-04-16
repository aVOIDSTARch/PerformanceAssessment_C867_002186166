#pragma once

#include "student.h"
#include <format>
#include <regex>

//Default Construtor with no data degree is unknown and age is -1 
Student::Student() :studentID(""), firstName(""), lastName(""),
emailAddress(""), age(-1), degreeProgram(DegreeProgram::UNKNOWN) {
	Student::setDaysToCompleteThreeClasses( 0,0,0 );
	std::cout << "Student Construction Complete.";
};

//Constructer with all parameters using array for class lengths
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
	int age, std::array<int, 3> daysForClasses, DegreeProgram degProgram) 
	:studentID(studentID), firstName(firstName), lastName(lastName),
	emailAddress(emailAddress), age(age), degreeProgram(degProgram) {
	Student::setDaysToCompleteThreeClasses(daysForClasses);
	std::cout << "Student Construction Complete.";
};

//Constructer with all parameters using individual ints for class lengths
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
	int age, int daysForClass1, int daysForClass2, int daysForClass3, DegreeProgram degProgram)
	:studentID(studentID), firstName(firstName), lastName(lastName),
	emailAddress(emailAddress), age(age), degreeProgram(degProgram) {
	Student::setDaysToCompleteThreeClasses(daysForClass1, daysForClass2, daysForClass3);
	std::cout << "Student Construction Complete.";
};

//Copy Constructor
//Student::Student(const Student &s) :studentID(s.studentID), firstName(s.firstName), lastName(s.lastName),
//emailAddress(s.emailAddress), age(s.age), degreeProgram(s.degreeProgram) {
//	this->Student::setDaysToCompleteThreeClasses(s.daysToCompleteThreeClasses[0], s.daysToCompleteThreeClasses[1],
//		s.daysToCompleteThreeClasses[2]);
//};

//Destructor
Student::~Student() {
	std::cout << "Student Destruction Complete.";
};

//Mutators - public access to mutate member variables
void Student::setStudentID(const std::string student_ID){ this->studentID = student_ID; };
void Student::setFirstName(const std::string fName){ this->firstName = fName; };
void Student::setLastName(const std::string lName){ this->lastName = lName; };
void Student::setEmailAddress(const std::string email){ this->emailAddress = email; };
void Student::setAge(const int age){ this->age = age; };
void Student::setDaysToCompleteThreeClasses(const int class1, const int class2, const int class3){
	this->daysToCompleteThreeClasses = { class1, class2, class3 };};
void Student::setDaysToCompleteThreeClasses(const std::array<int, 3> classLengthsInDays){
	this->daysToCompleteThreeClasses = { classLengthsInDays[0], classLengthsInDays[1], classLengthsInDays[2] };};
void Student::setDegreeProgram(const DegreeProgram program) { this->degreeProgram; };


//Accessors - public access to value of state variables
std::string Student::getStudentID() { return this->studentID; };
std::string Student::getFirstName() { return this->firstName; };
std::string Student::getLastName() { return this->lastName; };
std::string Student::getEmail() { return this->emailAddress; };
int Student::getAge() { return this->age; };
int Student::getTimeToCompleteClassAtIndex(int index) {
	return this->daysToCompleteThreeClasses[index];};
DegreeProgram Student::getProgram() { return this->degreeProgram; };

//Public Member Functions

/**
Print tab delimited studenbt object state to console using 
C++ 20 specific string formatter
@param implicit this
@retrun void
*/
void Student::printC20() { 
	std::cout << createFormatedStudentData(*this) << std::endl;
	};
/**
Print tab delimited student object state to console using more
compatible cout statement format
@param implicit this student pointer
@return void all output to console
*/
void Student::print() {
	std::cout << this->getStudentID() << "\t" <<
		"First Name: " << this->getFirstName() << "\t" <<
		"Last Name: " << this->getLastName() << "\t" <<
		"Age: " << this->getAge() << "\t" <<
		"Days In Courses: { " << this->getTimeToCompleteClassAtIndex(0) << " , " <<
		this->getTimeToCompleteClassAtIndex(1) << " , " <<
		this->getTimeToCompleteClassAtIndex(2) << " }" << "\t" <<
		"Degree Program: " << enumToString(this->getProgram()) << std::endl;
};

/**
Calculate the average time it took student to complete a class
@param implicit this
@return integer of average class length in days 
*/
int Student::avgClassLength(){ 
	int tempTotalLen = 0;

	for (int i : this->daysToCompleteThreeClasses) tempTotalLen += i; //iterate over array to get total

	return tempTotalLen / 3; //return average
};

//Static Functions

/**
* FOR C++20 or later
Takes student object and creates string representing the state for output to console
@param student object
@return string conprised of internal state data for student formatted with tab delimiters as required
*/
std::string Student::createFormatedStudentData(Student s) {
	//create properly formated string for output to console
	std::string formattedStr = std::format("{}\tFirst Name: {}\tLast Name: {}\tEmail: {}\tAge: {}\tdaysInCourse: {}, {}, {}\tDegree Program: {}",
		s.getStudentID(), s.getFirstName(), s.getLastName(), s.getEmail(), std::to_string(s.getAge()),  
		std::to_string(s.getTimeToCompleteClassAtIndex(0)), std::to_string(s.getTimeToCompleteClassAtIndex(1)),
		std::to_string(s.getTimeToCompleteClassAtIndex(2)), Student::enumToString(s.getProgram()));

	return formattedStr;
};

/**
Convert an enum of type DegreeProgam to a string
@param DegreeProgram enum 
@return string of the same name as enum variable
*/
std::string Student::enumToString(DegreeProgram d) {
	std::string stringFromEnum;

	//switch to assign string from enum class of type DegreeProgram
	switch (d) {
	case DegreeProgram::SECURITY:
		stringFromEnum = "SECURITY";
		break;
	case DegreeProgram::NETWORK:
		stringFromEnum = "NETWORK";
		break;
	case DegreeProgram::SOFTWARE:
		stringFromEnum = "SOFTWARE";
		break;
	default:
		stringFromEnum = "UNKNOWN";
		break;
	}

	return stringFromEnum;
};

/**
Convert string variable containing a degree program to an enumerated 
variable of type DegreeProgram
@param string in all capital letters of the degree program
@return enum variable of teh DegreeProgram type with the corresponding name
*/
DegreeProgram Student::programStringToEnum(std::string program) {
	DegreeProgram programEnum;
	std::string security = "SECURITY";
	std::string network = "NETWORK";
	std::string software = "SOFTWARE";
	

	//conditional to assign an enum class of type DegreeProgram to the mathcing string of text
	if (program == security) {
		programEnum = DegreeProgram::SECURITY;
	}
	else if (program == network) {
		programEnum = DegreeProgram::NETWORK;
	}
	else if (program == software) {
		programEnum = DegreeProgram::SOFTWARE;
	}
	else {
		programEnum = DegreeProgram::UNKNOWN; //assigns a default of unknown for error case 
	};

	return programEnum;
};

/**
Determine if email is in a valid format
@param string of email
@return bool true if valid false if invalid
*/
bool Student::hasValidEmailAddress(std::string email) {
	const std::regex pattern("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+[.][A-Za-z]{2,}$");
	return std::regex_match(email, pattern);
};