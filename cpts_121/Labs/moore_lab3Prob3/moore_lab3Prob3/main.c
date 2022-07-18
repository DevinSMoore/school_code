/////////////////////////////////////////////////////////////////////////////////
// Programmer: Devin Moore
// Assignment: Lab 3 Problem 3
// Class: CptS121 Section 9 Andrew O'Fallon TA: Muthuu Svs
// 
// Description: Calculate the weighted average of some scores
/////////////////////////////////////////////////////////////////////////////////


#include "lab3prob3functions.h"

int main(void)
{
	// Declaring Variables

	double examScore1 = 0.0,
		examScore2 = 0.0,
		labScore1 = 0.0,
		labScore2 = 0.0,
		projectScore1 = 0.0,
		projectScore2 = 0.0,
		examAverage = 0.0,
		labAverage = 0.0,
		projectAverage = 0.0,
		weightedScoreAverage = 0.0;

	// Asking user for input
	printf("Please enter only values between 1 and 100 Thanks!\n\n");
	printf("Please enter exam score 1: ");
	examScore1 = getScore();
	printf("Please enter exam score 2: ");
	examScore2 = getScore();
	printf("Please enter lab score 1: ");
	labScore1 = getScore();
	printf("Please enter lab score 2: ");
	labScore2 = getScore();
	printf("Please enter project score 1: ");
	projectScore1 = getScore();
	printf("Please enter project score 2: ");
	projectScore2 = getScore();

	printf("ExamScore1: %lf\nExamScore2: %lf\nlabScore1: %lf\nlabScore2: %lf\nprojectScore1: %lf\nprojectScore2: %lf\n", examScore1, examScore1, labScore1, labScore1, projectScore1, projectScore1);
	// claculating average score for exams, labs, and projects.
	examAverage = calculateAverageScore(examScore1, examScore2);
	labAverage = calculateAverageScore(labScore1, labScore2);
	projectAverage = calculateAverageScore(projectScore1, projectScore2);

	printf("examAverage: %lf\nlabAverage: %lf\nprojectAverage: %lf", examAverage, labAverage, projectAverage);
	// Calculating weighted average of the scores
	weightedScoreAverage = weightedAverage(examAverage, labAverage, projectAverage);
	

	// Print weighted average to the console
	printf("\nWeighted average of the scores entered: %.2lf\n", weightedScoreAverage);

	return 0;
}