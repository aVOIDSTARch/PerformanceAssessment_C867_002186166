#pragma once

#include "roster.h"


//Default Construstor
Roster::Roster() :classSize(5) {
	this->classRosterArray = {};
	for (Student* p : this->classRosterArray) p = nullptr;
	std::cout << "New Class Roster Created Successfully!!";
};
//Destructor
Roster::~Roster() {
	for (Student* p : this->classRosterArray) delete p;
};

//Private Member Functions
int Roster::findNextAvailableIndex() {
	int matchIndex = -1;
	for (int i = 0; i < classRosterArray.size(); i++) {
		if ((classRosterArray[i] == nullptr) || (classRosterArray[i]->getStudentID() == "")) {
			return matchIndex = i;
		};
	};
	return matchIndex;
};

Student* Roster::getStudentByID(std::string student_ID) {
	Student* aStudent = nullptr;
	for (Student* sp : classRosterArray) {
		if ((sp != nullptr) && (sp->getStudentID() == student_ID)) {
			return sp;
		};
	};
	return aStudent;
};

Student* Roster::getStudentByIndex(int index) {
	return this->classRosterArray[index];
};


//Public Member Functions
int Roster::getClassSize() { return this->classSize; };
/** Take student data and add a pointer to the new object to the class roster
@param string student ID
@param string first name of student
@param string last name of student
@param string student email address
@param int student age
@param int length in days of first course
@param int length in days of second course
@param int length in days of last course
@param DegreeProgram enum class of the student's degree program
@return void but function will indicate with console output success or failure
*/
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	//create new student object and then pointer from arguments
	Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1,
		daysInCourse2, daysInCourse3, degreeProgram);
	std::string success = "No Available Slots on Class Roster!!";
	int index = findNextAvailableIndex();
	if (index != -1) {
		delete classRosterArray[index];
		classRosterArray[index] = newStudent;
		success = classRosterArray[index]->getStudentID() == studentID ? "Student Sucessfully Added to Roster!!" :
			"Failed to Add Student to Roster!!";
	};
	std::cout << success << std::endl;
};
/***/
void Roster::add(Student* sPtr, int index) {
	classRosterArray[index] = sPtr;
};
/**
* When provide with a student ID will remove object from class roster array and assign a null ptr
* @param string studnet ID
* @return void but function will indicate with console output success or failure
*/
void Roster::remove(std::string studentToDel) {
	std::string success = "Operation Failed!";
	int indexOfStudent = 0;
	for (int i = 0; i < classRosterArray.size() && i != indexOfStudent ; i++) {
		if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID() == studentToDel)) {
			indexOfStudent = i;
			classRosterArray[i] = nullptr;
			break;
		};
	};
	success = (classRosterArray[indexOfStudent] == nullptr) ? "Student Sucessfully Removed from Roster!!" :
		"Failed to Remove Student from Roster!!";
	std::cout << success << std::endl;
		
	
};
/***/
void Roster::printAll() {
	for (Student* sPtr : this->classRosterArray) {
		if (sPtr == nullptr) {
			continue;
		}
		else { sPtr->print(); };
	};
};
/***/
void Roster::printAverageDaysInCourse(std::string studentID) {
	Student* thisStud = getStudentByID(studentID);
	int avgDaysInCOurse = 0;
	if (thisStud != nullptr) {
		std::cout << "The average days spent in one course for " <<
			thisStud->getFirstName() << " " << thisStud->getLastName() <<
			" is " << thisStud->avgClassLength() << "." << std::endl;
	}
};
/***/
void Roster::printInvalidEmails() {

};
/***/
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

};


//Static Functions



/**
 To parse the student data strings in individual pieces of useable data in a string vector
 @param string that you wish to slice
 @param string that is the delimiter
 @return the vector of separate strings
*/
std::array<std::string, 9> Roster::parseStudentDataByDelimiter(std::string stringToSlice, const std::string delim) {
	std::size_t indexStart = 0; //start position for search and substring extraction
	std::size_t indexEnd; //position of delimiter in current search
	std::size_t delimSize = delim.length(); //size of delimiter used to traverse for new substring start
	std::string tempString; //stores extracted substring 
	int arrIndex = 0;
	std::array<std::string, 9> outputArray; //array that is returned by function
		// while there is a delimiter in the remaining characters
		while ((indexEnd = stringToSlice.find(delim, indexStart)) != std::string::npos) {
			tempString = stringToSlice.substr(indexStart, indexEnd - indexStart); //slice substring 
			indexStart = indexEnd + delimSize; //move start index to the other side of the delimiter
			outputArray[arrIndex] = tempString;//place tempString in current array position
			arrIndex++; //increment the position in the array
		}


	outputArray[arrIndex] = stringToSlice.substr(indexStart); //place the rest of the string in the array after all delimiters are gone

	return outputArray;
};

/**
	Create student instance from student vector<std::string>
	@param vector of student information in string format
	@return student object
*/

Student* Roster::createStudentFromArray(std::array<std::string, 9>& studentArray) {
	//Create new student object out of stundent data string
	Student* newStudent = new Student(studentArray[0], studentArray[1], studentArray[2],
		studentArray[3], std::stoi(studentArray[4]), std::stoi(studentArray[5]), std::stoi(studentArray[6]),
		std::stoi(studentArray[7]), Student::programStringToEnum(studentArray[8]));

	return newStudent;

}