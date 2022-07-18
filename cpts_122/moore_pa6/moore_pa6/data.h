/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/22
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: Morse code decoder thing PA6

Description: This contains our class for the data in the BST
*******************************************************************************************/
#pragma once
#include <iostream>
#include <string>

class Data
{
public:
	// Constructor
	Data(const char& initChar = '\0', const std::string& initCode = "");
	// Copy constructor
	Data(const Data& newCopy);
	// Destructor
	~Data();
	// Overload of copy assignment operator
	Data& operator=(const Data& rhs);

	// Setters and Getters
	char getChar(void) const;
	std::string getMorseCode(void) const;

	void setChar(const char& newChar);
	void setMorseString(const std::string& newCode);
private:
	char character;
	std::string morseCode;
};


std::ostream& operator<<(std::ostream& os, const Data& data);