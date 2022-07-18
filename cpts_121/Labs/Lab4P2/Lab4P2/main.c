///////////////////////////////////////////////////////////
// Name: Devin Moore
// Class: CptS121 Section 9 Andrew O'Fallon
// TA: Muthuu Svs
// 
// Description: this will find the total bonus of a player
//				depending on what activities that they 
//				participated in.
///////////////////////////////////////////////////////////

#include "BballCalcs.h"

int main(void)
{
	// Declaring Variables
	char userInput = '\0';
	double playerBonus = 0.0;

	// 1. Telling user whats up
	printf("This program will calculate the total bonus a Basball player recieves given their participation in certain events.\n");
	printf("To each prompt please enter 'y' for yes, or 'n' for no.\n\n");
	
	// 2. Prompting user for all star inclusion
	printf("Did player appear in the All-Star Game? ");
	userInput = user_input();
	if (userInput == 'y')
	{
		playerBonus = playerBonus + ALL_STAR_BONUS;
		print_double(playerBonus);
	}

	// 3. Prompting user if player recieved regular season MVP
	printf("Was player an MVP during regular season? ");
	userInput = user_input();

	if (userInput == 'y')
	{
		playerBonus = playerBonus + REGULARSSN_MVP_BONUS;
		print_double(playerBonus);

	}

	// 4. Prompting user if player was MVP of the world series
	printf("Was player an MVP of the world series? ");
	userInput = user_input();

	if (userInput == 'y')
	{
		playerBonus = playerBonus = playerBonus + WRLDSRS_BONUS;
		print_double(playerBonus);

	}

	// 5. Prompting user if player recieved golden glove award
	printf("Was player awarded the Golden Glove? ");
	userInput = user_input();
	
	if (userInput == 'y')
	{
		playerBonus = playerBonus + GLDGLV_BONUS;
		print_double(playerBonus);

	}
	
	// 5. Prompting user if player recieved Silver Slugger award
	printf("Did player recieve the Silver Slugger award? ");
	userInput = user_input();

	if (userInput == 'y')
	{
		playerBonus = playerBonus + SLVRSLGR_BONUS;
		print_double(playerBonus);

	}

	// 6. Prompting user if player was the home run champ
	printf("Was player the home run champ? ");
	userInput = user_input();
	
	if (userInput == 'y')
	{
		playerBonus = playerBonus + HOME_RUN_BONUS;
		print_double(playerBonus);

	}

	// 7. Prompting user if player was the batting average champ
	printf("Was player awarded the batting average champ? ");
	userInput = user_input();

	if (userInput == 'y')
	{
		playerBonus = playerBonus + BATT_AVG_BONUS;
		print_double(playerBonus);

	}

	printf("The total bonus salary the player recieved is: %.2lf\n", playerBonus);
}