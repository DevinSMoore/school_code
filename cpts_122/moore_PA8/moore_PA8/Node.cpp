/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/12
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA8 Data Analysis with BSTs

Description: This contains the funcion definitions for the Node class
*******************************************************************************************/
#include "Node.h"

// Default Constructor
Node::Node(std::string newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;

}

// Copy constructor
Node::Node(Node& copy)
{
	mData = copy.getData();
	mpLeft = copy.getLeftPtr();
	mpRight = copy.getRightPtr();
}

// Copy assignment operator
Node& Node::operator=(Node& rhs)
{
	if(&rhs != this)
	{
		mData = rhs.getData();
		mpLeft = rhs.getLeftPtr();
		mpRight = rhs.getRightPtr();
	}

	return *this;
}

// Destructor
Node::~Node()
{

}


// Getters and Setters
std::string Node::getData(void) const
{
	return mData;
}

Node*& Node::getLeftPtr(void)
{
	return mpLeft;
}

Node*& Node::getRightPtr(void)
{
	return mpRight;
}

void Node::setData(const std::string& newData)
{
	mData = newData;
}

void Node::setLeftPtr(Node* newPtr)
{
	mpLeft = newPtr;
}

void Node::setRightPtr(Node* newPtr)
{
	mpRight = newPtr;
}
