/*********************************************************************************************
Programmer: Devin Moore
Date:       2021/04/06
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA7: Attendance Tracker w/ Class Templates

Description: Contains the function definitions and constructors/destructor for the Data class
*********************************************************************************************/
#include "Data.h"
#include <iostream>
#include <string>

// Default constructor
Data::Data(int newRecord, int newId, std::string newName, std::string newEmail, int newUnits, std::string newProgram, std::string newLevel, int newTotalAbsences)
{
	mRecordNumber = newRecord;
	mIdNumber = newId;
	mName = newName;
	mEmail = newEmail;
	mUnits = newUnits;
	mProgram = newProgram;
	mLevel = newLevel;

	mTotalAbsences = newTotalAbsences;
	mpAbsenceList = new Stack;
}

// Copy constructor
Data::Data(const Data& copy)
{
	mRecordNumber = copy.getRecordNumber();
	mIdNumber = copy.getIdNumber();
	mName = copy.getName();
	mEmail = copy.getEmail();
	mUnits = copy.getUnits();
	mProgram = copy.getProgram();
	mLevel = copy.getLevel();
	mTotalAbsences = copy.getTotalAbsences();

	if (mpAbsenceList == nullptr)
	{
		mpAbsenceList = new Stack;
	}
	mpAbsenceList->getStack() = copy.getStackPtr()->getStack(); // Set vecot arrays equal to eachother
}

// Destructor
Data::~Data()
{
	// boop
	// std::cout << "Hit Data class destructor...." << std::endl << "Deleting list...." << std::endl;
	delete mpAbsenceList; // Clearing memory
}

// Copy assignement operator overload
Data& Data::operator=(const Data& rhs)
{
	if (&rhs != this)
	{
		mRecordNumber = rhs.getRecordNumber();
		mIdNumber = rhs.getIdNumber();
		mName = rhs.getName();
		mEmail = rhs.getEmail();
		mUnits = rhs.getUnits();
		mProgram = rhs.getProgram();
		mLevel = rhs.getLevel();

		mTotalAbsences = rhs.getTotalAbsences();
		
		mpAbsenceList->getStack() = rhs.getStackPtr()->getStack(); // Vector arrays have an overloaded copy assignment operator and will copy it over all nice like
	}
	return *this;
}


// Getters and Setters
int Data::getRecordNumber(void) const
{
	return mRecordNumber;
}

int Data::getIdNumber(void) const
{
	return mIdNumber;
}

std::string Data::getName(void) const
{
	return mName;
}

std::string Data::getEmail(void) const
{
	return mEmail;
}

std::string Data::getUnits(void) const
{
	return mUnits;
}

std::string Data::getProgram(void) const
{
	return mProgram;
}

std::string Data::getLevel(void) const
{
	return mLevel;
}

int Data::getTotalAbsences(void) const
{
	return mTotalAbsences;
}

Stack* Data::getStackPtr(void) const
{
	return mpAbsenceList;
}

//Setters
void Data::setRecordNumber(const int& newNum)
{
	mRecordNumber = newNum;
}

void Data::setIdNubmer(const int& newNum)
{
	mIdNumber = newNum;
}

void Data::setName(const std::string& newName)
{
	mName = newName;
}

void Data::setEmail(const std::string& newEmail)
{
	mEmail = newEmail;
}

void Data::setUnits(const std::string& newUnitAmount)
{
	mUnits = newUnitAmount;
}

void Data::setProgram(const std::string& newProg)
{
	mProgram = newProg;
}

void Data::setLevel(const std::string& newLevel)
{
	mLevel = newLevel;
}

void Data::setTotalAbsences(const int& newTotal)
{
	mTotalAbsences = newTotal;
}

void Data::setStackPtr(Stack*& newPtr)
{
	mpAbsenceList = newPtr;
}

// Overloaded Ostream an fstream operators
std::ostream& operator<<(std::ostream& oStream, const Data& rhs)
{
	oStream << "Record Number: " << rhs.getRecordNumber() << std::endl
		<< "ID Number: " << rhs.getIdNumber() << std::endl
		<< "Name: " << rhs.getName() << std::endl
		<< "Email: " << rhs.getEmail() << std::endl
		<< "Units: " << rhs.getUnits() << std::endl
		<< "Program: " << rhs.getProgram() << std::endl
		<< "Level: " << rhs.getLevel();

	return oStream;
}

// Precondition: Header line has been taken in file, otherwise there's going to be a junk node
std::fstream& operator>>(std::fstream& iStream, Data& rhs) // Order of file data: record,ID,Name,Email,Units,Program,Level

{
	std::string tempString = "";
	std::getline(iStream, tempString, ',');
	
	// So .find('\n') will look for the first occurence of that character, if it doesn't find it, it will return std::string::npos.
	// had to look this function and the return up to know what it was and how it worked so I could prevent any newlines breaking the code
	if (tempString.find('\n') != std::string::npos || tempString == "") 
	{
		// if we found any newlines we want to break out of function
		return iStream;
	}

	rhs.setRecordNumber(std::stoi(tempString));

	std::getline(iStream, tempString, ',');
	rhs.setIdNubmer(std::stoi(tempString));

	std::getline(iStream, tempString, '"');
	std::getline(iStream, tempString, '"');

	rhs.setName(tempString);

	std::getline(iStream, tempString, ',');
	std::getline(iStream, tempString, ',');
	rhs.setEmail(tempString);
	std::getline(iStream, tempString, ',');
	rhs.setUnits(tempString);
	std::getline(iStream, tempString, ',');
	rhs.setProgram(tempString);
	std::getline(iStream, tempString);
	rhs.setLevel(tempString);
	
	return iStream;
}

/*
* Function: countAndSetAbsences()
* Date Created: 2021/04/06
* Last Modified: 2021/04/06
* Description: Sets mTotalAbsences after cheking the number of elements in the vector array
* Input Parameters: NONE
* Returns: NONE
* Precondition:	NONE
* Postcondition: Number of absences set to mTotalAbsences
*/
void Data::countAndSetAbsences(void)
{
	mTotalAbsences = mpAbsenceList->getStackCount();
}