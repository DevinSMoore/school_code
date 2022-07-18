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
#pragma once
#include "dietListNode.h"
class DietList
{
public:

	// Default Constructor
	DietList();
	// Copy Constructor
	DietList(const DietList& copyList);
	// Destructor
	~DietList();
	// Copy Assignment Operator
	DietList& operator= (DietList& rhs);

	// Getters and Setters
	// Returns a copy of the head pointer
	DietNode* getHeadPointer(void) const;

	// Sets the value of the head pointer to the passed argument
	void setHeadPointer(DietNode* pNew);

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
	int insertAtFront(const DietPlan& newPlanData);

	/*
	* Function: insertAtEnd()
	* Date Created: 2021/03/09
	* Last Modified: 2021/03/09
	* Description:	Will insert a new node with the passed data to the end of the list
	* Input Parameters:
	*	DietPlan& newPlanData: reference to the new data
	* Returns:
	*	int: success of allocation of memory
	* Precondition: NONE
	* Postcondition: Node inserted at the end of the list
	*/
	int insertAtEnd(const DietPlan& newPlanData);

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

	void deleteFront(void);
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
	void deleteEnd(void);



private:
	DietNode* mpHead;

	/*
	* Function: freeList()
	* Date Created: 2021/03/09
	* Last Modified: 2021/03/09
	* Description:	Will free the memory of the list
	* Input Parameters:
	*	DietPlan* pDietPointer: pointer to the head pointer of the list you want to delete
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: All memory allocated for nodes has been freed from the the list
	*/
	void freeList(DietNode* const pDietPointer);

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
	void deepDietCopy(DietNode* pNewHeadPointer, const DietNode* pHeadRhs);
};