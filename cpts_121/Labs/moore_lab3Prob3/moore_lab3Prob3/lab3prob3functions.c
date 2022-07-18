/////////////////////////////////////////////////////////////////////////////////
// Programmer: Devin Moore
// Assignment: Lab 3 Problem 3
// Class: CptS121 Section 9 Andrew O'Fallon TA: Muthuu Svs
// 
// Description: Calculate the weighted average of some scores
/////////////////////////////////////////////////////////////////////////////////

#include "lab3prob3functions.h"

// this will take in a score from the user and return it
double getScore(void)
{
	double score = 0.0;
	score = scanf ("%lf", &score);
	printf("score in getScore(): %lf\n", score);
	return score;
}

// will calculate the weighted average of the scores.
double calculateAverageScore(double score1, double score2)
{
	return ((score1 + score2) / (double)2);
}

// will calculate the weighted average of the scores.
double weightedAverage(double examAverage, double labAverage, double projectAverage)
{
	return ((examAverage * EXAM_WEIGHT) + (labAverage * LAB_WEIGHT) + (projectAverage * PROJECT_WEIGHT));
}