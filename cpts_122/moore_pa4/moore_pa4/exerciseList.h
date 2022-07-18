/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/8
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 4 Diet and Exercise App

Description:	This file contains the ExerciseList class which will hold our linked list
				full of the Exercise plans.
*******************************************************************************************/
#pragma once
#include "ExerciseListNode.h"
class ExerciseList
{
public:

	// Default Constructor
	ExerciseList();
	// Copy Constructor
	ExerciseList(const ExerciseList& copyList);
	// Destructor
	~ExerciseList();
	// Copy Assignment Operator
	ExerciseList& operator= (ExerciseList& rhs);

	// Getters and Setters
	// Returns a copy of the head pointer
	ExerciseNode* getHeadPointer(void) const;

	// Sets the value of the head pointer to the passed argument
	void setHeadPointer(ExerciseNode* pNew);

	/*
	* Function: insertAtFront()
	* Date Created: 2021/03/09
	* Last Modified: 2021/03/09
	* Description:	Will insert a new node with the passed data to the front of the list
	* Input Parameters:
	*	ExercisePlan& newPlanData: reference to the new data
	* Returns:
	*	Integer 1 for successful allocation of memory 0 for unsuccessfull allocation
	* Precondition: NONE
	* Postcondition: Node inserted at front and 1 returned, or 0 returned for unssuccefull allocation.
	*/
	int insertAtFront(const ExercisePlan& newPlanData);

	/*
	* Function: insertAtEnd()
	* Date Created: 2021/03/09
	* Last Modified: 2021/03/09
	* Description:	Will insert a new node with the passed data to the end of the list
	* Input Parameters:
	*	ExercisePlan& newPlanData: reference to the new data
	* Returns:
	*	int: success of allocation of memory
	* Precondition: NONE
	* Postcondition: Node inserted at the end of the list
	*/
	int insertAtEnd(const ExercisePlan& newPlanData);

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
	ExerciseNode* mpHead;

	/*
	* Function: freeList()
	* Date Created: 2021/03/09
	* Last Modified: 2021/03/09
	* Description:	Will free the memory of the list
	* Input Parameters:
	*	ExercisePlan* pExercisePointer: pointer to the head pointer of the list you want to delete
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: All memory allocated for nodes has been freed from the the list
	*/
	void freeList(ExerciseNode* const pExercisePointer);

	/*
	* Function:  deepExerciseCopy()
	* Date Created: 2021/03/9
	* Last Modified: 2021/03/9
	* Description: Will move through the list copying the contents of the RHS (pHeadRhs) node to the LHS (pHeadNew)
	* Input Parameters:
	*	ExerciseNode* pHeadNew: pointer to the newly created head pointer node
	* Returns: NONE
	* Precondition: RHS list isn't empty
	* Postcondition: Contents of RHS copied to LHS
*/
	void deepExerciseCopy(ExerciseNode* pNewHeadPointer, const ExerciseNode* pHeadRhs);
};