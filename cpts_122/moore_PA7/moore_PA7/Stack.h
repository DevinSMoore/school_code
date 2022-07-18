/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/07
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA7

Description: This will containt the Stack class with support for push, pop, peek, isEmpty,
				and getStackCount
*******************************************************************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>

class Stack
{
public:
	// Default constructor
	Stack();
	// Copy constructor
	Stack(const Stack& copy);
	// Destructor
	~Stack();
	// Copy assignment operator overload
	Stack& operator=(const Stack& rhs);

	// getter for the stack
	std::vector<std::string> getStack(void) const;

	/*
	* Function: getStackCount()
	* Date Created: 2021/04/07
	* Last Modified: 2021/04/07
	* Description: Will Print the items in the list
	* Input Parameters: NONE
	* Returns: Integer representing the number of elements in the stack
	* Precondition: NONE
	* Postcondition: Number of elements returned
	*/
	int getStackCount(void);

	/*
	* Function: popStack()
	* Date Created: 2021/04/09
	* Last Modified: 2021/04/09
	* Description: Will remove from the top (back) of the stack and set the poped data
	* Input Parameters:
	*	Reference to a string to be set with the poped data
	* Returns: NONE
	* Precondition: Stack is not empty
	* Postcondition: data that was contained at the top of the stack set into popedData, and the node has been deleted
	*/
	std::string& popStack(std::string& popedData);

	/*
	* Function: pushStack()
	* Date Created: 2021/04/09
	* Last Modified: 2021/04/09
	* Description: will add a new item to the top of the stack
	* Input Parameters:
	*	Reference to the data to be pushed
	* Returns: None
	* Precondition: NONE
	* Postcondition: Item added to the stack
	*/
	void pushStack(const std::string& newData);

	/*
	* Function: peekStack()
	* Date Created: 2021/04/09
	* Last Modified: 2021/04/09
	* Description: will set peekData to the item at the top of the stack
	* Input Parameters: 
	*	Reference to the string to hold the peeked data; will set string to "NONE" if there is no data
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: Data set to peekData and stack is undisturbed
	*/
	std::string& peekStack(std::string& peekData);

	/*
	* Function: isEmpty()
	* Date Created: 2021/04/09
	* Last Modified: 2021/04/09
	* Description: will check if the vector array is zero
	* Input Parameters: NONE
	* Returns: 
	*	Boolean representing if it's empty (true) or not (false)
	* Precondition: NONE
	* Postcondition: bool representing emptiness returned
	*/
	bool isEmpty(void);

private:
	std::vector<std::string> mBack; // Back is the top of our stack, but i wanted the language to be consistent with the vector operations so I stopped confusing myself


};
