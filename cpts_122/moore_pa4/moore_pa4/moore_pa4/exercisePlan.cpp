/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/8
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 4 Diet and Exercise App

Description:	This contains the exercisePlan class which contains the data for our
				plan (plan name, goal, start date), and overloaded operators to
				display the data, or read in or store to a file
*******************************************************************************************/
#include "ExercisePlan.h"
// Default Constructor
ExercisePlan::ExercisePlan(std::string planName, int goal, std::string startDate)
{
	this->planName = planName;
	this->goal = goal;
	this->startDate = startDate;
}

// Copy Constructor
ExercisePlan::ExercisePlan(const ExercisePlan& copyPlan)
{
	this->planName = copyPlan.planName;
	this->goal = copyPlan.goal;
	this->startDate = copyPlan.startDate;
}

// Deconstructor
ExercisePlan::~ExercisePlan(void)
{
	// Not sure what to do in this one since there's no memory to free up so I'll just set everything to default/null vals
	this->planName = "";
	this->goal = 0;
	this->startDate = "";
}

// Overloading assignment operator
ExercisePlan& ExercisePlan::operator= (const ExercisePlan& rhs)
{
	this->planName = rhs.planName;
	this->goal = rhs.goal;
	this->startDate = rhs.startDate;

	return *this;
}

// Setter and Getter functions for the memeber data
void ExercisePlan::setGoal(const int newGoal)
{
	this->goal = newGoal;
}

void ExercisePlan::setPlanName(const std::string newName)
{
	this->planName = newName;
}

void ExercisePlan::setStartDate(const std::string newDate)
{
	this->startDate = newDate;
}

std::string ExercisePlan::getPlanName(void) const
{
	return this->planName;
}


int ExercisePlan::getGoal(void) const
{
	return this->goal;
}


std::string ExercisePlan::getStartDate(void) const
{
	return this->startDate;
}

/*
* Function: editGoal
* Date Created: 2021/03/8
* Last Modified: 2021/03/8
* Description: prompts user to set a new value for the goal
* Input Parameters:	NONE
* Returns: NONE
* Precondition:	the object has been created
* Postcondition: new goal has been set
*/
int ExercisePlan::editGoal(void)
{
	int newGoal = 0, success = 0;
	std::cout << "Please enter a new goal for this plan: ";
	std::cin >> newGoal;
	if (newGoal >= 0) // If user entered a positive or zero value we will set the new goal and set success to 1
	{
		this->setGoal(newGoal);
		std::cout << std::endl << "New goal entered: " << newGoal << std::endl << "Updated Plan: " << std::endl << *this;
		success = 1;
	}
	return success;
}


// Overloading the outstream operator
std::ostream& operator<< (std::ostream& os, const ExercisePlan& plan)
{
	os << "Plan Name: " << plan.getPlanName() << std::endl << "Goal: " << plan.getGoal() << std::endl << "Plan Start Date: " << plan.getStartDate();
	return os;
}

// Will read in values from the file and place thim into the Exercise plan
std::istream& operator>> (std::fstream& infile, ExercisePlan& rhs)
{
	std::string tempString = "";
	int newGoal = 0;

	std::getline(infile, tempString);
	rhs.setPlanName(tempString);

	std::getline(infile, tempString);
	rhs.setGoal(std::stoi(tempString));

	std::getline(infile, tempString);
	rhs.setStartDate(tempString);

	return infile;
}

// Overloading the outstream operator
// Will print a Exercise plan to the file
std::ostream& operator<< (std::fstream& outfile, ExercisePlan& newPlan)
{
	outfile << newPlan.getPlanName() << std::endl << newPlan.getGoal() << std::endl << newPlan.getStartDate() << std::endl;
	return outfile;
}