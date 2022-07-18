/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/22
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: Morse code decoder thing PA6

Description: This contains our function definitions for the data class.

*******************************************************************************************/
#include "data.h"

Data::Data(const char& initChar, const std::string& initCode)
{
	character = initChar;
	morseCode = initCode;
}

// Copy constructor
Data::Data(const Data& newCopy)
{
	character = newCopy.getChar();
	morseCode = newCopy.getMorseCode();
}

// Destructor
Data::~Data()
{
	// Nothing to do here really
	// std::cout << std::endl << "Hit data deconstructor: Doing nothing..." << std::endl;
	
}

// Overload of copy assignment operator
Data& Data::operator=(const Data& rhs)
{
	character = rhs.getChar();
	morseCode = rhs.getMorseCode();

	return *this;
}



// Setters and Getters
char Data::getChar(void) const
{
	return character;
}

std::string Data::getMorseCode(void) const
{
	return morseCode;
}

void Data::setChar(const char& newChar)
{
	character = newChar;
}

void Data::setMorseString(const std::string& newCode)
{
	morseCode = newCode;
}


std::ostream& operator<<(std::ostream& os, const Data& data)
{
	os << "Ascii Character: " << data.getChar() << std::endl << "Morse Equivalent: " << data.getMorseCode();
	return os;
}