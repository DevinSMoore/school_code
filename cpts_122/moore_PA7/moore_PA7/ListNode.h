/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/10
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA7

Description: This holds the node class for the singly linked list
*******************************************************************************************/
#pragma once
#include <iostream>
#include <string>

template <typename T>
class ListNode
{
public:
	// Default constructor
	ListNode();
	// Constructor with data
	ListNode(const T& newData);
	// Copy constructor
	ListNode(const ListNode& copy);
	// Destructor
	~ListNode();
	// Copy constructor overload
	ListNode& operator=(const ListNode& rhs);

	// Getters and Setters
	ListNode* getNextPtr(void) const;
	T* getDataPtr(void) const;

	void setNextPtr(ListNode*& newPtr);
	void setDataPtr(T*& newPtr);

private:
	ListNode<T>* mpNext;
	T* mpData;
};

// Defualt constructor
template <typename T>
ListNode<T>::ListNode()
{
	std::cout << "Hit Base ListNode Constructor...." << std::endl;
	mpNext = nullptr;
	mpData = nullptr;
}

// Constructor with data
template <typename T>
ListNode<T>::ListNode(const T& newData)
{
	std::cout << "Hit ListNode w/ Data Constructor...." << std::endl;
	mpNext = nullptr;
	mpData = new T(newData);
}

// Copy constructor
template <typename T>
ListNode<T>::ListNode(const ListNode& copy)
{
	mpNext = copy.getNextPtr();
	if(mpData == nullptr)
	{
		mpData = new T(*copy.getDataPtr());
	}
	else
	{
		*mpData = *copy.getDataPtr();
	}
}

// Destructor
template <typename T>
ListNode<T>::~ListNode()
{
	std::cout << "Hit node destructor" << std::endl;
	mpNext = nullptr;
}

// Copy assignment operator overload
template <typename T>
ListNode<T>& ListNode<T>::operator=(const ListNode& rhs)
{
	if (&rhs != this)
	{
		mpNext = rhs.getNextPtr();
		mpData = new T;
		*T = *rhs.getDataPtr();
	}
	return *this;
}

// Getters and Setters
template <typename T>
ListNode<T>* ListNode<T>::getNextPtr(void) const
{
	return mpNext;
}

template <typename T>
T* ListNode<T>::getDataPtr(void) const
{
	return mpData;
}

template <typename T>
void ListNode<T>::setNextPtr(ListNode*& newPtr)
{
	mpNext = newPtr;
}

template <typename T>
void ListNode<T>::setDataPtr(T*& newPtr)
{
	mpData = newPtr;
}

