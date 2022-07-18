/////////////////////////////////////////////////////////////////////////////////
// Programmer: Devin Moore
// Assignment: Lab 3 Problem 3
// Class: CptS121 Section 9 Andrew O'Fallon TA: Muthuu Svs
// 
// Description: Calculate the weighted average of some scores
/////////////////////////////////////////////////////////////////////////////////

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



#define EXAM_WEIGHT 60
#define LAB_WEIGHT 10
#define PROJECT_WEIGHT 30


// this will take in a score from the user and return it
double getScore(void);

// will calculate the average of the scores.
double calculateAverageScore(double score1, double score2);

// this will calculate the weighted averages of the scores.
double weightedAverage(double examAverage, double labAverage, double projectAverage);