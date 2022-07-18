/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/15
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 5 Grocery Store Simulator

Description:	This will contain our clock class which will contain a clock that
				all actions are taken relative to. so for instance the difference
				between the current time and a customers creation time could be their
				arrival time which then will cause them to enter the queue. idk could
				be not really usefull but who knows.
*******************************************************************************************/
#include "clock.h"


// Constructor simply sets clock to zero bish bash bosh
Clock::Clock()
{
	mClock = 0;
}

int Clock::getClock(void) const
{
	return this->mClock;
}

void Clock::setClock(const int& newClk)
{
	mClock = newClk;
}

/*
* Function: incrementClock()
* Date Created: 2021/03/17
* Last Modified: 2021/03/17
* Description: Increments the clock by 1 unit (minute)
* Input Parameters:
* Returns: NONE
* Precondition: NONE
* Postcondition: Clock value has increased by one.
*/
void Clock::incrementClock(void)
{
	mClock++;
}

/*
* Function: resetClock()
* Date Created: 2021/03/18
* Last Modified: 2021/03/18
* Description: resets the clock to 0
* Input Parameters:
* Returns: NONE
* Precondition: NONE
* Postcondition: clock is reset to 0 time
*/
void Clock::resetClock()
{
	mClock = 0;
}