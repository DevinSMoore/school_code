/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/10/22
Class:      CptS121 Section 9 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: Programming Assignment 5: Yahtzee

Description: This program will allow 2 people to play a classic game of Yahtzee.
*******************************************************************************************/
#include "yahtzee.h"


int main(void)
{

	srand((unsigned int)time(NULL)); // Seeding the rand function


	// initializing program variables
	int p1Scorecard[SCORECARD_ARRAY_SIZE] = { 0 }, p2Scorecard[SCORECARD_ARRAY_SIZE] = { 0 }, tempScorecard[SCORECARD_ARRAY_SIZE] = { 0 },
		roundDiceArray[DICE_ARRAY_SIZE] = { 0 },
		turnCounter = 0, roundCounter = 0, rollCounter = 0, playerTurn = 0, winner = 0, menuChoice = 0, scoreChoice = 0, p1GrandTotal = 0, p2GrandTotal = 0,
		upperSectionSum = 0, lowerSectionSum = 0, *upper_ptr = &upperSectionSum, *lower_ptr = &lowerSectionSum; // upper and lower sections sums and their pointers 
	
	printf("Welcome to Yahtzee!\n");
	system("pause");
	do
	{ // entering game menu loop
		system("cls");
		printMenu();
		printf("Please enter a menu choice as an integer: ");
		menuChoice = integerInput();
		// printf("menuChoice: %d\n", menuChoice); // Used for debugging
		switch (menuChoice)
		{
		case 1:
			// printf("Print if case 1\n");
			printRules();
			system("pause");
			break;
		case 2: // entering main gameplay
			// printf("Print if case 2\n");

			turnCounter = 0, roundCounter = 1, rollCounter = 0, playerTurn = (turnCounter % 2) + 1; // reseting these to 0 for the new round, and player turn is set this way so I can reference the variable to get what player I care about that turn
			fillArray(0, roundDiceArray, DICE_ARRAY_SIZE); // setting all elements to 0 for round start
			fillArray(-1, p1Scorecard, SCORECARD_ARRAY_SIZE);
			fillArray(-1, p2Scorecard, SCORECARD_ARRAY_SIZE); // Filling the both player score cards with -1 so that I can detect when a player has or haasn't selected a score for the new game.
			fillArray(0, tempScorecard, SCORECARD_ARRAY_SIZE); // filling tempScorecard with 0's so my logic works in the checkScores, which fills an array element if it finds a score with that score otherwise it will leave that element 0 meaning that set of dice don't meet the reqs for it

			while (roundCounter < 14) // 
			{	

				for (int index = 0; index < 2; index++)
				{
					system("cls");
					displayScorecard(p1Scorecard, p2Scorecard, SCORECARD_ARRAY_SIZE);
					playerTurn = (turnCounter % 2) + 1;
					printf("Player %d, please press any key to roll your dice...\n", playerTurn);
					_getch();
					rollAllDice(roundDiceArray, DICE_ARRAY_SIZE);
					orderPlayerDie(roundDiceArray, DICE_ARRAY_SIZE);
					displayPlayerDice(roundDiceArray, DICE_ARRAY_SIZE); // rolling ordering then showing new dice roll
					printf("\nPress any key to proceed...\n");
					_getch();
					rollCounter = 1; // reseting roll counter to 1

					while (rollCounter < 3)
					{
						printPostRollMenu();
						printf("Please enter an option: ");
						menuChoice = integerInput();
						system("cls");
						switch (menuChoice)
						{
						case 1:		
							rollCounter = 4; // just setting the counter to over it's max here to break out of the loop
							break;
						case 2:
							printf("rerolling your dice...\n");
							rollAllDice(roundDiceArray, DICE_ARRAY_SIZE);
							orderPlayerDie(roundDiceArray, DICE_ARRAY_SIZE);
							displayPlayerDice(roundDiceArray, DICE_ARRAY_SIZE);
							printf("\nPress any key to proceed...\n");
							_getch();
							rollCounter++;
							break;
						case 3:
							rerollSelectDice(roundDiceArray, DICE_ARRAY_SIZE); // User will select which dice they wish to reroll
							orderPlayerDie(roundDiceArray, DICE_ARRAY_SIZE);
							displayPlayerDice(roundDiceArray, DICE_ARRAY_SIZE);
							printf("\nPress any key to proceed...\n");
							_getch();
							rollCounter++;
							break;
						default:
							printf("Hey you! how'd you get here?");
							break;
						}
					} // end of players rolls
					
					
					
					checkPlayerScores(tempScorecard, roundDiceArray, SCORECARD_ARRAY_SIZE); // will check which combos the player is eligable for					
					int validSelection = 0, userSelection = 0;
					if (playerTurn == 1)
					{
						do
						{
							displayScorecard(p1Scorecard, p2Scorecard, SCORECARD_ARRAY_SIZE);
							printSimpleCategoryList();
							displayPlayerDice(roundDiceArray, DICE_ARRAY_SIZE);
							printf("\nPlease enter a category to score: ");
							scoreChoice = integerInputForScore();
							if (p1Scorecard[scoreChoice - 1] == (-1)) {
								setPlayerScore(scoreChoice, tempScorecard, p1Scorecard, SCORECARD_ARRAY_SIZE);
								validSelection = 1;
							}
							else {
								printf("Please enter a category that you haven't selected previously");
							}
						} while (!validSelection);

						turnCounter++;
						printf("\ninside p1 soce turnCounter: %d\n\n", turnCounter);
					} // will set player 1 score
					else if (playerTurn == 2) // else would suffice i'm sure
					{
						do
						{
							displayScorecard(p1Scorecard, p2Scorecard, SCORECARD_ARRAY_SIZE);
							printSimpleCategoryList();
							displayPlayerDice(roundDiceArray, DICE_ARRAY_SIZE);
							printf("\nPlease enter a category to score: ");
							scoreChoice = integerInputForScore();
							if (p2Scorecard[scoreChoice - 1] == (-1)) {
								setPlayerScore(scoreChoice, tempScorecard, p2Scorecard, SCORECARD_ARRAY_SIZE);
								validSelection = 1;
							}
							else {
								system("cls");
								printf("Please enter a category that you haven't selected previously!!");
							}
						} while (!validSelection);

						turnCounter++;
						// printf("\ninside p2 turnCounter: %d\n\n", turnCounter);
					} // will set player 2 score

				} // End of for loop for the players turns (2 of them)


				roundCounter++;
				// printf("roundCounter: %d", roundCounter);
			
			} // end of game while loop 
			
			upperLowerSum(upper_ptr, lower_ptr, p1Scorecard, SCORECARD_ARRAY_SIZE); // getting p1's upper and lower section sums
			p1GrandTotal = computeGrandTotal(upperSectionSum, lowerSectionSum, checkIfBonus(upperSectionSum));
			upperLowerSum(upper_ptr, lower_ptr, p2Scorecard, SCORECARD_ARRAY_SIZE); // getting p2's upper and lower section sums
			p2GrandTotal = computeGrandTotal(upperSectionSum, lowerSectionSum, checkIfBonus(upperSectionSum));
			winner = determineVictor(p1GrandTotal, p2GrandTotal); // will check who the winner is and return the player number
			printEndGameScreen(p1GrandTotal, p2GrandTotal, winner);
	
			break;
		case 3:
			// printf("Print if case 3\n");
			printf("Thanks for playing my game, and I hope you have an excellent day!\n");
			menuChoice = 0;
			break;
		default:
			printf("How have you gotten here young one?\n"); // for real the input function  should block anything that might land you here.
			break;
		}


	} while (menuChoice != 0);
	return 0;
}
