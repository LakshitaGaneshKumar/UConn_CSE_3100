#include <stdio.h>
#include <stdlib.h>

double two_d_random(int n)
{
	// Calculate number of total points inside the square
    double total_possible = (n*2 - 1) * (n*2 - 1);

    // set up beginning variables and visited plot
    double count = 0;

    int visited[n*2 + 1][n*2 + 1];
	
	for (int i = 0; i < n*2 + 1; i++) {
		for (int j = 0; j < n*2 + 1; j++) {
			visited[i][j] = 0;
		}
	}

    int x = 0;
    int y = 0;
	
    while (x != n && x != -n && y != n && y != -n) {
        if (visited[x+n][y+n] == 0) {
			count++;
			visited[x+n][y+n] = 1;
		}
	
        //When deciding which way to go for the next step, generate a random number as follows.
        //Treat r = 0, 1, 2, 3 as up, right, down and left respectively.
        int r = rand() % 4;

        if (r == 0) y++;
        else if (r == 1) x++;
        else if (r == 2) y--;
        else if (r == 3) x--;
    }

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.
	return count / total_possible;
}

//Do not change the code below
int main(int argc, char *argv[])
{
	int trials = 1000;
	int i, n, seed;
	if (argc == 2) seed = atoi(argv[1]);
	else seed = 12345;

	srand(seed);
	for(n=1; n<=64; n*=2)
	{	
		double sum = 0.;
		for(i=0; i < trials; i++)
		{
			double p = two_d_random(n);
			sum += p;
		}
		printf("%d %.3lf\n", n, sum/trials);
	}
	return 0;
}