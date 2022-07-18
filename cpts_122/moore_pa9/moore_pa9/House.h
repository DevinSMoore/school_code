/*******************************************************************************************
Programmer: Devin Moore
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 9: Graphical Game

Description:	This holds the class House which holds the stone count and functions related
				to changing the quantity of the houses
*******************************************************************************************/
#pragma once
#include <iostream>

class House
{
public:
	House(const int& startingCount = 0, const int& HouseNumber = 0, const int& boardSide = 0);

	// Getters and Setters
	int getStoneCount(void) const;
	int getHouseNumber(void) const;
	int getBoardSide(void) const;

	void setStoneCount(const int& newCount);
	void setHouseNumber(const int& newNumber);
	void setBoardSide(const int& newSide);

	// Prints contents of house
	virtual void print(void);

	// Will check if house is empty of stones
	bool isEmpty(void) const;

	// Will empty the house of it's contents and return the quantity it contained
	// Returns:
	//		int: number of stones in pit before empty
	int emptyHouse(void);

	// increment the stone count in the house by 1
	void incrementHouse(void);

	// Increment stone coutn by bassed quantity
	// Input Parameters:
	//		int: number to increment by
	void incrementHouse(const int& incrementAmount);


private:
	int mStoneCount;
	int mHouseNumber;
	int mBoardSide; // will hold the player number of the side that the House is on
};
