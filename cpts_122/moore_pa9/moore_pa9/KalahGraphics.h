/*******************************************************************************************
Programmer: Devin Moore
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 9: Graphical Game

Description:	Contains all of the graphical functions for hte background and various texts
*******************************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> // mainly just for debuggin for the graphical game stuff
#include <SFML/Window.hpp>
#include <string> // for C++ strings

#include "HouseButton.h"
#define KALAH_STARTING_STONE_COUNT 4
#define KALAH_SIDE_HOUSE_COUNT 6
// This is a little goofy, these correlate the buttons with the index of the house they're assigned to. There's a smarter way to do this.
#define BTN0_HOUSE 12 // P2H6
#define BTN1_HOUSE 11 // P2H5
#define BTN2_HOUSE 10 // P2H4
#define BTN3_HOUSE 9 // P2H3
#define BTN4_HOUSE 8 // P2H2
#define BTN5_HOUSE 7 // P2H1
#define BTN6_HOUSE 0 // P1H6
#define BTN7_HOUSE 1 // P1H5
#define BTN8_HOUSE 2 // P1H4
#define BTN9_HOUSE 3 // P1H3
#define BTN10_HOUSE 4 // P1H2
#define BTN11_HOUSE 5 // P1H1

#define NAME_TOO_LONG "Name is too long, please enter a name with 30 or fewer characters...."
#define NO_NAME_ENTERED "You have not entered a name... Please enter a name to continue..."
#define INVALID_HOUSE_SEL_WRONG_SIDE "You have selected a house on the wrong side of the board...."
#define INVALID_HOUSE_SEL_SAME_SEL "You have selected the same house please select different house...."
#define INVALID_HOUSE_SEL_EMPTY_HOUSE "This house is empty, please select a non-empty house...."

typedef enum player
{
	P1 = 1, P2
} Player;


class Kalah
{
public:	
	Kalah();
	~Kalah();

	
	sf::Sprite*& getBackgroundSpritePtr(void);
	std::vector<HouseButton>*& getButtonArrayPtr(void);
	
	// sets a players name
	// Input Parameters:
	// std::string: name to set
	// int: player that we're setting the name of; 1 = p1; 2 = p2
	void setPlayerName(const int& whichPlayer, std::string& playerNameToSet);
	

	// Prints a splash screen then gathers both players names
	// Input Parameters:
	//		std::string: string P1s name is goign to be placed into
	//		std::string: string for P2s name
	void splashScreen(std::string& p1Name, std::string& p2Name);
	
	// This will show an error message on the screen
	// Input Parameters:
	//		std::string representing the message to be displayd
	void introWarning(const std::string& warningMessage);

	// This will go through and set all of the base values for all of the buttons
	// Input Parameters:
	//      sf::RenderWindow: reference to the game window that you want to display buttons onto.
	void initializeButtons(sf::RenderWindow& gameWindow);
	

private:
	std::vector<HouseButton>* mpButtonArray;
	sf::Texture* mpBackgroundTexture;
	sf::Sprite* mpGameBackgroundSprite;

};

