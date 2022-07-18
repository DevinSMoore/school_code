#include "queue.h"

Queue::Queue()
{
	mpHead = mpTail = nullptr;
}

Queue::Queue(const Queue& copy)
{
	if (copy.mpHead == nullptr)
	{
		// Queue is empty -> set both to new Node
		mpHead = mpTail = nullptr;
	}
	else
	{
		// Calling function to alocate memory and copy data
		copyQueueNodes(mpHead, copy.mpHead);
	}
}

Queue::~Queue()
{
	// will call destroyQueue to delete all of the nodes
	// std::cout << "Hit queue deconstructor, freeing queue memory..." << std::endl;
	if(mpTail != nullptr)
	{
		destroyQueue(mpTail);
	}
}

Queue& Queue::operator=(const Queue& rhs)
{
	if (rhs.getHeadPtr() == nullptr) // if it's empty set both to nullptr
	{
		mpHead = mpTail = nullptr;
	}
	else if (rhs.getHeadPtr() == rhs.getTailPtr())
	{
		// Queue has a single element in
		mpHead = mpTail = new QueueNode(*(rhs.getTailPtr()->getDataPtr())); // assign mpHead and mpTail to newly allocated memory

	}
	else
	{ // more than one node means we copy the whole lot of them
		mpHead = mpTail = new QueueNode(*(rhs.getTailPtr()->getDataPtr()));
		copyQueueNodes(mpHead, rhs.mpHead);
	}

	return *this;
}

QueueNode* Queue::getHeadPtr(void) const
{
	return mpHead;
}

QueueNode* Queue::getTailPtr(void) const
{
	return mpTail;
}


void Queue::setHeadPtr(QueueNode* newPtr)
{
	mpHead = newPtr;
}

void Queue::setTailPtr(QueueNode* newPtr)
{
	mpTail = newPtr;
}

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
bool Queue::isEmpty(void)
{
	return (this->mpHead == nullptr) ? (true) : (false); // if the head pointer is null the queue is empty therefore return true else return false.
}

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
void Queue::copyQueueNodes(QueueNode* const targetHeadPtr, QueueNode* const copyHeadPtr)
{
	if (copyHeadPtr != nullptr) // we haven't reached the end of the queue
	{

		*(targetHeadPtr->getDataPtr()) = *(copyHeadPtr->getDataPtr()); // targetData = copyData
		
		if (copyHeadPtr->getNextPtr() != nullptr)
		{
			targetHeadPtr->setNextPtr(new QueueNode(*(copyHeadPtr->getDataPtr()))); // Create new node for the next pointer if the rhs' next pointer is not null
		}
		
		copyQueueNodes(targetHeadPtr->getNextPtr(), copyHeadPtr->getNextPtr()); // Advancing through queue
	}
}

/*
* Function: destroyQueue()
* Date Created: 2021/03/17
* Last Modified: 2021/03/17
* Description: Will recursively free all of the memeory of the nodes in our queue, therefore we don't need to free the memory in our node constructor
* Input Parameters:
*	Tail pointer of the queue
* Returns: NONE
* Precondition:	Queue is not empty
* Postcondition: All data copied over
*/
void Queue::destroyQueue(QueueNode* pTail)
{
	if (pTail != nullptr)
	{
		// std::cout << std::endl << "Entered pHead != nullptr destroyQueue Recursive loop" << std::endl;
		destroyQueue(pTail->getNextPtr());
		delete pTail;
		// std::cout << std::endl << "Going backwards through queue from head to tail deleting as I go" << std::endl;
	}

}

/*
* Function: enqueue()
* Date Created:	2021/03/17
* Last Modified: 2021/03/17
* Description: Adds a new item to the tail of the queue. will become the new node mpTail points to
* Input Parameters:
*	reference to new customer data to insert
* Returns:
*	int representing success (1) or failure (0) to allocate memory.
* Precondition:	A queue object exists (lol)
* Postcondition: New node inserted to the back of the queue with the passed data.
*/
int Queue::enqueue(CustomerData& newData)
{
	int success = 0;
	
	QueueNode* pNew = new QueueNode(newData); // new node with new data passed into it
	
	if (pNew != nullptr)
	{
		success = 1;
		if (isEmpty())
		{
			// Queue is empty set head and tail pointers to newly created pointer
			mpHead = mpTail = pNew;
			// std::cout << "Data inserted in empty queue..." << std::endl;
		}
		else
		{
			// We're going to do the same thing to the queue for 1+ nodes in queue b/c we're just affecting the tail node
			pNew->setNextPtr(mpTail);
			mpTail = pNew; // Set new nodes next ptr to current tail node then set tail node to newly created node.
			// std::cout << "Data inserted in non-empty queue..." << std::endl;
		}
	}
	return success;
}

/*
* Function: dequeue()
* Date Created:	2021/03/17
* Last Modified: 2021/03/17
* Description: Removes an item from the head of the queue reseting where the head of our queue is
* Input Parameters: NONE
* Returns: NONE
* Precondition: Queue is not empty.
* Postcondition: Node has been removed from the front of the 
*/
void Queue::dequeue(void)
{
	QueueNode* pTemp = nullptr;
	if (mpHead == mpTail) // one node in queue
	{
		pTemp = mpHead;
		mpHead = mpTail = nullptr;
		delete pTemp;

	}
	else
	{
		pTemp = mpTail;
		while (pTemp->getNextPtr() != mpHead) // pTemp will be at the node before the head of the queue
		{
			pTemp = pTemp->getNextPtr();
		}
		delete mpHead;
		mpHead = pTemp; // Deallocate current head of the queue (customer being serviced) then set new head of queue to previous node
		mpHead->setNextPtr(nullptr); // set the current head next ptr to null
	}

}

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
int Queue::numberInQueue(void)
{
	int count = 0;
	countQueue(mpTail, count);
	return count;
}

/*
* Function: countQueue()
* Date Created:	2021/03/07
* Last Modified: 2021/03/07
* Description: Will count the number of elements in the queue and return the result
* Input Parameters:
*	pointer to headPointer
*	reference to count value
* Returns:
*	NONE
* Precondition: Queue is not empty
* Postcondition: Number of elements counted has been set to the count value reference
*/
void Queue::countQueue(QueueNode* const pTail, int& numElements)
{
	if (pTail/*->getNextPtr()*/ != nullptr)
	{
		countQueue(pTail->getNextPtr(), numElements);
		numElements++;
	}
}

// Overloading equal to comparison operator for the queue
// This will simply contain a function that loops through and does the comparison using the CustomerData overload of this operator
bool Queue::operator==(const Queue& rhs)
{
	bool isEqual = false;
	checkEquivalancy(this->getHeadPtr(), rhs.getHeadPtr(), isEqual);
	return isEqual;
}

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
void Queue::checkEquivalancy(QueueNode* lhsHeadPtr, QueueNode* rhsHeadPtr, bool& isEqual)
{

}