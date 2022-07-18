/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/8
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 4 Exercise and Exercise App

Description:	This contains the exercise list class and all functions necesarry to get 
				it running.
*******************************************************************************************/
#pragma once

#include <string>
#include "ExercisePlan.h"
class ExerciseNode
{
public:
	// Constructor
	ExerciseNode(void);
	ExerciseNode(ExercisePlan const& newPlan, ExerciseNode* mpNext = nullptr); // explicit constructor
	// Copy Constructor
	ExerciseNode(const ExerciseNode& copyNode);
	// Destructor
	~ExerciseNode();
	// Copy Assignment Operator overload
	ExerciseNode& operator=(const ExerciseNode& rhs);

	// Getter funcitons

	// Returns the pointer to the next node (or nullptr)
	ExerciseNode* getNextPointer(void) const;

	// Returns pointer to plan contained in node
	ExercisePlan* getPlanPointer(void) const;

	// Accepts a pointer, and will set the current objects mpNext
	void setNextPointer(ExerciseNode* const pNew);

	// Accepts a pointer, and will set the current objects mpNext
	void setPlanPointer(ExercisePlan* const pNew);

private:
	ExerciseNode* mpNext;
	ExercisePlan* mpPlan;
};