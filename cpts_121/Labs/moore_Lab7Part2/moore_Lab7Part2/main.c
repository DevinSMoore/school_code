#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // for fscanf(), printf()
#include <math.h> // for log() and pow()

// Contant macros
#define START_YEAR 1984
#define GIVEN_REVENUE_PREDICTION 1000000 // in millions => 1 million million => 1 trillion


// Function prototypes

// Description: function will calculate total revenue then pass that as the output parameter
// precondition: time and address of revenue variable have been passed
// postcondition: calculated revenue is passed as an integer output parameter
void calculateRevenue(int year, double* totalRevenue);

// Description: will find the year in which revenues are greater than the futureRevenue value. will return year as an output param
// precondition: revenue you wish to predict, and address of predicted year are passed
// postcondition: predicted year is returned as an output parameter
void predict(int futureRevenue, int* futureRevenueYear);

int main(void)
{
	// initializing variables
	int yearsUntilDone = 0, endYear = 0;
	double revenue = 0.0;
	int predictedYear = 0, yearCounter = 0;

	FILE* outfile = NULL;
	outfile = fopen("revenue_1984_to_prediction.txt", "w");

	// 1. Finding the end point for our revenue predictions
	predict(GIVEN_REVENUE_PREDICTION, &predictedYear);
	endYear = START_YEAR + predictedYear;
	// 2. Printing some preformating for the output file.
	fprintf(outfile, "Yearly revenue predictions for the Opera from %d to %d:\n\n", START_YEAR, endYear - 1);
	fprintf(outfile, "YEAR\t\tPredicted Revenue (in millions of dollars)\t\tYears until revenue exceeds %d\n", GIVEN_REVENUE_PREDICTION);
	
	// 3. Looping until we meet the predicted year, and printing that years revenue on each line.
	for (int i = START_YEAR; i < (endYear); i++)
	{
		yearsUntilDone = (endYear - i);
		calculateRevenue(i, &revenue);
		fprintf(outfile, "%d\t\t%.2lf\t\t\t\t\t\t\t\t\t\t\t%d\n", i, revenue, yearsUntilDone - 1); // ok I tried to get the formating nice, but it breaks half way through
	}
		
	fclose(outfile); // closing the file
	
	return 0;
}

// Description: function will calculate total revenue then pass that as the output parameter
// precondition: time and address of revenue variable have been passed
// postcondition: calculated revenue is passed as an integer output parameter
void calculateRevenue(int year, double* totalRevenue)
{
	double yearsSinceStart = year - (double) START_YEAR; // casted as a double because it complained at me about loss of precision
	*totalRevenue = 203.265 * pow(1.071, (yearsSinceStart)); // (year - start) year will give us years since 1984
}

// Description: will find the year in which revenues are greater than the futureRevenue value. will return year as an output param
// precondition: revenue you wish to predict, and address of predicted year are passed
// postcondition: predicted year is returned as an output parameter
void predict(int futureRevenue, int* futureRevenueYear)
{
	int localCounter = 0;
	double currentYearRev = 0.0;
	while (futureRevenue > currentYearRev)
	{
		calculateRevenue((START_YEAR + localCounter), &currentYearRev); // will set futureRevenue as 
			localCounter++;
	}
	printf("localCounter value inside predict(): %d\n", localCounter);
	*futureRevenueYear = localCounter;
}