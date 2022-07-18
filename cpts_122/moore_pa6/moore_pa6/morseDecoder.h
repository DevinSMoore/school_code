/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/22
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: Morse code decoder thing PA6

Description: This contains the class that just holds stuff not specific to the BST
*******************************************************************************************/
#pragma once
#include "BST.h"

class DecodeMorse
{
public:
	DecodeMorse();

	// Getters and Setters
	BST<Data> getTree(void) const;

	
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
	void runDecode(std::fstream& infile);


	/*
	* Function: searchTree()
	* Date Created: 2021/03/22
	* Last Modified: 2021/03/22
	* Description:
	* Input Parameters:
	*	reference to character being searched for
	*	root pointer of tree being searched
	* Returns: NONE
	* Precondition: BST is not empty
	* Postcondition: String that matches char returned
	*/
	
	void searchTree(const char& targetChar, std::string& returnString, BSTNode<Data>* pRoot) const;

private:
	BST<Data> mTree;

};
