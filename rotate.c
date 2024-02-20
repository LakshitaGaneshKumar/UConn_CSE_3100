#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 100000

//Return the next index and update a[]
int next_index(int a[], int k, int n)
{
    // Find next index
    int next = (k + a[k]) % n;

    // Decrement a[k] by one
    a[k] = a[k] - 1;

    return next;
}

int main(int argc, char *argv[])
{

	if(argc!=2)
	{
		printf("Usage: %s n\n", argv[0]);
		return -1;
	}
	int a[MAX];

	int n = atoi(argv[1]);
	assert(n >= 1 && n <= MAX);
	for(int i=0; i<n; i++)
	{
		a[i] = i + 1;
	}	

	int k = 0;
	while(a[k] > 0)
	{
		printf("k=%d a[%d] = %d\n", k, k, a[k]);
		k = next_index(a, k, n);
	}
	printf("finally:\nk=%d a[%d] = %d\n", k, k, a[k]);
	return 0;
}