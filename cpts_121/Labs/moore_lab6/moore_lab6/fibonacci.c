#include "fibonacci.h"



// finds the nth term in the fibonacci sequence and returns it
int nthFibonacciTerm(int userTerm)
{
    int next = 0, first = 0, second = 1;
    if (userTerm == 1)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < (userTerm - 1); i++)
        {
            next += second;
            first = second;
            second = next;
            printf("\nvalue of\nnext: %d\nfirst: %d\nsecond: %d", next, first, second);
        }
    }
    return next;

}
