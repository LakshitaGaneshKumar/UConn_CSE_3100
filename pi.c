#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;

    // get user input
	printf("n = ");
	scanf("%d", &n);

	double pi = 0.0;
	
    // loop through the summation from i=0 to i=n
    for (int i = 0; i <= n; i++) 
    {
        // calculate the summation for each value of i
        double inner = (4.0 / ((8.0*i) + 1.0)) - (2.0 / ((8.0*i) + 4.0)) - (1.0 / ((8.0*i) + 5.0)) - (1.0 / ((8.0*i) + 6.0));
        double outer = 1.0;

        // divide by 16 without using the pow function
        for (int j = 0; j < i; j++)
        {
            outer /= 16.0;
        }

        // update the estimated value of pi
        pi += (inner * outer);
    }

    // print result
	printf("PI = %.10f\n", pi);
	return 0;
}