//////////////////////////////////////////////////////////////////
//	Name: Devin moore
//	Class: CptS121 Andrew O'Fallon Section 9
//	TA: Muthuu Svs
//
//	Description: This is the first part of Lab 7 that I missed
//				 this program will read in customer internet
//				 usage data and find the total charge, and the 
//				 average charge per hour of internet used. Then
//				 result will be printed to a file.
//////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // printf() fprintf() scanf() fscanf()
// #include <stdlib.h> // 
#include <math.h> // round()

// Constant macros
#define CHARGE_TEN_HOURS 7.99 // amount charged for up to and including 10 hours of usage
#define	CHARGE_EXTRA_TIME 1.99 // amnount charged for any whole or partial extra hour.

// Function prototypes
// Description: Calculates the total customer charge for the month, and their average cost per hour of usage. These values will be assigned to the variables whos address' are passed
// precondition: Values have been read in from file
// postconditio: variables at the address' passed are set to the calculated values
void charges(double hours, double* custCharges, double* custAvgCust);


// Description: Will round the passed real number to the hundreds place.
// precondition: real number is passed as argument
// postconditio: real number rounded to the hundreds place is returned.
double round_money(double money);

// Description: Will read in a single line of customer information then assign the read values to the variable at the passed address
// precondtion: file has been opened, and passed as an argument
// postcondion: variables at passed address' have been set with proper values
void read_cust_data(FILE* infile, int* custIdent, double* custHours);


int main(void)
{

	int month = 0, year = 0;
	int cust1Ident = 0.0, cust2Ident = 0.0, cust3Ident = 0.0, cust4Ident = 0.0;
	double cust1Hrs = 0.0, cust2Hrs = 0.0, cust3Hrs = 0.0, cust4Hrs = 0.0,
			cust1Charges = 0.0, cust2Charges = 0.0, cust3Charges = 0.0, cust4Charges = 0.0,
			 cust1AvgCost = 0.0, cust2AvgCost = 0.0, cust3AvgCost = 0.0, cust4AvgCost = 0.0;

	FILE* infile = fopen("usage.txt", "r");
	if (infile == NULL) printf("error\n"); // if file didn't open it will print out error

	fscanf(infile, "%d %d", &month, &year);
	//printf("%lf %lf", day, month);

	read_cust_data(infile, &cust1Ident, &cust1Hrs);
	read_cust_data(infile, &cust2Ident, &cust2Hrs);
	read_cust_data(infile, &cust3Ident, &cust3Hrs);
	read_cust_data(infile, &cust4Ident, &cust4Hrs);

	fclose(infile); // closeing file after we read in data

	FILE *outfile = fopen("charges.txt", "w"); // opening and initializing output file
	if (outfile == NULL) printf("error\n"); // checking that file was opened properly

	fprintf(outfile, "Charges for %d/%d\n\n\n", month, year);
	fprintf(outfile, "Customer\t Hours Used\t Total Charge\t\t Average Cost per Hour\n\n");


	//printf("Charges for %d/%d\n\n\n", month, year);
	//printf("Customer      Hours used        Cost per Hour            Avg Cost\n\n");

	charges(cust1Hrs, &cust1Charges, &cust1AvgCost);
	charges(cust2Hrs, &cust2Charges, &cust2AvgCost);
	charges(cust3Hrs, &cust3Charges, &cust3AvgCost);
	charges(cust4Hrs, &cust4Charges, &cust4AvgCost);


	fprintf(outfile, "%d\t\t %.2lf\t\t %.2lf\t\t\t\t %.2lf\n\n", cust1Ident, cust1Hrs, cust1Charges, cust1AvgCost);
	fprintf(outfile, "%d\t\t %.2lf\t\t %.2lf\t\t\t\t %.2lf\n\n", cust2Ident, cust2Hrs, cust2Charges, cust2AvgCost);
	fprintf(outfile, "%d\t\t %.2lf\t\t %.2lf\t\t\t\t %.2lf\n\n", cust3Ident, cust3Hrs, cust3Charges, cust3AvgCost);
	fprintf(outfile, "%d\t\t %.2lf\t\t %.2lf\t\t\t\t %.2lf\n\n", cust4Ident, cust4Hrs, cust4Charges, cust4AvgCost);

	
	fclose(outfile);
	return 0;
}


// Function definitions

// Description: Calculates the total customer charge for the month, and their average cost per hour of usage. These values will be assigned to the variables whos address' are passed
// precondition: Values have been read in from file
// postconditio: variables at the address' passed are set to the calculated values
void charges(double custHrs, double* custCharges, double* custAvgCost)
{
	double hoursRemain = 0.0, money = 0.0;


	if (custHrs > 10) // total customer hours
	{
		money = CHARGE_TEN_HOURS + ((custHrs - 10) * CHARGE_EXTRA_TIME); // just a simple linear equation to find the total charge given a set cost, and a linearly scaling cost
		*custCharges = round_money(money);
	}
	else { // if total hours are less than 10 you et basic charge of 7.99
		*custCharges = round_money(CHARGE_TEN_HOURS); // rounding and setting custCharges to basic charge of 7.99
	}
	printf("custHrs value: %.2lf\n", custHrs);
	money = *custCharges / custHrs; // this will give us the average cost per hour customer was charged
	*custAvgCost = round_money(money); // rounds the number and sets the value of custAvgCost

	printf("custAvgCost: %.2lf\n", *custAvgCost);
}
// Description: Will round the passed real number to the hundreds place.
// precondition: real number is passed as argument
// postconditio: real number rounded to the hundreds place is returned.
double round_money(double money)
{

	money = money * 100;
	money = round(money); // round() returns the lowest integer, and will truncate and decimal places, so if we multiply by 100 and round 
	money = money / 100; // to the nearest 1's place then divide by 100. We'll get the 2 decimal places that we desire.

	return money;
}

// Description: Will read in a single line of customer information then assign the read values to the variable at the passed address
// precondtion: file has been opened, and passed as an argument
// postcondion: variables at passed address' have been set with proper values
void read_cust_data(FILE* infile, int* custIdent, double* custHours)
{
	fscanf(infile, "%d %lf", &*custIdent, &*custHours); //  customer ident is an integer and on the left, customer hours are a double and on the right
}