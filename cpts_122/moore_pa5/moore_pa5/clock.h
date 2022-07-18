/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/15
Class:      CptS121 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 5 Grocery Store Simulator

Description:	This will contain our clock which will contain our global clock that 
				all actions are taken relative to. so for instance the difference 
				between the current time and a customers creation time could be their
				arrival time which then will cause an action to be taken.
*******************************************************************************************/
#pragma once
#include <time.h>

class Clock
{
public:
	Clock();

	// Getters and Setters
	int getClock(void) const;

	void setClock(const int& newClk);

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
	void incrementClock(void);

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
	void resetClock();


private:
	int mClock;

};