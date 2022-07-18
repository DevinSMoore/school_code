/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/8
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 4 Diet and Exercise App

Description:	This file contains the class for our linked lists nodes. not much more
				than that really.
*******************************************************************************************/
#include "dietListNode.h"

DietNode::DietNode(void)
{ 
	this->mpNext = nullptr; // Always set next pointer to nullptr
	this->mpPlan = new DietPlan;
}

DietNode::DietNode(DietPlan const& newPlan, DietNode* mpNext)
{
	this->mpNext = mpNext;
	this->mpPlan = new DietPlan;
	*(this->mpPlan) = newPlan; // using the copy assignment operator to set the data in the new plan to the passed plan
}

DietNode::DietNode(const DietNode& copyNode)
{
	this->mpNext = copyNode.mpNext; // copying over next pointer from copyNode
	this->mpPlan = new DietPlan; // making space for a new plan
	*(this->mpPlan) = *(copyNode.mpPlan); // useing assingment operator from the DietPlan class to copy over data in plans
}

// Deconstructor
// I'm going to free the memory of the Plan in here
DietNode::~DietNode()
{
	std::cout << std::endl << "Hit node deconstructor...";
	
}

// Copy Assignment Operator overload
DietNode& DietNode::operator=(const DietNode& rhs)
{
	this->mpNext = rhs.mpNext; // copying over next pointer from copyNode
	this->mpPlan = new DietPlan; // making space for a new plan
	*(this->mpPlan) = *(rhs.mpPlan); // useing assingment operator from the DietPlan class to copy over data in plans

	return *this;
}


// Setters and Getters

// Returns the pointer to the next node (or nullptr)
DietNode* DietNode::getNextPointer(void) const
{
	return this->mpNext;
}

// Returns pointer to plan contained in node
DietPlan* DietNode::getPlanPointer(void) const
{
	return this->mpPlan;
}

// Accepts a pointer, and will set the current objects mpNext
void DietNode::setNextPointer( DietNode* const pNew)
{
	this->mpNext = pNew;
}

// Accepts a pointer, and will set the current objects mpNext
void DietNode::setPlanPointer(DietPlan* const pNew)
{
	this->mpPlan = pNew;
}


