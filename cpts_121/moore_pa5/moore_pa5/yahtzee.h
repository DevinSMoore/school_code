/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/10/22
Class:      CptS121 Section 9 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: Programming Assignment 5: Yahtzee

Description: This program will allow 2 people to play a classic game of Yahtzee.
*******************************************************************************************/


#ifndef YAHTZEE_H
#define YAHTZEE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // for scanf() and printf()
#include <stdlib.h> // for system functions and random functions
#include <time.h> // for time()
#include <math.h> // included incase I want math functions
#include <ctype.h> // for tolower() function
#include <conio.h> // for _getch()


#define BONUS_POINTS 35 // Amount of bonus points awarded if your upper half score card sum is >= 63

#define FULL_HOUSE_POINTS 25 // these are just the 4 score categories that don't depend on any other value therefore constant
#define SMALL_STRAIGHT_POINTS 30
#define LARGE_STRAIGHT_POINTS 40
#define	YAHTZEE_POINTS 50

#define	DICE_ARRAY_SIZE 5 // dice array size and scorecard array size don't change so I just made them constants
#define	SCORECARD_ARRAY_SIZE 13
#define UPPER_CATEGORY_SIZE 6 // size of the portion of the scorecard aray that makes up the Upper Categories as defined by the rules
#define LOWER_CATEGORY_SIZE 7 // size of lower portion; total is 13

/*
* Function: printMenu()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: This will simply print the game menu to the screen
* Input Parameters: NONE
* Returns: NONE
* Precondition: Program has started sucessfully
* Postcondition: Menu printed to console
*/
void printMenu(void);

/*
* Function: printSimpleCategoryList()
* Date Created: 2020/10/22
* Last Modified: 2020/10/26
* Description: prints a simply list of categories
* Input Parameters: NONE
* Returns: NONE
* Precondition: score portion of turn has begun
* Postcondition: categories printed to screen
*/
void printSimpleCategoryList(void);


/*
* Function: integerInput()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: Will get the users input as integer, check if it is valid then return it. If it isn't valid it will prompt user to enter a valid input 
*				Valid inputs: { 1, 2, 3 }
* Input Parameters: NONE
* Returns: User input as integer
* Precondition: User has been prompted for input
* Postcondition: Valid input is returned
*/
int integerInput(void);

/*
* Function: integerInputForScore()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: Will get the users input as integer, check if it is valid then return it. If it isn't valid it will prompt user to enter a valid input
*				Valid inputs: { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 }
* Input Parameters: NONE
* Returns: User input as integer
* Precondition: User has been prompted for input
* Postcondition: Valid input is returned
*/
int integerInputForScore(void);

/*
* Function: charInput()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: Gets user character input and check if it's a valid input.
				Valid inputs: chars ('y' or 'Y')
* Input Parameters: NONE
* Returns: User input as char
* Precondition: User has been prompted for input
* Postcondition: Valid user input is returned as a char
*/
char charInput(void);

/*
* Function: flushDataStream()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: will clear the input stream
* Input Parameters: NONE
* Returns: NONE
* Precondition: User has entered a value that needs to be cleared from the stream
* Postcondition: Stream is empty
*/
void flushDataStream(void);

/*
* Function: printRules()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: Will print rules to the console
* Input Parameters: NONE
* Returns: NONE
* Precondition: Option to print rules has been selected by user
* Postcondition: Rules have printed to console
*/
void printRules(void);

/*
* Function: fillArray()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: Will fill the passed array with the povided integer value
* Input Parameters:
*	integer that is the value that the array will be filled with.
*	integer array to be filled
*   integer size of array
* Returns: NONE
* Precondition: program has started
* Postcondition: Array has been filled completely with the provided integer.
*/
void fillArray(int fillValue, int integerArray[], int size);

/*
* Function: upperLowerSum()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description:
* Input Parameters: 
*	integer array of dice
*   integer size of dice array
*	int pointer of upperCategorySum
*	int pointer of lowerCategorySum
* Returns: NONE
* Precondition: Array has been initialized
* Postcondition: upper category sum, and lower category sum in main() have been assigned the calculated values.
*/
void upperLowerSum(int* upper_ptr, int* lower_ptr, int scoreCardArray[], int size);

/*
* Function: rollDie()
* Date Created: 2020/10/22
* Last Modified: 2020/10/26
* Description: Will simulate the roll of a dice using a seeded random value
* Input Parameters: NONE
* Returns: integer
* Precondition: Gameplay has begun
* Postcondition: Positive integer value between 1 and 6 returned
*/
int rollDie(void);

/*
* Function: rollAllDice()
* Date Created: 2020/10/22
* Last Modified: 2020/10/26
* Description: Will reroll all die for a player
* Input Parameters:
*	Integer array of dice
*	Integer size of input array
* Returns: NONE
* Precondition: Either the start of players turn, or player has selected re-roll all die.
* Postcondition: Players dice array has been filled with the rolled values.
*/
void rollAllDice(int playerDiceArray[], int size);

/*
* Function: rerollSelectDice()
* Date Created: 2020/10/22
* Last Modified: 2020/10/26
* Description: Will reroll the specific dice that the player has selected. 
* Input Parameters: 
*	Integer array of dice
*	Integer size of input array
* Returns: integer
* Precondition: Player has selected to reroll certain die
* Postcondition: Die that were selected for reroll have had their values replaced with rerolled integer values and number of dice rerolled returned
*/
int rerollSelectDice(int playerDiceArray[], int size);

/*
* Function: orderPlayerDie()
* Date Created: 2020/10/22
* Last Modified: 2020/10/26
* Description: will reorder the array of player die into ascending order.
* Input Parameters:
*	Integer array of dice
*	Integer size of input array
* Returns: NONE
* Precondition: Player dice have been rerolled in some way, or a new set of 5 has been rolled.
* Postcondition: Array of dice has been arranged into ascending order
*/
void orderPlayerDie(int playerDieArray[], int size);

/*
* Function: printPostRollMenu()
* Date Created: 2020/10/22
* Last Modified: 2020/10/26
* Description: prints menu with options to score current set of dice, or to re-roll whole set of dice or only a select few specified by user.
* Input Parameters: NONE
* Returns: NONE
* Precondition: Dice have been rolled and arranged.
* Postcondition: Menu options have been printed to screen.
*/
void printPostRollMenu(void);

/*
* Function: displayPlayerDice()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: will print player dice to the console
* Input Parameters:
*	Integer array of dice to be printed
*	Integer size of input array
* Returns: NONE
* Precondition: Player has rolled dice and filled the array
* Postcondition: Dice have been displayed to the console.
*/
void displayPlayerDice(int playerDiceArray[], int size);

/*
* Function: checkPlayerScores()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: This will fill an array with the scores for each category for the array of dice that has been provided
* Input Parameters:
*	integer array of players dice
*	integer array for the temporary score card array
*	integer size of the score card array
* Returns: NONE
* Precondition: Player has selected the score option or they have rolled three times this round.
* Postcondition: Temporary array is filled with the current player's scores
*/
void checkPlayerScores(int tempScoreArray[], int playerDiceArray[], int scoreCardArraySize);

/*
* Function: findNumberOfLikeElements()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: will find how many times the passed integer exists in the array
* Input Parameters:
*	integer number to check against
*	integer array of players dice
*	integer size of the score card array
* Returns: number of elements found
* Precondition: player has enetered scoring round
* Postcondition: Integer returned
*/
int findNumberOfLikeElements(int numberToCheck, int playerDiceArray[], int size);

/*
* Function: findSumOfLikeElements()
* Date Created: 2020/10/22
* Last Modified: 2020/10/27
* Description: find the sum of like elemnets in a set. i.e. if you pass a 1, it will go through and find the sum of all of the 1s in the array.
* Input Parameters:
*	integer array of player dice
*	integer size of array
*	integer which integer are we summing
* Returns: sum of integers
* Precondition: player has entered score portion of turn
* Postcondition: sum of integer returned
*/
int findSumOfLikeElements(int likeElementToSum, int playerDiceArray[], int size);

/*
* Function: setPlayerScore()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: This will take the players selection for their score category then set the cooresponding element in
*				the score card to the related value from the temporary score array.
* Input Parameters: 
*	integer array: temporary score card
*	integer array: players score card
*	integer size of score card array (will work for both player and temp score card)
* Returns: NONE
* Precondition: Player has rolled three times or has chosen to score current set of dice
* Postcondition: Correct value has been assigned to player score card array.
*/
void setPlayerScore(int playerCategorySelection,  int tempScoreArray[], int playerScoreCard[], int scoreCardArraySize);

/*
* Function: displayScorecard()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: Will show same information as basic but it will have an additional column that shows an explanation of each score category
* Input Parameters:
*	integer array: players score card
*	integer size of score card array
* Returns: NONE
* Precondition: Players score card has been initialized
* Postcondition: Score card of player is printed to console with more detailed descriptions of the categories
*/
void displayScorecard(int playerScoreCard[], int player2ScoreCard[], int scoreCardArraySize);

/*
* Function: checkIfBonus()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description:	Will check if a players Upper Section sum meets the conditions for the bonus points. 
*				If sum is >= 63 player will recieve 35 bonus points added to their total
* Input Parameters: 
*	integer sum of the upper section scores
* Returns: 1 if they do earn the bonus 0 if not
* Precondition: Normal gameplay has ended and we have moved to sequence that determines victor
* Postcondition: 1 or 0 returned as integers
*/
int checkIfBonus(int sumOfUpperSection);

/*
* Function: computeGrandTotal()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: Will find the grand total of the players score: 
*					Grand Total = (Upper Section Score) + (Lower Section Total) + (Bonus Points if applicable)
* Input Parameters:
*	integer sum of upper section
*	integer sum of lower section
*	intger result of checkIfBonus (1 if they do get bonus 0 if not)
* Returns:	integer which is the sum of all of the player's points
* Precondition:	Lower, and upper sums computed and players have been checked to see if they will be awarded bonus points
* Postcondition: Total sum of players points
*/
int computeGrandTotal(int upperSectionSum, int lowerSectionSum, int ifBonus);

/*
* Function: determineVictor()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: will determine who wins the game
* Input Parameters: 
*	integer player 1 grand total
*	integer player 2 grand total
* Returns: integer: 1 if player 1 wins or 2 if player 2 wins
* Precondition: Both players' grand total computed
* Postcondition: Winner returned as integer
*/
int determineVictor(int p1GrandTotal, int p2GrandTotal);

/*
* Function: printEndGameScreen()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: This will print the victor as well as both players scores
* Input Parameters: 
*	int p1 grand total
*	int p2 grand total
*	int winner (1 if p1, 2 if p2)
* Returns:	NONE
* Precondition:	winner has been determined
* Postcondition: End screen printed to console
*/
void printEndGameScreen(int p1GrandTotal, int p2GrandTotal, int winnerOfGame);

/*
* Function: sumArray()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: will sum all of the elements of an array
* Input Parameters:
*	integer array
*	integer size of array
* Returns: sum of elements of array
* Precondition: function is called
* Postcondition: sum is returned
*/
int sumArray(int intArray[], int size);

/*
* Function: findStraights()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: find the largest straight in the set of die
* Input Parameters:
*	integer array
*	integer size of array
* Returns: sum of elements of array
* Precondition: function is called
* Postcondition: sum is returned
*/
int findStraights(int intArray[], int size);

/*
* Function:
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/


// Unused functions below

/*
* Function: playerTurnOrder()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: will roll 5 die take the sum then compare them.
*				The player with the greater sum goes first.
* Input Parameters: NONE
* Returns: 1 for player 1 goes first, and 2 for player 2
* Precondition: Player has selected to begin play
* Postcondition: First player to go has been returned as a integer
*/
int playerTurnOrder(void);


#endif YAHTZEE_H