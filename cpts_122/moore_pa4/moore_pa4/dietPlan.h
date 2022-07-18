/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/8
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 4 Diet and Exercise App

Description:	This set of files holds the information for the plans, and overloaded
				File insertion operators
*******************************************************************************************/
#pragma once
#include <string>
#include <iostream>
#include <fstream>

class DietPlan
{
public:
	DietPlan( std::string planName = "", int goal = 0, std::string startDate = "");
	DietPlan(const DietPlan& copyPlan);
	~DietPlan(void);

	// Overloading assignment operator
	DietPlan& operator= (const DietPlan& rhs);

	// Setters and getters
	void setGoal(const int newGoal);
	void setPlanName(const std::string newName);
	void setStartDate(const std::string newDate);

	std::string getPlanName(void) const;
	int getGoal(void) const;
	std::string getStartDate(void) const;

	/*
	* Function: editGoal
	* Date Created: 2021/03/8
	* Last Modified: 2021/03/8
	* Description: prompts user to set a new value for the goal; I couldv'e done the prompting outside the function but 
					the PA says to make a funciton that prompts a user to do a thing so this is how I interpreted it.
	* Input Parameters:	NONE
	* Returns: 
	*	int representing wheter user entered valid value or not
	* Precondition:	the object has been created
	* Postcondition: new goal has been set
	*/
	int editGoal(void);

private:
	std::string planName;
	int goal;
	std::string startDate;

};

/*
* Function: oStream operator overload
* Date Created: 2021/03/8
* Last Modified: 2021/03/8
* Description: Overloads the oustream operator allowing us to plrint the diet plan
*/
std::ostream& operator<< (std::ostream& os, DietPlan const & plan);

/*
* Function: iStream operator overload
* Date Created: 2021/03/8
* Last Modified: 2021/03/8
* Description: Overloads the istream operator allowing us to load a plan in from a file
*/
std::istream& operator>> (std::fstream& infile, DietPlan& newPlan);

/*
* Function: oStream operator overload
* Date Created: 2021/03/8
* Last Modified: 2021/03/8
* Description: Overloads the ostream operator allowing us to load a plan in from a file
*/
// Overloading the outstream operator
// Will print a diet plan to the file
std::ostream& operator<< (std::fstream& outfile, DietPlan& newPlan);
