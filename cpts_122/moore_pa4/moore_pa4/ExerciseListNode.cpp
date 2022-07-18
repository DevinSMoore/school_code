/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/8
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 4 Exercise and Exercise App

Description:	This contains the exercise list class and all functions necesarry to get
				it running.
*******************************************************************************************/
#include "ExerciseListNode.h"

ExerciseNode::ExerciseNode(void)
{
	this->mpNext = nullptr; // Always set next pointer to nullptr
	this->mpPlan = new ExercisePlan;
}

ExerciseNode::ExerciseNode(ExercisePlan const& newPlan, ExerciseNode* mpNext)
{
	this->mpNext = mpNext;
	this->mpPlan = new ExercisePlan;
	*(this->mpPlan) = newPlan; // using the copy assignment operator to set the data in the new plan to the passed plan
}

ExerciseNode::ExerciseNode(const ExerciseNode& copyNode)
{
	this->mpNext = copyNode.mpNext; // copying over next pointer from copyNode
	this->mpPlan = new ExercisePlan; // making space for a new plan
	*(this->mpPlan) = *(copyNode.mpPlan); // useing assingment operator from the ExercisePlan class to copy over data in plans
}

// Deconstructor
// I'm going to free the memory of the Plan in here
ExerciseNode::~ExerciseNode()
{
	// std::cout << std::endl << "Hit node deconstructor..." << std::endl;
}

// Copy Assignment Operator overload
ExerciseNode& ExerciseNode::operator=(const ExerciseNode& rhs)
{
	this->mpNext = rhs.mpNext; // copying over next pointer from copyNode
	this->mpPlan = new ExercisePlan; // making space for a new plan
	*(this->mpPlan) = *(rhs.mpPlan); // useing assingment operator from the ExercisePlan class to copy over data in plans

	return *this;
}


// Setters and Getters

// Returns the pointer to the next node (or nullptr)
ExerciseNode* ExerciseNode::getNextPointer(void) const
{
	return this->mpNext;
}

// Returns pointer to plan contained in node
ExercisePlan* ExerciseNode::getPlanPointer(void) const
{
	return this->mpPlan;
}

// Accepts a pointer, and will set the current objects mpNext
void ExerciseNode::setNextPointer(ExerciseNode* const pNew)
{
	this->mpNext = pNew;
}

// Accepts a pointer, and will set the current objects mpNext
void ExerciseNode::setPlanPointer(ExercisePlan* const pNew)
{
	this->mpPlan = pNew;
}


