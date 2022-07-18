#include "test.h"
#include "grocerySim.h"

void Test::testEnqueueEmpty(void)
{
	Queue tQ;
	CustomerData tData(55, 7, 18, 0);
	if (tQ.isEmpty()) // Queue is empty
	{
		tQ.enqueue(tData);
		if (!tQ.isEmpty() && (*(tQ.getTailPtr()->getDataPtr()) == tData)) // overloaded equal to operator; if tQ is not empty & the data in the node is equal to the data passed then we win yay
		{
			std::cout << "Item inserted successfully" << std::endl;
		}
	}
}

void Test::testEnqueueOneNode(void)
{
	Queue tQ;
	CustomerData *pData1 = new CustomerData(55, 7, 18, 0), *pData2 = new CustomerData(60, 5, 30, 15); // 1 is first data entered therefore 
	tQ.enqueue(*pData1);
	if (tQ.numberInQueue() == 1) // Queue has one element
	{
		tQ.enqueue(*pData2);
		// overloaded equal to operator; if tQ is not empty & the data in the TAIL node is equal to the data passed, and the head pointer is still pointing at the first data entered we did it thumbs up
		if ((tQ.numberInQueue() == 2) && (*(tQ.getTailPtr()->getDataPtr()) == *pData2) && (*(tQ.getHeadPtr()->getDataPtr()) == *pData1))
		{
			std::cout << "Item inserted at the front of the queue with one item in it successfully" << std::endl;
		}
	}
	delete pData1, pData2;
}

void Test::testDequeueOneNode(void)
{
	int success = 0;
	
	Queue tQ;
	CustomerData tData(55, 7, 18, 0);
	success = tQ.enqueue(tData);

	if (success) // Insertion successful
	{
		tQ.dequeue(); // Get outa heea

		if (tQ.isEmpty()) // You've only gone and done it
		{
			std::cout << "Node dequeued from queue..." << std::endl;
			std::cout << "Test successful..." << std::endl;
		}
	}

}

void Test::testDequeueTwoNode(void)
{
	Simulation newSim;
	CustomerData tData1(55, 7, 18, 0), tData2(60, 5, 30, 15);
	Queue* pExQueue = newSim.getExpressQPtr();
	pExQueue->enqueue(tData1);
	pExQueue->enqueue(tData2);
	std::cout << std::endl << "Displaying contents of queue: " << std::endl;
	newSim.displayExpressQueue();
	putchar('\n');

 	if (pExQueue->numberInQueue() == 2)
	{
		std::cout << "Queue has " << pExQueue->numberInQueue() << " items in it dequeueing... " << std::endl;
		// 2 elements in queue -> dequeueing first node
		pExQueue->dequeue();
		if (pExQueue->numberInQueue() == 1)
		{
			std::cout << std::endl << "Displaying conents of queue: " << std::endl;
			newSim.displayExpressQueue();
			putchar('\n');
			std::cout << "Queue has " << pExQueue->numberInQueue() << " items in it: dequeueing... " << std::endl;
			pExQueue->dequeue(); // First dequeue worked, dequeueing second node
			if (pExQueue->isEmpty())
			{	// We done it!
				std::cout << "Displaying queue after 2 dequeue calls" << std::endl;
				newSim.displayExpressQueue(); 
				std::cout << "Queue empty; test successful.. " << std::endl;
			}
			else
			{
				std::cout << "Queue not empty, dequeue not sucessful" << std::endl;
			}
		}
		else
		{
			std::cout << "Queue still has 2 items in it, dequeue not successful" << std::endl;
		}
	}

}

void Test::case24Hours(void)
{
	Simulation newSim;
	newSim.runSimulation(1440); // 24 hours in minutes
	std::cout << "Simulation complete exiting..." << std::endl;
}