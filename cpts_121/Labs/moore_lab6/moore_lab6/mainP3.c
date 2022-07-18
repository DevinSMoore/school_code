#include "fibonacci.h"

int main(void)
{
    int desiredTerm = 0, nthTermOfFibonacci = 0;

    printf("What term of the Fibonacci series would you like to see?\n");
    printf("Please enter a positive integer: ");
    scanf("%d", &desiredTerm);
    printf("desiredTerm: %d", desiredTerm);
    nthTermOfFibonacci = nthFibonacciTerm(desiredTerm);

    printf("\n\nTerm %d of the Fibonacci series is: %d\n", desiredTerm, nthTermOfFibonacci);



    return 0;
}