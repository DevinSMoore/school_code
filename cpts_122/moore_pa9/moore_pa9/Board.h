/*******************************************************************************************
Programmer: Devin Moore
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 9: Graphical Game

Description:	Holds the board class which will hold functions related to taking turns and
				controlling game flow
*******************************************************************************************/
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h> // For rand(), srand()
#include <time.h> // for time()

#include "House.h"
#include "Store.h"
#include "KalahGraphics.h"



#define P1_STORE_INDEX KALAH_SIDE_HOUSE_COUNT
#define P2_STORE_INDEX (2*KALAH_SIDE_HOUSE_COUNT+1)
#define P2_B_SIDE_OFFSET KALAH_SIDE_HOUSE_COUNT + 1 // will put us at the start of p2s board

class Board : public Kalah
{
public:
	Board(const int& sideHouseCount = 0, const int& startingStoneCount = 0);
	Board(Board& copy);
	~Board();

	Board& operator=(Board& rhs);




	// Getters and Setters
	std::vector<House*>*& getBoardPtr(void);
	int getHouseCount(void) const;
	int getStartingStoneCount(void) const;
	int getBoardSize(void) const;
	House*& getStorePtrP1(void);
	House*& getStorePtrP2(void);

	void setBoardPtr(std::vector<House*>*& newPtr);
	void setHousePerSide(const int& newCount);
	void setStartingStones(const int& newCount);

	// Will set up board with proper side house count, and starting stone count
	virtual void initializeBoard(void);

	// Takes in players House chioce
	// Returns the index of the House landed on
	virtual int playerMove(House& HouseChoice, const int& whosTurn);

	// Input Parameters:
	//		int: Index of the position that the player placed final stone in after move
	//		int: pass whoevers turn it is (p1 = 1, p2 = 2)
	// Returns:
	//		NONE
	// Precondition: Landing index does not point to a player store
	// Postcondition: Opponents house has been emptied of stones (if any) and that count + the stone in the house player landed on will be added to players store
	virtual void captureOpponentHouse(int landingIndex, int playerTurn);

	// Will check if the game over configuration on the board is true (all houses on a side are empty)
	// Returns:
	//		bool: true if game over condition met; 0 elsewise
	virtual bool gameOverCondition(void);

	// Will print contents of board to console
	void printBoard(void);

	// Will loop continuously until user closes window or selects a button
	// Input Parameters:
	//		sf::RenderWindow: game window
	// Returns:
	//		sf::Vector2f: vecotr containing mouse cordinates player clicked on
	sf::Vector2f playerInputLoop(sf::RenderWindow& gameWindow);

	// Will check if input was a valid one
	// Input Parameters:
	//		sf::RenderWindow: game window
	//		sf::vector2f: mouse coordinates of user choice
	//		Kalah: Kalah graphics
	//		int: whos turn it is
	int validateInput(sf::RenderWindow& gameWindow, sf::Vector2f& mouseCoordinates, Kalah& graphics, int& whosTurn);

	// Will go through and update the text on the game screen for hte buttons' stone count
	// Input Parameters:
	//		sf::RenderWindow: game window to refresh info on
	//		Kalah: reference to the graphics class containing boards graphics
	void updateScreenText(sf::RenderWindow& gameWindow, Kalah& graphics);

	// Will add up any remaining stones in the houses into the particular sides players' store
	virtual void setFinalScore(void);

	// This will check which player won
	// Returns:
	//		int: 1 = p1 winner; 2 = p2 winner
	int checkWinner(void);

	// This will print onto the screen the winner of the match
	// Input Parameters:
	//	int: player that won game; 1 = P1, 2 = P2
	void printWinCondition(int& winner);

private:
	int mHousesPerSide;
	int mStartingStoneCount;
	std::vector<House*>* mpBoard;
	void printBoard(Board& boardData);
};