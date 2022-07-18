/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/06
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA7: Attendance Tracker w/ Class Templates

Description: This file conains the List template class for a Singly Linked List
				Supports stack like operations: insert at front and delete front
				contains the head pointer of the list.
*******************************************************************************************/
#pragma once
#include "ListNode.h"

template <typename T>
class List
{
public:
	// Default Constructors
	List();
	List(const T& newData);
	
	// Copy Constructor
	List(const List& copy);
	// Destructor
	~List();

	// Copy assignment operator overload
	List& operator=(const List& rhs);

	// Getters and Setters
	ListNode<T>* getPHead(void) const;

	void setPHead(const ListNode<T>& newPtr);

	/*
	* Function: copyNodes()
	* Date Created: 2021/04/06
	* Last Modified: 2021/04/06
	* Description: Will recursively copy the nodes from the copPointer list to the currentPointer list
	* Input Parameters:
	*	Pointer to list to copy TO = currentPointer
	*	Pointer ot list to copy FROM = copyPointer
	* Returns: NONE
	* Precondition: List not empty
	* Postcondition: Nodes from right list copied to left list
	*/
	void copyNodes(ListNode<T>* currentPointer, ListNode<T>* copyPointer);


	/*
	* Function: insertAtFront()
	* Date Created: 2021/04/06
	* Last Modified: 2021/04/06
	* Description: Will insert a node at the front of the list
	* Input Parameters: 
	*	Reference to the data to be place into the node
	* Returns:
	*	Bool representing success (= true) or failure (= false)
	* Precondition: NONE
	* Postcondition: Node inserted to front of the list with data.
	*/
	bool insertAtFront(const T& newData);
	
	/*
	* Function: deleteFrontNode()
	* Date Created: 2021/04/06
	* Last Modified: 2021/04/06
	* Description: Will delete the first node in the list
	* Input Parameters: NONE
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: Node at front of list deleted and head pointer properly reset
	*/
	void deleteFrontNode(void);

	/*
	* Function: deleteList()
	* Date Created: 2021/04/06
	* Last Modified: 2021/04/06
	* Description: will run through list deleteing all of the nodes
	* Input Parameters: NONE
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: List has been emptied of it's contents
	*/
	void deleteList();

	/*
	* Function: isEmpty()
	* Date Created: 2021/04/06
	* Last Modified: 2021/04/06
	* Description: will check if the list is empty
	* Input Parameters: NONE
	* Returns:
	*	Bool value representing emptiness.
	* Precondition: NONE
	* Postcondition: Emptiness confirmed and boolean value returned 
	*/
	bool isEmpty(void);

	/*
	* Function: countItems()
	* Date Created: 2021/04/06
	* Last Modified: 2021/04/06
	* Description: Will run through the list counting the items
	* Input Parameters:
	*	Reference to int that will hold the count val
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: Number of elements in the list returned
	*/
	void countItems(int& numItems);

	/*
	* Function: pringList()
	* Date Created: 2021/04/06
	* Last Modified: 2021/04/06
	* Description: Prints the list to the console, this is the public facing funciton, the private funciton does the work
	* Input Parameters: NONE
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: List printed to screen (if there were any elements in it)
	*/
	void printList(void);
private:
	ListNode<T>* mpHead;

	/*
	* Function: deleteList()
	* Date Created: 2021/04/06
	* Last Modified: 2021/04/06
	* Description: This will recursevely go through and empty the list out
	* Input Parameters:
	*	Pointer to head node pointer
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: List is empty
	*/
	void deleteList(ListNode<T>* ptr);
	
	/*
	* Function: countItems()
	* Date Created: 2021/04/06
	* Last Modified: 2021/04/06
	* Description: This will count the items in the list
	* Input Parameters:
	*	Reference to the integer that will hold the number of items found
	*	Head pointer of the list
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: Number of items st into the integer reference passed
	*/
	void countItems(int& numItems, ListNode<T>* headPtr);
	
	/*
	* Function: printlist()
	* Date Created: 2021/04/06
	* Last Modified: 2021/04/06
	* Description: Will Print the items in the list
	* Input Parameters:
	*	Head pointer of list to be printed
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: List print to console
	*/
	void printList(ListNode<T>* nextPtr);
};


// Default Constructors
template <typename T>
List<T>::List()
{
	mpHead = nullptr;
}

template <typename T>
List<T>::List(const T& newData)
{
	mpHead = new ListNode<T>(newData);
}

// Copy Constructor
template <typename T>
List<T>::List(const List& copy)
{
	if (copy.mpHead != nullptr) // if the copy list isn't empty we want to check if this list is empty
	{
		if(isEmpty()) // If it is empty then we want to create a new head node and set it's data to the copy list's head pointer data
		{
			mpHead = new ListNode<T>(*copy.getPHead()->getDataPtr());
			copyNodes(mpHead, copy.getPHead());
		}
	}
}

// Destructor
template <typename T>
List<T>::~List()
{
	std::cout << "Hit list destructor...." << std::endl;
	if(!isEmpty())
	{
		deleteList(mpHead);
	}
	// printList();
	// need to delete mpHead now
}

// Copy assignment operator overload
template <typename T>
List<T>& List<T>::operator=(const List& rhs)
{
	if (&rhs != this) // Check for self assignment
	{
		if (rhs.mpHead != nullptr) // if the copy list isn't empty we want to check if this list is empty
		{
			if (isEmpty()) // If it is empty then we want to create a new head node and set it's data to the copy list's head pointer data
			{
				mpHead = new ListNode<T>(*rhs.getPHead()->getDataPtr());
				copyNodes(mpHead, rhs.getPHead());
			}
		}
	}
	return *this;
}

// Getters and Setters
template <typename T>
ListNode<T>* List<T>::getPHead(void) const
{
	return mpHead;
}

template <typename T>
void List<T>::setPHead(const ListNode<T>& newPtr)
{
	mpHead = newPtr;
}

/*
* Function: isEmpty()
* Date Created: 2021/04/06
* Last Modified: 2021/04/06
* Description: will check if the list is empty
* Input Parameters: NONE
* Returns:
*	Bool value representing emptiness.
* Precondition: NONE
* Postcondition: Emptiness confirmed and boolean value returned
*/
template <typename T>
bool List<T>::isEmpty(void)
{
	return (mpHead == nullptr) ? (true) : (false);
}


/*
* Function: insertAtFront()
* Date Created: 2021/04/06
* Last Modified: 2021/04/06
* Description: Will insert a node at the front of the list
* Input Parameters:
*	Reference to the data to be place into the node
* Returns:
*	Bool representing success (= true) or failure (= false)
* Precondition: NONE
* Postcondition: Node inserted to front of the list with data.
*/
template <typename T>
bool List<T>::insertAtFront(const T& newData)
{

	bool success = false;
	ListNode<T>* tempPtr = new ListNode<T>(newData);
	if(tempPtr != nullptr)
	{
		success = true;
		if (mpHead == nullptr)
		{
			// No items in list
			mpHead = tempPtr;
		}
		else
		{
			tempPtr->setNextPtr(mpHead); // set new pHeads next ptr to current head ptr
			mpHead = tempPtr;			// set mpHead to newPtr
		}
		std::cout << "Node Inserted" << std::endl;
	}

	return success;
}

/*
* Function: deleteFrontNode()
* Date Created: 2021/04/06
* Last Modified: 2021/04/06
* Description: Will delete the first node in the list
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: Node at front of list deleted and head pointer properly reset
*/
template <typename T>
void List<T>::deleteFrontNode(void)
{
	ListNode<T>* tempPtr = nullptr;
	if (!isEmpty())
	{
		// list not empty; also doesn't matter if list has one node or much nodes all be same
		tempPtr = mpHead;
		mpHead = mpHead->getNextPtr();
		delete tempPtr; // I don't think this is necessary as it would go out of scope and the destructor would take care of the memory

	}
}

/*
* Function: countItems()
* Date Created: 2021/04/06
* Last Modified: 2021/04/06
* Description: Will run through the list counting the items
* Input Parameters:
*	Reference to int that will hold the count val
* Returns: NONE
* Precondition: NONE
* Postcondition: Number of elements in the list returned
*/
template <typename T>
void List<T>::countItems(int& numItems)
{
	numItems = 0;
	if (!isEmpty()) // If list isn't empty call recursive function
	{
		countItems(numItems, mpHead);
	}
}

/*
* Function: countItems()
* Date Created: 2021/04/06
* Last Modified: 2021/04/06
* Description: This will count the items in the list
* Input Parameters:
*	Reference to the integer that will hold the number of items found
*	Head pointer of the list
* Returns: NONE
* Precondition: List not empty
* Postcondition: Number of items st into the integer reference passed
*/
template <typename T>
void List<T>::countItems(int& numItems, ListNode<T>* headPtr)
{
	if (headPtr != nullptr)
	{
		countItems(numItems, headPtr->getNextPtr()); // will go to the end of the list then start counting from there
		numItems++;
	}
}	


/*
* Function: copyNodes()
* Date Created: 2021/04/06
* Last Modified: 2021/04/06
* Description: Will recursively copy the nodes from the copPointer list to the currentPointer list
* Input Parameters:
*	Pointer to list to copy TO = currentPointer
*	Pointer ot list to copy FROM = copyPointer
* Returns: NONE
* Precondition: List not empty
* Postcondition: Nodes from right list copied to left list
*/
template <typename T>
void List<T>::copyNodes(ListNode<T>* currentPtr, ListNode<T>* copyPtr)
{
	if (copyPtr->getNextPtr() != nullptr)// If the copy list has a next node 
	{
		if (currentPtr->getNextPtr() == nullptr) // and this list does not have a next node create new node and pass in data of copy's next node
		{
			currentPtr->setNextPtr(new ListNode<T>(*copyPtr->getNextPtr()->getDataPtr())); // set next pointer and pass in data from copy's next node
		}
		else // or if this list does have a node -> set nextPtr's data to copy's nextPtr's Data
		{
			*currentPtr->getNextPtr()->getDataPtr() = *copyPtr->getNextPtr()->getDataPtr();
		}

		copyNodes(currentPtr->getNextPtr(), copyPtr->getNextPtr()); // move to next pointer
	}
}

/*
* Function: deleteList()
* Date Created: 2021/04/06
* Last Modified: 2021/04/06
* Description: will run through list deleteing all of the nodes
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: List has been emptied of it's contents
*/
template <typename T>
void List<T>::deleteList()
{
	if (!isEmpty())
	{
		deleteList(mpHead);
	}
}

/*
* Function: deleteList()
* Date Created: 2021/04/06
* Last Modified: 2021/04/06
* Description: This will recursevely go through and empty the list out
* Input Parameters:
*	Pointer to head node pointer
* Returns: NONE
* Precondition: List not empty
* Postcondition: List is empty
*/
template <typename T>
void List<T>::deleteList(ListNode<T>* ptr)
{
	if (ptr != nullptr)
	{
	//	std::cout << "Deleting node: " << std::endl << *ptr->getDataPtr();
		deleteFrontNode();
		deleteList(mpHead);
	}
}

/*
* Function: pringList()
* Date Created: 2021/04/06
* Last Modified: 2021/04/06
* Description: Prints the list to the console, this is the public facing funciton, the private funciton does the work
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: List printed to screen (if there were any elements in it)
*/
template <typename T>
void List<T>::printList(void)
{
	if (!isEmpty())
	{
		// list not empty -> printing
		printList(mpHead);
	}
}

/*
* Function: printlist()
* Date Created: 2021/04/06
* Last Modified: 2021/04/06
* Description: Will Print the items in the list
* Input Parameters:
*	Head pointer of list to be printed
* Returns: NONE
* Precondition: NONE
* Postcondition: List print to console
*/
template <typename T>
void List<T>::printList(ListNode<T>* currentPtr)
{
	if (currentPtr != nullptr)
	{
		printList(currentPtr->getNextPtr());
		// printing from the back to the front so it should be in ascending order when it comes out the other side
		std::cout << *currentPtr->getDataPtr() << std::endl;
	}
}

