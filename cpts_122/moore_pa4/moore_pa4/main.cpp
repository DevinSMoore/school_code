/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/8
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 4 Exercise and Exercise App

Description:	This program will store a 7 day plan for a users Exercise and exercise
				It will allow the user to adjust the items in their plans, and load
				plans from a file. Plans will also be saved to a file upon request
				or exit from program.
*******************************************************************************************/
#include "fitnessAppWrapper.h"
#include "testApp.h"
int main(void)
{	
	FitnessApp app;
	std::cout << "Hello and welcome to my FitnessApp." << std::endl;

	app.runApp();

	//Test newTest;
	// newTest.testDietListCopyAssignmentOperator();
	//newTest.testStoreWeeklyPlanEx();
	//newTest.testExerciseListCopyAssignmentOperator();
	// newTest.testDietListCopyAssignmentOperator();

	// newTest.testFstreamInsertionOverload();
	
	// newTest.testLoadWeeklyPlan();
	
	//newTest.testStoreDayPlan();

	//file.open("dietPlans.txt", std::ios::out || std::ios::trunc);

	/*std::fstream dietPlans;

	dietPlans.open("dietPlans.txt", std::fstream::in);
	DietPlan nPlan;*/
	return 0;
}