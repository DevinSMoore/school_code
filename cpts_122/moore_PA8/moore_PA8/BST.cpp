/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/12
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA8 Data Analysis with BSTs

Description: This contains the funcion definitions for the BST class
*******************************************************************************************/
#include "BST.h"


BST::BST() 
{
	mpRoot = nullptr;
}

BST::~BST()
{
	if (mpRoot != nullptr)
	{
		destroyTree(mpRoot);
	}
}

// Getters and Setters
Node*& BST::getRoot(void)
{
	return mpRoot;
}

void BST::setRoot(Node*& newRoot)
{
	mpRoot = newRoot;
}

/*
* Function: insert()
* Date Created: 2021/04/12
* Last Modified: 2021/04/12
* Description: Will insert a node into the tree
* Input Parameters:
*	reference to string for the type of unit
*	reference to number of units
* Returns: NONE
* Precondition: NONE
* Postcondition: Node inserted into tree
*/
void BST::insert(std::string& newData, int& newUnitData)
{
	insert(newData, newUnitData, mpRoot);
}

/*
* Function: inOrderTraversal()
* Date Created: 2021/04/12
* Last Modified: 2021/04/12
* Description: will go through the tree in order priting the information
* Input Parameters:
*	NONE
* Returns:
*	NONE
* Precondition: NONE
* Postcondition: Tree printed to console
*/
void BST::inOrderTraversal(void)
{
	if (mpRoot != nullptr)
	{
		inOrderTraversal(mpRoot);
	}
}

/*
* Function: findSmallest()
* Date Created: 2021/04/12
* Last Modified: 2021/04/12
* Description: will find the node w/ the smallest value of units sold/purchased
* Input Parameters: NONE
* Returns:
*	reference to node with smallest unit val
* Precondition: Tree not empty
* Postcondition: Node with smallest val returned
*/
TransactionNode& BST::findSmallest(void)
{

	TransactionNode* tempRoot = (TransactionNode * )mpRoot;
	// traverse to the furthes left node which is the node with the lowest unit value
	while (tempRoot->getLeftPtr() != nullptr)
	{
		tempRoot = (TransactionNode*)tempRoot->getLeftPtr(); // keep going left until the next left ptr is null
	}

	return *tempRoot;
}

/*
* Function: findLargest()
* Date Created: 2021/04/12
* Last Modified: 2021/04/12
* Description: WIll return node with largest unit val
* Input Parameters: NONE
* Returns:
*	reference to node w/ largest value
* Precondition: Tree not empty
* Postcondition:Node with biggest val returned
*/
TransactionNode& BST::findLargest(void)
{
	TransactionNode* tempRoot = (TransactionNode*)mpRoot;
	// traverse to the furthes left node which is the node with the lowest unit value
	while (tempRoot->getRightPtr() != nullptr)
	{
		tempRoot = (TransactionNode*)tempRoot->getRightPtr(); // keep going left until the next left ptr is null
	}

	return *tempRoot;
}

/*
* Function: destroyTree()
* Date Created: 2021/04/12
* Last Modified: 2021/04/12
* Description: will recursively go through and delete all nodes in tree (post order)
* Input Parameters:
*	pointer to root node
* Returns: NONE
* Precondition: NONE
* Postcondition: No nodes remain in the tree
*/
void BST::destroyTree(Node* pRoot)
{
	if (pRoot != nullptr) // Doing post order deletion
	{
		destroyTree(pRoot->getLeftPtr());
		destroyTree(pRoot->getRightPtr());
		delete pRoot;
	}
}

/*
* Function: insert()
* Date Created: 2021/04/12
* Last Modified: 2021/04/12
* Description: will insert a node with the data into the tree
* Input Parameters:
*	reference to string of data to be inserted
*	reference to int of units to be stored
*	pointer to root node
* Returns: NONE
* Precondition: NONE
* Postcondition: Node inserted into the tree
*/
void BST::insert(std::string& newData, int& newUnitData, Node* pRoot)
{
	Node* tempNode = new TransactionNode(newData, newUnitData); // Allocating new memory for our node

	if (tempNode != nullptr)
	{
		if (pRoot == nullptr)
		{
			setRoot(tempNode);
		}
		else if (newUnitData < ((TransactionNode*)pRoot)->getUnits()) // If the ascii char in our passed data is less than the char in the node go left
		{
			if (pRoot->getLeftPtr() == nullptr) // If left is null then that's where we're going to insert the new node
			{
				pRoot->setLeftPtr(tempNode);
			}
			else {
				insert(newData, newUnitData, pRoot->getLeftPtr());
			}
		}
		else if (newUnitData > ((TransactionNode*)pRoot)->getUnits()) // newData greater than -> go right
		{
			if (pRoot->getRightPtr() == nullptr)
			{
				pRoot->setRightPtr(tempNode);
			}
			else
			{
				insert(newData, newUnitData, pRoot->getRightPtr());
			}
		}
		else // newData exists in tree -> do nothing
		{
			std::cout << "Data exists in tree..." << std::endl << "No new node inserted..." << std::endl;
		}
	}
}

/*
* Function: inOrderTraversal()
* Date Created: 2021/04/12
* Last Modified: 2021/04/12
* Description: will go through in order and print the data
* Input Parameters:
*	pointer to root node
* Returns: NONE
* Precondition: NONE
* Postcondition: All nodes printed to console
*/
void BST::inOrderTraversal(Node* pRoot)
{
	if (pRoot != nullptr)
	{
		inOrderTraversal(pRoot->getLeftPtr());
		((TransactionNode*)pRoot)->printData();
		std::cout << std::endl;
		inOrderTraversal(pRoot->getRightPtr());
	}
}