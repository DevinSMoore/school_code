#include "customerData.h"

// Default Constructor
CustomerData::CustomerData(int newCustomerNumber, int newServiceTime, int newTotalTime, int newCreationTime, int newArrivalTime)
{
	customerNumber = newCustomerNumber;
	serviceTime = newServiceTime;
	totalTime = newTotalTime;
	creationTime = newCreationTime;
	arrivalTime = newArrivalTime;
}

// Copy constructor
CustomerData::CustomerData(const CustomerData& copy)
{
	customerNumber = copy.customerNumber;
	serviceTime = copy.serviceTime;
	totalTime = copy.totalTime;
	creationTime = copy.creationTime;
	arrivalTime = copy.arrivalTime;
}

// Destructor
CustomerData::~CustomerData()
{
	 // Nothing to do here
	// std::cout << "Hit CustomerData destructor..." << std::endl;
}

// Copy assigment opererator overload
CustomerData& CustomerData::operator=(const CustomerData& rhs)
{ // This is the same as the copy constructor, and it feels like a problem but I don't know why.
	customerNumber = rhs.customerNumber;
	serviceTime = rhs.serviceTime;
	totalTime = rhs.totalTime;
	creationTime = rhs.creationTime;
	arrivalTime = rhs.arrivalTime;

	return *this;
}

// Getters and Setters
int CustomerData::getCustomerNumber(void) const
{
	return customerNumber;
}

int CustomerData::getServiceTime(void) const
{
	return serviceTime;
}

int CustomerData::getTotalTime(void) const
{
	return totalTime;
}

int CustomerData::getCreationTime(void) const
{
	return creationTime;
}

int CustomerData::getArrivalTime(void) const
{
	return arrivalTime;
}

void CustomerData::setCustomerNumber(int& newNumber)
{
	customerNumber = newNumber;
}

void CustomerData::setServiceTime(int& newTime)
{
	serviceTime = newTime;
}

void CustomerData::setTotalTime(int& newTime)
{
	totalTime = newTime;
}

void CustomerData::setCreationTime(int& newTime)
{
	creationTime = newTime;
}

void CustomerData::setArrivalTime(int& newTime)
{
	arrivalTime = newTime;
}

// Overloading equal to comparison operator
bool operator== (const CustomerData& lhs, const CustomerData& rhs)
{
	if (lhs.getCustomerNumber() == rhs.getCustomerNumber())
	{
		if (lhs.getServiceTime() == rhs.getServiceTime())
		{
			if (lhs.getTotalTime() == rhs.getTotalTime())
			{
				if (lhs.getCreationTime() == rhs.getCreationTime())
				{
					if (lhs.getArrivalTime() == rhs.getArrivalTime())
					{
						return true;
					}
				}
			}
		}
	}
	return false; // if any of the equal to comparisons fail we'll return false;
}

// Overloading the ostream << operator for the customerData class
std::ostream& operator<<(std::ostream& os, const CustomerData& rhs)
{
	os << "Customer Number: " << rhs.getCustomerNumber()
		<< std::endl << "Service time: " << rhs.getServiceTime()
		<< std::endl << "Total time in queue: " << rhs.getTotalTime()
		<< std::endl << "Customer creation time stamp: " << rhs.getCreationTime()
		<< std::endl << "Customer Arival Time: " << rhs.getArrivalTime();
	return os;
}

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
void CustomerData::calcTotalTime(const int& currentTime)
{
	int totalTime = (currentTime - (arrivalTime + creationTime));
	setTotalTime(totalTime); // currTime - (arrTime + creatTime) will give us the total amount of time they spent in the queue
}