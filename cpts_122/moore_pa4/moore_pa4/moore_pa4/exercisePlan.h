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
#pragma once
#include <string>
#include <iostream>
#include <fstream>

class ExercisePlan
{
public:
	ExercisePlan(std::string planName = "", int goal = 0, std::string startDate = "");
	ExercisePlan(const ExercisePlan& copyPlan);
	~ExercisePlan(void);

	// Overloading assignment operator
	ExercisePlan& operator= (const ExercisePlan& rhs);

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
* Description: Overloads the oustream operator allowing us to plrint the Exercise plan
*/
std::ostream& operator<< (std::ostream& os, ExercisePlan const& plan);

/*
* Function: oStream operator overload
* Date Created: 2021/03/8
* Last Modified: 2021/03/8
* Description: Overloads the oustream operator allowing us to plrint the Exercise plan
*/
std::istream& operator>> (std::fstream& infile, ExercisePlan& newPlan);

/*
* Function: oStream operator overload
* Date Created: 2021/03/8
* Last Modified: 2021/03/8
* Description: Overloads the oustream operator allowing us to plrint the Exercise plan
*/
// Overloading the outstream operator
// Will print a Exercise plan to the file
std::ostream& operator<< (std::fstream& outfile, ExercisePlan& newPlan);
