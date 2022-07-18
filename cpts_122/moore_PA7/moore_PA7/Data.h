/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/06
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA7: Attendance Tracker w/ Class Templates

Description: This file containts the Data structure which contains the absence stack, 
			Total days absent, Name, Email, Number of units taken, student ID, record num
*******************************************************************************************/

#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "Stack.h"

class Data
{
public:
	// Default constructor
	Data(int newRecord = 0, int newId = 0, std::string newName = "", std::string newEmail = "",
		  int newUnits = 0, std::string newProgram = "", std::string newLevel = "", int newTotalAbsences = 0);

	// Copy constructor
	Data(const Data& copy);
	// Destructor
	~Data();
	// Copy assignment operator overload
	Data& operator=(const Data& rhs);



	// Getters and Setters
	int getRecordNumber(void) const;
	int getIdNumber(void) const;
	std::string getName(void) const;
	std::string getEmail(void) const;
	std::string getUnits(void) const;
	std::string getProgram(void) const;
	std::string getLevel(void) const;
	int getTotalAbsences(void) const;
	Stack* getStackPtr(void) const;

	void setRecordNumber(const int& newNum);
	void setIdNubmer(const int& newNum);
	void setName(const std::string& newName);
	void setEmail(const std::string& newEmail);
	void setUnits(const std::string& newUnitAmount);
	void setProgram(const std::string& newProg);
	void setLevel(const std::string& newLevel);
	void setTotalAbsences(const int& newTotal);
	void setStackPtr(Stack*& newPtr);

	// Overloaded Ostream an fstream operators
	friend std::ostream& operator<<(std::ostream& oStream, const Data& rhs);
	friend std::fstream& operator>>(std::fstream& iStream, Data& rhs);

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
	void countAndSetAbsences(void);

private:
	int mRecordNumber;	// 3 digits max
	int mIdNumber;		// 9 digits max
	std::string mName;	// (last,first)
	std::string mEmail;
	std::string mUnits;		// Number of credits total 
	std::string mProgram; // major
	std::string mLevel; // freshmen, sophmore, junior, senior, graduate

	int mTotalAbsences;
	Stack* mpAbsenceList;
};