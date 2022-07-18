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
#include "pokerFiveCardDraw.h"

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
void printMenu(void)
{
	printf("Welcome to 5 card draw. Please select a menu option below, and Thanks for playing!\n");
	printf("+========================+\n");
	printf("| 1. Print Game Rules    |\n");
	printf("| 2. Play Game           |\n");
	printf("| 3. Exit the Game       |\n");
	printf("+========================+\n");
}

/*
* Function: flushDataStream()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: will clear the input stream
* Input Parameters: NONE
* Returns: NONE
* Precondition: User has entered a value that needs to be cleared from the stream
* Postcondition: Input stream is empty
*/
void flushDataStream(void)
{
	char tempChar = '\0';
	do { scanf("%c", &tempChar); } while (tempChar != '\n');
}

/*
* Function: integerInput()
* Date Created:  2020/11/30
* Date Created:  2020/11/30
* Description: Will get the users input as integer, check if it is valid then return it. If it isn't valid it will prompt user to enter a valid input
*				Valid inputs: { 1, 2, 3 }
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
		// printf("\nValue of 'status': %d\nValue of 'menu_choice: %d\n", status, menu_choice); // printing for more information
		if (menu_choice < 1 || menu_choice > 3) { printf("Please enter an integer between 1 and 3\n"); } // If the input is invalid, this will print and loop will run through again.
	} while (menu_choice < 1 || menu_choice > 3);
	return menu_choice;
}

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
int integerInput5(void)
{
	int status = 0, menu_choice = 0;
	do // User input validation loop
	{
		status = scanf("%d", &menu_choice);
		if (status < 1)
		{
			flushDataStream(); // Empties input stream
		}
		// printf("\nValue of 'status': %d\nValue of 'menu_choice: %d\n", status, menu_choice); // printing for more information
		if (menu_choice < 1 || menu_choice > 5) { printf("Please enter an integer between 1 and 5n"); } // If the input is invalid, this will print and loop will run through again.
	} while (menu_choice < 1 || menu_choice > 5);
	return menu_choice;
}

/*
* Function: charInput()
* Date Created:  2020/11/30
* Date Created:  2020/11/30
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
	} while (userOption != 'y' && userOption != 'n'); // will continue loop until input is either a 'y' or an 'n'

	return userOption;
}

/*
* Function: printRules()
* Date Created:  2020/11/30
* Date Created:  2020/11/30
* Description: Will print rules to the console
* Input Parameters: NONE
* Returns: NONE
* Precondition: Option to print rules has been selected by user
* Postcondition: Rules have printed to console
*/
void printRules(void)
{
	system("cls");
	printf("+===============================================================================+\n");
	printf("|                       Welcome to 5 card draw poker                            |\n");
	printf("| The game is pretty straightforeward, you and the dealer will recieve 5 cards. |\n");
	printf("| After you've taken a look at your cards you can redraw up to a max of 3.      |\n");
	printf("| The individual with the best hand (lowest rank) wins, otherwise it's a tie    |\n");
	printf("| The following combinations of cards are ranked from 0 to 6 (lower is better)  |\n");
	printf("|                                                                               |\n");
	printf("|  Rank 0: Four of a kind\t| Description: 4 cards with the same face value |\n");
	printf("|  Rank 1: Flush\t| Description: when all 5 cards are of the same suit.   |\n");
	printf("|  Rank 2: Straight\t| Description: a continuous run of 5 face values        |\n");
	printf("|  Rank 3: Three of a kind\t| Description: 3 cards with the same face value |\n");
	printf("|  Rank 4: Two pair\t| Description: two sets of pairs			|\n");
	printf("|  Rank 5: one pair\t| Description: 2 of the same face value card		|\n");
	printf("|  Rank 6: High Card\t| Description: Highest card in your hand (ACE > King)   |\n");
	printf("+===============================================================================+\n");
	system("pause");
}

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
void initializeHand(Hand *hand)
{
	for (int index = 0; index < HAND_SIZE; ++index)
	{
		hand->card->suitIndex = 0;
		hand->card->faceIndex = 0;
		hand->card->replace = 0;
	}
}

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
void printCardStruct(const Card *card, const char *wFace[], const char *wSuit[])
{
	printf("%s of %s", *(wFace + (card->faceIndex)), *(wSuit + card->suitIndex)); // decodes the indicies into strings
}



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
void printHands(const Hand *playerHand, const Hand* dealerHand, const char *wFace[], const char *wSuit[], int showDealer)
{
	printf("+-------------------------------------------------------+\n");
	printf("|        |    Players Hand\t|      Dealers Hand\t|\n");
	for (int index = 0; index < HAND_SIZE; ++index)
	{

		printf("| Card %d |  ", index + 1);
		//printf("| ");
		printCardStruct((playerHand->card + index), wFace, wSuit);
		
		if (showDealer == 0)
		{
			printf(" \t|\t    (-)\t\t|\n");
		}
		else
		{
			printf(" \t|  ");
			printCardStruct((dealerHand->card + index), wFace, wSuit);
			printf(" \t|\n");
		}
		
		
		//printf("faceVal: %d   SuitVal: %d\n", (hand->card + index)->faceIndex, (hand->card + index)->suitIndex); // used to show the index values themselves, used for debugging
	}
	printf("+-------------------------------------------------------+\n");
}

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
void shuffle(int wDeck[][NUM_FC_VALS])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= DECK_SIZE; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % NUM_SUITS;
			column = rand() % NUM_FC_VALS;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

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
void emptyDeck(int deck[][NUM_FC_VALS])
{
	for (int i = 0; i < NUM_SUITS; i++)
	{
		for (int j = 0; j < NUM_FC_VALS; j++)
		{
			deck[i][j] = 0;
		}
	}
}

/* deal cards in deck */
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
void deal(const int wDeck[][NUM_FC_VALS], const char* wFace[], const char* wSuit[], Hand *playerHand, Hand *dealerHand)
{
	int row_i = 0, column_i = 0, card = 0, /* card counter */
			cardNumInHand = 0; // represents the card in the hand
	for (card = 1; card <= (2 * HAND_SIZE); card++) // loops 10 times for 10 cards
	{
		for (row_i = 0; row_i <= (NUM_SUITS - 1); row_i++) // moving through the suits, then traversing the face values; NUM_SUITS - 1 = 3
		{
			for (column_i = 0; column_i <= (NUM_FC_VALS - 1); column_i++)//  NUM_FC_VALS - 1 = 12
			{
				if (wDeck[row_i][column_i] == card) // When we hit the row&column of the coord of that value of card then we will assign that set of coordinates to the the card in the players hand
				{
					if (card % 2 == 0) {
						dealerHand->card[cardNumInHand].suitIndex = row_i; // sets the dealers suit and face value for a particular card
						dealerHand->card[cardNumInHand].faceIndex = column_i;
						++cardNumInHand; // only increment on one because we need to go through both cards in both hands before we move to the next one
					}
					else {
						playerHand->card[cardNumInHand].suitIndex = row_i; // sets the players indicies for a card
						playerHand->card[cardNumInHand].faceIndex = column_i;
					}
				}
			}
		}
	}
	
}


/*
* Function: drawNumberOfCards()
* * Date Created:  2020/12/01
* Last Modified: 2020/12/03
* Description: draw specified number of cards
* Input Parameters:
*	pointer to players Hand struct
*	pointer to the dealers hand struct
*	int number of cards we want to replace
*	int dealerOrPlayer will choose to draw for player or dealer; 0 = player 1 = dealer
* Returns: NONE
* Precondition: Players has selected the number of cards to replace, and selected which ones they wish to replace. PRECOND for the dealerRedrawCheck is that we have determined the number of cards to redraw for the computer
* Postcondition: the dealers, or players cards have been dealt out.
*/
void drawNumberOfCards(Hand* playerHand_ptr, Hand* dealerHand_ptr, int numToReplace, int playerOrDealer)
{
	int newCard = 1, numReplaced = 0, dealerRandCardIndex = 0, randNumArray[3] = { 0, 0, 0 };
	Card tempCard = { 0, 0, 0 }, *tempCard_ptr = &tempCard;

	fillRandUniqueArray(randNumArray); // this fills a size 3 array with a unique random number between 1 and 5

	/*for (int i = 0; i < numToReplace; i++) // printing values for test
	{
		printf("randNumArray[%d]: %d\n", i, randNumArray[i]);
	}*/
	

	for (int i = 0; i < numToReplace; i++)
	{
		//printf("value of randNumArray[%d]: %d\n", i, randNumArray[i]);
		
		dealerHand_ptr->card[randNumArray[i]].replace = 1; // will set a random element to replace using the array filled with unique random numbers
	    
		//printf("value of card[%d].replace: %d\n", randNumArray[i], dealerHand_ptr->card[randNumArray[i]].replace);
	}

	for (int index = 0; index < numToReplace; ++index)
	{
		do
		{
			newCard = 1; // resetting newCard
			tempCard.suitIndex = (rand() % NUM_SUITS);
			tempCard.faceIndex = (rand() % NUM_FC_VALS); // creates a new card
				
			for (int i = 0; i < HAND_SIZE; ++i)
			{

				// if the temp card does not equal the card in the players hand, or does not equal the card in dealers hand then 
				if (((playerHand_ptr->card[i].faceIndex == tempCard.faceIndex) && (playerHand_ptr->card[i].suitIndex == tempCard.suitIndex)) || ((dealerHand_ptr->card[i].faceIndex == tempCard.faceIndex) && (dealerHand_ptr->card[i].suitIndex == tempCard.suitIndex)))
				{
					/*printf("Copy Found:\n");
					printf("tempCard.faceIndex = %d   tempCard.suitIndex = %d\n", tempCard.faceIndex, tempCard.suitIndex);
					printf("playerHand_ptr.faceIndex = %d   playerHand_ptr.suitIndex = %d\n", playerHand_ptr->card[i].faceIndex, playerHand_ptr->card[i].suitIndex);
					printf("dealerHand_ptr.faceIndex = %d   dealerHand_ptr.suitIndex = %d\n", dealerHand_ptr->card[i].faceIndex, dealerHand_ptr->card[i].suitIndex);*/
					
					
					newCard = 0;
					break; // we have not found a unique card continue the while loop
				}
			}			//printf("outside of for loop...\n");
			/*if (newCard) {
				printf("New card found:\n"); 
				printf("tempCard.faceIndex = %d   tempCard.suitIndex = %d\n", tempCard.faceIndex, tempCard.suitIndex);
				system("pause");
			}*/
		} while (!newCard);

		for (int i = 0; i < HAND_SIZE; ++i) 
		{
			if (playerOrDealer == 0) // do player card draw
			{
				if (playerHand_ptr->card[i].replace == 1) // if they have marked card for replace
				{
					/*printf("entered player draw:\n");
					printf("tempCard.faceIndex = %d   tempCard.suitIndex = %d\n", tempCard.faceIndex, tempCard.suitIndex);
					printf("playerHand_ptr.faceIndex = %d   playerHand_ptr.suitIndex = %d\n", playerHand_ptr->card[i].faceIndex, playerHand_ptr->card[i].suitIndex);
					printf("dealerHand_ptr.faceIndex = %d   dealerHand_ptr.suitIndex = %d\n", dealerHand_ptr->card[i].faceIndex, dealerHand_ptr->card[i].suitIndex);*/

					playerHand_ptr->card[i] = tempCard; // we have set the players card to temp card; this will also reset the value of 'replace' in the Card struct which is convinient
					++numReplaced;
					break; // break out of loop to create new unique card
				}
			}
			else 
			{ // if we're drawing dealers hand
				if (dealerHand_ptr->card[i].replace == 1) 
				{
					dealerHand_ptr->card[i] = tempCard; // set dealers card to temp card
					++numReplaced;
					break;
				}
			}
		}
	} 
}

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
void findHighCard(Hand *playerHand)
{
	int maxVal = 0;
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if ((playerHand->card + i)->faceIndex > maxVal)
		{
			maxVal = playerHand->card->faceIndex;
		}
	}
	playerHand->highCard = maxVal;
}

/*
* Function: findPairs()
* Date Created: 2020/12/01
* Last Modified: 2020/12/01
* Description: finds if there is a pair, and if there is more than one pair
* Input Parameters:
*	Hand variable that will be evauated
*	poiter to variable that represents the highest rank in the players hand
* Returns: will return 0 if no pairs exist, 1 if 1 pair exists, and 2 if two pair exists
* Precondition:
* Postcondition:
*/
int findPairs(const Hand hand)
{
	int row_i = 0, column_i = 0, faceVal = 0, cardCount = 0, pairCount = 0;

	for (column_i; column_i < NUM_FC_VALS; ++column_i)
	{
		cardCount = 0; // reseting cardCount
			for (int i = 0; i < HAND_SIZE; ++i)
			{
				if (hand.card[i].faceIndex == column_i) // each time a face value equals the column index for the same column we increment cardCount b/c we know that each column represents 4 cards of eache suit that shares that value
				{
					// printf("face index of card %d: %d\tFace Value index being checked: %d\tSuit: %d\n", i, hand.card[i].faceIndex, column_i, hand.card[i].suitIndex);
					// printf("cardCount incremented\n");
					cardCount++;
					// printf("cardCount: %d\n", cardCount);
				}

			}	if (cardCount >= 2) { (pairCount++); } // if our card count reaches 2 or greater we increment pairCount. then we reset cardCount when looking at the next column
			// printf("pairCount: %d\n", pairCount);
	}
	return pairCount;
}

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
int findThreeFourOfAKind(const Hand hand)
{
	int column_i = 0, cardCount = 0, maxCount = 0, check = 0;

	for (column_i; column_i < NUM_FC_VALS; ++column_i)
	{
		cardCount = 0; // reseting cardCount
		for (int i = 0; i < HAND_SIZE; ++i)
		{
			if (hand.card[i].faceIndex == column_i) // if the faceVal index = column then we increment the count, multiple cards of the same face value but different suits will reside in the same column => # of like elements in the same column represents a possible pair/ThreeO-A-K/fourO-A-K
			{
				// printf("face index of card %d: %d\tFace Value index being checked: %d\tSuit: %d\n", i, hand.card[i].faceIndex, column_i, hand.card[i].suitIndex);
				cardCount++;
				if (cardCount > maxCount) {
					maxCount = cardCount;
				}
				// printf("cardCount incremented\ncardCount: %d\n", cardCount);
			}
		}
		// printf("maxCount: %d\n", maxCount);
	}
	(maxCount == 3) ? (check = 1) : ((cardCount == 4) ? (check = 2) : (check = 0)); // if cardcount is three return 1, if it's 4 return 2 else return 0
	//printf("check: %d\n", check);
	return check;
}

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
int findFlush(const Hand hand)
{
	int suitCount[NUM_SUITS] = { 0, 0, 0, 0 };

	for (int i = 0; i < HAND_SIZE; i++)
	{
		suitCount[hand.card[i].suitIndex]++; // will increment the element of the suitCOunt array that corresponds to a particular suit index
	}
	for (int i = 0; i < HAND_SIZE; i++)
	{
		if (suitCount[i] == 5) // if we find 5 of the same suit we found a flush and return 1
		{
			return 1;
		}
	}
	return 0;
}

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
int findStraight(const Hand hand)
{
	int cardCount = 0, blah = 0;
	int faceVal[NUM_FC_VALS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < HAND_SIZE; i++)
	{
		faceVal[hand.card[i].faceIndex]++;
	}
	int count = 0;
	//Hand is of 5 consecutive face values
	//There should be a row of five 1's in numTimes consecutively
	for (int i = 0; i < NUM_FC_VALS; i++) {
		if (faceVal[i] == 1) { // we only have 5 cards so if we increment wherever it hits a 1. Then if the count is 5 we have a straight
			count++;
		}
		else if (faceVal[i] == 0 && count == 5) { // if we move to the next element and the count is 5 then we return 1
			return 1;
		}
		else { count = 0; } // else reset counter if we dont find a run
	}

	if (count == 5) {
		return 1;
	}

	return 0;
}

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
int findHandRank(const Hand hand)
{
	int maxRank = 0;
	if (findThreeFourOfAKind(hand) == 2) // four-of-a-kind
	{
		return 0; // highest rank
	}
	else if (findFlush(hand) == 1) // flush
	{
		return 1; // second
	}
	else if (findStraight(hand) == 1) // straight
	{
		return 2;
	}
	else if (findThreeFourOfAKind(hand) == 1) // three-of-a-kind
	{
		return 3;
	}
	else if (findPairs(hand) == 2) // two pair
	{
		return 4;
	}
	else if (findPairs(hand) == 1) // a lone pair
	{
		return 5;
	}
	else
	{
		return 6; // if there are no combos then we return 6 which will be for the Highest Value Card
	}
}


/*
* Function: findWinner()
* Date Created: 2020/12/01
* Last Modified: 2020/12/01
* Description: will find the winner of the game
* Input Parameters:
*	Hand var; dealers hand
*	Hand var; players hand
* Returns: NONE
* Precondition: Hands have been dealt, and betting rounds are over
* Postcondition: Winner (or tie) has been determined
*/
int findWinner(const Hand playerHand, const Hand dealerHand)
{
	int playerMaxRank = 0, dealerMaxRank = 0;
	// Setting each players max rank 
	playerMaxRank = findHandRank(playerHand);
	dealerMaxRank = findHandRank(dealerHand);

	if (playerMaxRank == dealerMaxRank) // if ranks are equal then we check who has the higher value card
	{
		if (playerHand.highCard == dealerHand.highCard)
		{
			return -1; // Hands tie therefore no winner
		}
		return (playerHand.highCard > dealerHand.highCard) ? 1 : 0; // if players hand is greater than the dealers hand return 1 else return 0
	}
	return (playerMaxRank < dealerMaxRank) ? 1 : 0; // if player rank is greater than dealer rank player wins, else dealer wins
}

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
int dealerDrawAi(const Hand* playerHand, const Hand* dealerHand)
{
	int playerHandRank = findHandRank(*playerHand), dealerRank = findHandRank(*dealerHand);
	if (dealerRank >= playerHandRank) { // if dealers hand has a greater rank (worse hand) or an equal one it will redraw cards
		if (dealerRank > PAIR) { // no combos; lower = better for rank so this is saying "if dealers hand doesn't have a pair or better return 3"
			//draw 3 cards
			//printf("dealerRank > 5 condition\n");
			return 3;
		}
		else if (dealerRank > TWO_PAIR || dealerRank <= PAIR) { // one pair
		//draw 2 cards
			//printf("dealerRank > 4 || dealerRank <= 5 condition\n");
			return 2;
		}
		else if (dealerRank >= THREE_OAK || dealerRank <= TWO_PAIR) { // if the dealers hand has three of a kind or worse or better than or equal to 2 pair hand draw a single card 
			//printf("dealerRank > 4 || dealerRank <= 5 condition\n");
			return 1;
		}

		
	} // if dealerRank is greater than player rank pass 0
	return 0;
}

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
void orderHand(Hand *hand)
{
	int index = 0, passes = 0, temp = 0, temp2 = 0;

	for (passes = 1; passes < HAND_SIZE; ++passes)
	{
		for (index = 0; index < (HAND_SIZE - passes); ++index) // will go through one fewer element in array for each run through
		{
			if ((hand->card + index)->faceIndex > (hand->card + (index + 1))->faceIndex)
			{

				temp = (hand->card + index)->faceIndex;	// will swap face values of the cards
				(hand->card + index)->faceIndex = (hand->card + (index + 1))->faceIndex;
				(hand->card + (index + 1))->faceIndex = temp;


				temp2 = (hand->card + index)->suitIndex; // will go through and swap the corrisponding suit index as well to properly shift the card over
				(hand->card + index)->suitIndex = (hand->card + (index + 1))->suitIndex;
				(hand->card + (index + 1))->suitIndex = temp2;
			}
		}
	}
	if (((hand->card)->faceIndex) == 0) // if the first element in the ordered list is zero will set highCard to 0. 0 represents the Ace
	{
		hand->highCard = 0; // 0 = Ace
	}
	else
	{
		hand->highCard = ((hand->card + 4)->faceIndex);
	}
	// printf("\nhighCardValue: %d\n", hand->highCard);
	
}

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
void fillRandUniqueArray(int array[])
{
	int randNum = 0, index = 0, doWhileIndex = 0, tempArray[5] = { 0, 0, 0, 0, 0 };

	for (; index < 5; index++) // filling array with values 0 - 4
	{
		tempArray[index] = index;
	}
	
	do
	{
		randNum = rand() % 5;
		if (tempArray[randNum] != -1) // going through and filling a random element with that value then setting element to -1 so we dont copy multiple times to the same element
		{
			array[doWhileIndex] = tempArray[randNum];
			tempArray[randNum] = -1;
			doWhileIndex++;
		} 
	} while (doWhileIndex != 3); // looping 3 times
	
}