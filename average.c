#include <stdio.h>

int main(void) 
{
    // initialize variables
    double total = 0;
    double average = 0;
    double x;
    int count = 0;

    while(scanf("%lf", &x) == 1) 
    {
        // increment count each time to help with computing the average
        count += 1;

        // compute the total and average values
        total += x;
        average = total / count;

        // print result
        printf("Total=%f Average=%f\n", total, average);
    }
}