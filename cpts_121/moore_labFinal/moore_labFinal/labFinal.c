#include "labFinal.h"

// name:		readCustomers()
// Description: Will take in the customers data in the following format
// String - name: first, last
// char - plan: (A, or B)
// int - number of minutes talked
// int - total data used in MBs
// Inputs:
// takes in a file to read
// takes in pointer to the array of customer profiles
// returns number of customers read from file
int readCustomers(FILE* infile, Profile* custProfiles)
{

	
		int numCustomers = 0;
		char junkChar = '\0';
		for (; (!(feof(infile))); custProfiles++)
		{
			fgets(custProfiles->name, 100, infile);

			fscanf(infile, " %c", &(custProfiles->plan));
			fscanf(infile, "%d", &(custProfiles->talk_minutes));
			fscanf(infile, "%d", &(custProfiles->data_MB));
			numCustomers++;
			fscanf(infile, "%c", &junkChar); // need this otherwise the data doesn't read in properly

		}
		return numCustomers;
		
}

// name:		readCustomers()
// Description: Will take in the array of customer profiles and print them
// Inputs: Array of Profiles to be printed and num customers
void printCustomers(const Profile *customers, int numCustomers)
{		
	for (int i = 0; i < numCustomers; i++)
	{
		printf("Name: %s", customers[i].name);
		printf("Plan: %c\n", customers[i].plan);
		printf("Total minutes: %d\n", customers[i].talk_minutes);
		printf("Total Data MB: %d\n", customers[i].data_MB);
		printf("Total Data GB: %.1lf\n", customers[i].data_MB / (double)MB_PER_GB);
		printf("Total Charges: %.2lf\n\n", customers[i].charges);
	}
}

// name:		sortCustomers()
// Description: Will take in the array of customer profiles andsort them in decending order based off of their name
// Inputs: Array of Profiles to be printed
void sortCustomers(Profile* profiles, int numCustomers)
{
	int index = 0, passes = 0, tempInt1 = 0, tempInt2 = 0;
	char tempStr[MAX_NAME_SIZE] = " ", tempChar = '\0';
	double tempDouble = 0.0;

	for (passes = 1; passes < numCustomers; ++passes)
	{
		for (index = 0; index < (numCustomers - passes); ++index) 
		{
			int compareVal = strncmp((profiles + index)->name, (profiles + (index + 1))->name, MAX_NAME_SIZE); // if the strcmp returns negative then we swap because then the one we're looking at has a lower name value the the one being compared to
			if (compareVal < 0)
			{

				strncpy(tempStr, (profiles + index)->name, MAX_NAME_SIZE);
				strncpy((profiles + index)->name, (profiles + (index + 1))->name, MAX_NAME_SIZE);
				strncpy((profiles + (index + 1))->name, tempStr, MAX_NAME_SIZE);


				tempChar = (profiles + index)->plan;	// swappping plans
				(profiles + index)->plan = (profiles + (index + 1))->plan;
				(profiles + (index + 1))->plan = tempChar;

				tempInt1 = (profiles + index)->talk_minutes;	// swapping minutes
				(profiles + index)->talk_minutes = (profiles + (index + 1))->talk_minutes;
				(profiles + (index + 1))->talk_minutes = tempInt1;

				tempInt2 = (profiles + index)->data_MB;	// swapping data
				(profiles + index)->data_MB = (profiles + (index + 1))->data_MB;
				(profiles + (index + 1))->data_MB = tempInt2;

				tempDouble = (profiles + index)->charges;	// swapping minutes
				(profiles + index)->charges = (profiles + (index + 1))->charges;
				(profiles + (index + 1))->charges = tempDouble;

			}
		}
	}

}

// name: chargeCustomers()
// description: will set a customers charge value on their struct
// input: array of customers
void setCustomerCharge(Profile* custArray, int numCustomers)
{
	int index = 0;
	double sumCharges = 0.0, dataGB = 0.0, tempMin = 0.0, tempData = 0.0;
	for (; index < numCustomers; ++index)
	{
		sumCharges = 0; // resetting sumCharges
		tempMin = (custArray + index)->talk_minutes;
		tempData = (custArray + index)->data_MB;
		dataGB = tempData / (double)MB_PER_GB; // converting MB to GB; 1GB = 1000MB

		if ((custArray + index)->plan == 'A') // if they're under plan A
		{
			// printf("HitPlanA with %s\n", (custArray + index)->name);
			sumCharges += PLAN_A_BASECHRG; // +$60.00 for base minutes, and data
			if ((custArray + index)->talk_minutes > 1000)
			{
				tempMin -= 1000.00;
				sumCharges += (tempMin * MIN_OVERAGE_RT_A); 
			}
			if (dataGB > 10.00)
			{
				tempData -= 10.00 * MB_PER_GB; // will take away 10 gigs of data from tempData
				sumCharges += (tempData * DATA_OVERAGE_RT_A);
			}
			
		}
		else {
			// printf("HitPlanB with %s\n", (custArray + index)->name);
			sumCharges += PLAN_B_BASECHRG; // +$85.00 for base minutes, and data
			if ((custArray + index)->talk_minutes > 2000)
			{
				tempMin -= 2000.00;
				sumCharges += (tempMin * MIN_OVERAGE_RT_B);
			}
			if (dataGB > 20)
			{
				tempData -= 20.0 * MB_PER_GB; // will take away 10 gigs of data from tempData
				sumCharges += (tempData * DATA_OVERAGE_RT_B);
			}
			
		}

		(custArray + index)->charges = sumCharges;

	}
}

// Description: Will take in the array of profiles, pointers to max and min paymant variables, and number of customers
void findMinMax(Profile* customers, double* maxPayment, double* minPayment, int numCustomers)
{
	int index = 0;
	*minPayment = customers->charges;
	*maxPayment = customers->charges; // will set the min and max values to just the first charges of the first customer

	for (; index < numCustomers; index++, customers++)
	{
		if (customers->charges > * maxPayment) { *maxPayment = customers->charges; } // if the elements totalPay is greater than the current max, set the current max to the current elements total pay
		else if (customers->charges < *minPayment) { *minPayment = customers->charges; } // similar logic
	}
}

// Descritption: Will take in the pointer to the sum variable, and the array of employees and find the total amount that they will pay their employees.
void sumCharges(double* sumPtr, Profile* custArray, int numCustomers)
{
	int index = 0;
	for (;index < numCustomers; (*sumPtr += custArray->charges), custArray++, index++);
}

// Descritption: Will take in the the sum , and the number of employees and find the average of their pay.
void averageCharge(double sumOfCharges, int numOfCustomers, double* averageVarPtr)
{
	*averageVarPtr = (sumOfCharges / numOfCustomers); 
}
