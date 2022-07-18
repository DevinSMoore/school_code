/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/8
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 4 Diet and Exercise App

Description:	This and fitnessAppWrapper.cpp wil contain all of the funcitons that will
				run the app, and display the app to the user.
*******************************************************************************************/
#pragma once

#include "dietList.h"
#include "exerciseList.h"
#include <fstream>

class FitnessApp
{
public:
	FitnessApp();// , ExerciseList* mpExerciseList = nullptr);
	FitnessApp(const FitnessApp& copy);
	~FitnessApp();
	FitnessApp& operator= (const FitnessApp& rhs);

	// Getters and Setters
	DietList* getDietListPointer() const;
	ExerciseList* getExerciseListPointer() const;

	std::fstream &getDietFile(void);
	std::fstream &getExerciseFile(void);

	// Sets the diet and exercise pointers in current object
	void setDietPointer(DietList* pNew);
	void setExercisePointer(ExerciseList* pNew);



	/*
	* Function: printMenu()
	* Date Created: 2021/03/13
	* Last Modified: 2021/03/13
	* Description: Will print the menu to the screen
	* Input Parameters: NONE
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: Menu printed to screen
	*/
	void printMenu(void);


	/*
	* Function: loadDailyPlan()
	* Date Created: 2021/03/10
	* Last Modified: 2021/03/10
	* Description: Will load a single plan from a file
	* Input Parameters:
	*	std::fstream infile: file to be read in
	* Returns: pointer to new plan
	* Precondition: File is open for reading
	* Postcondition: New plan has been filled with data from file and pointer returned
	*/
	void loadDailyPlan(std::fstream &infile, DietPlan &plan);

	/*
	* Function: loadWeeklyDietPlan()
	* Date Created: 2021/03/10
	* Last Modified: 2021/03/10
	* Description: Will load a weeks worth of plans from a file to the dietList
	* Input Parameters:
	* Returns: NONE
	* Precondition: File is open for reading
	* Postcondition: Seven plans read from file and placed into the list
	*/
	void loadWeeklyDietPlan(void);

	/*
	* Function: storeDailyPlan()
	* Date Created: 2021/03/12
	* Last Modified: 2021/03/12
	* Description: Will store a single plan to a file
	* Input Parameters:
	*	std::fstream infile: file to be read in
	* Returns: pointer to new plan
	* Precondition: File is open
	* Postcondition: New plan has been filled with data from file and pointer returned
	*/
	void storeDailyPlan(std::fstream& infile, DietPlan& plan);

	/*
	* Function: storeWeeklyPlan()
	* Date Created: 2021/03/12
	* Last Modified: 2021/03/12
	* Description: Will store a weeks worth of plans to a file from the dietList
	* Input Parameters:
	* Returns: NONE
	* Precondition: File is open
	* Postcondition: Seven plans read from file and placed into the list
	*/
	void storeWeeklyPlan(DietNode* pHeadTemp);

	/*
	* Function: loadDailyPlan()
	* Date Created: 2021/03/12
	* Last Modified: 2021/03/12
	* Description: Will load a single Exercise plan from a file
	* Input Parameters:
	*	reference to file to be read in
	*	Reference to a diet plan
	* Returns:
	* Precondition: File is open for reading
	* Postcondition: New plan has been filled with data from file
	*/
	void loadDailyPlan(std::fstream& infile, ExercisePlan& plan);

	/*
	* Function: loadWeeklyExercisePlan()
	* Date Created: 2021/03/10
	* Last Modified: 2021/03/10
	* Description: Will load a weeks worth of plans from a file to the dietList
	* Input Parameters:
	* Returns: NONE
	* Precondition: File is open for reading
	* Postcondition: Seven plans read from file and placed into the list
	*/
	void loadWeeklyExercisePlan(void);

	/*
	* Function: storeDailyPlan()
	* Date Created: 2021/03/12
	* Last Modified: 2021/03/12
	* Description: Will store a single plan to a file
	* Input Parameters:
	*	reference to file to be read in
	*	Reference to a diet plan
	* Returns: pointer to new plan
	* Precondition: File is open
	* Postcondition: New plan has been filled with data from file and pointer returned
	*/
	void storeDailyPlan(std::fstream& infile, ExercisePlan& plan);

	/*
	* Function: storeWeeklyPlan()
	* Date Created: 2021/03/12
	* Last Modified: 2021/03/12
	* Description: Will store a weeks worth of plans to a file from the dietList
	* Input Parameters:
	*	Head pointer to list to be printed to file
	* Returns: NONE
	* Precondition: File is open
	* Postcondition: Seven plans read from file and placed into the list
	*/
	void storeWeeklyPlan(ExerciseNode* pHeadTemp);





	/*
	* Function: displayDietDay()
	* Date Created: 2021/03/09
	* Last Modified: 2021/03/09
	* Description: Will display a single days diet plan
	* Input Parameters: 
	*	DietPlan& plan: reference to the plan to be displayed
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: Plan displayed to screen
	*/
	void displayDayPlan(const DietPlan& plan);

	/*
	* Function: displayWeekPlans()
	* Date Created: 2021/03/09
	* Last Modified: 2021/03/09
	* Description: Will display a week of diet plans
	* Input Parameters:
	*	DietNode* pHead: Pass a copy of the head pointer for the diet list
	* Returns: NONE
	* Precondition: List contains only 7 items
	* Postcondition: Entire week of plans displayed to console
	*/
	void displayWeekPlans(DietNode* const pHead);

	/*
	* Function: displayExerciseDay()
	* Date Created: 2021/03/09
	* Last Modified: 2021/03/09
	* Description: Will display a single exercise plan
	* Input Parameters:
	*	DietPlan& plan: reference to the plan to be displayed
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: Plan displayed to screen
	*/
	void displayDayPlan(const ExercisePlan& plan);

	/*
	* Function: displayWeekPlans()
	* Date Created: 2021/03/09
	* Last Modified: 2021/03/09
	* Description: Will display a week of exercise plans
	* Input Parameters:
	*	DietNode* pHead: Pass a copy of the head pointer for the Exercise list
	* Returns: NONE
	* Precondition: List contains only 7 items
	* Postcondition: Entire week of plans displayed to console
	*/
	void displayWeekPlans(ExerciseNode* const pHead);


	/*
	* Function: runApp()
	* Date Created: 2021/03/13
	* Last Modified: 2021/03/13
	* Description: Will go through the logic of the program. printing menu and handling all needed function calls and stuff like that
	* Input Parameters: NONE
	* Returns: NONE
	* Precondition: Program has been written
	* Postcondition: App runs
	*/
	void runApp(void);

private:
	DietList* mpDietList;
	ExerciseList* mpExerciseList;

	std::fstream dietPlans;
	std::fstream exercisePlans;

};
