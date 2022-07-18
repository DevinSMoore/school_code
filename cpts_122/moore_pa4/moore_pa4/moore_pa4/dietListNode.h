/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/8
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 4 Diet and Exercise App

Description:	This file contains the class for our linked lists nodes. not much more
				than that really.
*******************************************************************************************/
#pragma once

#include <string>
#include "dietPlan.h"
class DietNode
{
public:
	// Constructor
	DietNode(void);
	DietNode(DietPlan const& newPlan, DietNode* mpNext = nullptr); // explicit constructor
	// Copy Constructor
	DietNode(const DietNode& copyNode);
	// Destructor
	~DietNode();
	// Copy Assignment Operator overload
	DietNode& operator=(const DietNode& rhs);

	// Getter funcitons
	
	// Returns the pointer to the next node (or nullptr)
	DietNode* getNextPointer(void) const;

	// Returns pointer to plan contained in node
	DietPlan* getPlanPointer(void) const;

	// Accepts a pointer, and will set the current objects mpNext
	void setNextPointer(DietNode* const pNew);

	// Accepts a pointer, and will set the current objects mpNext
	void setPlanPointer(DietPlan* const pNew);

private:
	DietNode* mpNext;
	DietPlan* mpPlan;
};