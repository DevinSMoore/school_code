/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/12
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA8 Data Analysis with BSTs

Description: This holds the Binary Search Tree class. It has in order printing, and
			functions to find the node with the least units sold/purchased
*******************************************************************************************/
#pragma once
#include "Node.h"
#include "TransactionNode.h"

class BST
{
public:
	// Default constructor
	BST();
	// Destructor
	~BST();

	// Getters and Setters
	Node*& getRoot(void);

	void setRoot(Node*& newRoot);

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
	void insert(std::string& newData, int& newUnitData);

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
	void inOrderTraversal(void);

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
	TransactionNode& findSmallest(void);

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
	TransactionNode& findLargest(void);
private:
	Node* mpRoot;

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
	void destroyTree(Node* pRoot);

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
	void insert(std::string& newData, int& newUnitData, Node* pRoot);

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
	void inOrderTraversal(Node* pRoot);

};
