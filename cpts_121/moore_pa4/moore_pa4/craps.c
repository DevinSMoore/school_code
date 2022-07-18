////////////////////////////////////////////////////////////////////////////////
// Name: Devin Moore
// Class: CptS121 Andrew O'Fallon Section 9
// TA: Muthuu Svs
// Date: 2020/10/05
// 
// Description: This program impliments a craps game that will allow you to bet
//				before each round on whether the next dice roll will result
//				in a win. Gameplay ends when your bank balance reaches 0
////////////////////////////////////////////////////////////////////////////////
#include "craps.h"


/*
* Function: roll_die()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: Will simulate the roll of a dice using a seeded random value
* Input Parameters: None
* Returns: integer
* Precondition: Function has been called
* Postcondition: positive integer value between 1 and 6
*/
int roll_die(void)
{
	return ((rand() % 6) + 1); // adding one so the correct range of values is returned
}

/*
* Function: calc_sum()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: finds the sum of two integers, and returns it
* Input Parameters:
* integer num1
* integer num2
* Returns: integer sum
* Precondition: function is called with 2 integer arguments
* Postcondition: sum will be returned as integer
*/
int calc_sum(int num1, int num2)
{
	return (num1 + num2);
}

/*
* Function: eat_characters()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: will read in the values in the input stream then assign it to a variable. It will do this until it reaches the end of the stream
* Input Parameters: NONE
* Returns: NONE
* Precondition: user entered invalid data type
* Postcondition: input stream is empty
*/
void eat_characters(void)
{
	char eat_character = '\0';
	do
	{
		scanf("%c", &eat_character);
	} while (eat_character != '\n');
}


/*
* Function: display_rules()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: Will show user the rules of craps, and how betting works
* Input Parameters: None
* Returns: None
* Precondition: Menu option to display rules has been selected, and funcion called
* Postcondition: rules will display onto console
*/
void display_rules(void)
{
	printf("Hello, welcome to the game of craps!\n");
	printf("Craps is a betting game that involves rolling 2 die, and betting before each roll.\n");
	printf("The object of the game is to roll your dice such that the sum\n");
	printf("of the face up sides fall within a defined range of values.\n\n");
	printf("Before each roll is the betting round, and you may bet any amount that is within the balance of your bank.\n");
	printf("If the sum is 7, or 11: You win so your wager pays out and a new round will begin.\n\n");
	printf("If it is 2, 3, or 12: You lose, so your wager will be deducted from your bank and a new round will begin.\n\n");
	printf("If the sum is 4, 5, 6, 8, 9, or 10: This sum is now your \"point\" value.\n");
	printf("\nIf on your first roll you landed on a \"point\" value your new win condition is for the");
	printf(" sum of your die \nto be the \"point\" value. If the sum of the die is 7 you lose. ");
	printf("If you win or lose at this point, your \nwager will be added/deducted and we will begin a new round.\n");
	printf("\nPlay will continue until you no longer have a bank balance.\n");
}

/*
* Function: display_menu()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: Will show user the main menu for the game
* Input Parameters: None
* Returns: None
* Precondition: program has started
* Postcondition: menu will display onto console
*/
void display_menu(void)
{
	printf("1: Display rules.\n"); // simply will call display_rules function
	printf("2: Play game.\n"); // will enter game_play
	printf("3: Exit game.\n");
	printf("Please enter a menu option: ");
}

/*
* Function: verify_menu_choice()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: read in, verify that input is an integer and inside desired range, then return value of users choice
* Input Parameters: None
* Returns: integer
* Precondition: menu has been printed, and user prompted for intput
* Postcondition: integer will be returned representing the users menu choice.
*/
int verify_menu_choice(void)
{
	int status = 0, menu_choice = 0;
	do // User input validation loop
	{
		status = scanf("%d", &menu_choice);
		if (status < 1)
		{
			eat_characters(); // will eath the characters in the input stream so we can get a new one from the user
		}
		// printf("\nValue of 'status': %d\nValue of 'menu_choice: %d\n", status, menu_choice); // printing for more information
		if (menu_choice < 1 || menu_choice > 3) { printf("!! Please enter a valid menu option\n"); } // If the input is invalid, this will print and loop will run through again.
	} while (menu_choice < 1 || menu_choice > 3);
	return menu_choice;
}


/*
* Function: get_initial_balance()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: read in abd verify that bank balance desired an integer and inside desired range. Then return if it is.
* Input Parameters: None
* Returns: double
* Precondition: play game option chosen and we have entered that case bode in the switch statement
* Postcondition: valid bank balance as a double
*/
double get_initial_balance(void)
{
	int status = 0;
	double balance = 0.0;
	do // User input validation loop
	{
		status = scanf("%lf", &balance);
		if (status < 1)
		{
			eat_characters(); // will get rid of the characters in the stream so we can get a new input from user
		}
		// printf("\nValue of 'status': %d\nValue of 'balance': %.2lf\n", status, balance); // printing for more information
		if (balance < 0 || balance > pow(2, 60)) { printf("!! Please enter a valid balance amount\n"); } // If the input is invalid, this will print and loop will run through again.
	} while (balance < 0 || balance > pow(2, 60)); // (2 ^ 15) - 1 is the max integer size, and we want an amount greater than zero so we can wager
	return balance;
}

/*
* Function: get_wager()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: Gets the users wager amount, checks if it's a valid input, then if is valid, pass the amount user entered
* Input Parameters: None
* Returns: integer wager
* Precondition: game loop has been entered, and bank balance set
* Postcondition: wager amount returned as double
*/
double get_wager(void)
{
	int status = 0;
	double wager = 0.0;
	do // User input validation loop
	{
		status = scanf("%lf", &wager);
		if (status < 1)
		{
			eat_characters(); // will eat the characters in the input stream so we can get a new one from user
		}
		// printf("\nValue of 'status': %d\nValue of 'wager': %.2lf\n", status, wager); // printing for more information will get rid of before turn in
		if (wager < 0 || wager > pow(2, 60)) { printf("!! Please enter a valid wager\n"); } // If the input is invalid, this will print and loop will run through again.
	} while (wager < 0 || wager > pow(2, 60)); // doubles can be larger than this, but this is a massive number so it should be fine, zero is a valid wager amount.
	return wager;
}

/*
* Function: check_wager()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: Checks to see if the wager is possible given their current bank balance.
* Input Parameters: 
*	double: wager amount
*	double: bank balance
* Returns: integer false = 0, true = 1
* Precondition: game loop has been entered and a valid bank balance entered by user
* Postcondition: 0 or 1 will be returned to user. 
*/
int check_wager(double wager_amount, double bank_balance)
{
	double new_balance = bank_balance - wager_amount;
	if (new_balance < 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/*
* Function: round_result()
* Date Created: 2020/10/06
* Last Modified: 2020/10/06
* Description:  will check the sum of the roll to find out if it's a win, loss, or we move to the alternate mode where rolls continue until win/loss
* Input Parameters:
*	integer: sum of die rolls
* Returns: integer; -1 = lose, 0 = win, 1 = go to alternate play mode
* Precondition: Sum of dice has been calculated, and passed as an argument
* Postcondition: -1, 0, or 1 has been returned.
*/
int round_result(int die_sum)
{
	if (die_sum == 7 || die_sum == 11)
	{
		return 0; // win condition
	}
	else if (die_sum == 2 || die_sum == 3 || die_sum == 12)
	{
		return -1; // lose condition
	} else
	{
		return 1; // play goes to alternate mode, and new wind condition will be die_sum
	}
}

/*
* Function: alt_round_result()
* Date Created: 2020/10/06
* Last Modified: 2020/10/06
* Description:  will check the sum of the roll in the new round to find out if it's a win, loss, or reroll
* Input Parameters:
*	integer: sum of die rolls
*	integer: players "point" value
* Returns: integer 0 = win, -1 = lose, 1 = reroll
* Precondition: Sum of dice has been calculated, and passed as an argument
* Postcondition: -1, 0, or 1 has been returned.
*/
int alt_round_result(int die_sum, int player_point)
{
	if (die_sum == player_point)
	{
		return 0; // win condition
	}
	else if (die_sum == 7)
	{
		return -1; // lose condition
	}
	else
	{
		return 1; // will go back to begining of alt round and roll again
	}
}

/*
* Function: adjust_balance()
* Date Created: 2020/10/06
* Last Modified: 2020/10/06
* Description:  will adjust bank balance (or betting profit depending on which is passed) depending on if it's a win or loss
* Input Parameters:
*	integer: wager amount
*	integer: balance you wish to change
*	integer: players profit from betting
*	integer: add = 0 subtract = -1
* Returns: double
* Precondition: Sum of dice has been calculated, and passed as an argument
* Postcondition: will return adusted balance as double
*/
double adjust_balance(double wager, double balance, int add_subtract)
{
	if (add_subtract == -1) // lose condition therefore subtract the wager
	{
		balance -= wager;
	}
	else
	{
		balance += wager; // win condiiton to increment wager
	}

	return balance;
}

/*
* Function: lose_banter()
* Date Created: 2020/10/06
* Last Modified: 2020/10/06
* Description: will print banter to the console when you lose
* Input Parameters: None
* Returns: None
* Precondition: Player has rolled a losing condition in main, or alt round
* Postcondition: Losing banter text will display to screen.
*/
void lose_banter(void)
{
	int randNum = rand() % 6; // for numbers 0-5 so I can randomize the banter returned to user.
	
	switch (randNum)
	{
		case 0:
			printf("Sorry mate better luck next time\n\n");
			break;
		case 1:
			printf("Try again, sorry.\n\n");
			break;
		case 2:
			printf("Look what you did, you lost more money! Are you proud of yourself?\n\n");
			break;
		case 3:
			printf("Well, you win some, you lose some.\n\n");
			break;
		case 4:	
			printf("Sucks for you!\n");
			break;
		case 5:
			printf("Maybe you should try harder when you press the enter key. Just a suggestion\n\n");
			break;
	}
}

/*
* Function: win_banter()
* Date Created: 2020/10/06
* Last Modified: 2020/10/06
* Description:  will print banter to the console when you win
* Input Parameters: None
* Returns: None
* Precondition: player rolled a winning sum
* Postcondition: banter is displayed to console
*/
void win_banter(void)
{
	int randNum = rand() % 7; // for numbers 0-6 so I can randomize the banter returned to user.
	switch (randNum)
	{
		case 0:
			printf("Nice!\n\n");
			break;
		case 1:
			printf("Good Job!\n\n");
			break;
		case 2:
			printf("Now you're cooking with gas!\n\n");
			break;
		case 3:
			printf("Yaaaaaaaay, congrats!\n\n");
			break;
		case 4:
			printf("Winner winner chicken dinner!\n\n");
			break;
		case 5:
			printf("Yay, buy me something now!\n\n");
			break;
		case 6:
			printf("Don't you owe me money?\n\n");
			break;

	}
}

/*
* Function: wage_banter()
* Date Created: 2020/10/06
* Last Modified: 2020/10/06
* Description:  will print banter to the console when you make a wager, will check for ranges of bets and return something
* Input Parameters: None
* Returns: None
* Precondition: wage is valid, and passed as argument.
* Postcondition: One line of banter printed to console
*/
void wage_banter(double wager_amount)
{
	int oddOrEven = rand() % 2;
	if (wager_amount >= 1000)
	{
		if (oddOrEven == 0)
		{
			printf("Now that's big money!\n\n");
		}
		else
		{
			printf("I like your style, keep it up champ!\n\n"); // Gimme money
		}
	}
	else if (wager_amount <= 10)
	{
		if (oddOrEven == 0)
		{
			printf("Wow, that's what I call playing it safe\n\n");
		}
		else
		{
			printf("Live a little and bet BIG!\n\n"); // don't gamble folks
		}
	}
	else { // nothing just exit.
	}
}

/*
* Function: bank_banter()
* Date Created: 2020/10/06
* Last Modified: 2020/10/06
* Description:  will print banter to the console when you set your bank, just a couple here if it's a notably large or small value
*				if it's bank input is less than (or equal to) 10 or greater than (or equal to) 1,000,000
* Input Parameters:
*	double: current bank balance
* Returns: None
* Precondition: bank balanced has been validated and passed.
* Postcondition: One line of banter printed to console if balance is smaller than 10 or bigger than 1000000
*/
void bank_banter(double bank_balance)
{
	int oddOrEven = rand() % 2;
	if (bank_balance >= 1000000)
	{
		if (oddOrEven == 0)
		{
			printf("Looks like we have a \"whale\" in the hose.\n");
		}
		else 
		{
			printf("Dang, you're either mega rich, or you need some help with that addiction.\n");
		}
	}
	else if (bank_balance <= 10)
	{
		if (oddOrEven == 0)
		{
			printf("Keeping it reasonable I can respect that.\n");
		}
		else
		{
			printf("Come on! go wild and bring some more cash next time!\n"); // don't gamble folks
		}
	}
	else { // nothing just exit.
	}
}



