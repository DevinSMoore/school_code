/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/15
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 5 Grocery Store Simulator

Description: This will contain the queue class for our grocery store line
*******************************************************************************************/
#pragma once
#include "QueueNode.h"

class Queue
{
public:
	Queue();
	Queue(const Queue& copy);
	~Queue();

	Queue& operator=(const Queue& rhs);

	QueueNode* getHeadPtr(void) const;
	QueueNode* getTailPtr(void) const;

	void setHeadPtr(QueueNode* newPtr);
	void setTailPtr(QueueNode* newPtr);
	
	// Overloading equal to comparison operator for the queue
	// This will simply contain a function that loops through and does the comparison using the data overload of this operator
	// nees to be a member function to get
	bool operator==(const Queue& rhs);
	//bool operator==(const CustomerData& lhs, const CustomerData& rhs);



	/*
	* Function: isEmpty()
	* Date Created: 2021/03/17
	* Last Modified: 2021/03/17
	* Description: Will recursively free all of the memeory of the nodes in our queue, therefore we don't need to free the memory in our node constructor
	* Input Parameters:
	*	Head pointer of object being copied TO
	*	Head pointer of object being copied FROM
	* Returns: NONE
	* Precondition:	Queue is not empty
	* Postcondition: All data copied over
	*/
	bool isEmpty(void);

	/*
	* Function: enqueue()
	* Date Created:	2021/03/07
	* Last Modified: 2021/03/07
	* Description: Adds a new item to the tail of the queue. will become the new node mpTail points to
	* Input Parameters:
	*	reference to new customer data to insert
	* Returns: 
	*	int representing success (1) or failure (0) to allocate memory.
	* Precondition:	A queue object exists (lol)
	* Postcondition: New node inserted to the back of the queue with the passed data.
	*/
	int enqueue(CustomerData& newData);

	/*
	* Function: dequeue()
	* Date Created:	2021/03/07
	* Last Modified: 2021/03/07
	* Description: Removes an item from the head of the queue. will become the new node mpTail points to
	* Input Parameters: NONE
	* Returns: NONE
	* Precondition: Queue is not empty.
	* Postcondition: NONE
	*/
	void dequeue(void);

	/*
	* Function: numberInQueue()
	* Date Created:	2021/03/07
	* Last Modified: 2021/03/07
	* Description: calls the countQueue function and returns the number of elements in the queue
	* Input Parameters:
	*	NONE
	* Returns:
	*	integer representing number of elements in the queue
	* Precondition: NONE
	* Postcondition: Elements counted and returned to user
	*/
	int numberInQueue(void);


private:
	QueueNode* mpHead;
	QueueNode* mpTail;
	/*
	* Function: copyQueueNodes()
	* Date Created: 2021/03/17
	* Last Modified: 2021/03/17
	* Description: Will recursively copy all of the nodes in a queue. This should be private so only we can call it but idk what i'm doing so w/e
	* Input Parameters:
	*	Head pointer of object being copied TO
	*	Head pointer of object being copied FROM
	* Returns: NONE
	* Precondition:	Queue is not empty
	* Postcondition: All data copied over
	*/
	void copyQueueNodes(QueueNode* const targetHeadPtr, QueueNode* const copyHeadPtr);


	/*
	* Function: destroyQueue()
	* Date Created: 2021/03/17
	* Last Modified: 2021/03/17
	* Description: Will recursively free all of the memeory of the nodes in our queue, therefore we don't need to free the memory in our node constructor
	* Input Parameters:
	*	Tail pointer of the queue
	* Returns: NONE
	* Precondition:	Queue is not empty
	* Postcondition: All deeleted from queue
	*/
	void destroyQueue(QueueNode* pTail);

	/*
	* Function: countQueue()
	* Date Created:	2021/03/07
	* Last Modified: 2021/03/07
	* Description: Private member function will count the number of elements in the queue and return the result 
	* Input Parameters:
	*	pointer to headPointer
	*	reference to count value
	* Returns:
	*	NONE
	* Precondition: Queue is not empty
	* Postcondition: Number of elements counted has been set to the count value reference
	*/
	void countQueue(QueueNode* const pHead, int& numElements);

	/*
	* Function: checkEquivalancy()
	* Date Created: 2021/03/17
	* Last Modified: 2021/03/17
	* Description: Will loop through the queue checking if the LHS equals the RHS
	* Input Parameters:
	*	Head pointer of the left hand side queue
	*	Head pointer of the right hand side queue
	*	reference to bool that will be set if certain conditions are true
	* Returns:
	*	NONE
	* Precondition: Queue is not empty
	* Postcondition: bool reference has been set
	*/
	void checkEquivalancy(QueueNode* lhsHeadPtr, QueueNode* rhsHeadPtr, bool& isEqual);
};

