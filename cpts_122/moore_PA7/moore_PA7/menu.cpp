/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/10
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA7

Description: This contains the functions, constructors, and destructor for the Menu Class
*******************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <time.h>

// Default Constructor
Menu::Menu()
{
	// Do nothing
}

/*
* Function: printMenu()
* Date Created: 2021/04/10
* Last Modified: 2021/04/10
* Description: Will print menu to console
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: Menu printed to console
*/
void Menu::printMenu()
{
	std::cout << "1. Import course list" << std::endl
		<< "2. Load master list" << std::endl
		<< "3. Store master list" << std::endl
		<< "4. Mark absences" << std::endl
		<< "5. Edit absences (NYI)" << std::endl
		<< "6. Generate report" << std::endl
		<< "7. Exit Program =*(" << std::endl;
}

/*
* Function: printReportMenu()
* Date Created: 2021/04/10
* Last Modified: 2021/04/10
* Description: Will print the menu for the generate report functions
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: Menu printed to console
*/
void Menu::printReportMenu()
{
	std::cout << "1. Generate report for all students" << std::endl
		<< "2. Generate report for students over absence threshold (set by you)" << std::endl;
}

/*
* Function: getMenuChoice()
* Date Created: 2021/04/10
* Last Modified: 2021/04/10
* Description: Will take in the upper bound (assumed lower bound = 1) and print the proper menu option as well as check for valid inputs; P.S. I dind't check for ascii character input invalidation only integer for this function
* Input Parameters:
*	Integer which iwll be the upper bound of hte menu options allowed.
* Returns:
*	Integer representing the users valid choice for menu option (integer)
* Precondition: NONE
* Postcondition: User option returned
*/
int Menu::getMenuChoice(int upperBound)
{
	int userEntry = 0;
	do
	{	
		system("cls");
		if(upperBound == BASIC_MENU_UPPER_BOUND) // if we're doing the normal menu upper bound will be 7 and we'll pring that menu
		{
			printMenu();
		}
		else // else we'll print other menu
		{
			printReportMenu();
		} // This won't work if we have 2 menues that have the same upper bound, but thankfully we don't care here

		std::cout << "Please enter a menu option between 1 and " << upperBound << ": " << std::endl;
		std::cin >> userEntry;
		system("cls");
		if (userEntry < 1 || userEntry > upperBound)
		{
			std::cout << "Please enter a valid menu option" << std::endl;
		}
		//system("pause");
		//std::cin.ignore();

	} while (userEntry < 1 || userEntry > upperBound);

	return userEntry;
}

/*
* Function: readClassList()
* Date Created: 2021/04/10
* Last Modified: 2021/04/10
* Description: This will take in the list from classList.csv and populate the master list with it
* Input Parameters: NONE
* Returns: NONE
* Precondition: classList.csv exists
* Postcondition: data read into master list
*/
void Menu::readClassList(void)
{
	std::string tempString = "";
	Data tempData;
	std::fstream infile("classList.csv", std::ios::in); // opening file for read in
	if (infile.is_open())
	{
		mMasterList.deleteList(); // empty out list
		if (mMasterList.isEmpty()) { std::cout << "List was emptied" << std::endl; }
		std::getline(infile, tempString); // Get rid of the header line
		while (!infile.eof())
		{
			infile >> tempData;
			if (mMasterList.isEmpty() || (mMasterList.getPHead()->getDataPtr()->getIdNumber() != tempData.getIdNumber()))
			{
				// if the newly read in data is equal to the most resent data put into the list it means we didn't actually read anything in

				mMasterList.insertAtFront(tempData);
			}
			//mMasterList.printList();
			//system("pause");
			//system("cls");
		}
	}
	infile.close();
}

/*
* Function: doMenuThings()
* Date Created: 2021/04/10
* Last Modified: 2021/04/10
* Description: This is the function that will ask for user choice and direct the program where necessary
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: Program has exited with code 0
*/
void Menu::doMenuThings()
{
	int userChoice = getMenuChoice(BASIC_MENU_UPPER_BOUND), absenceThreshold = 0;;
	switch (userChoice)
	{
	case 1: // Import list
		readClassList();
		std::cout << "Current master list:" << std::endl;
		mMasterList.printList();
		system("pause");
		system("cls");
		break;
	case 2: // Load master list from master.txt
		std::cout << "Hit load master list option" << std::endl;
		loadMasterList();
		std::cout << "Loaded master list...." << std::endl;
		mMasterList.printList();
		system("pause");
		system("cls");
		break;
	case 3: // Store master list to master.txt
		storeMasterList();
		std::cout << "Master list stored to file...." << std::endl;
		system("pause");
		system("cls");
		break;
	case 4: // Mark students absent
		std::cout << "Hit mark students option" << std::endl;
		markAbsences();
		system("pause");
		system("cls");
		break;
	case 5: // Edit absences (NYI)
		std::cout << "Feature is not available, sorry." << std::endl;
		system("pause");
		system("cls");
		break;
	case 6:
		userChoice = getMenuChoice(GEN_REPORT_UPPER_BOUND);
		switch (userChoice)
		{
		case 1:
			std::cout << "hit generate general report"<< std::endl;
			generateReport();
			system("pause");
			system("cls");
			break;
		case 2:
			std::cout << "Please enter an integer representing the minimum number of absences a student needs to be included in the report" << std::endl << "Threshold:";
			absenceThreshold = 0;
			while (!(std::cin >> absenceThreshold) || absenceThreshold < 0)
			{
				std::cout << "Please enter a positive integer." << std::endl;
			}
			generateReport(absenceThreshold);
			system("pause");
			system("cls");
			break;
		default:
			std::cout << "Hit default case" << std::endl;
			system("pause");
			system("cls");
			break;
		}

		break;
	case 7: // Exit Program
		std::cout << "Exiting Program...." << std::endl << "Have a good one!" << std::endl;
		return;
		break;
	default:
		break;
	}
	doMenuThings(); // jump back into the menu if we don't explicetly hit the exit option
}

/*
* Function: loadMasterList()
* Date Created: 2021/04/10
* Last Modified: 2021/04/10
* Description: This will load the data from masterList.txt
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: mMasterList has been populated with data from masterList.txt
*/
void Menu::loadMasterList()
{
	std::string tempString = "";
	Data tempData;
	std::fstream infile("masterList.txt", std::ios::in); // opening file for read in
	if (infile.is_open())
	{
		mMasterList.deleteList(); // empty out list
		if (mMasterList.isEmpty()) { std::cout << "List was emptied" << std::endl; }
		while (!infile.eof())
		{
			infile >> tempData;
			if (mMasterList.isEmpty() || (mMasterList.getPHead()->getDataPtr()->getIdNumber() != tempData.getIdNumber()))
			{
				// if the newly read in data is equal to the most resent data put into the list it means we didn't actually read anything in
				// So we loop in here if the list is empty (the first go through) or if we don't read in copy data (which will happen on the final read in)
				mMasterList.insertAtFront(tempData);
			}
			//mMasterList.printList();
			//system("pause");
			//system("cls");
		}
	}
	infile.close();
}

/*
* Function: storeMasterList()
* Date Created: 2021/04/10
* Last Modified: 2021/04/10
* Description: This will store the master list to master.txt
* Input Parameters: NONE
* Returns: NONE
* Precondition: masterList.txt exists
* Postcondition: mastList.txt poulted with the current master list
*/
void Menu::storeMasterList()
{
	std::fstream outfile("masterList.txt", std::ios::out | std::ios::trunc); // open for write, and trunc to get rid of whatever was in there before

	if (outfile.is_open())
	{
		storeMasterList(mMasterList.getPHead(), outfile);
		outfile.close();
	}


}

/*
* Function: storeMasterList()
* Date Created: 2021/04/10
* Last Modified: 2021/04/10
* Description: This is the plrivate function that will go through and store all of the current mMasterList nodes to the file in the format <recordNum>,<IDnum>,<firstName,lastName>,<email>,<units>,<program>,<level>
* Input Parameters:
*	Pointer to the head node of the list
*	File to be populated
* Returns: NONE
* Precondition: file exists
* Postcondition: Data printed to file in proper format to be read in again(see description)
*/
void Menu::storeMasterList(ListNode<Data>* pNext, std::fstream& outfile)
{
	if (pNext != nullptr) // Did it with recursion so I could go from the end of the list toward the front
	{
		storeMasterList(pNext->getNextPtr(), outfile);
		outfile << std::to_string(pNext->getDataPtr()->getRecordNumber()) << ","
			<< std::to_string(pNext->getDataPtr()->getIdNumber()) << ",\""
			<< pNext->getDataPtr()->getName() << "\","
			<< pNext->getDataPtr()->getEmail() << ","
			<< pNext->getDataPtr()->getUnits() << ","
			<< pNext->getDataPtr()->getProgram() << ","
			<< pNext->getDataPtr()->getLevel() << std::endl;
	}

}

/*
* Function: getTimeStamp()
* Date Created: 2021/04/11
* Last Modified: 2021/04/11
* Description: This will fill the currentTime reference with a string of the format MM/DD/YYYY
* Input Parameters:
*	Reference to be populated with current computer time
* Returns: NONE
* Precondition: NONE
* Postcondition: Correct time set into currentTime variable
*/
void Menu::getTimeStamp(std::string& currentTime)
{
	time_t t = time(0);   // get time now

	struct tm* now = localtime(&t);



	char buffer[100];

	// got info on function from here https://www.cplusplus.com/reference/ctime/strftime/ and the stuff above from the PA7 page:http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c 
	strftime(buffer, sizeof(buffer), "%D", now);// loading time in format of mm/dd/yyyy from now struct into buffer
	std::string timeString(buffer);
	currentTime = timeString;

	//std::cout << currentTime << std::endl;
}

/*
* Function: markAbsences()
* Date Created: 2021/04/11
* Last Modified: 2021/04/11
* Description: will allow the user to traverse the linked list and set a sutdents absence for that day
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: Absence stacks have the most recent absences pushed to them where applicable.
*/
void  Menu::markAbsences()
{
	char userChoice = '\0';
	std::string currentTime = "";
	ListNode<Data>* pTemp = mMasterList.getPHead();

	while (pTemp != nullptr)
	{
		getTimeStamp(currentTime);
		std::cout << "Current time value returned: " << currentTime << std::endl;
		std::cout << "Mark " << pTemp->getDataPtr()->getName() << " absent? enter 'y' for yes or 'n' for no." << std::endl;
		do
		{
			std::cin >> userChoice;
			userChoice = std::tolower(userChoice);
			if (userChoice != 'y' && userChoice != 'n')
			{
				std::cout << "Please enter a valid choice: 'y' for yes or 'n' for no." << std::endl;
			}
		} while (userChoice != 'y' && userChoice != 'n');
		if (userChoice == 'y')
		{
			pTemp->getDataPtr()->getStackPtr()->pushStack(currentTime);
		} // if user choice is no just continue through list

		pTemp = pTemp->getNextPtr();

		if (pTemp == nullptr)
		{
			std::cout << "Reached the end of the class. Returning to main menu...." << std::endl;
			return;
		}
	}
}

/*
* Function: generateReport()
* Date Created: 2021/04/11
* Last Modified: 2021/04/11
* Description: This function will produce a report for all students displaying total absences, and most recent absence
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: Report printed to console, and print to generalReport.txt
*/
void Menu::generateReport(void)
{
	std::fstream outfile("generalReport.txt", std::ios::out | std::ios::trunc); // open for write with truncate

	if(outfile.is_open())
	{
		ListNode<Data>* pTemp = mMasterList.getPHead();
		// Setting all of the totalAbsence values before building report
		while (pTemp != nullptr)
		{
			pTemp->getDataPtr()->countAndSetAbsences();
			std::string peekedString = "";
			pTemp->getDataPtr()->getStackPtr()->peekStack(peekedString);
			std::cout <<"Name: " << pTemp->getDataPtr()->getName() << "  |  " << "Total absences: " << pTemp->getDataPtr()->getTotalAbsences() << "  |  " << "Most recent absence: " << peekedString << std::endl;
			outfile <<"Name: " << pTemp->getDataPtr()->getName() << "  |  " << "Total absences: " << pTemp->getDataPtr()->getTotalAbsences() << "  |  " << "Most recent absence: " << peekedString << std::endl;
			pTemp = pTemp->getNextPtr();
		}
	
		outfile.close();
	}
}

/*
* Function: generateReport()
* Date Created: 2021/04/11
* Last Modified: 2021/04/11
* Description: This will take in a threshold value representing the minimum days absent necessary to be included in the report
* Input Parameters:
*	Reference to the integer reperesentin the threshold
* Returns: NONE
* Precondition: NONE
* Postcondition: Report printed to console, and print to thresholdReport.txt
*/
void Menu::generateReport(int& absenceThreshold)
{

	std::fstream outfile("thresholdReport.txt", std::ios::out | std::ios::trunc); // open for write with truncate

	if (outfile.is_open())
	{
		ListNode<Data>* pTemp = mMasterList.getPHead();
		// Setting all of the totalAbsence values before building report
		while (pTemp != nullptr)
		{
			pTemp->getDataPtr()->countAndSetAbsences(); // Update students absence counts 

			if(pTemp->getDataPtr()->getTotalAbsences() >= absenceThreshold) // we only want to print reports whose absences are greater than the threshold
			{
				std::string peekedString = "";
				pTemp->getDataPtr()->getStackPtr()->peekStack(peekedString);
				std::cout << "Name: " << pTemp->getDataPtr()->getName() << "  |  " << "Total absences: " << pTemp->getDataPtr()->getTotalAbsences() << "  |  " << "Most recent absence: " << peekedString << std::endl;
				outfile << "Name: " << pTemp->getDataPtr()->getName() << "  |  " << "Total absences: " << pTemp->getDataPtr()->getTotalAbsences() << "  |  " << "Most recent absence: " << peekedString << std::endl;

			}
			pTemp = pTemp->getNextPtr();
		}

		outfile.close();
	}
}

