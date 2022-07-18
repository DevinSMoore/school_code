/*******************************************************************************************
Programmer: Devin Moore
Date:       2020/09/12
Class:      CptS121 Section 9 Andrew O'Fallon
Assignment: Program Assignment 2

Description: This program expands on the work we did in PA1. We will be moving the
calculations to functions, and employing a 3 file method of program orginization.
Everything is basically the same in main.c except the equations were replaced
by the functions.
*******************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <math.h>

#define PI 3.14159


/*
* Function: computeSeriesResistance ()  
* Date Created: 2020/09/12
* Last Modified: 2020/09/12
* Description: Calculates the equivalent resistance of 3 resistors in series.
* Input Parameters: 
* int R1
* int R2
* int R3
* Return: the equivalent series resistance.
* Precondition: Recieved user values for resistors
* Postcondition: Calculated equivalent series reistance returned.
*/
int calculate_series_resistance(int R1, int R2, int R3);

/*
* Function: computeSalesTaxRate ()
* Date Created: 2020/09/12
* Last Modified: 2020/09/12
* Description: Computes the sales tax rate from percent
* Input Parameters: double sales_tax_percent
* Returns: The rate of sales tax converted from a percentage
* Precondition: Recieved user value for percent sales tax
* Postcondition: Calculated sales tax rate is returned
*/
double computeSalesTaxRate(double sales_tax_percent);

/*
* Function: calculate_total_sales_tax ()  
* Date Created: 2020/09/12
* Last Modified: 2020/09/12
* Description: Calculates total sales tax for a given item price
* Input Parameters: double salesTaxRate
* Returns: The amount of sales tax you pay for that particular item.
* Precondition: Cost of Item, and Sales tax rate is recieved by user (or calculated then passed)
* Postcondition: calulated sales tax returned
*/
double calculate_total_sales_tax(double item_cost, double sales_tax_rate);

/*
* Function: computeVolumeOfPyramid ()  
* Date Created: 2020/09/12
* Last Modified: 2020/09/12
* Description: Calculates the volume of a pyramid.
* Input Parameters:
* double length
* double width
* double height
* Returns: the volume of the pyramid
* Precondition: values for length, width and height are given by user
* Postcondition: Returns the calculated value of the volume of a pyramid.
*/
double computeVolumeOfPyramid(double l, double w, double h);

/*
* Function: computeParallelResistance ()  
* Date Created: 2020/09/12
* Last Modified: 2020/09/12
* Description: Calculates the equivalent resistance of 3 resistors in parallel.
* Input Parameters:
* int R1
* int R2
* int R3
* Returns: the parallel resistance
* Precondition: values for R1, R2, and R3 are provided by user
* Postcondition: Returns the calculated value of equivalent resistance.
*/
double computeParallelResistance(int R1, int R2, int R3);

/*
* Function: computeEncodedCharacter ()  
* Date Created: 2020/09/12
* Last Modified: 2020/09/12
* Description: takes in a char and int, and will return the result as an ASCII character
* Input Parameters:
* char aChar
* int shiftInt
* Returns: the encoded character
* Precondition: a character, and integer are provided by the user.
* Postcondition: Returned an ASCII character
*/
char computeEncodedCharacter(char aChar, int shiftInt);

/*
* Function: computeDistanceBetweenPoints ()  
* Date Created: 2020/09/12
* Last Modified: 2020/09/12
* Description: Calculatues the distance between two points
* Input Parameters:
* double x1
* double y1
* double x2
* doulbe y2
* Returns: distance between the points
* Precondition: values for R1, R2, and R3 are provided by user
* Postcondition: Returns the calculated value of equivalent resistance.
*/
double computeDistanceBetweenPoints(double x1, double y1, double x2, double y2);

/*
* Function: computeValueForY ()  
* Date Created: 2020/09/12
* Last Modified: 2020/09/12
* Description: Finds the solution for a general equation.
* Input Parameters:
* int a
* double x
* double y
* double z
* Returns: the new value of y
* Precondition: values for a, x, y, and z are entered by user.
* Postcondition: Returns the calculated value of y.
*/
double computeValueForY(int a, double x, double y, double z);