/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/15
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA5: Grocery Store Simulator

Description:	This will contain the customer data class. This will hold their arrival
				time, service time, total time, and also creation time.
*******************************************************************************************/
#pragma once
#include <iostream>

class CustomerData
{
public:
	// Default constructor along with the spooky 3 (copy const. copy assignment op. overload & destructor)
	CustomerData(int newCustomerNumber = 0, int newServiceTime = 0, int newTotalTime = 0, int newCreationTime = 0, int newArrivalTime = 0);
	CustomerData(const CustomerData& copy);
	~CustomerData();

	CustomerData& operator=(const CustomerData& rhs);

	// Getters and Setters
	int getCustomerNumber(void) const;
	int getServiceTime(void) const;
	int getTotalTime(void) const;
	int getCreationTime(void) const;
	int getArrivalTime(void) const;

	void setCustomerNumber(int& newNumber);
	void setServiceTime(int& newTime);
	void setTotalTime(int& newTime);
	void setCreationTime(int& newTime);
	void setArrivalTime(int& newTime);

	/*
	* Function: calcTotalTime()
	* Date Created: 2021/03/18
	* Last Modified: 2021/03/18
	* Description: Will calculate the total time the customer has spent in the queue and set the internal value
	* Input Parameters:
	*	integer reference to current simulation time
	* Returns: NONE
	* Precondition:	NONE
	* Postcondition: Total time set
	*/
	void calcTotalTime(const int& currentTime);


private:
	int customerNumber; // A unique identifier each new customer gets, resets after 24h period
	int serviceTime; // Random number (depending on which queue is enetered) 3-8 if standard queue, 1-5 if express queue
	int totalTime; // Represents the total time a customer is in the queue
	int creationTime; // Will represent the clock time when the user was created
	int arrivalTime; // represents when they will enter the queue
};

// Overloading equal to comparison operator
bool operator== (const CustomerData& lhs, const CustomerData & rhs);

// Overloading the ostream << operator for the customerData class
std::ostream& operator<<(std::ostream& cout, const CustomerData& rhs);