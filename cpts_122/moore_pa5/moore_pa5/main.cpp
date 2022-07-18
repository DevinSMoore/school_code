/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/15
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 5 Grocery Stoer Simulation

Description:	This assignment will simulate a grocery store queue with one express lane	
				and one standard lane. A new customer will be created with an arrival to 
				queue time (arrival time) which represents how many ticks of the clock
				they will be shopping for until they go to checkout. Each tick of the
				clock represents 1 real time minute. If the arival  time is 1-5 they will
				enter 
*******************************************************************************************/
#include "test.h"
#include "grocerySim.h"

int main(void)
{
	Simulation newSim;

	newSim.simInit();


	//Test qTest;

	//qTest.testEnqueueEmpty();
	//qTest.testEnqueueOneNode();
	//qTest.testDequeueOneNode();
	//qTest.testDequeueTwoNode();
	//qTest.case24Hours();
	

	
	return 0;
}