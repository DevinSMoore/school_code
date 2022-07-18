#ifndef FINAL_H
#define FINAL_H


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#define MAX_NAME_SIZE 100 
#define MAX_NUM_CUSTOMERS 100
#define PLAN_A_BASECHRG 60 // base charge for minutes  (25) + base charge for data (35)
#define PLAN_B_BASECHRG 85 // 55 + 30
#define MIN_OVERAGE_RT_A 0.50
#define MIN_OVERAGE_RT_B 0.40
#define DATA_OVERAGE_RT_A 0.25
#define DATA_OVERAGE_RT_B 0.15

#define MB_PER_GB 1000



#pragma once

typedef struct {
	char name[100];
	char plan;
	int talk_minutes;
	int data_MB;
	double charges;
} Profile;


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
int readCustomers(FILE* infile, Profile* custProfiles);

// name:		readCustomers()
// Description: Will take in the array of customer profiles and print them
// Inputs: Array of Profiles to be printed and num customers
void printCustomers(const Profile* customers, int numCustomers);

// name:		sortCustomers()
// Description: Will take in the array of customer profiles andsort them in decending order based off of their name
// Inputs: Array of Profiles to be printed
void sortCustomers(Profile* profiles, int numCustomers);

// name: chargeCustomers()
// description: will set a customers charge value on their struct
// input: array of customers
void setCustomerCharge(Profile* custArray, int numCustomers);

// Description: Will take in the array of profiles, pointers to max and min paymant variables, and number of customers
void findMinMax(Profile* customers, double* maxPayment, double* minPayment, int numCustomers);

// Descritption: Will take in the pointer to the sum variable, and the array of profiles and find the total amount that they will be charged. (and number of customers)
void sumCharges(double* sumPtr, Profile* custArray, int numCustomers);

// Descritption: Will take in the he sum , and the number of employees and find the average of their pay.
void averageCharge(double sumOfCharges, int numOfCustomers, double* averageVarPtr);

#endif FINAL_H
