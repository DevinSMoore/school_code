/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/22
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: Morse code decoder thing PA6

Description: This contains the template class for the Binary Search Tree 
*******************************************************************************************/
#pragma once
#include "BSTNode.h"
#include <string>
#include <fstream>

template <typename T>
class BST
{
public:
	// Constructor
	BST();
	// Copy constructor
	BST(const BST<T>& copy);
	// Destrcutor
	~BST();

	// Overloaded thing operator
	BST<T>& operator= (const BST<T>& rhs);

	// Getters and Setters
	BSTNode<T>* getRootPtr(void) const;

	void setRootPtr(BSTNode<T>* const newPtr);

	// Public Member Functions

	/*
	* Function: printInOrder()
	* Date Created: 2021/03/21
	* Last Modified: 2021/03/21
	* Description: This is the public function for the printInOrder which will print the tree in ascending order
	* Input Parameters:
	*	BSTNode*: Pointer to root node of tree
	* Returns: NONE
	* Precondition:	Queue is not empty
	* Postcondition: All data in tree displayed to screen
	*/
	void printInOrder(void);


	/*
	* Function: isEmpty()
	* Date Created: 2021/03/21
	* Last Modified: 2021/03/21
	* Description: Will check if the tree is empty
	* Input Parameters: NONE
	* Returns:
		bool value true if tree is empty false if it's isn't
	* Precondition:	NONE
	* Postcondition: bool value returned
	*/
	bool isEmpty(void);

private:
	// Member data
	BSTNode<T>* mpRoot;

	// Private member functions

	/*
	* Function: isEmpty()
	* Date Created: 2021/03/21
	* Last Modified: 2021/03/21
	* Description: Will delete all of the nodes in our tree; This function is meant for the destructor
	* Input Parameters:
	*	Root pointer of BST
	* Returns: NONE
	* Precondition:	Tree is not empty
	* Postcondition: All nodes deleted from tree
	*/
	void deleteTree(BSTNode<T>* rootPtr);

	/*
	* Function: printInOrder()
	* Date Created: 2021/03/21
	* Last Modified: 2021/03/21
	* Description: will print tree in order
	* Input Parameters:
	*	BSTNode*: Pointer to root node of tree
	* Returns: NONE
	* Precondition:	Queue is not empty
	* Postcondition: All data in tree displayed to screen
	*/
	void printInOrder(BSTNode<T>* rootPtr);

	/*
	* Function: copyNodes()
	* Date Created: 2021/03/22
	* Last Modified: 2021/03/22
	* Description: Deep copies the nodes from the copyRoot to the targetRoot
	* Input Parameters:
	*	BSTNode* pointer to copy target
	*	BSTNode* pointer to thing we're copying from
	* Returns: NONE
	* Precondition: Tree not empty
	* Postcondition:
	*/
	void copyNodes(BSTNode<T>* targetRoot, BSTNode<T>* copyRoot);


	/*
	* Function: insertNode()
	* Date Created: 2021/03/22
	* Last Modified: 2021/03/22
	* Description: Inserts a node into our tree
	* Input Parameters:
	*	Data reference to information to add to node
	*	BSTNode pointer to root of tree
	* Returns:
	*	int indicating success (1 = true; 0 = false)
	* Precondition: NONE
	* Postcondition: Node inserted into proper location and int returned
	*/
	int insertNode(const T& newData, BSTNode<T>* pRoot);
};

// Constructor
template <typename T>
BST<T>::BST()
{
	std::string tempString = "";
	mpRoot = nullptr;
	std::fstream infile;
	infile.open("morseTable.txt"); // open for reading

	T newData;
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			std::getline(infile, tempString, ' ');
			// so tempString should have the char representing the ascii character 
			newData.setChar(tempString.c_str()[0]); // so .c_str() returns a c type string and the 0th element in that ctype string should be the ascii char we're concerned with
			std::getline(infile, tempString);
			newData.setMorseString(tempString); // newData should contain both a char and a string with our morse info in it
		//	std::cout << newData << std::endl;
			if (newData.getChar() != '\n') // this is so we don't insert any junk nodes full of new lines
			{
				insertNode(newData, mpRoot);
			}
		}
		infile.close(); // closing file
	}
}
// Copy constructor
template <typename T>
BST<T>::BST(const BST<T>& copy)
{

	if (copy.getRootPtr() == nullptr)
	{
		mpRoot = nullptr;
	}
	else
	{
		mpRoot = new BSTNode<T>;
		copyNodes(mpRoot, copy.getRootPtr());
	}


}
// Destrcutor
template <typename T>
BST<T>::~BST()
{
	// std::cout << "Hit BST destructor..." << std::endl;
	if (mpRoot != nullptr)
	{
		deleteTree(mpRoot); // Delete all nodes
	}
}

// Overloaded thing operator
template <typename T>
BST<T>& BST<T>::operator= (const BST<T>& rhs)
{
	if (rhs.getRootPtr() == nullptr)
	{
		mpRoot = nullptr;
	}
	else
	{
		copyNodes(mpRoot, rhs.getRootPtr());
	}
	return *this;

}

template <typename T>
void BST<T>::copyNodes(BSTNode<T>* targetRoot, BSTNode<T>* copyRoot)
{
	if (copyRoot != nullptr) // this should copy the tree in order (not that order matters in this particular case
	{
		*targetRoot = *copyRoot; // copy node at this location

		if (copyRoot->getLeftPtr() != nullptr) // If the left subtree is not null the we want to create a new space on the heap for the left pointer of our target
		{
			targetRoot->setLeftPtr(new BSTNode<T>);
		}

		copyNodes(targetRoot->getLeftPtr(), copyRoot->getLeftPtr()); // go down left subtree

		if (copyRoot->getRightPtr() != nullptr) // Same logic as above but for going to the right
		{
			targetRoot->setRightPtr(new BSTNode<T>);
		}

		copyNodes(targetRoot->getRightPtr(), copyRoot->getRightPtr()); // go down right subtree

	}
}

// Getters and Setters
template <typename T>
BSTNode<T>* BST<T>::getRootPtr(void) const
{
	return mpRoot;
}

template <typename T>
void BST<T>::setRootPtr(BSTNode<T>* const newPtr)
{
	mpRoot = newPtr;
}

// Public Member Functions

/*
* Function: printInOrder()
* Date Created: 2021/03/21
* Last Modified: 2021/03/21
* Description: This is the public function for the printInOrder which will print the tree in ascending order
* Input Parameters:
*	BSTNode*: Pointer to root node of tree
* Returns: NONE
* Precondition:	NONE
* Postcondition: printInOrder recursion function (if tree not empty) called and data displayed to screen
*/
template <typename T>
void BST<T>::printInOrder(void)
{
	if (mpRoot != nullptr)
	{
		printInOrder(mpRoot);
	}
	else
	{
		std::cout << "Tree empty..." << std::endl;
	}
}


// Private member functions

/*
* Function: isEmpty()
* Date Created: 2021/03/21
* Last Modified: 2021/03/21
* Description: Will check if the tree is empty
* Input Parameters: NONE
* Returns:
	bool value true if tree is empty false if it's isn't
* Precondition:	NONE
* Postcondition: bool value returned
*/
template <typename T>
bool BST<T>::isEmpty(void)
{
	return (mpRoot == nullptr) ? (true) : (false);
}

/*
* Function: isEmpty()
* Date Created: 2021/03/21
* Last Modified: 2021/03/21
* Description: Will delete all of the nodes in our tree; This function is meant for the destructor
* Input Parameters:
*	Root pointer of BST
* Returns: NONE
* Precondition:	Tree is not empty
* Postcondition: All nodes deleted from tree
*/
template <typename T>
void BST<T>::deleteTree(BSTNode<T>* rootPtr)
{
	// static int count = 1;
	if (rootPtr != nullptr)
	{
		deleteTree(rootPtr->getLeftPtr());
		deleteTree(rootPtr->getRightPtr());
		delete rootPtr;
		// std::cout << count++ << " Node(s) deleted...." << std::endl;
	}
}

/*
* Function: printInOrder()
* Date Created: 2021/03/21
* Last Modified: 2021/03/21
* Description: will print tree in order
* Input Parameters:
*	BSTNode*: Pointer to root node of tree
* Returns: NONE
* Precondition:	Queue is not empty
* Postcondition: All data in tree displayed to screen
*/
template <typename T>
void BST<T>::printInOrder(BSTNode<T>* rootPtr)
{
	if (rootPtr != nullptr)
	{
		printInOrder(rootPtr->getLeftPtr());
		std::cout << std::endl << *(rootPtr->getDataPtr()) << std::endl;
		printInOrder(rootPtr->getRightPtr()); // Go to lowest node (keep going to left until you can't anymore) then print then start to crawl back up the list checking for values that will be greater than the current node
	}
}

/*
* Function: insertNode()
* Date Created: 2021/03/22
* Last Modified: 2021/03/22
* Description: Inserts a node into our tree
* Input Parameters:
*	Data reference to information to add to node
*	BSTNode pointer to root of tree
* Returns:
*	int indicating success (1 = true; 0 = false)
* Precondition: NONE
* Postcondition: Node inserted into proper location and int returned
*/
template <typename T>
int BST<T>::insertNode(const T& newData, BSTNode<T>* pRoot)
{
	if (pRoot == nullptr)
	{
		setRootPtr(new BSTNode<T>(newData));
		return (pRoot != nullptr) ? (1) : (0); // if the memory was successfully allocated return 1

	}
	else if (newData.getChar() < pRoot->getDataPtr()->getChar()) // If the ascii char in our passed data is less than the char in the node go left
	{
		if (pRoot->getLeftPtr() == nullptr) // If left is null then that's where we're going to stake our claim
		{
			pRoot->setLeftPtr(new BSTNode<T>(newData));
			return (pRoot->getLeftPtr() != nullptr) ? (1) : (0); // if the memory was successfully allocated return 1
		}
		else {
			insertNode(newData, pRoot->getLeftPtr());
			return 0; // I included these because the compiler bugged be about not all control paths returning a value
		}
	}
	else if (newData.getChar() > pRoot->getDataPtr()->getChar()) // newData greater than -> go right
	{
		if (pRoot->getRightPtr() == nullptr)
		{
			pRoot->setRightPtr(new BSTNode<T>(newData));
			return (pRoot->getRightPtr() != nullptr) ? (1) : (0); // if the memory was successfully allocated return 1
		}
		else
		{
			insertNode(newData, pRoot->getRightPtr());
			return 0;
		}
	}
	else // newData exists in tree -> do nothing
	{
		// boo
		std::cout << "Data exists in tree..." << std::endl << "No new node inserted..." << std::endl;
		return 0;
	}
}