/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/22
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: Morse code decoder thing PA6

Description: This contains the template class for a BSTnode that contains some data type T
*******************************************************************************************/
#pragma once
#include <iostream>
#include <string>
#include "data.h"

template <typename T>
class BSTNode
{
public:
	// Default (explicit) Constructor
	BSTNode();
	BSTNode(const T& pData);
	// Copy constructor
	BSTNode(const BSTNode<T>& copy);
	// Destructor
	~BSTNode();
	// Overloading the copy assignment operator
	BSTNode<T>& operator= (BSTNode<T>& rhs);

	// Getters and Setters
	T* getDataPtr(void) const;
	BSTNode<T>* getLeftPtr(void) const;
	BSTNode<T>* getRightPtr(void);

	void setDataPtr(T* const newPtr);
	void setLeftPtr(BSTNode<T>* const newPtr);
	void setRightPtr(BSTNode<T>* const newPtr);



private:
	T* mpData;
	BSTNode<T>* mpLeft;
	BSTNode<T>* mpRight;
};


// Constructor
template <typename T>
BSTNode<T>::BSTNode()
{
	mpLeft = mpRight = nullptr;
	mpData = nullptr;
}


template <typename T>
BSTNode<T>::BSTNode(const T& pData)
{
	mpLeft = mpRight = nullptr;
	mpData = new T;
	*mpData = pData;

}


// Copy constructor
template <typename T>
BSTNode<T>::BSTNode(const BSTNode& copy)
{
	mpLeft = nullptr;
	mpRight = nullptr;
	mpData = new T;
	*mpData = *copy.getDataPtr();
}


// Destructor
template <typename T>
BSTNode<T>::~BSTNode()
{
	// I'm going to delete all of the nodes in the BST class
	// std::cout << std::endl << "Hit BSTNode Destructor... " << std::endl;

}

// Overloading the copy assignment operator
template <typename T>
BSTNode<T>& BSTNode<T>::operator= (BSTNode& rhs)
{
	mpData = new T;
	*mpData = *rhs.getDataPtr();

	mpLeft = rhs.getLeftPtr();
	this->mpRight = rhs.getRightPtr();

	return *this;
}

// Getters and Setters
template <typename T>
T* BSTNode<T>::getDataPtr(void) const
{
	return mpData;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getLeftPtr(void) const
{
	return mpLeft;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getRightPtr(void)
{
	return mpRight;
}

template <typename T>
void BSTNode<T>::setDataPtr(T* const newPtr)
{
	mpData = newPtr;
}

template <typename T>
void BSTNode<T>::setLeftPtr(BSTNode<T>* const newPtr)
{
	mpLeft = newPtr;
}

template <typename T>
void BSTNode<T>::setRightPtr(BSTNode<T>* const newPtr)
{
	mpRight = newPtr;
}
