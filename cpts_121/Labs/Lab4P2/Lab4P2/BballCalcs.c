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

// Precondition: User has been prompted for a response to a question
// intakes a char: 'y' for yes 'n' for no
// postcondition: will return value
char user_input(void)
{
	char response = '\0';
	scanf(" %c", &response);
	return response;
}

// Precondition: user has responded to question
// postcondition: will return the total bonus the player has accumulated
void print_double(double playerTotal)
{
	printf("Player Bonus: %.2lf\n\n", playerTotal);
}