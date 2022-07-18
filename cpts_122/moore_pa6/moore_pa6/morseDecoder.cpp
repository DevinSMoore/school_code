/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/22
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: Morse code decoder thing PA6

Description: This contains function definitions for the DecodeMorse class
*******************************************************************************************/
#include "morseDecoder.h"
#include <locale> // for toupper() function
#define MAX_LEN 20

DecodeMorse::DecodeMorse()
{
	// nothing to see here move along sir
}

BST<Data> DecodeMorse::getTree(void) const
{
	return mTree;
}

/*
* Function: runDecode()
* Date Created: 2021/03/22
* Last Modified: 2021/03/22
* Description: Decodes the file contents
* Input Parameters:
*	std::fstream reference to file to be decoded
* Returns: NONE
* Precondition: file is open for reading
* Postcondition: Decoded contents of file displayed to screen
*/
void DecodeMorse::runDecode(std::fstream& infile)
{
	std::locale locale;
	std::string tempString = "", returnString = "";
	char tempChar = '\0';
	unsigned int index = 0;
	while (std::getline(infile, tempString, ' '))
	{
		
		for(index = 0; index < tempString.size(); index++)
		{
			tempChar = std::toupper(tempString.c_str()[index], locale); // set tempChar and then increment index to next char in string; AND CAPATALIZEZZKLKDL it
			if(tempChar != '\n')
			{
				searchTree(tempChar, returnString, mTree.getRootPtr()); // will move through the string (tempString) until we hit the newline
				if (returnString != "")
				{
					std::cout << returnString; // if the val returned is not "" then we will print the morse code to the screen
					returnString = "";
					putchar(' '); // space after every char 
				}
			}
			else if (tempChar == '\n')
			{
				putchar('\n');
			}
		}
		index = 0; // resetting index
		putchar('   '); // add a triple space between words
	}
}

/*
* Function: searchTree()
* Date Created: 2021/03/22
* Last Modified: 2021/03/22
* Description:
* Input Parameters:
*	reference to character being searched for
*	reference to string that will be filled with the found string
*	root pointer of tree being searched
* Returns: NONE
* Precondition: BST is not empty
* Postcondition: String that matches char returned
*/
void DecodeMorse::searchTree(const char& targetChar, std::string& returnString, BSTNode<Data>* pRoot) const
{
	if (pRoot != nullptr)
	{
		if (pRoot->getDataPtr()->getChar() == targetChar)
		{
			returnString = pRoot->getDataPtr()->getMorseCode();
		}

		searchTree(targetChar, returnString, pRoot->getLeftPtr());
		searchTree(targetChar, returnString, pRoot->getRightPtr());
	}
}