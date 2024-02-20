#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

// Returns the index of the coordinate on the grid
// test
int offset(int x, int y, int z, int n) { 
    return (x * (2*n+1) * (2*n+1)) + (y * (2*n+1)) + z; 
}

void one_particle(int *grid, int n)
{
    // Start at origin of grid
    int x = n;
    int y = n;
    int z = n;

    // loop n times
    for (int i = 0; i < n; i++) {
        // random number generator to choose next step
        int num = rand() % 6;

        // decrease/increase x
        if (num == 0) x--;
        if (num == 1) x++;
        
        // decrease/increase y
        if (num == 2) y--;
        if (num == 3) y++;

        // decrease/increase z
        if (num == 4) z--;
        if (num == 5) z++;
    }

    int index = offset(x, y, z, n);
    int grid_value = grid[index];
    grid[index] = grid_value + 1;
}

//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int *grid, int n, double r)
{
   double grid_size = ((2*n) + 1) * ((2*n) + 1) * ((2*n) + 1);
   double distance = r * n;
   double total = 0;
   double num_particles = 0;

   // Loop through each coordinate
   for (int i = 0; i < grid_size; i++) {
        
        // Initialize sum to 0
        double sum = 0;

        // Increment the total num of particles
        total += grid[i];

        // Need to find the x, y, and z given an index on the grid
        // Grid has (2n+1) * (2n+1) * (2n+1) indices

        // Every (2n+1) * (2n+1) is a new x value
        int x = i / ( (2*n+1) * (2*n+1) );

        // Every (2n+1) is a new y value
        int y = (i / (2*n+1)) - (x * (2*n+1));
            
        // Every index is a new z value from 0 to 2n+1
        int z = i % (2*n+1);

        // Adjust values so the origin is (0, 0, 0) instead of (n, n, n)
        x -= n;
        y -= n;
        z -= n;

        // Find distance from origin of each point
        sum = x*x + y*y + z*z;

        // If particle is within the distance, increment num_particles
        if (sum <= (distance * distance)) {
            num_particles += grid[i];
        }
    }

    return num_particles / total;
}

//use this function to print results
void print_result(int *grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
    // Create 3D array
    int grid_size = ((2*n) + 1) * ((2*n) + 1) * ((2*n) + 1);
    int* grid = (int*) calloc(grid_size, sizeof(int));

    // Move each particle
	for (int i = 1; i<=m; i++) one_particle(grid, n);

	print_result(grid, n);
}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}