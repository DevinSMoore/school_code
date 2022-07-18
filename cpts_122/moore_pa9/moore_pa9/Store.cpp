#include "Store.h"


std::string& Store::getPlayerName(void)
{
	return mPlayerName;
}

void Store::setPlayerName(std::string& newName)
{
	mPlayerName = newName;
}

Store::Store(const std::string& newName)
{
	mPlayerName = newName;
}

// will print contents of store, and call print from base class
void Store::print(void)
{
	House::print();
	std::cout << std::endl << "Player Name: " << mPlayerName;
}