/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/10
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA7

Description: This contains the Menu class which probably does more than it shoudl but, well
			it runs the whole program. It suppors displaying the menu and contains the
			functions and logic necessary to make it work good.
*******************************************************************************************/
#pragma once
#include "List.h"
#include "Data.h"
#include <iostream>
#include <string>

#define BASIC_MENU_UPPER_BOUND 7
#define GEN_REPORT_UPPER_BOUND 2

class Menu
{
public:
	// Default constructor
	Menu();

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
	void printMenu();

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
	void printReportMenu();

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
	int getMenuChoice(int upperBound);

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
	void doMenuThings();

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
	void readClassList();

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
	void loadMasterList();
	
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
	void storeMasterList();

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
	void getTimeStamp(std::string& currentTime);

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
	void markAbsences();

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
	void generateReport(void);

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
	void generateReport(int& absenceThreshold);


private:
	List<Data> mMasterList;

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
	void storeMasterList(ListNode<Data>* pNext, std::fstream& outfile);
};