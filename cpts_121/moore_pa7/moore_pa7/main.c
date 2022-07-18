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

int main(void) 
{
	srand((unsigned)time(NULL)); /* seed random-number generator */

	int winner = 0, menuChoice = 0, dealerDrawAmt = 0;
	char playAgain = '\0', responseChar = '\0';
	
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	// Declaring
	Hand playerHand, dealerHand, * playerHand_ptr = &playerHand, * dealerHand_ptr = &dealerHand;
	

	
	do { // entering game menu loop
		system("cls");
		printMenu();
		printf("Please enter a menu choice as an integer: ");
		menuChoice = integerInput();
		// printf("menuChoice: %d\n", menuChoice); // Used for debugging
		switch (menuChoice)
		{
			case 1:
				// printf("Print if case 1\n");
				system("cls");
				printRules();
				break;
			case 2: // entering main gameplay
				
				// These next four functions reset the state of the game
				emptyDeck(deck);
				shuffle(deck);
				initializeHand(playerHand_ptr);
				initializeHand(dealerHand_ptr);
				system("cls");
				
				printf("\nDealing Hands...");
				system("pause");
				system("cls");
				deal(deck, face, suit, playerHand_ptr, dealerHand_ptr); // dealing out hands to both players
				orderHand(playerHand_ptr); // ordering hands by face value so it's a little easier to see straights/runs etc...
				orderHand(dealerHand_ptr);
				printHands(playerHand_ptr, dealerHand_ptr, face, suit, 0);
				printf("Would you like to draw any cards?\n");
				responseChar = charInput();
				if (responseChar == 'y')
				{
					printf("How many would you like to redraw?");
					menuChoice = integerInput();
					system("cls");
					printHands(playerHand_ptr, dealerHand_ptr, face, suit, 0);
					
					switch(menuChoice)
					{
						case 1:
							printf("Please enter the number of the card you would like to replace:\n");
							printf("Card Number: ");
							menuChoice = integerInput5();
							playerHand.card[menuChoice - 1].replace = 1; // sets the chosen card replace tag to 1 then we call the draw cards function 
							drawNumberOfCards(playerHand_ptr, dealerHand_ptr, 1, 0);
							break;
						case 2:
							printf("Please enter the number of the first card you would like to replace:\n");
							printf("Card Number: ");
							menuChoice = integerInput5();
							playerHand.card[menuChoice - 1].replace = 1;
							printf("Please enter the number of the second card you would like to replace:\n");
							printf("Card Number: ");
							menuChoice = integerInput5();
							playerHand.card[menuChoice - 1].replace = 1;
							drawNumberOfCards(playerHand_ptr, dealerHand_ptr, 2, 0); // two cards
							break;
						case 3:
							printf("Please enter the number of the first card you would like to replace:\n");
							printf("Card Number: ");
							menuChoice = integerInput5();
							playerHand.card[menuChoice - 1].replace = 1;

							printf("Please enter the number of the second card you would like to replace:\n");
							printf("Card Number: ");
							menuChoice = integerInput5();
							playerHand.card[menuChoice - 1].replace = 1;

							printf("Please enter the number of the third card you would like to replace:\n");
							printf("Card Number: ");
							menuChoice = integerInput5();
							playerHand.card[menuChoice - 1].replace = 1;
							drawNumberOfCards(playerHand_ptr, dealerHand_ptr, 3, 0); // three cards
							break;
						default:
							printf("Hit default Case.\n");
							break;
					}					
				}
				
				printHands(playerHand_ptr, dealerHand_ptr, face, suit, 0);
				orderHand(playerHand_ptr); // ordering player hand after draw
				system("pause");
				system("cls");
				// Going through dealers turn
				dealerDrawAmt = dealerDrawAi(playerHand_ptr, dealerHand_ptr); // finding number of cards to draw
				printf("Dealer chose to draw %d new cards\n", dealerDrawAmt);
				if (dealerDrawAmt) { printf("Drawing...\n"); }
				system("pause");
				
				drawNumberOfCards(playerHand_ptr, dealerHand_ptr, dealerDrawAmt, 1); // drawing cards for dealer
				orderHand(dealerHand_ptr);

				//int testInt = 0;
				//testInt = findPairs(playerHand);
				//printf("Player Pair Count: %d\n", testInt);
				//testInt = findPairs(dealerHand);
				//printf("Dealer Pair Count: %d\n", testInt);
				//
				//testInt = findThreeFourOfAKind(playerHand);
				//printf("Player three or four of a kind: %d\n", testInt);
				//testInt = findThreeFourOfAKind(dealerHand);
				//printf("Dealer three or four OAK: %d\n", testInt);

				//testInt = findFlush(playerHand);
				//printf("Player flush: %d\n", testInt);
				//testInt = findFlush(dealerHand);
				//printf("Dealer flush: %d\n", testInt);

				//testInt = findStraight(playerHand);
				//printf("Player straight: %d\n", testInt);
				//testInt = findStraight(dealerHand);
				//printf("Dealer straight: %d\n", testInt);
				//
				//testInt = findHandRank(playerHand);
				//printf("Player Rank: %d\n", testInt);
				//testInt = findHandRank(dealerHand);
				//printf("Dealer Rank: %d\n", testInt);

				printHands(playerHand_ptr, dealerHand_ptr, face, suit, 1);
				winner = findWinner(playerHand, dealerHand);

				switch (winner) 
				{
					case -1:
						printf("TIE!\n");
						break;
					case 0:
						printf("Dealer Wins!\nBetter luck next time mate.\n");
						break;
					case 1:
						printf("Player Wins!\nCongratulations!\n");
						break;
					default:
						printf("default case hit.\n");
						break;
				}

				printf("Would you like to play again?\n");
				playAgain = charInput();
				break;
			case 3:
				playAgain = 'n';
				break;
			default:
				printf("Hit default case\n");
				break;
		}
	} while (playAgain != 'n'); // end of game loop
	
	return 0;
}