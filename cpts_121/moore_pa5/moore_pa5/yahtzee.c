/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/10/22
Class:      CptS121 Section 9 Andrew O'Fallon
TA:			Muthuu Svs
Assignment: Programming Assignment 5: Yahtzee

Description: This program will allow 2 people to play a classic game of Yahtzee.
*******************************************************************************************/
#include "yahtzee.h"

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
void printMenu(void)
{
	printf("\n1. Print Game Rules\n"); 
	printf("2. Play Game\n");
	printf("3. Exit the Game\n");
}


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
		if (menu_choice < 1 || menu_choice > 3) { printf("Invalid input!! Please enter a valid input.\n"); } // If the input is invalid, this will print and loop will run through again.
	} while (menu_choice < 1 || menu_choice > 3);
	return menu_choice;
}

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
int integerInputForScore(void)
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
		if (menu_choice < 1 || menu_choice > 13) { printf("Invalid input!! Please enter a valid input.\n"); } // If the input is invalid, this will print and loop will run through again.
	} while (menu_choice < 1 || menu_choice > 13);
	return menu_choice;
}

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
* Function: printRules()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: Will print rules to the console
* Input Parameters: NONE
* Returns: NONE
* Precondition: Option to print rules has been selected by user
* Postcondition: Rules have printed to console
*/
void printRules(void)
{
	system("cls");
	printf("Yahtzee Game Rules:\n");
	printf("The object of the game is to roll dice to match specific scoring combinations of dice to get the highest score possible.\n\n");
	printf("Player 1 will go first\n\n");
	printf("Each player, on their turn, may reroll the dice a maximum of three times. After the first, and second roll the player\n");
	printf("may chose to match a scoring combination with their current set (which would would move them to the scoring segment), reroll\n");
	printf("specific dice in their set, or to reroll the entire set. After the third roll the player must move onto the scoring segment of their turn.\n\n");
	printf("After the third roll you must chose which of the 13 scoring catagories you're going to apply to your set of dice. Even if the score you get will be 0.\n\n");
	printf("The categories are split into the \"Upper Section\" and \"Lower Sections.\" The upper section consists of 6 categories all of which\n");
	printf("involve taking the sum of the particular value you chose. i.e if you chose -Ones- you would take the sum of all of the dice valued at 1\n");
	printf("and that would be your score for that category. The lower categories are more similiar to trditional betting categores with fixed scores\n");
	printf("i.e. Small Sequence is four dice in ascending sequential order, selecting this and meething the requirements will net you 30 points.");
	printf("\n\nUpper Categories:\n");
	printf("_________________________________________________________________________\n");
	printf("1. Ones \t\t|\tsum of 1s only\t\t\t\t|\n2. Twos \t\t|\tsum of 2s only\t\t\t\t|\n3. Threes\t\t|\tsum of 3s only\t\t\t\t|\n4. Fours\t\t|\tsum of 4s only\t\t\t\t|\n5. Fives\t\t|\tsum of 5s only\t\t\t\t|\n6. Sixs \t\t|\tsum of 6s only\t\t\t\t|\n");
	printf("_________________________________________________________________________\n");
	printf("\nLower Categories:\n");
	printf("_________________________________________________________________________\n");
	printf("7. 3-of-a-kind\t\t|\tSum of all dice\t\t\t\t|\n8. 4-of-a-kind \t\t|\tSum of all dice\t\t\t\t|\n9. Full House\t\t|\t(2-of-a-kind and 3-of-a-kind) 25 points\t|\n10. Small Straight\t|\t(sequence of 3) 30 points\t\t|\n11. Large Straight\t|\t(sequence of 4) 40 points\t\t|\n12. YAHTZEE!\t\t|\t(5 of a kind) 50 points\t\t\t|\n13. Chance \t\t|\t(no prerequisite) sum of all dice\t|\n");
	printf("_________________________________________________________________________\n");
}

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
void fillArray(int fillValue, int integerArray[], int size)
{
	for (int index = 0; index < size; index++) // simply goes through the array sequentially setting each element to fillValue
	{
		integerArray[index] = fillValue;
	}
}

/*
* Function:
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description:
* Input Parameters:
*	integer array of dice
*   integer size of dice array
* Returns: Sum of all elements in the array
* Precondition: Array has been initialized
* Postcondition: Sum of array returned as integer
*/
void upperLowerSum(int *upper_ptr, int *lower_ptr, int scoreCardArray[], int size) 
{
	int index = 0; // need to set upper and lower indirect values to zero before i compute otherwise the previous players sum will affect the following player
	*upper_ptr = 0, * upper_ptr = 0;
	// upper categories are array elements 0 - 5
	for (; index < UPPER_CATEGORY_SIZE; index++) // index will end at value of 6 which lets us go ritght into our next loop all nice like
	{
		*upper_ptr += scoreCardArray[index];
	}
	// printf("index in upperLowerSum after first for loop: %d\n", index);
	for (; index < size; index++)
	{
		*lower_ptr += scoreCardArray[index];
	}
}

/*
* Function: roll_die()
* Date Created: 2020/10/22
* Last Modified: 2020/10/26
* Description: Will simulate the roll of a dice using a seeded random value
* Input Parameters: NONE
* Returns: integer
* Precondition: Gameplay has begun
* Postcondition: Positive integer value between 1 and 6 returned
*/
int rollDie(void)
{
	int dieRoll = ((rand() % 6) + 1); // I did it this way so I could track the random numbers generated with a printf() statemnt
	// printf("die_roll: %d\n", die_roll);  // for debugging
	return dieRoll; // adding one so the correct range of values is returned

}

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
void rollAllDice(int playerDiceArray[], int size)
{
	for (int index = 0; index < size; index++)
	{
		playerDiceArray[index] = rollDie(); // will roll a new random value for each element in the list
	}
}

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
int rerollSelectDice(int playerDice[], int size)
{
	int rerollCounter = 0;
	char reroll = '\0';
	 // I know this probably isn't super kosher but it fit's here well
	for (int index = 0; index < DICE_ARRAY_SIZE; index++)
	{
		system("cls");
		displayPlayerDice(playerDice, size);
		printf("\nReroll die %d?\n", index + 1);
		reroll = charInput();
		if (reroll == 'y') { playerDice[index] = rollDie(); rerollCounter++; } // die at that element will get a new random valu if reroll is 1. and will increment reroll counter
	}
	return rerollCounter; // returns the number of times re rerolled
}

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
void orderPlayerDie(int playerDieArray[], int size) // just the bubble sort algorithm here
{
	int index = 0, passes = 0, temp = 0;

	for (passes = 1; passes < size; ++passes) 
	{
		for (index = 0; index < (size - passes); ++index) // will go through one fewer element in array for each run through
		{
			if (playerDieArray[index] > playerDieArray[index + 1]) 
			{

				temp = playerDieArray[index];	// will swap elements if condition is true
				playerDieArray[index] = playerDieArray[index + 1];
				playerDieArray[index + 1] = temp;
			}
		}
	}
}

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
void printPostRollMenu(void)
{
	printf("\n1. Use this set of dice for this rounds score.\n");
	printf("2. Reroll all dice in this set\n");
	printf("3. Reroll only select dice from this set\n");
}
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
void printSimpleCategoryList(void)
{
	printf("1.  sum of 1s only  2. sum of 2s only\n");
	printf("3.  sum of 3s only   4. sum of 4s only\n");
	printf("5.  sum of 5s only   6. sum of 6s only\n");
	printf("7.  3 of-a-kind (total of all dice)\n");
	printf("8.  4 of-a-kind (total of all dice)\n");
	printf("9.  Full House (2 of-a-kind AND 3 of-a-kind - 25 points)\n");
	printf("10. Small Straight (sequence of 4 - 30 points)\n");
	printf("11. Large Straight (sequence of 5 - 40 points)\n");
	printf("12. YAHTZEE! (5 of-a-kind - 50 points)\n");
	printf("13. Chance (total of all dice, no prerequisit)\n");
}

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
void displayPlayerDice(int playerDiceArray[], int size)
{
	printf("Players current dice:\n");
	for (int index = 0; index < size; index++)
	{
		printf("Die %d: [%d] ", index + 1, playerDiceArray[index]); // index + 1 so that our die are enumerated with 1 - 5
	}
	printf("\n"); // just for formating
}

// This next function is an absolut monster it was just kind of nice to have all of them checked out at once. I know there are other ways to solve this problem

/*
* Function: checkPlayerScores()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: This will fill an array with the scores for each category for the array of dice that has been provided, this will be used to fill the players array when they choose they score category
* Input Parameters:
*	integer array of players dice
*	integer array for the temporary score card array
*	integer size of the score card array
* Returns: NONE
* Precondition: Player has selected the score option or they have rolled three times this round.
* Postcondition: Temporary array is filled with the current player's scores
*/
void checkPlayerScores(int tempScoreArray[], int playerDiceArray[], int size)
{

	int index = 0, i = 0, j = 0, sumOfDice = sumArray(playerDiceArray, DICE_ARRAY_SIZE), checkerArray[6] = { 0 }; ;

	for (; index < size; index++) // getting the scores for the upper section based on the passed die roll
	{
		tempScoreArray[index] = findSumOfLikeElements(index + 1, playerDiceArray, DICE_ARRAY_SIZE);
	} // this will fill the first 6 elements in the tempScoreCard array, which corolates to the upper section

	// setting the chance element to the sumOfDice
	tempScoreArray[12] = sumOfDice;

	for (i = 0; i < DICE_ARRAY_SIZE; i++)
	{
		/* Tracks die with the same value */
		checkerArray[playerDiceArray[i] - 1]++;
	}

	// Checking for a three of a kind
	for (i = 0; i < 6; i++)
	{
		if (checkerArray[i] == 3) // if any element shows up 3 times there's a three of a kind
		{
			tempScoreArray[6] = sumOfDice;
			break;
		}
		else {
			tempScoreArray[6] = 0; // if it doesn't exist set element to zero
		}
	}
	
	// Checking for 4 of a kind
	for (i = 0; i < 6; i++)
	{
		if (checkerArray[i] == 4)
		{
			tempScoreArray[7] = sumOfDice;
			break;
		}
		else {
			tempScoreArray[7] = 0; // if it doesn't exist set element to zero
		}
	}
	

	for (i = 0; i < 6; i++) // checking for yahtzee
	{
		if (checkerArray[i] == 5) // if any of the die are counted 5 times then a yahtzee exists
		{
			tempScoreArray[11] = YAHTZEE_POINTS; // setting the score at th
			break;
		}
		else {
			tempScoreArray[11] = 0; // if it doesn't exist set element to zero
		}
	}
	

	for (i = 0; i < 6; i++) // checking for a full house
	{
		printf("checking Full House elegability...\n");
		if (checkerArray[i] == 3 || checkerArray[i] == 2) 
		{
			printf("if we passed the first condition we print here \n");
			for (j = i + 1; j < 6; j++)
			{ 
				if (checkerArray[j] == 3 || checkerArray[j] == 2) // will check if one of the elements is a 3 and another is 2.
				{
					printf("if we pass the second condition we print here.\n");
					tempScoreArray[8] = FULL_HOUSE_POINTS;
					break;
				}


			}
		}
	}
	
	// checking for a continuous sequence of 5
	if (checkerArray[0] == 0) // if the number 1 doesn't exist in the array then we start from 2 and check if all elements above are 1 if any aree 0 we set the score to 0 at that location
	{
		for (i = 1; i < 6; i++)
		{
			if (checkerArray[i] == 0)
			{
				tempScoreArray[10] = 0;
				break;
			}
			tempScoreArray[10] = LARGE_STRAIGHT_POINTS;
		}
	}
	else
	{
		for (i = 1; i < 5; i++)
		{
			if (checkerArray[i] == 0)
			{
				break;
			}
			tempScoreArray[10] = LARGE_STRAIGHT_POINTS;
		}
	}
	
	// checking for a continuous sequence of 4 elements
	if ((checkerArray[0] == 0 && checkerArray[1] == 0) ||
		(checkerArray[0] == 1 && checkerArray[1] == 0)) // if first 2 numbers dont exist or 1 does and 2 doesn't then we start from 3
	{
		for (i = 2; i < 6; i++)
		{
			if (checkerArray[i] == 0)
			{
				tempScoreArray[9] = 0;
				break;
			}
			tempScoreArray[9] = SMALL_STRAIGHT_POINTS;
		}
	}
	else if (checkerArray[0] == 0)
		{
			for (i = 1; i < 5; i++) // checking 2-5
			{
				if (checkerArray[i] == 0)
				{
					tempScoreArray[9] = 0;
					break;
				}
				tempScoreArray[9] = SMALL_STRAIGHT_POINTS;
			}
		}
		else
		{
			for (i = 0; i < 4; i++) // checking 1 - 4
			{
				if (checkerArray[i] == 0)
				{
					tempScoreArray[9] = 0;
					break;
				}
				tempScoreArray[9] = SMALL_STRAIGHT_POINTS;
			}
		}
}
	
	
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
int findNumberOfLikeElements(int numberToCheck, int playerDiceArray[], int size)
{
	int counter = 0;
	for (int index = 0; index < size; index++) // goes trough and will sum like elements
	{
		if (playerDiceArray[index] == numberToCheck) // i + 1 will represent each face value of a 6 sided die
		{
			counter++;
		}
	}
	return counter;
}


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
int findSumOfLikeElements(int likeElementToSum, int playerDiceArray[], int size)
{
	int integerScalar = 0;
	for (int index = 0; index < size; index++)
	{
		if (playerDiceArray[index] == likeElementToSum)
		{
			integerScalar++; // simply incriments the counter every time it hits the number, then at the end we're going to scale the likeElementToSum by that number which will equal our sum
		}
	}
	return integerScalar * likeElementToSum; // goofy way to do it I know, could've just done the ol' integerSum += playerDiceArray[index]; if the conditions are right but that's boring

}


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
int sumArray(int intArray[], int size)
{
	int sumOfArray = 0;
	for (int index = 0; index < size; index++)
	{
		sumOfArray += intArray[index];
	}
	return sumOfArray;
}

/*
* Function: findStraights()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: find the largest straight in the set of die
* Input Parameters:
*	integer array
*	integer size of array
* Returns: sum of elements of array
* Precondition: array is in ascending order
* Postcondition: sum is returned
*/
int findStraights(int intArray[], int size)
{
	int index = 0, runCounter = 1, newMax = 1;
	int diffInElements = 0, sequenceCounter = 0; // sequence counter is 1 because there's always at least a sequence of 1
	while (runCounter < size - 1)
	{
		for (index = runCounter; index < size - 1; index++) // size - 1 so we don't go over the array size
		{
			diffInElements = (intArray[index + 1] - intArray[index]);
			printf("index outside: %d\n", index);
			if (diffInElements == 1)
			{
				printf("index inside: %d\n", index);
				sequenceCounter++;
				printf("\nintArray[index + 1]: %d\n intArray[index]: %d\nsequencCounter: %d\n", intArray[index + 1], intArray[index], sequenceCounter);
			}
			if (sequenceCounter > newMax) { newMax = sequenceCounter; }

		}
		sequenceCounter = 0;
		runCounter++; // reseting counter and increaseing the size of index so we can check sequences in the laterparts of the array
;
	}
	return newMax; // newMax will be the largest sequence we find
}

/*
* Function: setPlayerScore()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: This will take the players selection for their score category then set the cooresponding element in
*				the score card to the related value from the temporary score array.
* Input Parameters:
*	integer that represents the players choice of score category
*	integer array: temporary score card
*	integer array: players score card
*	integer size of score card array (will work for both player and temp score card)
* Returns: NONE
* Precondition: Player has rolled three times or has chosen to score current set of dice
* Postcondition: Correct value has been assigned to player score card array.
*/
void setPlayerScore(int playerCategorySelection, int tempScoreArray[], int playerScoreCard[], int scoreCardArraySize) // used to be different couldn't get some logic to work so I pruned it and did most of the work outside the function
{
				playerScoreCard[playerCategorySelection - 1] = tempScoreArray[playerCategorySelection - 1];
}

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
void displayScorecard(int player1ScoreCard[], int player2ScoreCard[], int scoreCardArraySize)
{
	printf("\n\nUpper Categories:\n");
	printf("_____________________________________________________________________________________________________________\n");
	printf("|   Category Name\t|\tScore for Category\t\t\t| Player 1 Scores | Player 2 Scores |\n");
	printf("|1. Ones \t\t|\tsum of 1s only\t\t\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[0], player2ScoreCard[0]);
	printf("|2. Twos \t\t|\tsum of 2s only\t\t\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[1], player2ScoreCard[1]);
	printf("|3. Threes\t\t|\tsum of 3s only\t\t\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[2], player2ScoreCard[2]);
	printf("|4. Fours\t\t|\tsum of 4s only\t\t\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[3], player2ScoreCard[3]);
	printf("|5. Fives\t\t|\tsum of 5s only\t\t\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[4], player2ScoreCard[4]);
	printf("|6. Sixs\t\t|\tsum of 6s only\t\t\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[5], player2ScoreCard[5]);
	printf("|_______________________|_______________________________________________|_________________|_________________|\n");
	printf("\nLower Categories:\n");
	printf("_____________________________________________________________________________________________________________\n");
	printf("|    Category Name\t|\tScore for Category\t\t\t| Player 1 Scores | Player 2 Scores |\n");
	printf("|7.  3-of-a-kind\t|\tSum of all dice\t\t\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[6], player2ScoreCard[6]);
	printf("|8.  4-of-a-kind\t|\tSum of all dice\t\t\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[7], player2ScoreCard[7]);
	printf("|9.  Full House\t\t|\t(2-of-a-kind and 3-of-a-kind) 25 points\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[8], player2ScoreCard[8]);
	printf("|10. Small Straight\t|\t(sequence of 4) 30 points\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[9], player2ScoreCard[9]);
	printf("|11. Large Straight\t|\t(sequence of 5) 40 points\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[10], player2ScoreCard[10]);
	printf("|12. YAHTZEE!\t\t|\t(5 of a kind) 50 points\t\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[11], player2ScoreCard[11]);
	printf("|13. Chance \t\t|\tsum of all dice\t\t\t\t|\t%d\t  |\t   %d\t    |\n", player1ScoreCard[12], player2ScoreCard[12]);
	printf("|_______________________|_______________________________________________|_________________|_________________|\n");
}

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
int checkIfBonus(int sumOfUpperSection)
{
	if (sumOfUpperSection >= 63)
	{ return 1; } // sum of players upper section is >= 63
	else { return 0; }
}

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
int computeGrandTotal(int upperSectionSum, int lowerSectionSum, int bonus)
{
	if (bonus == 1) // if we do recieve bonus add to grand total
	{
		return (upperSectionSum + lowerSectionSum + BONUS_POINTS);
	} 
	else 
	{
		return upperSectionSum + lowerSectionSum;
	}
}

/*
* Function: determineVictor()
* Date Created:  2020/10/22
* Last Modified: 2020/10/26
* Description: will determine who wins the game
* Input Parameters:
*	integer player 1 grand total
*	integer player 2 grand total
* Returns: integer: 0 if tie; 1 if player 1 wins; 2 if player 2 wins
* Precondition: Both players' grand total computed
* Postcondition: Result returned as integer
*/
int determineVictor(int p1GrandTotal, int p2GrandTotal)
{
	if (p1GrandTotal > p2GrandTotal)
	{
		return 1;
	}
	else if (p2GrandTotal > p1GrandTotal)
	{
		return 2;
	}
	else {
		return 0;
	}
}

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
void printEndGameScreen(int p1GrandTotal, int p2GrandTotal, int winnerOfGame)
{
	system("cls");
	printf("Player 1 Final Score: %d\nPlayer 2 Final Score: %d\n", p1GrandTotal, p2GrandTotal);
	printf("Congratulations on your victory Player %d\n", winnerOfGame);
	printf("Please press any button to return to the main menu, Thanks for playing!");
	_getch();
}

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
int playerTurnOrder(void) // I know this function is a bit silly, but if I wanted to iplement more players this would be a way I handled those additional players thought there's probably a much better way to do this
{						  // You could just take ((random number) % (player count) + 1) but the real game determines play in this way so that's why I programmed this.
	int index = 0, p1Sum = 0, p2Sum = 0, p1Die[DICE_ARRAY_SIZE] = { 0 }, p2Die[DICE_ARRAY_SIZE] = { 0 };

	rollAllDice(p1Die, DICE_ARRAY_SIZE);
	rollAllDice(p2Die, DICE_ARRAY_SIZE);


	for (; index < DICE_ARRAY_SIZE; index++)
	{
		p1Sum += p1Die[index];
	}
	for (index = 0; index < DICE_ARRAY_SIZE; index++) // these two loops sum the random dice of player 1 and player 2
	{
		p2Sum += p2Die[index];
	}

	// printf("\np1Sum: %d\np2Sum: %d\n", p1Sum, p2Sum); // for debugging

	if (p1Sum > p2Sum) // If P1 is bigger return one, if p2 is bigger return 2. if they're euqal run through the program again.
	{
		return 1;
	}
	else if (p2Sum > p1Sum)
	{
		return 2;
	}
	else
	{
		return playerTurnOrder(); // this is 
	}
}

