/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/15
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 5 Grocery Store Simulator

Description: This will contain all of the functions and statements necessary for the
			 the simulation to be run. Just like we did we the FitnessApp class in the
			 last PA.
*******************************************************************************************/
#pragma once
#include "queue.h"
#include "clock.h"

#define MAX_RUNTIME 1440


class Simulation
{
public:
	Simulation(); // I don't think I need the three constructors here for the simulation class
	Simulation(const Simulation& copy);
	~Simulation();

	Simulation& operator= (const Simulation& copy);

	Queue* getExpressQPtr(void) const;
	Queue* getNormalQPtr(void) const;

	void setExpressQPtr(Queue* const newPtr);
	void setNormalQPtr(Queue* const newPtr);

	// These functions will loop and display all of the customer information in both queues
	void displayExpressQueue();
	void displayNormalQueue();


	/*
	* Function: howManyQueued()
	* Date Created: 2021/03/17
	* Last Modified: 2021/03/17
	* Description: Will set the 2 passed variables to the number of customers in their respective queues
	* Input Parameters:
	*	int reference to expressQeueue count
	*	int reference to normalQueue count
	* Returns: NONE
	* Precondition: Queue is not empty
	* Postcondition:
	*/
	void howManyQueued(int& exprCount, int& normCount);

	/*
	* Function: simInit()
	* Date Created: 2021/03/17
	* Last Modified: 2021/03/17
	* Description: Will just ask the user for the amount of time they want to run the simulation for (in minutes)
	* Input Parameters: NONE
	* Returns: NONE
	* Precondition: Object instantiated
	* Postcondition: Simulation has run
	*/
	void simInit(void);

	/*
	* Function: enterQueue()
	* Date Created: 2021/03/17
	* Last Modified: 2021/03/17
	* Description: Will check if it's time for a customer to enter the queue
	* Input Parameters:
	*	reference to Customer Deata
	*	reference to integer which is current time
	* Returns: boolean value
	* Precondition: NONE
	* Postcondition: Bool returned
	*/
	bool enterQueue(const CustomerData& custData, const int& currentTime);

	/*
	* Function: servoceDone()
	* Date Created: 2021/03/18
	* Last Modified: 2021/03/18
	* Description: Will check if the person at tthe heaad of the queue is done
	* Input Parameters:
	* *	reference to Customer Deata
	*	reference to integer which is service clock
	* Returns:
	*	bool representing whether we should dequeue customer b/c they're done
	* Precondition: NONE
	* Postcondition: Bool returned
	*/
	bool serviceDone(const CustomerData& custData, const int& serviceClock);



	void runSimulation(const int& runTime);

private:
	Queue* mpExpressQueue; // Pointer to the Express queue
	Queue* mpNormalQueue; // Ptr to normal queue

	/*
	* Function: copyQueueNodes()
	* Date Created: 2021/03/17
	* Last Modified: 2021/03/17
	* Description:
	* Input Parameters:
	*	Tail pointer of object queue being displayed
	* Returns: NONE
	* Precondition:	Queue is not empty
	* Postcondition: All dat displayed to console
	*/
	void displayLoop(QueueNode* pTail);

	/*
	* Function: copyQueueNodes()
	* Date Created: 2021/03/17
	* Last Modified: 2021/03/17
	* Description: 
	* Input Parameters:
	*	Head pointer of object being copied TO
	*	Head pointer of object being copied FROM
	* Returns: NONE
	* Precondition:	Queue is not empty
	* Postcondition: All data copied over
	*/
	// void copyQueueNodes(QueueNode* const targetHeadPtr, QueueNode* const copyHeadPtr);


};



// This function will return a value between 1 and 5
int randExpress();

// This function will return a value between 3 and 8
int randNormal();
