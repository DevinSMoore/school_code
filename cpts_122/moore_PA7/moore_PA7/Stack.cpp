/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/07
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA7

Description: Holds the destructor, constructor, and function definition(s).
*******************************************************************************************/
#include "Stack.h"

// Default constructor
Stack::Stack()
{
	// don't really need to do anything here because the vector class will handle allocating new memory and all that
	
}

// Copy constructor
Stack::Stack(const Stack& copy)
{
	int index = 0;
	if (!copy.mBack.empty())
	{
		// If we're copying over contents I"m going to empy the list of the current object if the copy object is not empty
		this->mBack.clear();

		if (copy.mBack.size() > 1)
		{
			while ((copy.mBack.begin() + index) != copy.mBack.end())  // while the list isn't at then end
			{

				mBack.push_back(*(copy.mBack.begin() + index));
				index++;
			}  
		}
		mBack.push_back(copy.mBack.back()); // Push the only item in the list if it's size 1, this will also push the last element in the copy list after we go through previous loop
	}
}

// Destructor
Stack::~Stack()
{
	std::cout << "Hit Stack destructor...." << std::endl << "Clearing stack...." << std::endl;
	this->mBack.clear();
}

// Operator overload
Stack& Stack::operator=(const Stack& rhs)
{
	int index = 0;
	if (this != &rhs) // Stopping self-assignment
	{
		if (!rhs.mBack.empty())
		{
			this->mBack.clear(); // clearing current stack

			if (rhs.mBack.size() > 1)
			{
				while ((rhs.mBack.begin() + index) != rhs.mBack.end())  // while the list isn't at end
				{

					mBack.push_back(*(rhs.mBack.begin() + index));
					index++;
				}
			}
			mBack.push_back(rhs.mBack.back()); // Push the only item in the list if it's size 1, this will also push the last element in the copy list after we go through previous loop
		}
	}

	return *this;
}

// Getter
std::vector<std::string> Stack::getStack(void) const
{
	return mBack;
}

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
std::string& Stack::popStack(std::string& popedData)
{

	popedData = mBack.back(); // Save current last item
	mBack.pop_back(); // Pop last item
		
	return popedData; // return string
}

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
void Stack::pushStack(const std::string& newData)
{
	mBack.push_back(newData); // Push new data to the stack
}

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
std::string& Stack::peekStack(std::string& peekData)
{
	if (mBack.size() != 0)
	{
		peekData = mBack.back();
	}
	else { peekData = "NONE"; }
	return peekData;
}

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
bool Stack::isEmpty(void)
{
	return mBack.empty();
}

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
int Stack::getStackCount(void)
{
	return mBack.size();
}
