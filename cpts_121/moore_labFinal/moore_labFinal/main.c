#include "labFinal.h"


int main(int argc, char* argv[])
{
	// initializing variables
	FILE* infile = NULL, *outfile = NULL;

	Profile customers[MAX_NUM_CUSTOMERS] = { " ", '\0', 0, 0, 0.0 }; // name (first,last), plan type, num minutes, tot data, tot charges

	int numCustomers = 0;
	double minCharge = 0.0, maxCharge = 0.0, * minCharge_ptr = &minCharge, * maxCharge_ptr = &maxCharge,
			sumOfCharges = 0.0, * sumOfCharges_ptr = &sumOfCharges,
			 avgCharges = 0.0, * avgCharges_ptr = &avgCharges;


	
	infile = fopen("customers.txt", "r");
	numCustomers = readCustomers(infile, customers); // reading in file and setting number of customers read in
	fclose(infile); // closing file after read

	int num = 0;
	printCustomers(customers, numCustomers);
	printf("sorting customers by last name descending order and calculating their charges... \n");
	sortCustomers(customers, numCustomers); // sorting the customers by last name
	setCustomerCharge(customers, numCustomers); // setting all of the customers total charge amounts

	printCustomers(customers, numCustomers);
		
	findMinMax(customers, maxCharge_ptr, minCharge_ptr, numCustomers);
	sumCharges(sumOfCharges_ptr, customers, numCustomers);
	averageCharge(sumOfCharges, numCustomers, avgCharges_ptr);

	outfile = fopen("charges.txt", "w"); // openeing file to write stats to
	fprintf(outfile, "Total charges: %.2lf\n", sumOfCharges);
	fprintf(outfile, "Average charge: %.2lf\n", avgCharges);
	fprintf(outfile, "Highest customer charge: %.2lf\n", maxCharge);
	fprintf(outfile, "Lowest charge: %.2lf\n", minCharge);
	fclose(outfile); // closing file

	//printCustomers(customers);
	printf("Files are closed, and total charges, average charge, highest customer charge, and lowest customer charge printed to file.");

	return (0);
}
