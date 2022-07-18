///////////////////////////////////////////////////////////
// Name: Devin Moore
// Class: CptS121 Andrew O'Fallon
// TA: Muthuu Svs
// Date: 2020/10/08
//
// Description: Write a program that takes in an int from
//				a file and determines if the sum of the 
//				digits of the integer is a prime number.
///////////////////////////////////////////////////////////
#include "isPrime.h"

int main(void) {
    FILE* infile = NULL;
    infile = fopen("integerInput.txt", "r");
   
    if (infile != NULL) {
        int integerTotal = 0, digitTotal = 0;
        
        integerTotal = sumIntegers(infile);

        printf("Sum of integers in file is %d\n", integerTotal);
        if (isPrime(integerTotal) == 1) {
            printf("%d is a prime number\n", integerTotal);
        }
        else {
            printf("%d is not a prime number\n", integerTotal);
        }
        
        digitTotal = sumDigits(integerTotal);
        
        printf("Sum of digits of %d is %d\n", integerTotal, digitTotal);
        if (isPrime(digitTotal)) {
            printf("%d is a prime number\n", digitTotal);
        }
        else {
            printf("%d is not a prime number\n", digitTotal);
        }
        
        fclose(infile); // closing file
    }
    else {
        printf("File does not exist");
    }
    return 0;
}