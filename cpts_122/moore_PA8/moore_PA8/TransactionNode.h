/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/12
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA8 Data Analysis with BSTs

Description: This contains the TransactionNode class which holds information on the 
			number of units involved in a particular transaction.
*******************************************************************************************/
#pragma once
#include "Node.h"
#include <iostream>

class TransactionNode : public Node
{
public:
	// Default constructor
	TransactionNode(std::string& newData, int newUnits = 0);
	// Destructor
	~TransactionNode();

	// Getters and Setters
	int getUnits(void) const;

	void setUnits(const int& newUnit);

	/*
	* Function: printData()
	* Date Created: 2021/04/12
	* Last Modified: 2021/04/12
	* Description: Will print the data in node to console
	* Input Parameters: NONE
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: Nodes data print to console
	*/
	void printData(void);
private:
	int mUnits;
};
