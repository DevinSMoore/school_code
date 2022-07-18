/*******************************************************************************************
Programmer: Devin Moore
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 9: Graphical Game

Description:	This is derived from House.h, but only expands it into a name
*******************************************************************************************/
#pragma once
#include "House.h"
#include <string>


class Store : public House
{
public:
	Store(const std::string& newName = "");

	std::string& getPlayerName(void);
	void setPlayerName(std::string& newName);

	// will print contents of store, and call print from base class
	void print(void);

private:
	std::string mPlayerName;
};