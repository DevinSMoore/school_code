/*******************************************************************************************
Programmer: Devin Moore
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 9: Graphical Game

Description:	This will allow you to play a game of mancalah, rules outlined in readme.txt
*******************************************************************************************/
#include "Board.h"

int main(void)
{
	int playerTurn = P1, winner = 0;

	srand((uint32_t)time(NULL));
	sf::Vector2f mouseCoords;
	Board nB(KALAH_SIDE_HOUSE_COUNT, KALAH_STARTING_STONE_COUNT);
	//Kalah newGraphics;
	std::string p1Name = "", p2Name = "", tmpStr = "";
	
	sf::Font font;
	font.loadFromFile("fonts/Montserrat-Regular.ttf");
	sf::Text playerTurnText, player1Score, player2Score, player1Name, player2Name;
	playerTurnText.setFont(font);
	playerTurnText.setPosition(550.0f, 650.0f);
	playerTurnText.setCharacterSize(50);
	playerTurnText.setFillColor(sf::Color::Black);

	player1Score.setFont(font);
	player2Score.setFont(font);
	player1Name.setFont(font);
	player2Name.setFont(font);

	player1Score.setFillColor(sf::Color::Black);
	player2Score.setFillColor(sf::Color::Black);
	player1Name.setFillColor(sf::Color::Black);
	player2Name.setFillColor(sf::Color::Black);

	player1Score.setCharacterSize(30);
	player2Score.setCharacterSize(30);
	player1Name.setCharacterSize(30);
	player2Name.setCharacterSize(30);

	player1Score.setPosition(1250.0f, 350.0f);
	player2Score.setPosition(120.0f, 300.0f);
	player1Name.setPosition(1250.0f, 650.0f);
	player2Name.setPosition(130.0f, 27.0f);




	int returnIndex = -1, whosTurn = -1, userSelection = -1, selectionIndex = 0, turnCount = ((uint32_t)rand() * 15); // Start with a random player; also this does not reflect the number of turns taken

	nB.initializeBoard();

	nB.splashScreen(p1Name, p2Name);
	
	((Store*)nB.getStorePtrP1())->setPlayerName(p1Name);
	((Store*)nB.getStorePtrP2())->setPlayerName(p2Name);
	
	player1Name.setString(p1Name);
	player2Name.setString(p2Name);

	sf::RenderWindow gameScreen(sf::VideoMode(1500, 700), "Welcome to Kalah! - Devin Moore", sf::Style::Close | sf::Style::Titlebar);
	gameScreen.draw(*nB.getBackgroundSpritePtr());

	
	nB.initializeButtons(gameScreen);
	


	nB.printBoard();
	gameScreen.display();
	while (!nB.gameOverCondition())
	{
		if (whosTurn != (turnCount % 2) + 1) // Basically just detecting a state change; If a turn happened then last turns turncount%2 + 1 will be different from this turns turnCount % 2 + 1 because we increment turnCount
		{
			whosTurn = (turnCount % 2) + 1;
			std::cout << "WhosTurn: " << whosTurn << std::endl;
			
		}

		if (whosTurn == 1)
		{
			p1Name = ((Store*)nB.getStorePtrP1())->getPlayerName();
			p1Name += "'s turn...";
			playerTurnText.setString(p1Name);
		}
		else
		{
			p2Name = ((Store*)nB.getStorePtrP2())->getPlayerName();
			p2Name += "'s turn...";
			playerTurnText.setString(p2Name);

		}
		tmpStr = "Stones: ";
		tmpStr += std::to_string(nB.getStorePtrP1()->getStoneCount());
		player1Score.setString(tmpStr);
		tmpStr = "Stones: ";
		tmpStr += std::to_string(nB.getStorePtrP2()->getStoneCount());
		player2Score.setString(tmpStr);

		gameScreen.clear();
		nB.updateScreenText(gameScreen, nB);
		gameScreen.draw(playerTurnText);
		gameScreen.draw(player1Name);
		gameScreen.draw(player1Score);
		gameScreen.draw(player2Name);
		gameScreen.draw(player2Score);
		gameScreen.display();


		do
		{
		mouseCoords = nB.playerInputLoop(gameScreen);
		
		if (!gameScreen.isOpen())
		{
			return 0;
		}
		
		selectionIndex = nB.validateInput(gameScreen, mouseCoords, nB, whosTurn);
		std::cout << "returned Selection index: " << selectionIndex << std::endl;
		} while(selectionIndex == -1);

		returnIndex = nB.playerMove(*nB.getBoardPtr()->at(selectionIndex), whosTurn);
		std::cout << "Return Index: " << returnIndex << std::endl;

		while (selectionIndex == returnIndex)
		{
			nB.introWarning(INVALID_HOUSE_SEL_SAME_SEL);
			mouseCoords = nB.playerInputLoop(gameScreen);
			if (!gameScreen.isOpen())
			{
				return 0;
			}
			selectionIndex = nB.validateInput(gameScreen, mouseCoords, nB, whosTurn);
	
			returnIndex = nB.playerMove(*nB.getBoardPtr()->at(selectionIndex), whosTurn); // Continue to ask 
		}

		if (returnIndex == 6 || returnIndex == 13)
		{
			// don't increment so player can take another turn
		}
		else if (nB.getBoardPtr()->at(returnIndex)->getStoneCount() == 1) // Means that the house was empty before we placed a stone
		{
			nB.captureOpponentHouse(returnIndex, whosTurn);
			turnCount++;
		}
		else
		{ // just increment turn
			turnCount++;
		}
		nB.printBoard();
		nB.updateScreenText(gameScreen, nB);
	}
	nB.setFinalScore();
	gameScreen.close();
	winner = nB.checkWinner();
	nB.printWinCondition(winner);


}

