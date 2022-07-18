///////////////////////////////////////////////////////////
// Name: Devin Moore
// Class: CptS121 Section 9 Andrew O'Fallon
// TA: Muthuu Svs
// 
// Description: this will find the total bonus of a player
//				depending on what activities that they 
//				participated in.
///////////////////////////////////////////////////////////

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define ALL_STAR_BONUS 25000
#define REGULARSSN_MVP_BONUS 75000
#define WRLDSRS_BONUS 100000
#define GLDGLV_BONUS 50000
#define SLVRSLGR_BONUS 35000
#define HOME_RUN_BONUS 25000
#define BATT_AVG_BONUS 25000

// Precondition: User has been prompted for a response to a question
// postcondition: will return value
char user_input(void);

// Precondition: user has responded to question
// postcondition: will return the total bonus the player has accumulated
void print_double(double playerTotal);