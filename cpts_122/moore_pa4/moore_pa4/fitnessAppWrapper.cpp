
#include "fitnessAppWrapper.h"


FitnessApp::FitnessApp()// , ExerciseList* mpExerciseList);
{
	DietList* pNewDList = new DietList;
	ExerciseList* pNewEList = new ExerciseList;
	this->mpDietList = pNewDList;
	this->mpExerciseList = pNewEList;
	this->dietPlans.open("dietPlans.txt");
	this->exercisePlans.open("exercisePlans.txt");
}

FitnessApp::FitnessApp(const FitnessApp& copy)
{
	this->mpDietList = new DietList;
	*(this->mpDietList) = *(copy.getDietListPointer()); // This will use the copy assignment operator from the Diet/ExerciseList class by dereferencing both pointers so this *should* create a deep copy, because the assignent operator does
	this->mpExerciseList = new ExerciseList;
	*(this->mpExerciseList) = *(copy.getExerciseListPointer()); // Same as above
}

FitnessApp::~FitnessApp()
{
	//std::cout << std::endl << "Deleting Fitness App Pointers..." << std::endl;
	delete this->getDietListPointer();
	delete this->getExerciseListPointer();

	//std::cout << std::endl << "Closing plan files" << std::endl;
	this->dietPlans.close();
	this->exercisePlans.close();
}

FitnessApp& FitnessApp::operator= (const FitnessApp& rhs)
{
	this->mpDietList = new DietList;
	*(this->mpDietList) = *(rhs.getDietListPointer()); // This will use the copy assignment operator from the Diet/ExerciseList class by dereferencing both pointers so this *should* create a deep copy, because the assignent operator does
	this->mpExerciseList = new ExerciseList;
	*(this->mpExerciseList) = *(rhs.getExerciseListPointer()); // Same as above

	return *this;
}

// Getters and Setters

DietList* FitnessApp::getDietListPointer() const
{
	return this->mpDietList;
}

ExerciseList* FitnessApp::getExerciseListPointer() const
{
	return this->mpExerciseList;
}

std::fstream &FitnessApp::getDietFile(void)
{
	return this->dietPlans;
}
std::fstream &FitnessApp::getExerciseFile(void)
{
	return this->exercisePlans;
}

// Sets the diet and exercise pointers in current object
void FitnessApp::setDietPointer(DietList* pNew)
{
	this->mpDietList = pNew;
}

void FitnessApp::setExercisePointer(ExerciseList* pNew)
{
	this->mpExerciseList = pNew;
}



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
void FitnessApp::printMenu(void)
{
	std::cout << "1. Load weekly diet plan from file."
		<< std::endl << "2. Load weekly exercise plan from file."
		<< std::endl << "3. Store Weekly diet plan to file."
		<< std::endl << "4. Store weekly exercise plan to file."
		<< std::endl << "5. Display weekly diet plan to screen."
		<< std::endl << "6. Display weekly exercise plan to screen."
		<< std::endl << "7. Edit daily diet plan."
		<< std::endl << "8. Edit daily exercise plan."
		<< std::endl << "9. Exit." << std::endl;   // Note: this must write the most recent weekly plans to the corresponding files.
}



/*
* Function: loadDailyPlan()
* Date Created: 2021/03/10
* Last Modified: 2021/03/10
* Description: Will load a single diet plan from a file
* Input Parameters:
*	reference to file to be read in
*	Reference to a diet plan
* Returns: pointer to new plan
* Precondition: File is open for reading
* Postcondition: New plan has been filled with data from file
*/
void FitnessApp::loadDailyPlan(std::fstream& infile, DietPlan& plan)
{
	infile >> plan; // Use the overloaded insertion operator to load in plan
}

/*
* Function: loadWeeklyDietPlan()
* Date Created: 2021/03/13
* Last Modified: 2021/03/13
* Description: Will load a weeks worth of diet plans from a file to the dietList
* Input Parameters:
* Returns: NONE
* Precondition: File is open for reading
* Postcondition: Seven plans read from file and placed into the list
*/
void FitnessApp::loadWeeklyDietPlan(void)
{
	std::string tempString = "";
	DietPlan tempPlan;

	while (!this->getDietFile().eof()) // While we're not at the end of the file; Also I could make this recursive by making this an if statment and calling the function below it but whatevs
	{
		loadDailyPlan(this->getDietFile(), tempPlan);
		this->getDietListPointer()->insertAtEnd(tempPlan);
		std::getline(this->getDietFile(), tempString); // This is to clear out the empty line
		// std::cout << "TempString from loadWeeklyPlan: " << tempString << std::endl;
	}
}

/*
* Function: storeDailyPlan()
* Date Created: 2021/03/12
* Last Modified: 2021/03/12
* Description: Will store a single diet plan to a file
* Input Parameters:
*	reference to file to be read in
*	Reference to a diet plan
* Returns: pointer to new plan
* Precondition: File is open
* Postcondition: New plan has been filled with data from file and pointer returned
*/
void FitnessApp::storeDailyPlan(std::fstream& infile, DietPlan& plan)
{
	infile << plan; // Overloaded function to store plans to file
}

/*
* Function: storeWeeklyPlan()
* Date Created: 2021/03/13
* Last Modified: 2021/03/13
* Description: Will store a weeks worth of diet plans to a file from the dietList
* Input Parameters:
*	Head pointer to list to be printed to file
* Returns: NONE
* Precondition: File is open
* Postcondition: Seven plans read from file and placed into the list
*/
void FitnessApp::storeWeeklyPlan(DietNode* pHeadTemp)
{

	std::fstream outfile("dietPlanStore.txt", std::ios::out | std::ios::trunc);
	DietNode* pTemp = pHeadTemp;
	while (pTemp != nullptr) // Progress through list until we hit the null ptr
	{
		storeDailyPlan(outfile, *(pTemp->getPlanPointer()));
		outfile << "\n";
		pTemp = pTemp->getNextPointer();
	}
	outfile.close();
}

/*
* Function: loadDailyPlan()
* Date Created: 2021/03/13
* Last Modified: 2021/03/13
* Description: Will load a single Exercise plan from a file
* Input Parameters:
*	reference to file to be read in
*	Reference to a diet plan
* Returns: 
* Precondition: File is open for reading
* Postcondition: New plan has been filled with data from file
*/
void FitnessApp::loadDailyPlan(std::fstream& infile, ExercisePlan& plan)
{
	infile >> plan; // Use the overloaded insertion operator to load in plan
}

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
void FitnessApp::loadWeeklyExercisePlan(void)
{
	std::string tempString = "";
	ExercisePlan tempPlan;

	while (!this->getExerciseFile().eof()) // While we're not at the end of the file; Also I could make this recursive by making this an if statment and calling the function below it but whatevs
	{
		loadDailyPlan(this->getExerciseFile(), tempPlan);
		this->getExerciseListPointer()->insertAtEnd(tempPlan);
		std::getline(this->getExerciseFile(), tempString); // This is to clear out the empty line
		//std::cout << "TempString from loadWeeklyPlan: " << tempString << std::endl;
	}
}

/*
* Function: storeDailyPlan()
* Date Created: 2021/03/13
* Last Modified: 2021/03/13
* Description: Will store a single plan to a file
* Input Parameters:
*	reference to file to be read in
*	Reference to a diet plan
* Returns: pointer to new plan
* Precondition: File is open
* Postcondition: New plan has been filled with data from file and pointer returned
*/
void FitnessApp::storeDailyPlan(std::fstream& infile, ExercisePlan& plan)
{
	infile << plan; // Overloaded function to store plans to file
}

/*
* Function: storeWeeklyPlan()
* Date Created: 2021/03/13
* Last Modified: 2021/03/13
* Description: Will store a weeks worth of exercise plans to a file from the dietList
* Input Parameters:
*	Head pointer to list to be printed to file
* Returns: NONE
* Precondition: File is open
* Postcondition: Seven plans read from file and placed into the list
*/
void FitnessApp::storeWeeklyPlan(ExerciseNode* pHeadTemp)
{
	std::fstream newFile("exercisePlanStore.txt", std::ios::out | std::ios::trunc);
	ExerciseNode* pTemp = pHeadTemp;
	while (pTemp != nullptr)
	{
		storeDailyPlan(newFile, *(pTemp->getPlanPointer()));
		newFile << "\n";
		pTemp = pTemp->getNextPointer();
	}

	newFile.close();
}

/*
* Function: displayDietDay()
* Date Created: 2021/03/09
* Last Modified: 2021/03/09
* Description: Will display a single days diet plan
* Input Parameters:
*	DietPlan* plan: pointer to the plan to be displayed
* Returns: NONE
* Precondition: NONE
* Postcondition: Plan displayed to screen
*/
void FitnessApp::displayDayPlan(const DietPlan& plan)
{
	std::cout << std::endl << plan << std::endl;
}
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
void FitnessApp::displayWeekPlans(DietNode* const pHead)
{
	if (pHead != nullptr)
	{
		displayDayPlan(*(pHead->getPlanPointer())); // pass the dereferenced plan pointer in the node to the displayDay funciton
		displayWeekPlans(pHead->getNextPointer()); // pass the next pointer to the displayWeek function to recursively go throught and print it
	} // Else do nothing
}
/*
* Function: displayDayPlan()
* Date Created: 2021/03/09
* Last Modified: 2021/03/09
* Description: Will display a single exercise plan
* Input Parameters:
*	DietPlan* plan: pointer to the plan to be displayed
* Returns: NONE
* Precondition: NONE
* Postcondition: Plan displayed to screen
*/
void FitnessApp::displayDayPlan(const ExercisePlan& plan)
{
	std::cout << std::endl << plan << std::endl;
}

/*
* Function: displayExerciseWeekPlans()
* Date Created: 2021/03/09
* Last Modified: 2021/03/09
* Description: Will display a week of diet plans
* Input Parameters:
*	DietNode* pHead: Pass a copy of the head pointer for the diet list
* Returns: NONE
* Precondition: List contains only 7 items
* Postcondition: Entire week of plans displayed to console
*/
void FitnessApp::displayWeekPlans(ExerciseNode* const pHead)
{
	if (pHead != nullptr)
	{
		displayDayPlan(*(pHead->getPlanPointer())); // pass the dereferenced plan pointer in the node to the displayDay funciton
		displayWeekPlans(pHead->getNextPointer()); // pass the next pointer to the displayWeek function to recursively go throught and print it
	} // else do nothing
}

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
void FitnessApp::runApp(void)
{
	// Declaring Objects/variables

	int menuChoice = 0;
	bool valid = false, exitProgram = false;
	char charMenuChoice = '\0';
	DietNode* pdTemp = nullptr;
	ExerciseNode* peTemp = nullptr;
	while (!exitProgram)
	{
		do
		{
			system("cls");
			this->printMenu();
			std::cout << std::endl << "To navigate the menu please enter a positive integer: ";
			std::cin >> menuChoice;
			valid = (menuChoice <= 9 && menuChoice >= 1) ? (true) : (false); // if menu choice is between 1 and 9 inclusive set valid to true, else set to false
			std::cout << valid << std::endl;
			system("cls");
			if (!valid) { std::cout << std::endl <<  "!!Please enter a valid menu choice (between 1 and 9 inclusive)!!" << std::endl << std::endl; } // Just printing a message if our choice is not valid
		} while (!valid);

		switch (menuChoice)
		{
			case (1): // Load week of diets
				this->loadWeeklyDietPlan();
				std::cout << "Diet plans loaded from file." << std::endl << " Displaying data..." << std::endl;
				this->displayWeekPlans(this->getDietListPointer()->getHeadPointer()); // pass head pointer of expersize list to
				system("pause");
				break;
			case (2): // Load week of exercises
				this->loadWeeklyExercisePlan();
				std::cout << "Exercise plans loaded from file." << std::endl << " Displaying data..." << std::endl;
				this->displayWeekPlans(this->getExerciseListPointer()->getHeadPointer()); // pass head pointer of expersize list to 
				system("pause");
				break;
			case (3): // Store week of diets
				this->storeWeeklyPlan(this->getDietListPointer()->getHeadPointer());
				std::cout << "Current diet plan list has been saved to a file." << std::endl;
				system("pause");
				break;
			case (4): // Store week of exercises
				this->storeWeeklyPlan(this->getExerciseListPointer()->getHeadPointer());
				std::cout << "Current diet plan list has been saved to a file." << std::endl;
				system("pause");
				break;
			case (5): // display diets
				this->displayWeekPlans(this->getDietListPointer()->getHeadPointer());
				system("pause");
				break;
			case (6):// Display exercises
				this->displayWeekPlans(this->getExerciseListPointer()->getHeadPointer());
				system("pause");
				break;
			case (7):// Store week of diets
				valid = false;
				pdTemp = this->getDietListPointer()->getHeadPointer();
				while (valid != true && pdTemp != nullptr)
				{
					std::cout << "Goal name: " << pdTemp->getPlanPointer()->getPlanName() << std::endl;

					do
					{
						std::cout << std::endl << "Enter 'y' if you would like to edit this plan's goal otherwise enter 'n'";
						std::cin >> charMenuChoice;
						if (charMenuChoice == 'y')
						{
							system("cls");
							pdTemp->getPlanPointer()->editGoal();
							std::cout << std::endl;
							valid = true; // set valid to true so we break out of loop
							system("pause");

						}


						if (charMenuChoice != 'y' && charMenuChoice != 'n') { std::cout << "Please enter 'y' or 'n'."; }

					} while (charMenuChoice != 'y' && charMenuChoice != 'n');
					pdTemp = pdTemp->getNextPointer();
				}
				break;
			case (8):
				valid = false;
				peTemp = this->getExerciseListPointer()->getHeadPointer();
				while (valid != true && peTemp != nullptr)
				{
					std::cout << "Goal name: " << peTemp->getPlanPointer()->getPlanName() << std::endl;

					do
					{
						std::cout << std::endl << "Enter 'y' if you would like to edit this plan's goal otherwise enter 'n'";
						std::cin >> charMenuChoice;
						if (charMenuChoice == 'y')
						{
							system("cls");
							peTemp->getPlanPointer()->editGoal();
							std::cout << std::endl;
							valid = true; // set valid to true so we break out of loop
							system("pause");

						}


						if (charMenuChoice != 'y' && charMenuChoice != 'n') { std::cout << "Please enter 'y' or 'n'."; }

					} while (charMenuChoice != 'y' && charMenuChoice != 'n');
					peTemp = peTemp->getNextPointer();
				}
				break;
			case (9):
				exitProgram = true;
				std::cout << "Thanks for using my program... Exiting now and printing diet and exercise plans to file" << std::endl;
				this->storeWeeklyPlan(this->getDietListPointer()->getHeadPointer());
				this->storeWeeklyPlan(this->getExerciseListPointer()->getHeadPointer());
				break;
			default:
				std::cout << "Hit default case." << std::endl;
				break;
		}// End of normal program loop
	} 
}
