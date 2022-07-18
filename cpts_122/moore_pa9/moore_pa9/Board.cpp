#include "Board.h"

Board::Board(const int& sideHouseCount, const int& startingStoneCount)
{
	mHousesPerSide = sideHouseCount;
	mStartingStoneCount = startingStoneCount;
	mpBoard = new std::vector<House*>(2 * (sideHouseCount + 1)); // this will give us 2 sides ofthe board with the player store at (houseCount + ) and 
}

Board::Board(Board& copy)
{
	mHousesPerSide = copy.getHouseCount();
	mStartingStoneCount = copy.getStartingStoneCount();
	*mpBoard = *copy.getBoardPtr();
}

Board::~Board()
{
	mpBoard->clear();
	std::cout << "Board has been cleared and deleted...." << std::endl;
}

Board& Board::operator=(Board& rhs)
{
	if(&rhs != this)
	{
		mHousesPerSide = rhs.getHouseCount();
		mStartingStoneCount = rhs.getStartingStoneCount();
		*mpBoard = *(rhs.getBoardPtr());
	}

	return *this;
}

// Getters and Setters
std::vector<House*>*& Board::getBoardPtr(void)
{
	return mpBoard;
}

int Board::getHouseCount(void) const
{
	return mHousesPerSide;
}

int Board::getStartingStoneCount(void) const
{
	return mStartingStoneCount;
}

int Board::getBoardSize(void) const
{
	return mpBoard->size();
}

House*& Board::getStorePtrP1(void)
{
	return (mpBoard->at(mHousesPerSide));
}

House*& Board::getStorePtrP2(void)
{
	return (mpBoard->at(2 * mHousesPerSide + 1));
}

void Board::setBoardPtr(std::vector<House*>*& newPtr)
{
	mpBoard = newPtr;
}

void Board::setHousePerSide(const int& newCount)
{
	mHousesPerSide = newCount;
}

void Board::setStartingStones(const int& newCount)
{
	mStartingStoneCount = newCount;
}

// Will set up board with proper side house count, and starting stone count
void Board::initializeBoard(void)
{
	int currentHouseNumber = 0, currentBoardSide = 0;
	for (int index = 0; index < (int)mpBoard->size(); index++)
	{
		currentHouseNumber = (index % mHousesPerSide) + 1; // This will get us a number between 1 and mHousesPerSide which is the number of houses per player side
		currentBoardSide = (index > mHousesPerSide) ? (2) : (1);

		// mHousesPerSide convienently is also the index of player one's store, so we can use that to our advantage
		if (index < mHousesPerSide)
		{
			mpBoard->at(index) = new House(mStartingStoneCount, currentHouseNumber, currentBoardSide);
		}
		else if (index == mHousesPerSide || index == (2 * mHousesPerSide + 1)) // At P1s store
		{
			mpBoard->at(index) = new Store;
			mpBoard->at(index)->setStoneCount(0); // Want an empty store to begin with, and we want the players store numbers to be mHousesPerSide + 1
			mpBoard->at(index)->setHouseNumber(mHousesPerSide + 1);
			mpBoard->at(index)->setBoardSide(currentBoardSide);
		}
		else if (index > mHousesPerSide)
		{
			currentHouseNumber = ((index - 1) % mHousesPerSide) + 1; // Need to take away one from the index here so we get another pattern of 1-mHousesPerSide, otherwise we'll be in a OBONE situation
			mpBoard->at(index) = new House(mStartingStoneCount, currentHouseNumber, currentBoardSide); // 
		}

	}
}

// Takes in players House chioce
// Returns the index of the House landed on
int Board::playerMove(House& houseChoice, const int& whosTurn)
{
	int stoneCount = houseChoice.emptyHouse(), 	 // Remove the stones from the house user selected ant set the number of stones it had
		currentIndex = houseChoice.getHouseNumber() - 1; // House number will be 1 -to-> (mHousesPerSide); thus we just take away one to get the index;

	if (houseChoice.getBoardSide() == 2) // Player 2s side
	{
		currentIndex += P2_B_SIDE_OFFSET; // Add the offest to get to P2s side of the board
	}

	std::cout << "Stone count BEFORE entering while loop: " << stoneCount << std::endl;
	while (stoneCount > 0) // while we have any stones left in our "hand" to distribute
	{
		std::cout << "current stone count: " << stoneCount << std::endl;
		++currentIndex %= 14; // advance 1 place then do mod 14 to get an index of 0-13 so it behaves as if we're circling around the board
		std::cout << "Index after increment & mod14: " << currentIndex << std::endl;

		if (currentIndex == 6 || currentIndex == 13) // If we're at p1 or p2s stores
		{
			if (whosTurn == P1 && houseChoice.getBoardSide() == P1) // If we're taking p1s turn then increment their store
			{
				getStorePtrP1()->incrementHouse();
			}
			else if (whosTurn == P2 && houseChoice.getBoardSide() == P2) // taking p2s turn and we hit their store
			{
				getStorePtrP2()->incrementHouse();
			}
		}
		else { // not a player store
			(*mpBoard)[currentIndex]->incrementHouse(); // then add a stone to the House

		}
		stoneCount--;
	} // after we leave this loop startingIndex will be sitting on the House in which we placed our last stone
	
	std::cout << "Current Index: " << currentIndex << std::endl;
	return currentIndex;

}

// Input Parameters:
//		int: Index of the position that the player placed final stone in after move
//		int: pass whoevers turn it is (p1 = 1, p2 = 2)
// Returns:
//		NONE
// Precondition: Landing index does not point to a player store; for board size 14 this will be [6] and [13]; or more generally [mHousesPerSide] and [2*mHousesPerSide + 1]
// Postcondition: Opponents house has been emptied of stones (if any) and that count + the stone in the house player landed on will be added to players store
void Board::captureOpponentHouse(int landingIndex, int playerTurn)
{
	
	int opponentIndex = 2 * mHousesPerSide - landingIndex; // 2 * mHousesPerSide will get us to the opponentsStore index -1 which is the last house on their side of hte board; works for both sides of the board

	int houseSum = mpBoard->at(landingIndex)->getStoneCount() + mpBoard->at(opponentIndex)->getStoneCount(); // Sum of stones we're going to add to players store
	std::cout << "House Sum: " << houseSum << std::endl;

	if (playerTurn == 1)
	{

		getStorePtrP1()->incrementHouse(houseSum);
	}
	else
	{
		getStorePtrP2()->incrementHouse(houseSum);
	}

	mpBoard->at(landingIndex)->emptyHouse();
	mpBoard->at(opponentIndex)->emptyHouse();// Empty houses of stones
}

// Will check if the game over configuration on the board is true (all houses on a side are empty)
// Returns:
//		bool: true if game over condition met; 0 elsewise
bool Board::gameOverCondition(void)
{
	int sumSide = 0, i = 0;
	for (; i < 6; i++)
	{
		sumSide += mpBoard->at(i)->getStoneCount();
	}
	if (sumSide == 0)
	{
		return true;
	}
	else
	{
		sumSide &= ~sumSide; // clear sumside
		for (i++; i < 12; i++) // add one to i so we get p2 house indicies 7-12
		{
			sumSide += mpBoard->at(i)->getStoneCount();
		}
		if(sumSide == 0)
		{
			return true;
		}
		else { return false; }
	}
}

// Will print contents of board to console

void Board::printBoard(void)
{
	printBoard(*this);
}

// Will loop continuously until user closes window or selects a button
// Input Parameters:
//		sf::RenderWindow: game window
// Returns:
//		sf::Vector2f: vecotr containing mouse cordinates player clicked on
sf::Vector2f Board::playerInputLoop(sf::RenderWindow& gameWindow)
{
	
	sf::Vector2f mouseCoords;
	while (gameWindow.isOpen())
	{
		mouseCoords.x = 0;
		mouseCoords.y = 0; // reset coordinates
		sf::Event gameEvent;

		while (gameWindow.pollEvent(gameEvent))
		{
			switch (gameEvent.type)

			{
			case sf::Event::Closed:
				std::cout << "playerInputLoop Window closing...." << std::endl;
				gameWindow.close();
				break;
			case sf::Event::MouseButtonPressed:
				// This chunk of code is a bit of a monster, all it does is check that the pit selected by user with the mouse is valid as in it's a house on their own side of the board
				// Tried to think of how to get a case statement to work here but I'm a dummy

				mouseCoords = gameWindow.mapPixelToCoords(sf::Mouse::getPosition(gameWindow)); // set the coordinate of the mouse at button press

				std::cout << "Testing Mouse pressed Event...." << std::endl;
				std::cout << "Mouse position at press: " << std::endl << "X: " << sf::Mouse::getPosition(gameWindow).x << std::endl << "Y: " << sf::Mouse::getPosition(gameWindow).y << std::endl;

				return mouseCoords;
			default:
				break;
			}
		} // end event poll loop
	}
	return mouseCoords;

}

// Will check if input was a valid one
// Input Parameters:
//		sf::RenderWindow: game window
//		sf::vector2f: mouse coordinates of user choice
//		Kalah: Kalah graphics
//		int: whos turn it is
int Board::validateInput(sf::RenderWindow& gameWindow, sf::Vector2f& mouseCoordinates, Kalah& graphics, int& whosTurn)
{
	int returnIndex = 0;
if (whosTurn == P2)
{ // every check is the same but with different values so I only commented the top check
	if (graphics.getButtonArrayPtr()->at(0).getButton().getGlobalBounds().contains(mouseCoordinates)) // If user selected button above P2 House 6 then going proceeding to the right
	{
			std::cout << "Hit BTN0 P2 H6...." << std::endl;
			returnIndex = BTN0_HOUSE;

		}
		else if (graphics.getButtonArrayPtr()->at(1).getButton().getGlobalBounds().contains(mouseCoordinates)) // P2 House 5
		{
			std::cout << "Hit BTN0 P2 H5...." << std::endl;

			returnIndex = BTN1_HOUSE;
		}
		else if (graphics.getButtonArrayPtr()->at(2).getButton().getGlobalBounds().contains(mouseCoordinates)) // P2 House 4
		{
			std::cout << "Hit BTN0 P2 H4...." << std::endl;

			returnIndex = BTN2_HOUSE;
		}
		else if (graphics.getButtonArrayPtr()->at(3).getButton().getGlobalBounds().contains(mouseCoordinates)) // P2 House 3
		{
			std::cout << "Hit BTN0 P2 H3...." << std::endl;

			returnIndex = BTN3_HOUSE;
		}
		else if (graphics.getButtonArrayPtr()->at(4).getButton().getGlobalBounds().contains(mouseCoordinates)) // P2 House 2
		{
			std::cout << "Hit BTN0 P2 H2...." << std::endl;

			returnIndex = BTN4_HOUSE;
		}
		else if (graphics.getButtonArrayPtr()->at(5).getButton().getGlobalBounds().contains(mouseCoordinates)) // P2 House 1
		{
			std::cout << "Hit BTN0 P2 H1...." << std::endl;

			returnIndex = BTN5_HOUSE;
		}
		else
		{
			returnIndex = -1;
		}

	}
	else if (whosTurn == P1)
	{

		if (graphics.getButtonArrayPtr()->at(6).getButton().getGlobalBounds().contains(mouseCoordinates)) // P1 House 1; starting at the left hand side of player 1s house then going right
		{
			returnIndex = BTN6_HOUSE;
		}
		else if (graphics.getButtonArrayPtr()->at(7).getButton().getGlobalBounds().contains(mouseCoordinates)) // P1 House 2
		{
			returnIndex = BTN7_HOUSE;
		}
		else if (graphics.getButtonArrayPtr()->at(8).getButton().getGlobalBounds().contains(mouseCoordinates)) // P1 House 2
		{
			returnIndex = BTN8_HOUSE;
		}
		else if (graphics.getButtonArrayPtr()->at(9).getButton().getGlobalBounds().contains(mouseCoordinates)) // P1 House 2
		{
			returnIndex = BTN9_HOUSE;
		}
		else if (graphics.getButtonArrayPtr()->at(10).getButton().getGlobalBounds().contains(mouseCoordinates)) // P1 House 2
		{
			returnIndex = BTN10_HOUSE;
		}
		else if (graphics.getButtonArrayPtr()->at(11).getButton().getGlobalBounds().contains(mouseCoordinates)) // P1 House 2
		{
			returnIndex = BTN11_HOUSE;
		}
		else
		{
			returnIndex = -1;
		}

	}
return returnIndex;

}

// Will go through and update the text on the game screen for hte buttons' stone count
// Input Parameters:
//		sf::RenderWindow: game window to refresh info on
//		Kalah: reference to the graphics class containing boards graphics
void Board::updateScreenText(sf::RenderWindow& gameWindow, Kalah& graphics)
{
	int i = 0;
	gameWindow.draw(*graphics.getBackgroundSpritePtr());
	std::string tempString = "";

	for (; i < 6; i++)
	{
		gameWindow.draw(graphics.getButtonArrayPtr()->at(i).getButton());
		tempString = std::to_string(mpBoard->at(P2_STORE_INDEX - 1 - i)->getStoneCount());
		std::cout << "TempString for i[" << i << "]: " << tempString << std::endl;
		graphics.getButtonArrayPtr()->at(i).setCountTextString(tempString); // Setting all to 4 intitially
		gameWindow.draw(graphics.getButtonArrayPtr()->at(i).getCountText());
	}
	for (; i < 12; i++)
	{
		gameWindow.draw(graphics.getButtonArrayPtr()->at(i).getButton());
		tempString = std::to_string(mpBoard->at(i - 6)->getStoneCount());
		std::cout << "TempString for i[" << i << "]: " << tempString << std::endl;
		graphics.getButtonArrayPtr()->at(i).setCountTextString(tempString); // Setting all to 4 intitially
		gameWindow.draw(graphics.getButtonArrayPtr()->at(i).getCountText());
	}
}

// Will add up any remaining stones in the houses into the particular sides players' store
void Board::setFinalScore(void)
{
	int i = 0;
	for (; i < 6; i++)
	{
		getStorePtrP1()->incrementHouse(mpBoard->at(i)->emptyHouse()); // add the contents of each store to the players store and empty them, we can do this with both because one will have some non-empty houses and the other will only have mepty houses
	}
	for (i++; i < 13; i++)
	{
		// advance one to skip P1 store
		getStorePtrP2()->incrementHouse(mpBoard->at(i)->emptyHouse());
	}
}

// This will check which player won
// Returns:
//		int: 1 = p1 winner; 2 = p2 winner
int Board::checkWinner(void)
{
	return (getStorePtrP1()->getStoneCount() > getStorePtrP2()->getStoneCount()) ? (1) : (2); // if player ones store is greater than p2 store, then return 1 else return 2
}

// This will print onto the screen the winner of the match
// Input Parameters:
//	int: player that won game; 1 = P1, 2 = P2
void Board::printWinCondition(int& winner)
{
	sf::RenderWindow gameEndWindow(sf::VideoMode(400, 200), "Winner, Good Job!", sf::Style::Close | sf::Style::Titlebar);
	sf::Texture newTexture;
	newTexture.loadFromFile("art/winScreen.png");
	sf::Sprite newSprite;
	newSprite.setTexture(newTexture);
	sf::Font newFont;
	newFont.loadFromFile("fonts/Montserrat-Regular.ttf");
	
	sf::Event endingEvent;
	std::string winnerName = "";
	if (winner == 1)
	{
		winnerName = ((Store*)getStorePtrP1())->getPlayerName();
	}
	else
	{
		winnerName = ((Store*)getStorePtrP2())->getPlayerName();

	}
	sf::Text endingText;
	endingText.setString(winnerName);
	std::cout << "Winner Name: " << winnerName << std::endl;
	float midPoint = (endingText.getCharacterSize() / 10) * (float)winnerName.size();
	endingText.setOrigin(0.0f, 0.0f);

	endingText.setPosition(150.0f, 90.0f);
	
	endingText.setFillColor(sf::Color::Black);
	endingText.setFont(newFont);
	
	gameEndWindow.draw(newSprite);

	gameEndWindow.draw(endingText);
	gameEndWindow.display();

	while (gameEndWindow.isOpen())
	{
		while (gameEndWindow.pollEvent(endingEvent))
		{
			switch (endingEvent.type)

			{
			case sf::Event::Closed:
				std::cout << "playerInputLoop Window closing...." << std::endl;
				gameEndWindow.close();
				break;
			default:

				break;
			}
		}
	}
}

void Board::printBoard(Board& boardData)
{
	for (int index = 0; index < boardData.getBoardSize(); index++)
	{
		if (index == boardData.getHouseCount() || index == (2 * boardData.getHouseCount() + 1)) // index getHouseCount gets us player 1s store, and 2 * houseCount + 1 gets P2s store
		{
			((House*)boardData.getBoardPtr()->at(index))->print();
			std::cout << std::endl;
		}
		else
		{
			boardData.getBoardPtr()->at(index)->print();
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}
