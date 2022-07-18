/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/12
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA8 Data Analysis with BSTs

Description: This contains the funcion definitions for the TransactionNode class
*******************************************************************************************/
#include "TransactionNode.h"

// default constructor
TransactionNode::TransactionNode(std::string& newData, int newUnits) : Node(newData)
{
	mUnits = newUnits;
}

// destructor
TransactionNode::~TransactionNode()
{
	
}

// Getters and Setters
int TransactionNode::getUnits(void) const
{
	return mUnits;
}

void TransactionNode::setUnits(const int& newUnit)
{
	mUnits = newUnit;
}

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
void TransactionNode::printData(void)
{
	std::cout << "Data:	" << getData() << std::endl << "Units: " << mUnits;
}