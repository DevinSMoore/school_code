/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/11/28
Class:      CptS121 Section 9 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 6

Description: Programming a game 2 player game of battleship in which the second player is
the PC, and will have automated moves. Eache player's moves will be printed to a file
along with hits/misses and sinks. At the end of the game, the statistics will also be
printed to the file
*******************************************************************************************/
#include "battleship.h"



int main(void)
{
	srand((unsigned)time(NULL)); // seeding rand()
	
	Bool isValid = FALSE, validDirections[NUM_DIRECTIONS] = { FALSE }, winner = FALSE, isValid2 = FALSE, hitShot = FALSE; // This is an array of bool values, each element represents a direction: 0 = up, 1 = down, 2 = left, 3 = right.
	int menuChoice = 0, status = 0, userChoice = 0, userRowChoice = 0, userColumnChoice = 0, turnCounter = 0, playerTurn = 0;
	int tempIntArray1[5] = { 0 }, tempIntArray2[5] = { 0 };
	Location validPlacementCoordinates[4] = { 0, 0, 0, 0 }, // frontRow, frontColumn, backRow, backColumn
			p1_shipLocations[5] = { 0, 0, 0, 0 }, p2_shipLocations[5] = { 0, 0, 0, 0 }; // we will assume that the first Location in this array represents the first ship we place on the board. c->

	 // Initializing player boards with cells (symbol, isOccupied)
	Cell p1_board[MAX_ROWS][MAX_COLUMNS] = { '\0', FALSE, FALSE }, p2_board[MAX_ROWS][MAX_COLUMNS] = { '\0', FALSE, FALSE }, p1HitMiss_board[MAX_ROWS][MAX_COLUMNS] = { '\0', FALSE, FALSE }, p2HitMiss_board[MAX_ROWS][MAX_COLUMNS] = { '\0', FALSE, FALSE };
	
	Stats p1_stats = { 0, 0, 0, 0.0, FALSE }, p2_stats = { 0, 0, 0, 0.0, FALSE }, * p1_stats_ptr = &p1_stats, * p2_stats_ptr = &p2_stats;

	// initializing the ships; symbol then size then name of the ship.
	Ship carrier = { CARR_SYMB, CARR_SIZE, "carrier" }, battleship = { BTL_SYMB, BTL_SIZE, "battleship" }, cruiser = { CRSR_SYMB, CRSR_SIZE, "cruiser" },
		submarine = { SUB_SYMB, SUB_SIZE, "submarine" }, destroyer = { DEST_SYMB, DEST_SIZE, "destroyer" }; 

	Ship fleet[NUM_SHIPS] = { carrier, battleship, cruiser, submarine, destroyer }; // made this array for the manual placement function

	FILE* outfile = NULL;
	outfile = fopen("battleship.log", "a");

	do {
		system("cls");
		printf("Welcome to the game of Battleship!\n");
		printMenu();
		printf("Please enter a menu choice as an integer: ");
		menuChoice = integerInput();
		switch (menuChoice)
		{
			case 1: // Print Rules
				printRules();
				break;
			case 2: // Play Game
				// Initializing initial game state
				
				turnCounter = (rand() % 10), playerTurn = (turnCounter % 2) + 1;

				init_board(p1_board, MAX_ROWS, MAX_COLUMNS);
				init_board(p2_board, MAX_ROWS, MAX_COLUMNS);
				init_board(p1HitMiss_board, MAX_ROWS, MAX_COLUMNS);
				init_board(p2HitMiss_board, MAX_ROWS, MAX_COLUMNS);
				automaticPlacement(p2_board, fleet, p2_shipLocations);
				do {
					system("cls");
					printf("Would you like to manually or automatically place your ships?\n");
					printf("Enter 1 for Manual placement, or enter 2 for Automatic placement.\n");
					printf("Please enter an integer: ");
					status = scanf("%d", &userChoice);
					if (status < 1)
					{
						flushDataStream(); // Emptying input stream
					}
				} while (userChoice < 1 || userChoice > 2);

				switch (userChoice) {
					case 1:
						manualPlacement(p1_board, fleet, p1_shipLocations);
						break;
					case 2:
						automaticPlacement(p1_board, fleet, p1_shipLocations);
						break;
					default:
						break;
				}
				// Regular play begins here

				while (!winner)
				{
					isValid2 = FALSE;
					playerTurn = (turnCounter % 2) + 1;
					//printf("playerTurn before if check: %d\n", playerTurn);
					//printf("turnCounter: %d\n", turnCounter);
					
					if (playerTurn == 1)
					{
						//printBool(isValid2);
						//printf("\n");
						while (!isValid2)
						{
							system("cls");
							print_hitMiss_board(p1HitMiss_board, MAX_ROWS, MAX_COLUMNS, playerTurn);
							calulateHitMissPercent(p1_stats_ptr);
							print_board(p1_board, MAX_ROWS, MAX_COLUMNS, playerTurn, p1_stats);
							
							printf("Please enter a row and column to target between 0 and 9\n"); // Getting users input for their shot
							printf("Row: ");
							userRowChoice = integerInput();
							printf("Column: ");
							userColumnChoice = integerInput();
							
							if (p2_board[userRowChoice][userColumnChoice].hitAttempt == FALSE) // if we haven't attempted a shot at that location
							{
								//printf("hitAttampt at the chosen cell: ");
								//printBool(p2_board[userRowChoice][userColumnChoice].hitAttempt);
								//printf("\n");
								hitShot = playerShot(p2_board, p1HitMiss_board, userRowChoice, userColumnChoice, p1_stats_ptr);
							    //hitShot = automaticTurn(p2_board, p1HitMiss_board, p1_stats_ptr, outfile, playerTurn);
								if (hitShot) { 
									printf("Nice shot Good Job!\n");
									fprintf(outfile, "Player 1 hit at row: %d column: %d\n", userRowChoice, userColumnChoice);
									}
								else { 
									printf("Sorry you missed! bad luck\n"); 
									fprintf(outfile, "Player 1 miss at row: %d column: %d\n", userRowChoice, userColumnChoice);
									}
								print_simple_board(p1HitMiss_board, MAX_ROWS, MAX_COLUMNS);
								printf("Press any key to continue to the next turn...");
								_getch();
								turnCounter++;
								isValid2 = TRUE;
								p1_stats.isWinner = gameOverCondition(p1HitMiss_board, p2_shipLocations, fleet);
								//printf("p1 isWinner: ");
								//printBool(p1_stats.isWinner);
								// print_simple_board(p2_board, MAX_ROWS, MAX_COLUMNS, playerTurn % 2 + 1);
							}
							else {
								printf("You've already attempted a shot at this location. Please enter a different location.\n");
								system("pause");
								// go back through loop
							}
						}
					}
					
					else if (playerTurn == 2) {
						system("cls");
						printf("Player 2's turn: \n");
						hitShot = automaticTurn(p1_board, p2HitMiss_board, p2_stats_ptr, outfile, playerTurn);
						//print_hitMiss_board(p2HitMiss_board, MAX_ROWS, MAX_COLUMNS, playerTurn);
						if (hitShot) { 
							printf("HIT! Nice shot computer!\n"); 
							fprintf(outfile, "Player 2 hit\n");
						}
						else { 
							printf("Computer missed! Better luck next time\n");
							fprintf(outfile, "Player 2 miss\n");
						}
						calulateHitMissPercent(p2_stats_ptr);
						//print_board(p2_board, MAX_ROWS, MAX_COLUMNS, playerTurn, p2_stats);

						p2_stats.isWinner = gameOverCondition(p2HitMiss_board, p1_shipLocations, fleet);
						turnCounter++;
						printf("Press any key to continue to the next turn...");
						_getch();

					}

					for (int i = 0; i < NUM_SHIPS; ++i)
					{
						if (isSunk(p2_board, p2_shipLocations, fleet[i].symbol))
						{
							if (tempIntArray2[i] == 0) // if the ship at this element hasn't been sunk this will be zero
							{ // I used these integer arrays to hold information about wherthe a specific ship was sunk or not. I know which ship corrolates to which index so I set it up under that assumption

								fprintf(outfile, "Player 1 Sunk: ");
								fputs(fleet[i].name, outfile);
								fprintf(outfile, "\n");
								tempIntArray2[i]++; // Incrementing to tell program that this ship has been sunk
								system("pause");
							}
						}
					}

					for (int i = 0; i < NUM_SHIPS; ++i)
					{
						if (isSunk(p1_board, p1_shipLocations, fleet[i].symbol))
						{
							if (tempIntArray1[i] == 0)
							{
								fprintf(outfile, "Player 2 Sunk: ");
								fputs(fleet[i].name, outfile);
								fprintf(outfile, "\n");
								tempIntArray1[i]++;
								system("pause");
							}
						}
					}
					


					if ((p1_stats.isWinner == TRUE) || (p2_stats.isWinner == TRUE))
					{
						endGameScreen(p1_stats_ptr, p2_stats_ptr, outfile);
						winner = TRUE;
					} 

				}

				system("pause");
				break;
			case 3: // Exit Game
				// printf("Print if case 3\n");
				printf("Thanks for playing the game!\nI hope you have an excellent day!\n");
				menuChoice = 0;
				break;
			default:
				printf("Hit default case");
				break;
		}


	} while (menuChoice != 0);

	fclose(outfile);
return 0;
}