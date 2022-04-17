#pragma once
#include "roster.h"

/**Default Construstor
@param int size of class hard coded to 5
@return Roster object pointer
*/
Roster::Roster() :classSize(5) {
	//intialize class roster array with null pointers
	this->classRosterArray = {};
	for (Student* p : this->classRosterArray) p = nullptr;
	//output to confirm successful creation
	std::cout << "New Class Roster Created Successfully!!" << std::endl;
};
/**Destructor
@param none 
@return void but will output start and finish of function
*/
Roster::~Roster() {
	//indicate beginning of function call
	std::cout << "Roster Object Destruction Started:" << std::endl;
	//iterate over roster array and call delete function on all live Student objects in array avoiding null pointers
	for (Student* p : this->classRosterArray) if (p != nullptr) { delete p; }
	//indicate end of function call
	std::cout << "Roster object destroyed" << std::endl;
};

//Private Member Functions
/** 
Private Function to determine next open array position
@param none
@return int containing index of open position in array or -1 if fails to find open position
*/
int Roster::findNextAvailableIndex() {
	//variable to return index defaults to -1 if fails to find open postion in array
	int matchIndex = -1;
	//itereate over array attempting to find a null pointer and assign its index to the return variable
	for (int i = 0; i < classRosterArray.size(); i++) {
		if (classRosterArray[i] == nullptr) {
			return matchIndex = i;
		};
	};
	return matchIndex;
};
/**
Find student in class raoster array by studentID
@param string student ID
@return student pointer of matching student or null pointer if no match
*/
Student* Roster::getStudentByID(std::string student_ID) {
	//assigns return variable to default to null pointer
	Student* aStudent = nullptr;
	//iterate roster array and assign matching pointer to return variable
	for (Student* sp : classRosterArray) {
		if ((sp != nullptr) && (sp->getStudentID() == student_ID)) {
			return sp;
		};
	};
	return aStudent; //return null pointer if search fails
};
/**
Function to get student pointer for object at index provided
@param int index of pointer requested
@return stundent object pointer
*/
Student* Roster::getStudentByIndex(int index) {
	return this->classRosterArray[index];
};


//Public Member Functions
/**
Accessor function for array size
@return int of size 
*/
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
	//assign default value of failure to output string variable
	std::string success = "No Available Slots on Class Roster!!";
	//variable to store index of next available array position
	int index = findNextAvailableIndex();
	//verify array position was found
	if (index != -1) {
		//assign new student pointer to open position
		classRosterArray[index] = newStudent;
		//verify succesful assignment
		success = classRosterArray[index]->getStudentID() == studentID ? "Student Sucessfully Added to Roster!!" :
			"Failed to Add Student to Roster!!";
	};
	std::cout << success << std::endl; //return status string
};
/**
Overloaded function to assign student pointer to array position indicated
@param student pointer
@param int index of array positon to assign new pointer 
*/
void Roster::add(Student* sPtr, int index) {
	classRosterArray[index] = sPtr;
};
/**
* When provide with a student ID will remove object from class roster array and assign a null ptr
* @param string studnet ID
* @return void but function will indicate with console output success or failure
*/
void Roster::remove(std::string studentToDel) {
	std::cout << "\n\r" << std::endl; // formatting for readable output
	//default output string of failure message
	std::string success = "Operation Failed: Student with this ID Not Found!!"; //Default string
	int indexOfStudent = -1; //assign negative value to index for verification of successful operation
	//iterate over array to find matching student object by student ID
	for (int i = 0; i < classRosterArray.size(); i++) {
		if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID() == studentToDel)) {
			indexOfStudent = i; //if succeeds assign index to results variable
			delete classRosterArray[i]; //send delete function to existing student object
			classRosterArray[i] = nullptr; //assign null pointer as place holder
			//update output string dependent of success od operation
			success = (classRosterArray[indexOfStudent] == nullptr) ? "Student Sucessfully Removed from Roster!!" :
				"Failed to Remove Student from Roster!!";
			break;
		};
	};
	std::cout << success << "\n\r" << std::endl; //output to console results of operation	
};
/**
Function that iterates over current class roster and outputs to console tab-delimited student data for student object
@param implicit this roster object
@return void but formatted console output will follow
*/
void Roster::printAll() {
	std::cout << "\n\r\n\r" << "Class Roster Information:" << "\n\r" << std::endl; //formattinmg
	for (Student* sPtr : this->classRosterArray) { //iterate array
		if (sPtr == nullptr) {  //validate live student object
			continue;
		}
		else { sPtr->print(); }; //call student print function 
	};
};
/**
Print formatted student inforamtion indluding full name and corresponding 
average class length for student with the indicated student ID
@param string student ID
@return void - output is sent to console
*/
void Roster::printAverageDaysInCourse(std::string studentID) {
	//assign appropriate student pointer to variable by funciton call
	Student* thisStud = getStudentByID(studentID); 
	int avgDaysInCOurse = 0; //initialize output variable
	if (thisStud != nullptr) { //validate student object pointer
		//send formatted results to the console for display
		std::cout << thisStud->getFirstName() << " " << thisStud->getLastName() <<
			" is " << thisStud->avgClassLength() << "." << std::endl;
	};
};
/**
Retrieve and output to console all students who have invalid emails in the class roster
@param implicit this roster object
@return void - outputs to results console 
*/
void Roster::printInvalidEmails() {
	std::cout << "\n\r\n\r" << "The following students in this class roster have invalid emails:" << "\n\r" << std::endl; //formatting
	int count = 0; //running count of emails return
	for (Student* sPtr : classRosterArray) { //interate class roster
		if (!Student::hasValidEmailAddress(sPtr->getEmail())) { //determine if email is invalid
			count++; //increment count if email is invalid
			std::cout << "Student: " << sPtr->getFirstName() << " " << sPtr->getLastName() <<
				"\t Email: " << sPtr->getEmail() << std::endl; //output results if inva;id
		};
	};
	if (count == 0) {
		std::cout << "There are no invalid emails on this class roster" << std::endl; //default out if no results found
	};
};
/**
Retrieve and output students with the desired degree program
@param enum class DegreeProgram indicating desired program
@result void - results output to console
*/
void Roster::printByDegreeProgram(DegreeProgram prog) {
	std::cout << "\n\r\n\r" << "Students in the " << Student::enumToString(prog) << 
		" program are as follows:" << "\n\r" << std::endl; //formatting
	for (Student* sPtr : this->classRosterArray) { //interate roster 
		if (sPtr->getProgram() == prog) { //determine if matches
			std::cout << "Student: " << sPtr->getFirstName() << " " << sPtr->getLastName() <<
				"\tProgram: " << Student::enumToString(sPtr->getProgram()) << std::endl; //outpout formatted results if match
		};
	};
};


//Static Functions
/**
 To parse the student data strings in individual pieces of useable data in a string vector
 @param string that you wish to slice
 @param string that is the delimiter
 @return the vector<size 9> of separate strings
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
	};
	outputArray[arrIndex] = stringToSlice.substr(indexStart); //place the rest of the string in the array after all delimiters are gone
	return outputArray;
};
/**
	Create student instance from student vector<std::string>
	@param vector<size 9> of student information in string format
	@return student object
*/
Student* Roster::createStudentFromArray(std::array<std::string, 9>& studentArray) {
	//Create new student object out of stundent data string
	Student* newStudent = new Student(studentArray[0], studentArray[1], studentArray[2],
		studentArray[3], std::stoi(studentArray[4]), std::stoi(studentArray[5]), std::stoi(studentArray[6]),
		std::stoi(studentArray[7]), Student::programStringToEnum(studentArray[8]));
	return newStudent;
}