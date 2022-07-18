/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/12/01
Class:      CptS121 Section 9 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA7 5 card poker

Description: This implimnets a 5 card poker game between you and the dealer. dealer has some
				dumb AI to respond to the quality of hte other players hand as well as their
				own.

*******************************************************************************************/
#ifndef POKERFIVECARDDRAW_H
#define POKERFIVECARDDRAW_H

#define _CRT_SECURE_NO_WARNINGS

// Defining Constants
#define DECK_SIZE 52
#define HAND_SIZE 5
#define NUM_SUITS 4
#define NUM_FC_VALS 13

// defining hand Ranks lower = better
#define FOUR_OAK 0
#define FLUSH 1
#define STRAIGHT 2
#define THREE_OAK 3
#define TWO_PAIR 4
#define PAIR 5

// Importing libraries
#include <stdio.h> // for scanf() and printf()
#include <stdlib.h> // for system functions and random functions
#include <time.h> // for time()
#include <math.h> // included incase I want math functions
#include <ctype.h> // for tolower() function
#include <conio.h> // for _getch()

// Structs

// Struct that containts the integer that represents the indicies of the matrix that containts the names of the suits, and their face values
typedef struct {
	int faceIndex;
	int suitIndex;
	int replace; // 1 for yes, 0 for no
} Card;

// contains an array of Cards that represents a playters hand
typedef struct {
	Card card[5];
	int highCard;
} Hand;


// Function prototypes

/*
* Function: printMenu()
* Date Created:  2020/11/30
* Date Created:  2020/12/03
* Description: This will simply print the game menu to the screen
* Input Parameters: NONE
* Returns: NONE
* Precondition: Program has started sucessfully
* Postcondition: Menu printed to console
*/
void printMenu(void);

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
* Function: integerInput5()
* Date Created:  2020/10/22
* Last Modified: 2020/12/03
* Description: Will get the users input as integer, check if it is valid then return it. If it isn't valid it will prompt user to enter a valid input
*				Valid inputs: { 1, 2, 3, 4, 5 }
* Input Parameters: NONE
* Returns: User input as integer
* Precondition: User has been prompted for input
* Postcondition: Valid input is returned
*/
int integerInput5(void);

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
* Function: printRules()
* Date Created:  2020/12/03
* Last Modified: 2020/12/03
* Description: Will print rules to the console
* Input Parameters: NONE
* Returns: NONE
* Precondition: Option to print rules has been selected by user
* Postcondition: Rules have printed to console
*/
void printRules(void);

/*
* Function: initializeHand()
* Date Created:  2020/11/30
* Date Created:  2020/12/01
* Description: Will initialize the hand Struct passed
* Input Parameters:
*	pointer to Hand type variable
* Returns: NONE
* Precondition:
* Postcondition: Hand has been initialized with all zeros in the card's coordinates
*/
void initializeHand(Hand* hand);

/*
* Function: printCardStruct()
* Date Created:  2020/12/01
* Last Modified: 2020/12/01
* Description: Will print card struct to the console
* Input Parameters:
*	Card var to be printed
*	Array of strings representing the face value of the cards
*	Array of strings representing the Sut of the cards
* Returns: NONE
* Precondition: Card struct initialized
* Postcondition: card val printed to console
*/
void printCardStruct(const Card* card, const char* wFace[], const char* wSuit[]);



/*
* Function: printHands()
* Date Created:  2020/12/01
* Last Modified: 2020/12/02
* Description: Will print Hand struct to the console
* Input Parameters:
*	pointer to players Hand struct
*	pointer to dealers Hand struct
*	Array of strings representing the face value of the cards
*	Array of strings representing the Sut of the cards
*	integer that represents whether we want to show the dealers hand or not; 0 = don't show 1 = show
* Returns: NONE
* Precondition: Hand is initialized
* Postcondition: Hand printed to console
*/
void printHands(const Hand* playerHand, const Hand* dealerHand, const char* wFace[], const char* wSuit[], int showDealer);

/* shuffle cards in deck */
/*
* Function: shuffle()
* Description: Copied from the PA page; THis function will go through the deck array and fill in each element with a number between 1 and 52. no repeates
* Input Parameters:
*	2d array of ints representing the deck of cards
* Returns: NONE
* Precondition: array with 4 rows and 13 columns has been initialized
* Postcondition: Deck has been filled with values 1 - 52 with no repeats
*/
void shuffle(int wDeck[][NUM_FC_VALS]);

/*
* Function: emptyDeck()
* Date Created:  2020/12/01
* Last Modified: 2020/12/02
* Description: will go through the deck and fill each element wih a 0
* Input Parameters:
*	2d array of ints representing the deck of cards
* Returns: NONE
* Precondition:
* Postcondition: all elements have been set to 0
*/
void emptyDeck(int deck[][NUM_FC_VALS]);

/*
* Function: deal()
* Description: Copied from the PA page; THis function will go through the deck array and fill in each element of the players' hands with a unique card
* Input Parameters:
*	2d array of ints representing the deck of cards
*	Array of strings representing the face value of the cards
*	Array of strings representing the Sut of the cards
*	pointer to players Hand struct
*	pointer to the dealers hand struct
* Returns: NONE
* Precondition: Players hands have been initialized
* Postcondition: Each players hand has been filled with 5 unique cards
*/
void deal(const int wDeck[][NUM_FC_VALS], const char* wFace[], const char* wSuit[], Hand* playerHand, Hand* dealerHand);

/*
* Function: drawNumberOfCards()
* Description: draw specified number of cards
* Input Parameters:
*	pointer to players Hand struct
*	pointer to the dealers hand struct
*	int number of cards we want to replace
*	int dealerOrPlayer will choose to draw for player or dealer; 0 = player 1 = dealer
* Returns: NONE
* Precondition: Players has selected the number of cards to replace, and selected which ones they wish to replace
* Postcondition: Each players hand has been filled with 5 unique cards
*/
void drawNumberOfCards(Hand* playerHand_ptr, Hand* dealerHand_ptr, int numToReplace, int playerOrDealer);

/*
* Function: findHighCard()
* Date Created:  2020/12/01
* Last Modified: 2020/12/01
* Description: Will find the highest face value of the hand
* Input Parameters:
*	pointer to Hand to be evalutated
* Returns: NONE
* Precondition: hand has been dealt
* Postcondition: higest card found and has been set in struct
*/
void findHighCard(Hand* playerHand);

/*
* Function: findPairs()
* Date Created: 2020/12/01
* Last Modified: 2020/12/01
* Description: finds if there is a pair, and if there is more than one pair
* Input Parameters:
*	Hand variable that will be evauated
* Returns: will return 0 if no pairs exist, 1 if 1 pair exists, and 2 if two pair exists
* Precondition:
* Postcondition:
*/
int findPairs(const Hand hand);

/*
* Function: findThreeFourOfAKind()
* Date Created: 2020/12/01
* Last Modified: 2020/12/01
* Description: finds if there is a run of three or four.
* Input Parameters:
*	Hand of cards being evalutated
* Returns: integer 0 for not found, 1 for found three of a kind, 2 for found 4 of a kind
* Precondition: Hands have been dealt
* Postcondition: integer returned to main
*/
int findThreeFourOfAKind(const Hand hand);

/*
* Function: findFlush()
* Date Created: 2020/12/01
* Last Modified: 2020/12/03
* Description: Finds a flush wich is a set of 4 cards of the same suit
* Input Parameters:
*	Hand of cards being evalutated
* Returns: 0 if flush not found 1 if found
* Precondition: NONE
* Postcondition: 0 or 1 is returned by function
*/
int findFlush(const Hand hand);

/*
* Function: findStraight()
* Date Created: 2020/12/01
* Last Modified: 2020/12/01
* Description:
* Input Parameters:
*	Hand of cards being evalutated
* Returns: returns 0 if straight not found 1 if found
* Precondition: NONE
* Postcondition: 0 or 1 is returned to
*/
int findStraight(const Hand hand);

/*
* Function: findHandRank()
* Date Created: 2020/12/01
* Last Modified: 2020/12/01
* Description: Finds the highest rank combo of cards in hand passed
* Input Parameters:
*	Hand var type for the hand to be examined
* Returns: int that represents the rank of the hand lower is better
* Precondition: hands have been dealt to players
* Postcondition: Highest rank has been returned to player as int
*/
int findHandRank(const Hand hand);


/*
* Function: findWinner()
* Date Created: 2020/12/01
* Last Modified: 2020/12/01
* Description: will find the winner of the game
* Input Parameters:
*	Hand var; players hand
*	Hand var; dealers hand
* Returns: NONE
* Precondition: Hands have been dealt, and betting rounds are over
* Postcondition: Winner (or tie) has been determined
*/
int findWinner(const Hand playerHand, const Hand dealerHand);

/*
* Function: dealerDrawAi()
* Date Created: 2020/12/01
* Last Modified: 2020/12/01
* Description: Based on the opponents hand, and their own hand the pooter will draw new cards
* Input Parameters:
*	Hand pointer for dealers hand
*	Hand pointer for player
* Returns: number of cards toi be drawn by computer;
* Precondition: Hands have been dealt
* Postcondition: number of cards to redraw is returned
*/
int dealerDrawAi(const Hand* playerHand, const Hand* dealerHand);

/*
* Function: orderHand()
* Date Created: 2020/12/01
* Last Modified: 2020/12/01
* Description: will reorder the hand into ascending order based on face value (will assume ACE is lowest value).
* Input Parameters:
*	Hand variable of hand being sorted
* Returns: NONE
* Precondition: Hand has been dealt
* Postcondition: cards properly sorted with face values in ascending order
*/
void orderHand(Hand* hand);

/*
* Function: fillRandUniqueArray()
* Date Created: 2020/12/02
* Last Modified: 2020/12/02
* Description: fills an array of size 3 with random unique numbers between 0 and 4
* Input Parameters:
*	Array of ints you want filled; SIZE = 3 (limitation of my implimintation)
* Returns: NONE
* Precondition: Array initialized to size of 3 (just a limitation of this specific limitation. I might be able to sovle this with dynamic memory but I'm lazy
* Postcondition: Array filled with unique random numbers ranging between 0 and 4
*/
void fillRandUniqueArray(int array[]);

#endif POKERFIVECARDDRAW_H