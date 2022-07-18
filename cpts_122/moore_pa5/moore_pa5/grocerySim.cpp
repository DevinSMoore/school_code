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
#include "grocerySim.h"
#include "clock.h"

Simulation::Simulation() 
{
	mpExpressQueue = new Queue;
	mpNormalQueue = new Queue;
}

// Copy constructor
Simulation::Simulation(const Simulation& copy) // I don't understand the squigly I'm getting on this one; it says mpNormalQueue is uninitialized, but my queue constructor initializes the queue and i'm creating memory for it above
{
	if (!copy.mpExpressQueue->isEmpty()) // if the object we're copying is not empty
	{
		// We allocated memory when we construct the object therefore we don't need to in here
		
		mpExpressQueue = new Queue;
		*(mpExpressQueue) = *(copy.getExpressQPtr());
		mpNormalQueue = new Queue; // This should (fingers crossed) create a deep copy because all of the new memory for the nodes will be allocated inside the overloaded expression,and the lhs pointers have their own address'
		*(mpNormalQueue) = *(copy.getNormalQPtr());
	} 
	else
	{
		mpExpressQueue = nullptr;
		mpExpressQueue = nullptr; // Set queue pointers to null, and (hopefully) when they fall out of scope they delete their own memeory
	}
}

// Destructor
Simulation::~Simulation()
{
	delete mpExpressQueue;
	delete mpNormalQueue;
	// std::cout << "Hit Simulation deconstructor" << std::endl;
}

// Copy assignment operator overload
Simulation& Simulation::operator= (const Simulation& rhs)
{
	if (!rhs.mpExpressQueue->isEmpty()) // if the object we're copying is not empty
	{
		// We allocated memory when we construct the object therefore we don't need to in here

		mpExpressQueue = new Queue;
		*(mpExpressQueue) = *(rhs.getExpressQPtr());
		mpNormalQueue = new Queue; // This should (fingers crossed) create a deep copy because all of the new memory for the nodes will be allocated inside the overloaded expression,and the lhs pointers have their own address'
		*(mpNormalQueue) = *(rhs.getNormalQPtr());
	}
	else
	{
		mpExpressQueue = nullptr;
		mpExpressQueue = nullptr; // Set queue pointers to null, and (hhopefully) when they fall out of scope they delete their own memeory
	}
	return *this;
}


Queue* Simulation::getExpressQPtr(void) const
{
	return mpExpressQueue;
}
Queue* Simulation::getNormalQPtr(void) const
{
	return mpNormalQueue;
}

void Simulation::setExpressQPtr(Queue* const newPtr)
{
	mpExpressQueue = newPtr;
}

void Simulation::setNormalQPtr(Queue* const newPtr)
{
	mpNormalQueue = newPtr;
}

void Simulation::displayExpressQueue()
{
	if (mpExpressQueue->getTailPtr() != nullptr)
	{
		displayLoop(mpExpressQueue->getTailPtr());
	}
	else 
	{
		std::cout << "Queue is empty, there is nothing to display..." << std::endl;
	}
}

void Simulation::displayNormalQueue()
{
	if (mpExpressQueue->getTailPtr() != nullptr)
	{
		displayLoop(mpNormalQueue->getTailPtr());
	}
	else
	{
		std::cout << "Queue is empty, there is nothing to display..." << std::endl;
	}
}

/*
* Function: displayLoop()
* Date Created: 2021/03/17
* Last Modified: 2021/03/17
* Description:
* Input Parameters:
*	Tail pointer of object queue being displayed
* Returns: NONE
* Precondition:	Queue is not empty
* Postcondition: All dat displayed to console
*/
void Simulation::displayLoop(QueueNode* pTail)
{
	if(pTail != nullptr)
	{
		displayLoop(pTail->getNextPtr());
		std::cout << *pTail->getDataPtr() << std::endl;
	}
}

// This function will return a value between 1 and 5
int randExpress()
{
	return ((rand() % 5) + 1);
}

// This function will return a value between 3 and 8
int randNormal()
{
	return ((rand() % 5) + 3);
}

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
void Simulation::howManyQueued(int& exprCount, int& normCount)
{
	exprCount = mpExpressQueue->numberInQueue();
	normCount = mpNormalQueue->numberInQueue();
}

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
bool Simulation::enterQueue(const CustomerData& custData, const int& currentTime)
{
	// if the random arival time is equal to the difference btwn cur time and creation time then we want them to enter the queue
	return (custData.getArrivalTime() == (currentTime - custData.getCreationTime()));  
}

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
bool Simulation::serviceDone(const CustomerData& custData, const int& serviceClock)
{
	// service clock is just how long a customer has been at the head of the queue
	// if serviceTime - serviceClcok is zero return true
	return ((custData.getServiceTime() - serviceClock) == 0);
}

/*
* Function: simInit()
* Date Created: 2021/03/17
* Last Modified: 2021/03/17
* Description: Will run through the steps of simulating the two grocery store lanes
* Input Parameters: NONE
* Returns: NONE
* Precondition: Object instantiated
* Postcondition: Simulation has run
*/
void Simulation::simInit()
{
	bool valid = false;
	int userRuntime = 0;
	do
	{
	std::cout << "Please enter a number of minutes to run the simulation for (postitive integers only)" << std::endl;
	std::cin >> userRuntime;
	if (userRuntime >= 0 && userRuntime <= MAX_RUNTIME) 
	{ 
		valid = true; 
	} // set valid to true if the input is valid

	
	} while (!valid);
	runSimulation(userRuntime);
}

/*
* Function: runSimulation()
* Date Created: 2021/03/17
* Last Modified: 2021/03/17
* Description: Will run through the steps of simulating the two grocery store lanes
* Input Parameters: 
*	int reference to the run time of the simulation
* Returns: NONE
* Precondition: Object instantiated
* Postcondition: Simulation has run
*/
void Simulation::runSimulation(const int& runTime)
{
	Clock simTime, expressCounter, normalCounter;
	int currentTime = 0, junkInt = 0, randInt = 0, expressQueueOccupancy = 0, normalQueueOccupancy = 0, custNumberCounter = 0;
	CustomerData *pExprWaiting = new CustomerData, *pNormWaiting = new CustomerData;


	srand((unsigned)time(0));

	


	while (simTime.getClock() <= runTime) // Loop until we hit requested sim time
	{
		currentTime = simTime.getClock();
		
		if (simTime.getClock() == 0) // Start of simulation at t=0
		{
			
			pExprWaiting->setCreationTime(currentTime);
			pNormWaiting->setCreationTime(currentTime); // Set both customers creation time to current time

			// Setting arival times for the initial startup
			randInt = randExpress(); // val from 1-5 for express cust
			pExprWaiting->setArrivalTime(randInt); // set val

			randInt = randNormal(); // val from 3-8 for normal cust
			pNormWaiting->setArrivalTime(randInt);

			pExprWaiting->setCustomerNumber(custNumberCounter);
			custNumberCounter++;
			pNormWaiting->setCustomerNumber(custNumberCounter); // setting customer neumbers
			custNumberCounter++;
		} 
		
		// If any waiting pointer is null then we want to create a new customer
		if (pExprWaiting == nullptr) // We set cust data ptrs to null when we add them to the queue
		{
			randInt = randExpress(); // val from 1-5 for express cust
			pExprWaiting = new CustomerData(custNumberCounter++, 0, 0, currentTime, randInt); // set initial customer conditions and increment custNumberCounter
		}
		else if (pNormWaiting == nullptr) // no normy waiting -> create new one
		{
			randInt = randNormal(); // 1-5 for normies
			pNormWaiting = new CustomerData(custNumberCounter++, 0, 0, currentTime, randInt);
		}
         
 
		if (pExprWaiting != nullptr && enterQueue(*pExprWaiting, currentTime) == true) // if we've waited the arival time amount we want to enqueue them and delete mem then set ptr to null
		{
			randInt = randExpress();
			pExprWaiting->setServiceTime(randInt); // Set random service time between 1-5

			mpExpressQueue->enqueue(*pExprWaiting);

			if (*(mpExpressQueue->getTailPtr()->getDataPtr()) == *pExprWaiting) // If the data at the tail (where they are enqueued) is equal to the data we passed in
			{
				expressQueueOccupancy++; // increment number of ppl in express queue
				delete pExprWaiting;
				pExprWaiting = nullptr;
				std::cout << simTime.getClock() << ": " << "New customer joined express queue..." << std::endl;
				std::cout << simTime.getClock() << ": " << "Customer Number: " << mpExpressQueue->getHeadPtr()->getDataPtr()->getCustomerNumber() << std::endl;
				std::cout << simTime.getClock() << ": " << "Time they joined the queue: " << simTime.getClock() << std::endl;
				std::cout << simTime.getClock() << ": " << "Individual Service Time: " << mpExpressQueue->getTailPtr()->getDataPtr()->getServiceTime() << std::endl;
			}
			else {
				std::cout << simTime.getClock() << "WARNING: Customer data at tail does not match data we tried to enter!!!" << std::endl;
			}
		} 
			
		// Doing same as above but checking the normal queue
		if (pNormWaiting != nullptr && enterQueue(*pNormWaiting, currentTime) == true) // if we've waited the arival time amount we want to enqueue them and delete mem then set ptr to null
		{
			randInt = randNormal();
			pNormWaiting->setServiceTime(randInt); // Set random service time between 3-8
				
			mpNormalQueue->enqueue(*pNormWaiting);

			if (*(mpNormalQueue->getTailPtr()->getDataPtr()) == *pNormWaiting) // If the data at the tail (where they are enqueued) is equal to the data we passed in
			{
				normalQueueOccupancy++; // increment number of ppl in normal queue
				delete pNormWaiting;
				pNormWaiting = nullptr;
				std::cout << simTime.getClock() << ": " << "New customer joined normal queue..." << std::endl;
				std::cout << simTime.getClock() << ": " << "Customer Number:" << mpNormalQueue->getHeadPtr()->getDataPtr()->getCustomerNumber() << std::endl;
				std::cout << simTime.getClock() << ": " << "Time they joined the queue: " << simTime.getClock() << std::endl;
				std::cout << simTime.getClock() << ": " << "Individual Service Time: " << mpNormalQueue->getTailPtr()->getDataPtr()->getServiceTime() << std::endl;
			}
			else
			{
				std::cout << simTime.getClock() << "WARNING: Customer data at tail does not match data we tried to enter!!!" << std::endl;
			}
		}
		 // enqueue block

		// so at this point we should have 2 people waiting to get in if we don't add more this turn otherwise we'll have 0/1 people waiting
		
		if (!mpExpressQueue->isEmpty()) // If the queue is empty skip attempting to dequeue
		{
			if (serviceDone(*(mpExpressQueue->getHeadPtr()->getDataPtr()), expressCounter.getClock())) {
				// current person in express queue is going to be dequeued then we're going to reset counter
				
				mpExpressQueue->getHeadPtr()->getDataPtr()->calcTotalTime(currentTime);
				expressCounter.resetClock(); // reset the cashier's clock
				std::cout << simTime.getClock() << ": " << "Customer exiting the express queue..." << std::endl;
				std::cout << simTime.getClock() << ": " << "Customer Number:" << mpExpressQueue->getHeadPtr()->getDataPtr()->getCustomerNumber() << std::endl;
				std::cout << simTime.getClock() << ": " << "Total time customer spent in queue:" << mpExpressQueue->getHeadPtr()->getDataPtr()->getTotalTime() << std::endl;
				
				
				mpExpressQueue->dequeue();
				expressQueueOccupancy--; // decrement 


			}
			else
			{
				expressCounter.incrementClock(); // no dequeue = increment service clock
			}
		}
		if (!mpNormalQueue->isEmpty()) // if it's not empty check for dqeueue conditions
		{// if the service tiem is done for normal queue then we go through dequeue

			if (!mpNormalQueue->isEmpty() && serviceDone(*(mpNormalQueue->getHeadPtr()->getDataPtr()), normalCounter.getClock()))
			{
				mpNormalQueue->getHeadPtr()->getDataPtr()->calcTotalTime(currentTime);
				std::cout << simTime.getClock() << ": " << "Customer exiting the normal queue..." << std::endl;
				std::cout << simTime.getClock() << ": " << "Customer Number:" << mpNormalQueue->getHeadPtr()->getDataPtr()->getCustomerNumber() << std::endl;
				std::cout << simTime.getClock() << ": " << "Total time customer spent in queue:" << mpNormalQueue->getHeadPtr()->getDataPtr()->getTotalTime() << std::endl;

				mpNormalQueue->dequeue();
				normalQueueOccupancy--; // decrementing num ppl in normal queue
				normalCounter.resetClock();  // reset normal cashier's service clock


			}
			else
			{
				normalCounter.incrementClock(); // if we didn't dequeue someone increment the cashier's sevice clock
			}

		}


			if ((simTime.getClock() % 10) == 0) // if the counter is a multiple of 10 print number of customers in queue
	{
		std::cout << simTime.getClock() << ": " << "Normal Customer Count: " << normalQueueOccupancy << std::endl;
		std::cout << simTime.getClock() << ": " << "Express Customer Count: " << expressQueueOccupancy << std::endl;
	}

	if (simTime.getClock() == runTime)
	{
		// if we reach the end of the simulation reset all clocks and exit
		simTime.resetClock();
		normalCounter.resetClock();
		expressCounter.resetClock();
		delete pExprWaiting;
		delete pNormWaiting;

		std::cout << std::endl << "Customers in NORMAL queue after simulation end:" << normalQueueOccupancy << std::endl;
		std::cout << std::endl << "Customers in EXPRESS queue after simulation end:" << expressQueueOccupancy << std::endl;
		return;
	}


	simTime.incrementClock(); // increment the sim global clock
	}

}