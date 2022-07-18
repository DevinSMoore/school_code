/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/12
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA8 Data Analysis with BSTs

Description: This has the abstract node class with supporting functions
*******************************************************************************************/
#pragma once
#include <string>

class Node
{
public:
	Node(std::string newData = "");

	Node(Node& copy);
	Node& operator=(Node& rhs);

	virtual ~Node();

	// Getters and Setters
	std::string getData(void) const;
	Node*& getLeftPtr(void);
	Node*& getRightPtr(void);

	void setData(const std::string& newData);
	void setLeftPtr(Node* newPtr);
	void setRightPtr(Node* newPtr);

	/*
	* Function: printData()
	* Date Created: 2021/04/12
	* Last Modified: 2021/04/12
	* Description: This does nothing because it's a pure virtual function
	* Input Parameters: NONE
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: NONE
	*/
	virtual void printData(void) = 0;

protected:
	std::string mData;
	Node* mpLeft;
	Node* mpRight;
};