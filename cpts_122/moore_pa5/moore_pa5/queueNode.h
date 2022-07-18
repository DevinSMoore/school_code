/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/15
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 5 Grocery Store Simulator

Description: This will contain the node class which will contain our customer data
*******************************************************************************************/
#pragma once
#include "customerData.h"

class QueueNode
{
public:
	// Default constcructors
	QueueNode();
	QueueNode(const CustomerData& newData);
	// Copy constructor
	QueueNode(const QueueNode& newCopy);
	// Destructor
	~QueueNode();
	//Copy Assignment operator overload
	QueueNode& operator= (const QueueNode& rhs);

	// Getters and Setters
	CustomerData* getDataPtr(void) const;
	QueueNode* getNextPtr(void) const;

	void setDataPtr(CustomerData* newPtr);
	void setNextPtr(QueueNode* const newPtr);


private:
	CustomerData* mpData;
	QueueNode* mpNext;
};