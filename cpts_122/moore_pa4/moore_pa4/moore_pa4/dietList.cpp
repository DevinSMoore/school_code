/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/8
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 4 Diet and Exercise App

Description:	This file contains the dietList class which will hold our linked list
				full of the diet plans and the functions necessary to and and remove
				from it.
*******************************************************************************************/
#include "dietList.h"



// Default Constructor for the list
DietList::DietList()
{
	this->setHeadPointer(nullptr);
}

// Creates a deep (I'm pretty sure) of the list for the copy constructor
DietList::DietList(const DietList& copyList)
{
	const DietList* pCopyTemp = &copyList; // so this is a copy (pRhsTemp)of a pointer (&rhs) to a dietList which is constant. So we can change the copied pointer and not affect the real pointer or the data in the dietlist this is almost silly but whatevs

	if (pCopyTemp->mpHead == nullptr)
	{
		this->setHeadPointer(nullptr); // If the list we're copyings head pointer is null then we just set the new nodes head pointer to null to null and drop out of the function
	}
	else
	{	// We want to create a new head pointer for the LHS list, and then pass that to the deepCopy function to set all of the nodes (if any) on the LHS to the values on the RHS
		DietNode* pNewHeadPointer = new DietNode;
		DietNode* pRhsHeadPointer = pCopyTemp->mpHead;
		deepDietCopy(pNewHeadPointer, pRhsHeadPointer);
	}
}


// This simply frees the space the node created the object was instantiated
DietList::~DietList()
{
	std::cout << "Hit list deconstructor." << std::endl;
	std::cout << "Deleting all items in list...";
	freeList(this->getHeadPointer());
}

void DietList:: freeList(DietNode* const pDietPointer) // a constant pointer to a DietNode
{
	if (pDietPointer != nullptr)
	{
		freeList(pDietPointer->getNextPointer());
		delete pDietPointer; // Deletes from the back to the front
	}// if we hit the null pointer do nothing

}

DietList& DietList::operator= (DietList& rhs)
{
	DietList *pRhsTemp = &rhs; // so this is a copy (pRhsTemp)of a pointer (&rhs) to a dietList which is constant. So we can change the copied pointer and not affect the real pointer or the data in the dietlist this is almost silly but whatevs

	if (pRhsTemp->mpHead == nullptr)
	{
		this->setHeadPointer(nullptr); // If the rhs head pointer is null then we just set the lhs side to null and drop out of the function
	}
	else
	{	// We want to create a new head pointer for the LHS list, and then pass that to the deepCopy function to set all of the nodes (if any) on the LHS to the values on the RHS
		this->mpHead = new DietNode;
		deepDietCopy(this->mpHead, pRhsTemp->mpHead);
	}
	
	return *this;
}

// Getters and Setters

// This will return a copy of the head pointer
DietNode* DietList::getHeadPointer(void) const
{
	return this->mpHead;
}

// Sets the value of the head pointer to the passed argument
void DietList::setHeadPointer(DietNode* pNew)
{
	this->mpHead = pNew;
}

/*
* Function:  deepDietCopy()
* Date Created: 2021/03/9
* Last Modified: 2021/03/9
* Description: Will move through the list copying the contents of the RHS (pHeadRhs) node to the LHS (pHeadNew)
* Input Parameters: 
*	DietNode* pHeadNew: pointer to the newly created head pointer node
* Returns: NONE
* Precondition: RHS list isn't empty
* Postcondition: Contents of RHS copied to LHS
*/
void DietList::deepDietCopy(DietNode* pHeadNew, const DietNode* pHeadRhs) // for the rhs we can change the pointer passed but not the data inside it
{
	*(pHeadNew->getPlanPointer()) = *(pHeadRhs->getPlanPointer()); // Ok this is just copying over the values from the RHS to the LHS using DietPlan's copy assignment operator.

	if (pHeadRhs->getNextPointer() == nullptr)// If the next node of the RHS is the null pointer we want to set the mpNext of the LHS
	{
		pHeadNew->setNextPointer(nullptr); // set mpNext of the last node in the new diet list

	}
	else
	{
		pHeadNew->setNextPointer(new DietNode);
		deepDietCopy(pHeadNew->getNextPointer(), pHeadRhs->getNextPointer()); // calling function for some of that (hopefully) recursive action.
	}
}

/*
* Function: insertAtFront()
* Date Created: 2021/03/09
* Last Modified: 2021/03/09
* Description:	Will insert a new node with the passed data to the front of the list
* Input Parameters:
*	DietPlan& newPlanData: reference to the new data
* Returns:
*	Integer 1 for successful allocation of memory 0 for unsuccessfull allocation
* Precondition: NONE
* Postcondition: Node inserted at front and 1 returned, or 0 returned for unssuccefull allocation.
*/
int DietList::insertAtFront(const DietPlan& newPlanData)
{
	int success = 0;
	DietNode* pNew = new DietNode(newPlanData); // Allocate memory to the heap, and instantiate node with passed data
	
	if (pNew != nullptr)
	{
		success = 1;

		if (this->mpHead == nullptr) // List is empty
		{
			this->setHeadPointer(pNew); // Set mpHead of object to pNew
		}
		else
		{
			pNew->setNextPointer(this->getHeadPointer()); // set new mpHead's mpNext to current mpHead
			this->setHeadPointer(pNew); // Set current mpHead to new Node
		}
	}

	return success;
}

/*
* Function: insertAtEnd()
* Date Created: 2021/03/09
* Last Modified: 2021/03/09
* Description:	Will insert a new node with the passed data to the end of the list if the list is empty it'll just put it at the front which is the end I guess.
* Input Parameters:
*	DietPlan& newPlanData: reference to the new data
* Returns:
*	int: success of allocation of memory
* Precondition: NONE
* Postcondition: Node inserted at the end of the list
*/
int DietList::insertAtEnd(const DietPlan& newPlanData)
{
	DietNode* pTemp = this->getHeadPointer(), *pNew = new DietNode(newPlanData);
	int success = 0;
	
	if (pNew != nullptr)
	{
		success = 1;
		if (pTemp == nullptr)
		{
			// empty list therefore instert at the front here
			this->setHeadPointer(pNew);
		}
		else
		{
			while (pTemp->getNextPointer() != nullptr) // stop at the last node
			{
				pTemp = pTemp->getNextPointer(); // Advance through list
			}

			pTemp->setNextPointer(pNew); // set the last node in the lists next pointer to the nullptr; DietNodes are constructed with the next pointer being the nullptr so it's not necessary to set it but i'll test to make sure
		}
	}

	return success;

}

/*
* Function: deleteFront()
* Date Created: 2021/03/09
* Last Modified: 2021/03/09
* Description: Deletes the node at the front of the list
* Input Parameters: NONE
* Returns: NONE
* Precondition: List not empty
* Postcondition: Node deleted from the front of the list
*/

void DietList::deleteFront(void)
{
	DietNode* pTemp = this->getHeadPointer(); // create a temp pointer for old mpHead
	this->setHeadPointer(this->mpHead->getNextPointer()); // set mpHead to current mpHead's nextPointer
	delete pTemp; // Free up memory; I don't know if this is neccessary because the DietNode class has a deconstructor that will delete it's memeory if it falls out of scope, so does that mean if I just don't do this will it work? I'll test it
}

/*
* Function: deleteEnd()
* Date Created: 2021/03/09
* Last Modified: 2021/03/09
* Description: Deletes node from end of list
* Input Parameters: NONE
* Returns: NONE
* Precondition: List not empty
* Postcondition: Node deleted from end of list
*/
void DietList::deleteEnd(void)
{
	DietNode* pTemp = this->getHeadPointer();
	while (pTemp->getNextPointer()->getNextPointer() != nullptr) // stop at the node just before the last node in the list by looking at the node after nexts pointer
	{
		pTemp = pTemp->getNextPointer(); // Advance through list
	}
	delete pTemp->getNextPointer(); // delete memory of the next pointer (sounds brutal)
	pTemp->setNextPointer(nullptr); // set the last node in the lists next pointer to the nullptr
}