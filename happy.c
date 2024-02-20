#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;

	// get user input
	printf("n = ");
	scanf("%d", &n);

	int m = n;

	// set the sum equal to n
	int sum = n;

	// repeat this loop while sum is not equal to 4 because this is how we know the number is NOT a happy number
	while (sum != 4) 
	{
		// reset the value of sum to zero with each repetition of the while loop
		sum = 0;
		
		// repeatedly remove the last digit of n, square the value, and add it to the sum
		while (n != 0)
		{
			int last_digit = n % 10;
			sum += last_digit * last_digit;
			n /= 10;
		}

		// Set the value of n to the new calculated value of sum, which is the sum of the squares of all the digits in n, and print result
		n = sum;
		printf("%d\n", sum);

		// break the while loop if n equals 1, which indicates that it is a happy number
		if (n==1) break;
	}
	
	// print results
	if(n==1) printf("%d is a happy number.\n", m);
	else printf("%d is NOT a happy number.\n", m);
	return 0;
}