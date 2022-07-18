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

int main(void)
{
	srand((unsigned int)time(NULL)); // Seeding the rand function

	// Initializing variables
	int menu_choice = 0,
		player_die1 = 0, player_die2 = 0,
		die_sum = 0, player_point = 0, roll_continue_check = 0;
	double bank_balance = 0.0, wager = 0.0, betting_profit = 0.0;


	do
	{
		display_menu();
		menu_choice = verify_menu_choice(); // checks that the input is valid. So is inside range 0 - 3, and is an int type otherwise it will prompt user until they do.
		switch (menu_choice)
		{
		case 1:
			system("cls");
			display_rules();
			break;
		case 2:
			system("cls"); // Just clearing the screen before we begin play
			// 1. Getting initial bank balance
			printf("Please enter an initial bank balance: ");
			bank_balance = get_initial_balance();
			printf("Current balance: %.2lf\n", bank_balance);
			bank_banter(bank_balance); // will print some banter about the balance entered if it's greater than 1 million or less than 10

			// 2. beginning game loop
			while (bank_balance != 0) // we will loop until our bank account is empty.
			{


				// 1. Betting
				printf("\nPlease enter a wager: ");
				wager = get_wager();
				// printf("check_wager value: %d\n", check_wager(wager, bank_balance)); // for debugging 
				while (!check_wager(wager, bank_balance)) // will loop if the wager we enter will cause our balance to go to less than 0, but it can make it go to 0.
				{
					// printf("This prints when we enter while loop if our wager doesn't check out.\n"); // for debugging
					printf("Please enter a wager that does not exceed the balance of your bank.\n\n");
					printf("Current balance: %.2lf", bank_balance);
					printf("\nPlease enter a wager: ");
					wager = get_wager();
				} // end of wager while loop
				wage_banter(wager);

				// 2. Rolling
				printf("Rolling\n");
				system("pause");
				player_die1 = roll_die();
				player_die2 = roll_die();
				die_sum = calc_sum(player_die1, player_die2);
				printf("\nRoll 1: %d\nRoll 2: %d\nSum of your roll: %d\n\n", player_die1, player_die2, die_sum);

				// 3. Evaluating roll and paying out/deducting bets
				switch (round_result(die_sum))
				{
				case -1: // player loses: wager is deducted from bank balance, then we break out of the switch statement.
					// printf("LOSE CONDITION MET\n");

					printf("LOSE!\nYour wager of %.2lf dollars has be deducted from your bank balance.\n\n", wager);
					bank_balance = adjust_balance(wager, bank_balance, SUBTRACT);
					betting_profit = adjust_balance(wager, betting_profit, SUBTRACT); // adjusting both the bank balance and betting profit
					lose_banter();
					break;
				case 0: // player wins: wager is added to account balance
					// printf("WIN CONDITION MET\n");
					printf("WIN!\nYour wager of %.2lf dollars has be added to your bank balance.\n\n", wager);
					bank_balance = adjust_balance(wager, bank_balance, ADD);
					betting_profit = adjust_balance(wager, betting_profit, ADD); // adjusting both the bank balance and betting profit
					win_banter();
					break;
				case 1: // roll value gets set as players amount then we go into a new loop that will repeat until we get a win/lose condiiton.
					// printf("ALT PLAY MODE ENTERED\n"); // for checking as program runs
					// system("cls");
					player_point = die_sum;
					printf("** Entering new play mode, to win you now must roll %d, and if you roll a 7 you lose. **\n\n", player_point); // Lets user know we entered different play mode
					do
					{
						printf("Rolling\n"); // going through roll procedure again with a pause
						system("pause");
						player_die1 = roll_die();
						player_die2 = roll_die();
						die_sum = calc_sum(player_die1, player_die2);
						printf("\nRoll 1: %d\nRoll 2: %d\nSum of roll: %d\n", player_die1, player_die2, die_sum);
						switch (alt_round_result(die_sum, player_point)) // new win condition
						{
						case -1:  // lose condition

							// printf("ALT LOSE CONDITION MET\n"); // for checking as program runs
							printf("LOSE!\nYour wager of %.2lf dollars has be deducted from your bank balance.\n\n", wager);
							lose_banter();
							bank_balance = adjust_balance(wager, bank_balance, SUBTRACT);
							betting_profit = adjust_balance(wager, betting_profit, SUBTRACT); // adjusting both the bank balance and betting profit
							roll_continue_check = 1;
							break;

						case 0:
							// printf("ALT WIN CONDITION MET\n"); // for checking as program runs

							printf("WIN!\nYour wager of %.2lf dollars has be added to your bank balance.\n\n", wager);
							win_banter();
							bank_balance = adjust_balance(wager, bank_balance, ADD);
							betting_profit = adjust_balance(wager, betting_profit, ADD); // adjusting both the bank balance and betting profit
							roll_continue_check = 1;
							break;
						case 1:
							break; // this just breaks out of the switch block and will cause us to reroll
						}
						system("pause");
						// system("cls"); // clearing the screen before each roll just to keep things a little clean
						} while (roll_continue_check != 1); // end of alt play do-while loop
					
						
				} 
				printf("Current Bank Balance: %.2lf\nCurrent Profit from betting: %.2lf\n", bank_balance, betting_profit); // printing current balance, and total profit after the end of a round
			}// end of game loop
			printf("Sorry but you're out of money in your bank, we'll bring you back to the menu.\n"); // This prints if the bank balance goes to 0
			printf("Thanks for playing, and better luck next time!\n\n");
			break;
		case 3: // Option for exit
			printf("\nThanks for playing!\n");
			menu_choice = 0; // Setting to zero to break out of do-while loop
			break;
		}
	} while (menu_choice != 0); // end of do-while loop for menu, will exit if user enters choice 3




	
	return 0;
}