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

/*
* Function: printMenu()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: This will simply print the game menu to the screen
* Input Parameters: NONE
* Returns: NONE
* Precondition: Program has started sucessfully
* Postcondition: Menu printed to console
*/
void printMenu(void)
{
	printf("1. Print Rules\n");
	printf("2. Play Game\n");
	printf("3. Exit Game\n");
}

/*
* Function: printBool()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: This will print the bool value of FALSE or TRUE to screen
* Input Parameters: NONE
* Returns: NONE
* Precondition:
* Postcondition: value printed to console
*/
void printBool(Bool boolVal)
{
	if (boolVal) 
		{ printf("TRUE"); }
	else 
		{ printf("FALSE"); }

}

/*
* Function: init_board()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: Fills each element of the board array with a '~' character
* Input Parameters:
*	2d array of chars that is the board
*	int number of rows
*	int number of columns
* Returns:
* Precondition: board is declared
* Postcondition: every element of the array is a '~' char
*/
void init_board(Cell board[][MAX_COLUMNS], int rows, int cols)
{
	for (int row_i = 0; row_i < MAX_ROWS; ++row_i)
	{
		for (int col_i = 0; col_i < MAX_COLUMNS; ++col_i)
		{
			(board[row_i][col_i]).isOccupied = FALSE;
			(board[row_i][col_i]).symbol = '~';
		}
	}
}

/*
* Function: print_board
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: prints board to console with the stats on the bottom
* Input Parameters:
*	2d array of chars that is the board
*	int number of rows
*	int number of columns
* Returns:
* Precondition:
* Postcondition: board printed to console
*/
void print_board(Cell board[MAX_ROWS][MAX_COLUMNS], int rows, int cols, int player, Stats playerStats)
{
	printf("+-----------------------------------------------+\n");
	//printf("|----------------------------------------------|\n");
	printf("|                Player %d's fleet               |\n", player);
	printf("|      0   1   2   3   4   5   6   7   8   9    |\n");
	for (int row_i = 0; row_i < MAX_ROWS; ++row_i)
	{
		printf("|  %d ", row_i);
		for (int col_i = 0; col_i < MAX_COLUMNS; ++col_i)
		{
			printf("| %c ", (board[row_i][col_i]).symbol);
		}
		printf("|  |\n");
	}
	printf("|   Hits: %d Misses: %d Hit-to-Miss percent: %.0lf\t|\n", playerStats.hits, playerStats.misses, playerStats.hitMissPercent);
	//printf("|----------------------------------------------|\n");
	printf("+-----------------------------------------------+\n");
}

/*
* Function: print_simple_board
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: prints board to console
* Input Parameters:
*	2d array of chars that is the board
*	int number of rows
*	int number of columns
* Returns:
* Precondition:
* Postcondition: board printed to console
*/
void print_simple_board(Cell board[MAX_ROWS][MAX_COLUMNS], int rows, int cols)
{
	printf("+-----------------------------------------------+\n");
	//printf("|----------------------------------------------|\n");
	printf("|                                               |\n");
	printf("|      0   1   2   3   4   5   6   7   8   9    |\n");
	for (int row_i = 0; row_i < MAX_ROWS; ++row_i)
	{
		printf("|  %d ", row_i);
		for (int col_i = 0; col_i < MAX_COLUMNS; ++col_i)
		{
			printf("| %c ", (board[row_i][col_i]).symbol);
		}
		printf("|  |\n");
	}
	printf("|                                               |\n");
	//printf("|----------------------------------------------|\n");
	printf("+-----------------------------------------------+\n");
}

/*
* Function: print_hitMiss_board
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: prints board to console
* Input Parameters:
*	2d array of chars that is the board
*	int number of rows
*	int number of columns
*	int currentPlayer
* Returns:
* Precondition:
* Postcondition: board printed to console
*/
void print_hitMiss_board(Cell board[MAX_ROWS][MAX_COLUMNS], int rows, int cols, int player)
{
	printf("+-----------------------------------------------+\n");
	//printf("|----------------------------------------------|\n");
	printf("|            Player %d's Hit/Miss board          |\n", player);
	printf("|      0   1   2   3   4   5   6   7   8   9    |\n");
	for (int row_i = 0; row_i < MAX_ROWS; ++row_i)
	{
		printf("|  %d ", row_i);
		for (int col_i = 0; col_i < MAX_COLUMNS; ++col_i)
		{
			printf("| %c ", (board[row_i][col_i]).symbol);
		}
		printf("|  |\n");
	}
	printf("|                                               |\n");
	//printf("|----------------------------------------------|\n");
	printf("+-----------------------------------------------+\n");
}

/*
* Function: print_board_Bool
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: prints a version of the board to console that shows the values of isOccupied for each cell of the board.
* Input Parameters:
*	2d array of Cells that is the board
*	int number of rows
*	int number of columns
*	integer representing the players number
* Returns:
* Precondition:
* Postcondition: board printed to console
*/
void print_board_Bool(Cell board[MAX_ROWS][MAX_COLUMNS], int rows, int cols, int player)
{
	printf("+-----------------------------------------------+\n");
	//printf("|----------------------------------------------|\n");
	printf("|             Player %d's Bool board             |\n", player);
	printf("|     0   1   2   3   4   5   6   7   8   9     |\n");
	for (int row_i = 0; row_i < MAX_ROWS; ++row_i)
	{
		printf("| %d ", row_i);
		for (int col_i = 0; col_i < MAX_COLUMNS; ++col_i)
		{
			printf("| %d ", (board[row_i][col_i]).isOccupied);
		}
		printf("|   |\n");
	}
	printf("|                                               |\n");
	//printf("|----------------------------------------------|\n");
	printf("+-----------------------------------------------+\n");
}

/*
* Function: flushDataStream()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: will clear the input stream
* Input Parameters: NONE
* Returns: NONE
* Precondition: User has entered a value that needs to be cleared from the stream
* Postcondition: Stream is empty
*/
void flushDataStream(void)
{
	char tempChar = '\0';
	do { scanf("%c", &tempChar); } while (tempChar != '\n');
}

/*
* Function: integerMenuInput()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: Will get the users input as integer, check if it is valid then return it. If it isn't valid it will prompt user to enter a valid input
*				Valid inputs: { 1, 2, 3 }
* Input Parameters: NONE
* Returns: User input as integer
* Precondition: User has been prompted for input
* Postcondition: Valid input is returned
*/
int integerMenuInput(void)
{
	int status = 0, menu_choice = 0;
	do // User input validation loop
	{
		status = scanf("%d", &menu_choice);
		if (status < 1)
		{
			flushDataStream(); // Empties input stream
		}
		if (menu_choice < 1 || menu_choice > 3) { printf("Please enter a valid menu choice.\n"); printMenu(); } // If the input is invalid, this will print and loop will run through again.
	} while (menu_choice < 1 || menu_choice > 3);
	return menu_choice;
}

/*
* Function: charInput()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: Gets user character input and check if it's a valid input.
				Valid inputs: chars ('y' or 'Y')
* Input Parameters: NONE
* Returns: User input as char
* Precondition: User has been prompted for input
* Postcondition: Valid user input is returned as a char
*/
char charInput(void)
{
	int check = 0;
	char userOption = '\0';
	do
	{
		printf("Please enter 'Y' for yes, or 'N' for no:\n");
		check = scanf(" %c", &userOption);
		userOption = tolower(userOption);
	} while (userOption != 'y' && userOption != 'n' && userOption != 0); // will continue loop until input is either a 'y' or an 'n'

	return userOption;
}

/*
* Function: printRules()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: Will print rules to the console
* Input Parameters: NONE
* Returns: NONE
* Precondition: Option to print rules has been selected by user
* Postcondition: Rules have printed to console
*/
void printRules(void)
{
	system("cls");
	printf("Rules:\nThe object of the game is to sink the other players fleet of ships.\n");
	printf("Both players will place ships on their 10x10 play board either manually or automagically.\n");
	printf("Each ship can be placed vertically, or horizontally only and they cannot overlap with eachother or overhang the edge.\n");
	printf("You will be prompted to place the ships in order (carrier->battleship->cruiser->sub->destroyer) if you select manual placement.");
	printf("Play will start with a random player.\n");
	printf("On your turn you must guess a cell on the board to shoot.\n");
	printf("If you miss your turn is over, but if you hit and you've hit every location on that particular ship, it will sink.\n");
	printf("The winner is the player that first sinks all of their opponents ships.\n\n");
	printf("Carrier:	symbol: %c	Size: %d\n", CARR_SYMB, CARR_SIZE);
	printf("Battleship:	symbol: %c	Size: %d\n", BTL_SYMB, BTL_SIZE);
	printf("Cruiser:	symbol:	%c	Size: %d\n", CRSR_SYMB, CRSR_SIZE);
	printf("Submarine:	symbol: %c	Size: %d\n", SUB_SYMB, SUB_SIZE);
	printf("Destroyer:	symbol: %c	Size: %d\n", DEST_SYMB, DEST_SIZE);
	printf("Good luck!\n");
	system("pause");
}

/*
* Function: integerInput()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: Will get the users input as integer, check if it is valid then return it. If it isn't valid it will prompt user to enter a valid input
*				Valid inputs: 0 - 9
* Input Parameters: NONE
* Returns: User input as integer
* Precondition: User has been prompted for input
* Postcondition: Valid input is returned
*/
int integerInput(void)
{
	int status = 0, menu_choice = 0;
	do // User input validation loop
	{
		status = scanf("%d", &menu_choice);
		if (status < 1)
		{
			flushDataStream(); // Empties input stream
		}
		if (menu_choice < 0 || menu_choice > 9) { printf("Invalid Coordinate!\nPlease enter a value between 0 and 9:"); } // If the input is invalid, this will print and loop will run through again.
	} while (menu_choice < 0 || menu_choice > 9);
	return menu_choice;
}

/*
* Function: checkPlacementChoice()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: Checks for valid placement positions for a piece

* Input Parameters:
*	2d array of type Cell which represents the players board
*	int row choice for front of piece
*	int column choice for front of piece
*	int piece size
*	Bool array representing the Array of cardinal directions
*	Bool array that is the players array of ship locations
* Returns: Bool value TRUE or FALSE if it is a valid placement location and it has valid placement options.
* Precondition: rowChoice, and columnChoice must be less than 10 and greater than 0
* Postcondition: Valid routes (up,down,left,right) have been set and their coordinates set in validCoord array
*/
Bool checkPlacementChoice(Cell board[][MAX_COLUMNS], int rowChoice, int columnChoice, int sizeOfShip, Bool directionArray[], Location validCoord[])
{
	sizeOfShip = sizeOfShip - 1;
	int index = 1, // variable for loops starts at 1 so when we're looping to check for 
		upCoord = (rowChoice - sizeOfShip), downCoord = (rowChoice + sizeOfShip), leftCoord = (columnChoice - sizeOfShip), rightCoord = (columnChoice + sizeOfShip); // this gives the Coordinate of the back of the ship if we were to place it vertically up or down, or horizatally left or right
	Bool checkLeft = TRUE, checkRight = TRUE, checkUp = TRUE, checkDown = TRUE;

	
	for (int i = 0; i < 4; i++) // can only loop for the head coordinates because the're the same for every possible placement location
	{
		validCoord[i].frontRow = rowChoice;
		validCoord[i].frontColumn = columnChoice;
	}
	
	validCoord[0].backRow = upCoord; // upper placement
	validCoord[0].backColumn = columnChoice;
	validCoord[1].backRow = downCoord; // lower placement
	validCoord[1].backColumn = columnChoice;
	validCoord[2].backRow = rowChoice;
	validCoord[2].backColumn = leftCoord; // leftmost placement
	validCoord[3].backRow = rowChoice;
	validCoord[3].backColumn = rightCoord; // rightmost placement
	
	if ((board[rowChoice][columnChoice]).isOccupied == TRUE) // if the location for the head of the ship is occupied return false
	{
		// printf("THIS WILL PRINT IF THE THING THAT WE DONT WANT TO BE TRUE IS TRUE");
		directionArray[0] = FALSE; // UP
		directionArray[1] = FALSE; // DOWN
		directionArray[2] = FALSE; // LEFT
		directionArray[3] = FALSE; // RIGHT; I'm setting all of these to false so that there can be no mistake later on that this might be a valid location to place the ship
		return FALSE;
	}
	if (upCoord >= 0) // if we check (sizeOfShip - 1) above rowChoice and it is less than 0 then we have moved out of the bounds of the array
	{
		// printf("checkUp: \n");
		for (; index <= sizeOfShip; index++)
		{
			//printBool((board[(rowChoice - index)][columnChoice]).isOccupied);
			// printf(" <- outside if check | index: %d\n", index);
			if ((board[(rowChoice - index)][columnChoice]).isOccupied == TRUE)
			{
				// printBool(checkUp);
				// printf(" <- inside if check before | index: %d\n", index);
				checkUp = FALSE;
				// printBool(checkUp);
				// printf(" <- inside if check after | index: %d\n", index);
			}

		}
	}
	if (downCoord < 10) // anything over 9 is out of bounds
	{
		//printf("\n checkDown: \n");

		for (index = 1; index <= sizeOfShip; index++)
		{
			//printBool((board[(rowChoice + index)][columnChoice]).isOccupied);
			//printf(" <- outside if check | index: %d\n", index);
			if ((board[(rowChoice + index)][columnChoice]).isOccupied == TRUE)
			{
				//printBool(checkDown);
				//printf(" <- inside if check before | index: %d\n", index);
				checkDown = FALSE;
				//printBool(checkDown);
				//printf(" <- inside if check after | index: %d\n", index);
			}

		}
	}
	if (rightCoord < 10) // again less than zero is outside of array bounds
	{
		//printf("\n checkRight: \n");
		for (index = 1; index <= sizeOfShip; index++)
		{
			//printBool((board[rowChoice][(columnChoice + index)]).isOccupied);
			//printf(" <- outside if check | index: %d\n", index);
			if ((board[rowChoice][(columnChoice + index)]).isOccupied == TRUE)
			{
				//printBool(checkRight);
				//printf(" <- inside if check before | index: %d\n", index);
				checkRight = FALSE;
				//printBool(checkRight);
				//printf(" <- inside if check after | index: %d\n", index);
			}

		}
	}
	if (leftCoord >= 0) // anything over 9 is out of bounds
	{
		//printf("\n checkLeft: \n");

		for (index = 1; index <= sizeOfShip; index++)
		{
			//printBool((board[rowChoice][columnChoice - index]).isOccupied);
			//printf(" <- outside if check | index: %d\n", index);
			if ((board[rowChoice][columnChoice - index]).isOccupied == TRUE)
			{
				//printBool(checkLeft);
				//printf(" <- inside if check before | index: %d\n", index);
				checkLeft = FALSE;
				//printBool(checkLeft);
				//printf(" <- inside if check after | index: %d\n", index);
			}

		}
	}

	
	
	if ((columnChoice - sizeOfShip) < 0) { checkLeft = FALSE; }
	if ((columnChoice + sizeOfShip) >= 10) { checkRight = FALSE; }
	if ((rowChoice + sizeOfShip) >= 10) { checkDown = FALSE; }
	if ((rowChoice - sizeOfShip) < 0) { checkUp = FALSE; } // These just check to see if any of directions will put the ship out of bounds, if so it sets that direction to FALSE
	
	directionArray[0] = checkUp, directionArray[1] = checkDown, directionArray[2] = checkLeft, directionArray[3] = checkRight;
	if (checkUp == TRUE || checkDown == TRUE || checkLeft == TRUE || checkRight == TRUE) // if any of the legs return true then function returns true
	{ 
		
		
		//printf("will print if any checks are true\ncheckUp: %d\ncheckDown: %d\ncheckLeft: %d\ncheckRight: %d\n", checkUp, checkDown, checkLeft, checkRight);
		return TRUE;
	}
	else // if the placement location is valid, but no valid placement in the other directions is possible
	{
		return FALSE;
	} 
}

/*
* Function: placeShip()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: will place the piece onto the board and set the varios necessary flags indicating this
* Input Parameters:
*	2d array of type Cell which represents the players board
*	char of ships symbol
*	ships location as a Location type
*	Bool value representing whether we are filling a space (TRUE), or emptying it (FALSE)
* Returns: NONE
* Precondition:	User has eneterd a valid placement
* Postcondition: piece has been placed on board, and cells have their occupied flags set true
*/
void placeShip(Cell board[][MAX_COLUMNS], Ship ship, Location shipsLocation, Bool toPlace)
{
	Bool placeOrUnplace = FALSE;
	char tempSymbol = '~';

	if (toPlace == TRUE) // This check will let us empty a ships location on the board if we wish.
	{
		placeOrUnplace = TRUE;
		tempSymbol = ship.symbol;
	}// else keep it as FALSE and as tilde
	int index = 0;
	if (shipsLocation.frontRow == shipsLocation.backRow) // If the front row and back row coordinates are the same then it is horizon tal and we need to then check if it's to the right or left
	{
		if (shipsLocation.backColumn > shipsLocation.frontColumn) // if the back of the ship is ahead of the front it is going to the right, otherwise it's going left
		{
			for (index = shipsLocation.frontColumn; index <= shipsLocation.backColumn; ++index) // start at the front and will run for each segment including the final one
			{
				board[shipsLocation.frontRow][index].isOccupied = placeOrUnplace;
				board[shipsLocation.frontRow][index].symbol = tempSymbol;
			}
		}
		else // ship is going to the left from the front placement
		{
			for (index = shipsLocation.frontColumn; index >= shipsLocation.backColumn; --index) // starts at the front location and moves to the left
			{
				board[shipsLocation.frontRow][index].isOccupied = placeOrUnplace;
				board[shipsLocation.frontRow][index].symbol = tempSymbol;
			}
		}
	}
	else // if it's not horizontal then it's verticle which means we need to check the rows, and traverse them
	{
		if (shipsLocation.backRow > shipsLocation.frontRow) // if back is greater than front then it is going down from the front of the ship (back is below front)
		{
			for (index = shipsLocation.frontRow; index <= shipsLocation.backRow; ++index) // Will run for each segment including the final one
			{
				board[index][shipsLocation.frontColumn].isOccupied = placeOrUnplace;
				board[index][shipsLocation.frontColumn].symbol = tempSymbol;
			}
		}
		else // going up from front of ship (back is above front)
		{
			for (index = shipsLocation.frontRow; index >= shipsLocation.backRow; --index) // starts at the front and moves up
			{
				board[index][shipsLocation.frontColumn].isOccupied = placeOrUnplace;
				board[index][shipsLocation.frontColumn].symbol = tempSymbol;
			}
		}
	}
}

/*
* Function: manualPlacement()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: will go through with the user and manually place each piece
* Input Parameters:
*	2d array of type Cell which represents the players board
*	Array of ships
*	Players' ships Location array
* Returns:
* Precondition:
* Postcondition:
*/
void manualPlacement(Cell board[][MAX_COLUMNS], Ship* fleet, Location* playerShipLocations)
{
	char tempChar = '\0';
	int userEntry_row = 0, userEntry_column = 0, index = 0, playerTurn = 1; // for manual placement it's always going to be player 1
	Bool validInput = FALSE, validDirections[NUM_DIRECTIONS] = { FALSE }; // valid directions; 0 = up; 1 = down; 2 = left; 3 = right
	Location validPlacementCoordinates[NUM_DIRECTIONS] = { 0, 0, 0, 0 };


	for (; index < NUM_SHIPS; index++) 
	{

		//if()
		do
		{
			print_simple_board(board, MAX_ROWS, MAX_COLUMNS);
			printf("Please enter the row and column you would like the -front- spot of the %s to be placed on.\n", (fleet + index)->name);
			printf("Row: ");
			userEntry_row = integerInput();
			printf("Column: ");
			userEntry_column = integerInput();
			validInput = checkPlacementChoice(board, userEntry_row, userEntry_column, (fleet + index)->size, validDirections, validPlacementCoordinates); // if this returns true then there is at least one valid placement
			printf("validInput: ");
			printBool(validInput);
			printf("\n");
		} while (!validInput);
		validInput = FALSE; // reseting validInput
		do {
			for (int i = 0; i < NUM_DIRECTIONS; i++) // asking user which direction they want to place their piece
			{
				system("cls");
				if (!(board[userEntry_row][userEntry_column].isOccupied))
				{
					printf("Please place the piece before moving onto the next step.\n");
				}
				if (validDirections[i] == TRUE)
				{



					printf("Would you like to place it like this?\n");
					placeShip(board, *(fleet + index), validPlacementCoordinates[i], TRUE);
					print_simple_board(board, MAX_ROWS, MAX_COLUMNS);
					tempChar = charInput();
					
					if (tempChar == 'n')
					{
						placeShip(board, *(fleet + index), validPlacementCoordinates[i], FALSE); // resetting those spots to default values
					}
					else {
						system("cls");
						printf("%s has been placed.\n", (fleet + index)->name);
						*(playerShipLocations + i) = validPlacementCoordinates[i]; // if the user selects yes this will set the Location in the players array of ship locations to the Location selected.
						//printLocationStruct(playerShipLocations[i]);
						break;
					}
				
				}
			}
			
		} while (!(board[userEntry_row][userEntry_column].isOccupied));
	}
}

/*
* Function: automaticPlacement()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: will place each piece onto the board automatically
* Input Parameters:
*	2d array of type Cell which represents the players board
*	Array of ships
*	Players' ships Location array
* Returns:
* Precondition:
* Postcondition:
*/
void automaticPlacement(Cell board[][MAX_COLUMNS], const Ship* fleet, Location* playerShipLocations)
{
	int randRow = 0, randColumn = 0, randDirection = 0;
	Bool validPlacement = FALSE, validDirections[NUM_DIRECTIONS] = { FALSE }; // valid directions; 0 = up; 1 = down; 2 = left; 3 = right
	Location validPlacementCoordinates[NUM_DIRECTIONS] = { 0, 0, 0, 0 };

	for(int i = 0; i < NUM_SHIPS; ++i)
	{
		do
		{
			randRow = (rand() % 10);
			randColumn = (rand() % 10);
			validPlacement = checkPlacementChoice(board, randRow, randColumn, fleet[i].size, validDirections, validPlacementCoordinates);
		} while (!validPlacement);
		validPlacement = FALSE; // reseting the variable
		do
		{
			randDirection = (rand() % 4); // direction between 0 - 3
			if (validDirections[randDirection] == TRUE)
			{
				placeShip(board, *(fleet + i), validPlacementCoordinates[randDirection], TRUE);
				*(playerShipLocations + i) = validPlacementCoordinates[randDirection];
				validPlacement = TRUE;
			}
		} while (!validPlacement);
	}

}

void printLocationStruct(Location location)
{
	printf("Front Row Index: %d\n", location.frontRow);
	printf("Front Column Index: %d\n", location.frontColumn);
	printf("Back Row Index: %d\n", location.backRow);
	printf("Back Column Index: %d\n", location.backColumn);
}

/*
* Function: playerShot()
* Date Created:  2020/11/25
* Last Modified: 2020/11/27
* Description: Will check if the players guess is a hit or miss and increment the players stats to reflect the result
* Input Parameters:
*	2d array of Cells that is the TARGETS board
*	2d array of Cells that is the players -hitMiss- board
*	int rowGuess
*	int columnGuess
*	pointer to players stats
* Returns: Bool value TRUE if hit, FALSE if miss
* Precondition: All ships have been placed on the board
* Postcondition: TRUE or FALSE returned to user, and players Stat struct has been updated to reflect the shot taken
*/
Bool playerShot(Cell targetBoard[][MAX_COLUMNS], Cell playerHitMissBoard[][MAX_COLUMNS], const int rowGuess, const int ColumnGuess, Stats *playerStats)
{
	targetBoard[rowGuess][ColumnGuess].hitAttempt = TRUE; // set hit attempt at cell to true
	(playerStats->guesses)++;
	if (targetBoard[rowGuess][ColumnGuess].isOccupied == TRUE)
	{
		playerHitMissBoard[rowGuess][ColumnGuess].symbol = 'H';
		targetBoard[rowGuess][ColumnGuess].symbol = 'H';
		(playerStats->hits)++;
		//printf("hit!\n");
		//system("pause");
		return TRUE;
	} else
	{
		playerHitMissBoard[rowGuess][ColumnGuess].symbol = 'M';
		targetBoard[rowGuess][ColumnGuess].symbol = 'M';
		(playerStats->misses)++;
		//printf("miss!\n");
		//system("pause");
		return FALSE;
	}
}

/*
* Function: AutomaticTurn()
* Date Created:  2020/11/25
* Last Modified: 2020/11/28
* Description: will play through a turn automatically
* Input Parameters:
*	2d array of type Cell that represents the board of the TARGET of the player whos turn is being automated (this is a dumb/brute force version of automated play)
*	2d array of type Cell that is the Hit/Miss board of the player
*	pointer to players stats
*	FILE for gameplay to be printed to
*	int that represents the current players turn
* Returns: Bool value of true or false if the shot hit or not
* Precondition:
* Postcondition: turn has been taken, and stats have been updated, and TRUE of FALSE returned, stat has been printed to file.
*/
Bool automaticTurn(Cell targetBoard[][MAX_COLUMNS], Cell playerHitMissBoard[][MAX_COLUMNS], Stats* playerStats, FILE *outfile, int playerTurn)
{
	int randRowGuess = 0, randColumnGuess = 0;
	Bool isValidMove = FALSE, hit = FALSE;
	do
	{
		randRowGuess = (rand() % 10); // gives a random number between 0 and 9 for the row
		randColumnGuess = (rand() % 10); // random column guess
		if (targetBoard[randRowGuess][randColumnGuess].hitAttempt != TRUE) // if we have not tried to hit that spot before
		{
			hit = playerShot(targetBoard, playerHitMissBoard, randRowGuess, randColumnGuess, playerStats);
			printf("Player %d took a shot at row: %d and Column: %d\n", playerTurn, randRowGuess, randColumnGuess);
			fprintf(outfile, "Player %d took a shot at row: %d and Column: %d: ", playerTurn, randRowGuess, randColumnGuess);

			isValidMove = TRUE;
		}
	} while (!isValidMove);
	return hit;

}

/*
* Function: isSunk()
* Date Created:  2020/11/25
* Last Modified: 2020/11/27
* Description: Figures out if a ship is sunk
* Input Parameters:
*	The targets board as a 2d array of cells
*	array of targets ship Locations
*	char that represents the ships symbol that is going to be checked
* Returns: True if it is sunk False if it is not
* Precondition:
* Postcondition: TRUE if ship is sunk or FALSE otherwise
*/
Bool isSunk(const Cell board[][MAX_COLUMNS], const Location shipLocations[], const char shipSymbol)
{
	int shipSelect = 0, index = 0;
	switch (shipSymbol)
	{
		case CARR_SYMB:
			shipSelect = 0;
			break;
		case BTL_SYMB:
			shipSelect = 1;
			break;
		case CRSR_SYMB:
			shipSelect = 2;
			break;
		case SUB_SYMB:
			shipSelect = 3;
			break;
		case DEST_SYMB:
			shipSelect = 4;
			break;
		default:

			break;
	}
	if ((shipLocations[shipSelect].frontRow == shipLocations[shipSelect].backRow) && (shipLocations[shipSelect].frontColumn == shipLocations[shipSelect].backColumn)) // if it's diagonal somehow or sitting ontop of itself it will return false
	{
		return FALSE;
	}
	
	if (shipLocations[shipSelect].frontRow == shipLocations[shipSelect].backRow) // If the front row and back row coordinates are the same then it is horizon tal and we need to then check if it's to the right or left
	{
		if (shipLocations[shipSelect].backColumn > shipLocations[shipSelect].frontColumn) // if the back of the ship is ahead of the front it is going to the right, otherwise it's going left
		{
			for (index = shipLocations[shipSelect].frontColumn; index <= shipLocations[shipSelect].backColumn; ++index) // start at the front and will run for each segment including the final one. moving right
			{
				if ((board[shipLocations[shipSelect].frontRow][index].symbol != 'H'))
				{
					return FALSE;
				}
			}
		}
		else // ship is going to the left from the front placement
		{
			for (index = shipLocations[shipSelect].frontColumn; index >= shipLocations[shipSelect].backColumn; --index) // starts at the front location and moves to the left
			{
				if ((board[shipLocations[shipSelect].frontRow][index].symbol != 'H'))
				{
					return FALSE;
				}
			}
		}
	}
	else // if it's not horizontal then it's verticle which means we need to check the rows, and traverse them
	{
		if (shipLocations[shipSelect].backRow > shipLocations[shipSelect].frontRow) // if back is greater than front then it is going down from the front of the ship (back is below front)
		{
			for (index = shipLocations[shipSelect].frontRow; index <= shipLocations[shipSelect].backRow; ++index) // Will run for each segment including the final one moving down
			{
				if ((board[index][shipLocations[shipSelect].frontColumn].symbol != 'H'))
				{
					return FALSE;
				}
			}
		}
		else // going up from front of ship (back is above front)
		{
			for (index = shipLocations[shipSelect].frontRow; index >= shipLocations[shipSelect].backRow; --index) // starts at the front and moves up
			{
				if ((board[index][shipLocations[shipSelect].frontColumn].symbol != 'H'))
				{
					return FALSE;
				}
			}
		}
	}
	return TRUE;
}

/*
* Function: gameOverCondition()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: will check to see if a players fleet has been sunk which represents the end of the game.
* Input Parameters:
*	current player's Hit/Miss board as a 2d array of Cells
*   array of all of the ships Loactions for the OPPONENT's fleet
*	array of all of the Ships (fleet)
* Returns: True if one of the boards has all of its ships sunk.
* Precondition:
* Postcondition: Victor has been determined.
*/
Bool gameOverCondition(const Cell board[][MAX_COLUMNS], const Location *shipLocations, const Ship *fleet)
{
	for (int i = 0; i < NUM_SHIPS; ++i)
	{
		if (!isSunk(board, shipLocations, (fleet + i)->symbol))
			return FALSE;
	}
	return TRUE;
}

/*
* Function: printStatStructs()
* Date Created:  2020/11/25
* Last Modified: 2020/11/27
* Description: This will print all of the values of the passed Stat struct to the console
* Input Parameters:
*	Stats variable for player 1
*	Stats variable for player 2
* Returns:
* Precondition:
* Postcondition: Contents of structs are printed to console
*/
void printStatStructs(const Stats* player1_stats, const Stats* player2_stats)
{
	printf("+---------------------------------------------------------------+\n");
	printf("| Players:\t\t\t|    Player 1\t|    Player 2\t|\n");
	printf("| Guesses\t\t\t|\t%d\t|\t%d\t|\n", player1_stats->guesses, player2_stats->guesses);
	printf("| Hits\t\t\t\t|\t%d\t|\t%d\t|\n", player1_stats->hits, player2_stats->hits);
	printf("| Misses\t\t\t|\t%d\t|\t%d\t|\n", player1_stats->misses, player2_stats->misses);
	printf("| Hit-Miss Percentage\t\t|\t%.0lf\t|\t%.0lf\t|\n", player1_stats->hitMissPercent, player2_stats->hitMissPercent);
	printf("| Is this player the winner\t|     ");
	if (player1_stats->isWinner) { printf("TRUE"); }
	else { printf("FALSE"); }
	printf("\t|     ");
	if (player2_stats->isWinner) { printf("TRUE"); }
	else { printf("FALSE"); }
	printf("\t|\n");
	printf("+---------------------------------------------------------------+\n");
}

/*
* Function: calulateHitMissPercent()
* Date Created:  2020/11/25
* Last Modified: 2020/11/27
* Description: calculates the hit miss percent
* Input Parameters:
*	Stat struct of some players stats
* Returns: NONE
* Precondition:
* Postcondition: Hit miss variable has been set
*/
void calulateHitMissPercent(Stats *playerStats)
{
	if (playerStats->misses == 0 && playerStats->hits > 0) // if we don't have any misses, but have any number of hits over 0, then our hit% is 100
	{
		playerStats->hitMissPercent = 100.00;
	}
	else if (playerStats->misses == 0) // Otherwise if misses is zero then we just return percent overall as zero.
	{
		playerStats->hitMissPercent = 0.0;
	}
	else
	{
		(playerStats->hitMissPercent) = ((double)(playerStats->hits) / (double)(playerStats->misses)) * 100;
	}

}


/*
* Function: endGameScreen()
* Date Created:  2020/11/25
* Last Modified: 2020/11/28
* Description:	Will show the winners and their stats for the game to the console
* Input Parameters:
*	Stats p1 stats
*	Stats p2 stats
*	FILE output file for game log
* Returns: NONE
* Precondition: One of the players has won the game
* Postcondition: Endgame screen printed to console, and to file.
*/
void endGameScreen(const Stats *p1Stats, const Stats *p2Stats, FILE *outfile)
{
	printStatStructs(p1Stats, p2Stats);
	if (p1Stats->isWinner == TRUE) // if player 1 wins
	{
		writeStats(outfile, p1Stats, p2Stats);
		printf("Congratulations Player 1!!");
		fprintf(outfile, "Congratulations Player 1!!");
	}
	else
	{
		writeStats(outfile, p1Stats, p2Stats);
		printf("Congratulations Player 2!!");
		fprintf(outfile, "Congratulations Player 2!!");
	}
}

/*
* Function: writeStats()
* Date Created:  2020/11/25
* Last Modified: 2020/11/28
* Description:	writes the statistices for each player to a file
* Input Parameters:
*	FILE variable to be written to
*	Stats for p1
*	Stats for p2
* Returns: NONE
* Precondition: File has been opened sucessfully
* Postcondition: Stats have been wirtten/appended to file.
*/
void writeStats(FILE* outfile, const Stats *p1Stats, const Stats *p2Stats)
{
	fprintf(outfile, "+-----------------------------------------------------------+\n");
	fprintf(outfile, "| Players:\t\t\t\t\t|    Player 1\t|    Player 2\t|\n");
	fprintf(outfile, "| Guesses\t\t\t\t\t|\t\t%d\t\t|\t\t%d\t\t|\n", p1Stats->guesses, p2Stats->guesses);
	fprintf(outfile, "| Hits\t\t\t\t\t\t|\t\t%d\t\t|\t\t%d\t\t|\n", p1Stats->hits, p2Stats->hits);
	fprintf(outfile, "| Misses\t\t\t\t\t|\t\t%d\t\t|\t\t%d\t\t|\n", p1Stats->misses, p2Stats->misses);
	fprintf(outfile, "| Hit-Miss Percentage\t\t|\t\t%.0lf\t\t|\t\t%.0lf\t\t|\n", p1Stats->hitMissPercent, p2Stats->hitMissPercent);
	fprintf(outfile, "| Is this player the winner\t|     ");
	if (p1Stats->isWinner) { fprintf(outfile, " TRUE"); }
	else { fprintf(outfile, " FALSE"); }
	fprintf(outfile, "\t\t|     ");
	if (p2Stats->isWinner) { fprintf(outfile, " TRUE"); }
	else { fprintf(outfile, " FALSE"); }
	fprintf(outfile, "\t\t|\n");
	fprintf(outfile, "+-----------------------------------------------------------+\n");
}





