#include <stdio.h>
#include <stdlib.h>

int oddSumHelp(int count, int bound, int value)
{
    // Base Cases
    if (count == 0 && value == 0) return 1; // We used up all the counts and the value is now 0, so we found a solution
    if (value <= 0 || count <= 0 || bound <= 0) return 0; // We went too far without finding a solution

    // If the current number is odd and smaller than the total value, print that out
    if (bound <= value && bound % 2 == 1) {
        if (oddSumHelp(count - 1, bound - 2, value - bound)) {
            printf("%d ", bound);
            return 1; // Then recursively check the next biggest odd number
        }
    }

    // If the next biggest odd number doesn't work, recursively go down to the odd number below that
    return oddSumHelp(count, bound - 2, value);
}

//Do not change the code below
void oddSum(int count, int bound, int value)
{
    if(value <= 0 || count <= 0 || bound <= 0) return;

    if(bound % 2 == 0) bound -= 1;

    if(!oddSumHelp(count, bound, value)) printf("No solutions.\n");
    else printf("\n");
}

int main(int argc, char *argv[])
{
	if(argc != 4) return -1;

	int count = atoi(argv[1]);
	int bound = atoi(argv[2]);
	int value = atoi(argv[3]);

	//oddSum(12,30,200);
	//oddSum(10,20,100);
	//oddSum(20,20,200);
	oddSum(count, bound, value);
	return 0;
}