/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/8
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 4 Diet and Exercise App

Description:	This set of files holds the information for the plans, and overloaded
				File insertion operators
*******************************************************************************************/
#include "dietPlan.h"

// Default Constructor
DietPlan::DietPlan(std::string planName, int goal, std::string startDate)
{
	this->planName = planName;
	this->goal = goal;
	this->startDate = startDate;
}

// Copy Constructor
DietPlan::DietPlan(const DietPlan& copyPlan)
{
	this->planName = copyPlan.planName;
	this->goal = copyPlan.goal;
	this->startDate = copyPlan.startDate;
}

// Deconstructor
DietPlan::~DietPlan(void)
{
	// Not sure what to do in this one since there's no memory to free up so I'll just set everything to default/null vals
	this->planName = "";
	this->goal = 0;
	this->startDate = "";
}

// Overloading assignment operator
DietPlan& DietPlan::operator= (const DietPlan& rhs)
{
	this->planName = rhs.planName;
	this->goal = rhs.goal;
	this->startDate = rhs.startDate;

	return *this;
}

// Setter and Getter functions for the memeber data
void DietPlan::setGoal(const int newGoal)
{ 
	this->goal = newGoal;
}

void DietPlan::setPlanName(const std::string newName)
{
	this->planName = newName;
}

void DietPlan::setStartDate(const std::string newDate)
{
	this->startDate = newDate;
}

std::string DietPlan::getPlanName(void) const
{
	return this->planName;
}


int DietPlan::getGoal(void) const
{
	return this->goal;	
}


std::string DietPlan::getStartDate(void) const
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
int DietPlan::editGoal(void)
{
	int newGoal = 0, success = 0;
	std::cout << "Please enter a new goal for this plan: ";
	std::cin >> newGoal;
	if(newGoal >= 0) // If user entered a positive or zero value we will set the new goal and set success to 1
	{	
		this->setGoal(newGoal);
		std::cout << std::endl << "New goal entered: " << newGoal << std::endl << "Updated Plan: " << std::endl << *this;
		success = 1;
	}
	return success;
}


// Overloading the outstream operator
std::ostream& operator<< (std::ostream& os, const DietPlan & plan)
{
	os << "Plan Name: " << plan.getPlanName() << std::endl << "Goal: " << plan.getGoal() << std::endl << "Plan Start Date: " << plan.getStartDate();
	return os;
}

// Will read in values from the file and place thim into the diet plan
std::istream& operator>> (std::fstream& infile, DietPlan& rhs)
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
// Will print a diet plan to the file
std::ostream& operator<< (std::fstream& outfile, DietPlan & newPlan)
{
	outfile << newPlan.getPlanName() << std::endl << newPlan.getGoal() << std::endl << newPlan.getStartDate() << std::endl;
	return outfile;
}