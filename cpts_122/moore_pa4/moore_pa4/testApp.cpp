#include "testApp.h"
#include "fitnessAppWrapper.h"

void Test::testEditGoal(void)
{
	DietPlan nPlan;

	nPlan.setGoal(5);
	std::cout << std::endl << nPlan << std::endl;

	int success = 0;

	success = nPlan.editGoal();
	// going to enter 7 into console
	if (nPlan.getGoal() == 7 && success)
	{
		std::cout << "function was called and value successfully edited." << std::endl;
	}
	else
	{
		std::cout << std::endl << "Failed to properly allocate value" << std::endl << "Value of success: " << success;
	}

	success = nPlan.editGoal();

	if (success)
	{
		std::cout << "Value has been set." << std::endl << "Value: " << nPlan.getGoal() << std::endl;
	}
	else
	{
		std::cout << "Bad value entered" << "Value of success: " << success << std::endl;
	}
}


void Test::testDietListCopyAssignmentOperator(void)
{
	std::string names[7] = {"Plan: 0" , "Plan: 1", "Plan: 2", "Plan: 3", "Plan: 4", "Plan: 5", "Plan: 6"};
	std::string dates[7] = { "00/00/0000" , "11/11/1111", "22/22/2222", "33/33/3333", "44/44/4444", "55/55/5555", "66/66/6666" };
	int goals[7] = { 0 };
	
	FitnessApp aApp;
	FitnessApp bApp;
	DietPlan* pPlan = new DietPlan;
	// bPlan will be our RHS variable being copied

	for (int i = 0; i < 7; i++)
	{
		goals[i] = (i + (i * i)); // goal[0] = 0, g[1] = 2, g[2] = 6, g[3] = 12, g[4] = 20
		pPlan->setGoal(goals[i]);
		pPlan->setPlanName(names[i]);
		pPlan->setStartDate(dates[i]);

		bApp.getDietListPointer()->insertAtFront(*pPlan); // Each new loop will insert a new node with the new information
	}

	std::cout << std::endl << "Printing plan b before: " << std::endl;
	bApp.displayWeekPlans(bApp.getDietListPointer()->getHeadPointer());
	
	*(aApp.getDietListPointer()) = *(bApp.getDietListPointer());
	
	std::cout << std::endl << "Printing plan b after: " << std::endl;
	bApp.displayWeekPlans(bApp.getDietListPointer()->getHeadPointer());
	std::cout << std::endl << "\nPrinting plan a after: " << std::endl;
	aApp.displayWeekPlans(aApp.getDietListPointer()->getHeadPointer());
	
	delete pPlan;
}

void Test::testFstreamInsertionOverload(void)
{
	FitnessApp aApp;
	DietPlan* pPlan = new DietPlan;

	
	if(aApp.getDietFile().is_open())
	{
		aApp.loadDailyPlan(aApp.getDietFile(), *pPlan);
		aApp.displayDayPlan(*pPlan);
		aApp.getDietListPointer()->insertAtFront(*pPlan);
		aApp.displayWeekPlans(aApp.getDietListPointer()->getHeadPointer());
	}
	delete pPlan;
}

void Test::testLoadWeeklyPlan(void)
{
	FitnessApp aApp;
	DietPlan* pPlan = new DietPlan;

	if (aApp.getDietFile().is_open())
	{
		aApp.loadWeeklyDietPlan();
	}
}

void Test::testStoreDayPlan(void)
{
	FitnessApp aApp;

	DietPlan newPlan;
	newPlan.setGoal(50);
	newPlan.setPlanName("Billy Bob's Adventure");
	newPlan.setStartDate("06/15/2025");


	std::fstream outfile("dietPlanStore.txt", std::ios::out | std::ios::trunc);
	aApp.storeDailyPlan(outfile, newPlan);
}



void Test::testExerciseListCopyAssignmentOperator(void)
{
	std::string names[7] = { "Plan: 0" , "Plan: 1", "Plan: 2", "Plan: 3", "Plan: 4", "Plan: 5", "Plan: 6" };
	std::string dates[7] = { "00/00/0000" , "11/11/1111", "22/22/2222", "33/33/3333", "44/44/4444", "55/55/5555", "66/66/6666" };
	int goals[7] = { 0 };

	FitnessApp aApp;
	FitnessApp bApp;
	ExercisePlan* pPlan = new ExercisePlan;
	// bPlan will be our RHS variable being copied

	for (int i = 0; i < 7; i++)
	{
		goals[i] = (i + (i * i)); // goal[0] = 0, g[1] = 2, g[2] = 6, g[3] = 12, g[4] = 20
		pPlan->setGoal(goals[i]);
		pPlan->setPlanName(names[i]);
		pPlan->setStartDate(dates[i]);

		bApp.getExerciseListPointer()->insertAtFront(*pPlan);
	}

	std::cout << std::endl << "Printing plan b before: " << std::endl;
	bApp.displayWeekPlans(bApp.getExerciseListPointer()->getHeadPointer());

	*(aApp.getExerciseListPointer()) = *(bApp.getExerciseListPointer());

	std::cout << std::endl << "Printing plan b after: " << std::endl;
	bApp.displayWeekPlans(bApp.getExerciseListPointer()->getHeadPointer());
	std::cout << std::endl << "\nPrinting plan a after: " << std::endl;
	aApp.displayWeekPlans(aApp.getExerciseListPointer()->getHeadPointer());

	delete pPlan;
}

void Test::testStoreDayExercisePlan(void)
{
	FitnessApp aApp;

	ExercisePlan newPlan;
	newPlan.setGoal(50);
	newPlan.setPlanName("Billy Bob's Adventure");
	newPlan.setStartDate("06/15/2025");


	std::fstream outfile("exercisePlanStore.txt", std::ios::out | std::ios::trunc);
	aApp.storeDailyPlan(outfile, newPlan);
}

void Test::testLoadWeeklyPlanEx(void)
{
	FitnessApp aApp;
	DietPlan* pPlan = new DietPlan;

	if (aApp.getExerciseFile().is_open())
	{
		aApp.loadWeeklyExercisePlan();
	}
}

void Test::testStoreWeeklyPlanEx(void)
{
	FitnessApp aApp;
	DietPlan* pPlan = new DietPlan;

	if (aApp.getExerciseFile().is_open())
	{
		aApp.loadWeeklyExercisePlan();
	}
	aApp.displayWeekPlans(aApp.getExerciseListPointer()->getHeadPointer());
	aApp.storeWeeklyPlan(aApp.getExerciseListPointer()->getHeadPointer());

}