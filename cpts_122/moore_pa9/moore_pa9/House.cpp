#include "House.h"

House::House(const int& newCount, const int& newHousenumber, const int& boardSide)
{
	mStoneCount = newCount;
	mHouseNumber = newHousenumber;
	mBoardSide = boardSide;
}

// Getters and Setters
int House::getStoneCount(void) const
{
	return mStoneCount;
}

int House::getHouseNumber(void) const
{
	return mHouseNumber;
}

int House::getBoardSide(void) const
{
	return mBoardSide;
}


void House::setStoneCount(const int& newCount)
{
	mStoneCount = newCount;
}

void House::setHouseNumber(const int& newNumber)
{
	mHouseNumber = newNumber;
}

void House::setBoardSide(const int& newSide)
{
	mBoardSide = newSide;
}

// Print data in line
void House::print(void)
{
	std::cout << "House Number: " << getHouseNumber() << std::endl << "Board Side: P" << getBoardSide() << std::endl << "Stone Count: " << getStoneCount();
}

// Will check if house is empty of stones

bool House::isEmpty(void) const
{
	return (mStoneCount == 0) ? (true) : (false);
}

// Will empty the house of it's contents and return the quantity it contained
// Returns:
//		int: number of stones in pit before empty
int House::emptyHouse(void)
{
	int tempInt = mStoneCount;
	mStoneCount = 0;
	return tempInt;
}

// increment the stone count in the house by 1
void House::incrementHouse()
{
	mStoneCount++;
}

// Increment stone coutn by bassed quantity
// Input Parameters:
//		int: number to increment by
void House::incrementHouse(const int& incrementAmount)
{
	mStoneCount += incrementAmount;
}
