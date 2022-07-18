/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/04/12
Class:      CptS122 Section 10 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: PA8 Data Analysis with BSTs

Description: This contains the funcion definitions for the DataAnalysis class
*******************************************************************************************/
#include "DataAnalysis.h"

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
void DataAnalysis::runAnalysis()
{
	openFile(mCsvStream);
	loadTransactions(mCsvStream);
	std::cout << std::endl;
	printTrends();
}

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
void DataAnalysis::openFile(std::ifstream& infile)
{
	infile.open("data.csv", std::ios::in);
	std::string junkString = "";
	std::getline(infile, junkString); // just reading in the first line to get rid of it
}

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
void DataAnalysis::readLine(std::ifstream& infile, std::string& data, int& units, std::string& transactions)
{
	std::getline(infile, data, ','); // just using the data string as the justString for the units

	if (data == "") 
	{ 
		return; // this is to prevent any extra lines from breaking things
	}
	units = std::stoi(data); // Set units sold/purchased

	std::getline(infile, data, ','); // Set data reference for type

	std::getline(infile, transactions); // Set what kind of transaction (purchase/sold)
}

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
void DataAnalysis::loadTransactions(std::ifstream& infile)
{
	std::string tempData = "", tempTransaction = "";
	int tempUnits = 0;
	while (!infile.eof())
	{
		readLine(infile, tempData, tempUnits, tempTransaction); // Read in single line
		// std::cout << "tmpData: " << tempData << "   tempUnits: " << tempUnits << "   tempTransaction: " << tempTransaction << std::endl;
		if (tempData != "")
		{
			insertTransaction(tempData, tempUnits, tempTransaction); // insert data/units into appropriate tree
		}
	}
	infile.close(); // not making a destructor to close this file, so I just did it here

	// Print both trees
	std::cout << "Purchased tree: " << std::endl;
	mTreePurchased.inOrderTraversal();
	std::cout << std::endl;
	std::cout << "Sold tree: " << std::endl;
	mTreeSold.inOrderTraversal();
}

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
void DataAnalysis::insertTransaction(std::string& data, int& units, std::string& transactions)
{
	if (transactions == "Sold" || transactions == "sold") // checking for upper/lowercase
	{
		mTreeSold.insert(data, units);
	}
	else if (transactions == "Purchased" || transactions == "purchased")
	{
		mTreePurchased.insert(data, units);
	}
}

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
void DataAnalysis::printTrends(void)
{
	std::cout << "Most Purchased type: " << mTreePurchased.findLargest().getData() << "  Units: " << mTreePurchased.findLargest().getUnits() << std::endl;
	std::cout << "Least Purchased Type: " << mTreePurchased.findSmallest().getData() << "  Units: " << mTreePurchased.findSmallest().getUnits() << std::endl;
	std::cout << std::endl;
	std::cout << "Most Sold type: " << mTreeSold.findLargest().getData() << "  Units: " << mTreeSold.findLargest().getUnits() << std::endl;
	std::cout << "Least Sold Type: " << mTreeSold.findSmallest().getData() << "  Units: " << mTreeSold.findSmallest().getUnits() << std::endl;
}