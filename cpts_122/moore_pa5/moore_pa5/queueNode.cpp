/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/15
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 5 Grocery Store Simulator

Description: This will contain the node class which will contain our customer data
*******************************************************************************************/
#include "queueNode.h"

// Default Constructors
QueueNode::QueueNode()
{
	mpNext = new QueueNode; 

	mpData = new CustomerData;
}

QueueNode::QueueNode(const CustomerData& newData)
{
	mpNext = nullptr; 
	
	mpData = new CustomerData;
	*mpData = newData;
}

// Copy constructor
QueueNode::QueueNode(const QueueNode& newCopy)
{
	mpData = new CustomerData(*newCopy.getDataPtr());
	mpNext = newCopy.mpNext;
}

// Destructor
QueueNode::~QueueNode()
{
	// std::cout << "Hit QueueNode destructor: Deleting Data..." << std::endl;
	delete mpData;
}

// Copy assignment operator
QueueNode& QueueNode::operator= (const QueueNode& rhs)
{
	mpData = new CustomerData(*rhs.getDataPtr());
	mpNext = rhs.mpNext;
	
	return *this;
}

// Getters and Setters
CustomerData* QueueNode::getDataPtr(void) const
{
	return mpData;
}

QueueNode* QueueNode::getNextPtr(void) const
{
	return mpNext;
}

void QueueNode::setDataPtr(CustomerData* newPtr)
{
	mpData = newPtr;
}

void QueueNode::setNextPtr(QueueNode* const newPtr)
{
	mpNext = newPtr;
}