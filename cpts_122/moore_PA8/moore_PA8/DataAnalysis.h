/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/12
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA8 Data Analysis with BSTs

Description: This contains the DataAnalysis class which contains all of the functions
			necessary to get read in a CSV file of purchased/sold goods and their quantites
			Will also sort them into BSTs and report min/max values for each tree
*******************************************************************************************/
#pragma once
#include "BST.h"
#include <iostream>
#include <fstream>

class DataAnalysis
{
public:

	/*
	* Function: runAnalysis()
	* Date Created: 2021/04/12
	* Last Modified: 2021/04/12
	* Description: This will read in the data from the data.csv file, populate the trees, and then print them out along with trends
	* Input Parameters: NONE
	* Returns: NONE
	* Precondition: program has started
	* Postcondition: All information proccessed and where applicable print to console
	*/
	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;

	/*
	* Function: openFile()
	* Date Created: 2021/04/12
	* Last Modified: 2021/04/12
	* Description: This simply opens the file and reads in the header line
	* Input Parameters: 
	*	Reference to the file you want to open and read the first line
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: File has opened
	*/
	void openFile(std::ifstream& infile);

	/*
	* Function: readLine()
	* Date Created: 2021/04/12
	* Last Modified: 2021/04/12
	* Description: Reads a single line in from file and sets the reference values
	* Input Parameters:
	*	reference to file to be read
	*	reference to integer to be set for Units
	*	reference to string for product type
	*	reference to string for transaction type
	* Returns: NONE
	* Precondition: file is open
	* Postcondition: values have been set
	*/
	void readLine(std::ifstream& infile, std::string& data, int& units, std::string& transactions);

	/*
	* Function: loadTransactions()
	* Date Created: 2021/04/12
	* Last Modified: 2021/04/12
	* Description: will read in all lines from file, call insertTransaction function, then call in order traversal printing from each class
	* Input Parameters:
	*	reference to file to be read
	* Returns: NONE
	* Precondition: file is open
	* Postcondition: all data read in from file
	*/
	void loadTransactions(std::ifstream& infile);

	/*
	* Function: insertTransaction
	* Date Created: 2021/04/12
	* Last Modified: 2021/04/12
	* Description: Will insert a note into the proper BST (purchased/sold)
	* Input Parameters:
	*	reference to string for product type
	*	reference to integer to be set for Units
	*	reference to string for transaction type
	* Returns: NONE
	* Precondition: NONE
	* Postcondition: New node inserted into proper tree
	*/
	void insertTransaction(std::string& data, int& units, std::string& transactions);

	/*
	* Function: printTrends()
	* Date Created: 2021/04/12
	* Last Modified: 2021/04/12
	* Description: This will print out the max/min vals from each tree
	* Input Parameters: NONE
	* Returns: NONE
	* Precondition: Data read in from file and proccessed
	* Postcondition: All trends print to console
	*/
	void printTrends(void);

};
