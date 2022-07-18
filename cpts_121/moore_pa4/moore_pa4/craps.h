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

#ifndef CRAPS_H // Guard code
#define CRAPS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>   // scanf(), and printf() 
#include <stdlib.h>  // srand(), and rand()
#include <stdbool.h> // included so I can use boolean values
#include <time.h>    // time() function
#include <math.h>    // pow()

#define ADD 0 // Both to these are used for the adjust_balance function
#define SUBTRACT -1
 

/*
* Function: roll_die()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: Will simulate the roll of a dice using a seeded random value
* Input Parameters: NONE
* Returns: integer
* Precondition: Function has been called
* Postcondition: positive integer value between 1 and 6
*/
int roll_die(void);

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
int calc_sum(int num1, int num2);

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
void eat_characters(void);

/*
* Function: display_rules()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: Will show user the rules of craps, and how betting works
* Input Parameters: NONE
* Returns: NONE
* Precondition: Menu option to display rules has been selected, and funcion called
* Postcondition: rules will display onto console
*/
void display_rules(void);

/*
* Function: display_menu()
* Date Created: 2020/10/05
* Last Modified: 2020/10/05
* Description: Will show user the main menu for the game
* Input Parameters: NONE
* Returns: NONE
* Precondition: program has started
* Postcondition: menu will display onto console
*/
void display_menu(void);

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
int verify_menu_choice(void);

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
double get_initial_balance(void);

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
double get_wager(void);

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
int check_wager(double wager_amount, double bank_balance);

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
int round_result(int die_sum);

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
int alt_round_result(int die_sum, int player_point);

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
double adjust_balance(double wager, double balance, int add_subtract);

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
void lose_banter(void);

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
void win_banter(void);

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
void wage_banter(double wager_amount);

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
void bank_banter(double bank_balance);


#endif CRAPS_H 