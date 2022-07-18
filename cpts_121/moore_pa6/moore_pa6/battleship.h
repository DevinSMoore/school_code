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
#ifndef BATTLESHIP_H
#define BATTLESHIP_H


#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // for fprintf() fscanf() printf() scanf()
#include <stdlib.h> // for rand() srand()
#include <time.h> // for time()
#include <string.h> // just for the library of string funactions
#include <math.h> // included incase I want math functions
#include <ctype.h> // for tolower() function
#include <conio.h> // for _getch() 

// Constants
#define MAX_ROWS 10
#define MAX_COLUMNS 10
#define NUM_SHIPS 5

// Defining our ships attributes
#define CARR_SYMB 'c'
#define CARR_SIZE 5

#define BTL_SYMB 'b'
#define BTL_SIZE 4

#define CRSR_SYMB 'r'
#define CRSR_SIZE 3

#define SUB_SYMB 's'
#define SUB_SIZE 3

#define DEST_SYMB 'd'
#define DEST_SIZE 2

#define NUM_SHIPS 5
#define NUM_DIRECTIONS 4 // this is just silly


typedef enum { // Dunno If I'll use but it could be nice this is also to test it
	FALSE,
	TRUE
} Bool;

typedef enum { // Just a readable way to show orientation
	HORIZONTAL,
	VERTICLE
} Orientation;

// Just tells us the location (of the tip and tail) of a ship
//int frontRow, frontColumn, backRow, backColumn
typedef struct {
	int frontRow;
	int frontColumn;

	int backRow;
	int backColumn;
} Location;

// char symbol, int size, char name[50]
typedef struct {
	char symbol;
	int size;
	char name[50];
} Ship;

// A struct that contains a players game stats
// int guesses, hits, misses, double hitMissPercent, Bool isWinner
typedef struct {
	int guesses;
	int hits;
	int misses;
	double hitMissPercent;
	Bool isWinner;
} Stats;

// char symbol, Bool isOccupied, Bool hitAttmpt
typedef struct {
	char symbol; // the symbol that represents the cell on the game board
	Bool isOccupied;
	Bool hitAttempt; // True if a shot has been attempted at this cell
} Cell;

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
void printMenu(void);

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
void printBool(Bool boolVal);

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
void init_board(Cell board[][MAX_COLUMNS], int rows, int cols);

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
void print_board(Cell board[MAX_ROWS][MAX_COLUMNS], int rows, int cols, int player, Stats playerStats);

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
void print_simple_board(Cell board[MAX_ROWS][MAX_COLUMNS], int rows, int cols);

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
void print_hitMiss_board(Cell board[MAX_ROWS][MAX_COLUMNS], int rows, int cols, int player);

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
void print_board_Bool(Cell board[MAX_ROWS][MAX_COLUMNS], int rows, int cols, int player);

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
void flushDataStream(void);

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
int integerMenuInput(void);

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
char charInput(void);

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
void printRules(void);

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
int integerInput(void);

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
Bool checkPlacementChoice(Cell board[][MAX_COLUMNS], int rowChoice, int columnChoice, int sizeOfShip, Bool directionArray[], Location validCoord[]);

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
void placeShip(Cell board[][MAX_COLUMNS], Ship ship, Location shipsLocation, Bool toPlace);

/*
* Function: manualPlacement()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: will go through with the user and manually place each piece
* Input Parameters:
*	2d array of type Cell which represents the players board
*	ptr to array of Ships that represents all of the ships in the fleet
*	ptr to array of locations for each user selected location
* Returns:
* Precondition:
* Postcondition:
*/
void manualPlacement(Cell board[][MAX_COLUMNS], Ship* fleet, Location* playerShipLocations);

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
void automaticPlacement(Cell board[][MAX_COLUMNS], const Ship* fleet, Location* playerShipLocations);

/*
* Function: printLocationStruct()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description:	Prints all elements of the sturct passed
* Input Parameters: Location type for a ship
* Returns: NONE
* Precondition:
* Postcondition: Location printed to console
*/
void printLocationStruct(Location location);

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
Bool playerShot(Cell targetBoard[][MAX_COLUMNS], Cell playerHitMissBoard[][MAX_COLUMNS], const int rowGuess, const int ColumnGuess, Stats* playerStats);

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
Bool automaticTurn(Cell targetBoard[][MAX_COLUMNS], Cell playerHitMissBoard[][MAX_COLUMNS], Stats* playerStats, FILE* outfile, int playerTurn);

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
Bool isSunk(const Cell board[][MAX_COLUMNS], const Location shipLocations[], const char shipSymbol);

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
Bool gameOverCondition(const Cell board[][MAX_COLUMNS], const Location* shipLocations, const Ship* fleet);

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
void printStatStructs(const Stats* player1_stats, const Stats* player2_stats);

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
void calulateHitMissPercent(Stats* playerStats);

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
void endGameScreen(const Stats* p1Stats, const Stats* p2Stats, FILE* outfile);

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
void writeStats(FILE* outfile, const Stats* p1Stats, const Stats* p2Stats);

/*
* Function:
* Date Created:  2020/11/25
* Last Modified: 2020/11/28
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/
/*
* Function:
* Date Created:  2020/11/25
* Last Modified: 2020/11/27
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/



#endif BATTLESHIP_H
