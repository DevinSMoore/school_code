/*******************************************************************************************
Programmer: Devin Moore
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 9: Graphical Game

Description:	This holds the information for the graphical portion of the buttons
*******************************************************************************************/
#pragma once
#include "SFML/Graphics.hpp"
//#include "KalahGraphics.h"


class HouseButton
{
public:
	HouseButton();

	sf::RectangleShape& getButton(void);
	sf::Text& getCountText(void);
	void setCountTextString(std::string& newCount);
	void setCountFont(sf::Font& newFont);

private:
	sf::RectangleShape mButton;
	sf::Font mCountFont;
	sf::Text mCountText;

};

