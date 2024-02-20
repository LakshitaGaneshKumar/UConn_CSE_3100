#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//There will be m players in an array
typedef struct Player 
{
	int id;
	int loc;
	long balance;
} TPlayer;

//There will be n properties in an array
typedef struct Property
{
	int id;
	int owner_id;
	int rent;
} TProperty;

//Implement the following function
//The player p1 needs to pay the player p2 'amount' of dollars
//If p1 has enough balance, the transaction will be successful
//Otherwise, p1 will pay all of their balance to p2, and the transaction
//is not successful 
//return 1 if the transaction is successful
//Otherwise, return 0
int transaction(TPlayer *p1, TPlayer *p2, int amount)
{
	// Get the balances of both players
	long p1_balance = p1->balance;
	long p2_balance = p2->balance;

	// Check if p1 has enough balance to pay rent
	if (p1_balance >= amount) {
		p1->balance = p1_balance - amount;
		p2->balance = p2_balance + amount;
		return 1;
	} else {
		p1->balance = 0;
		p2->balance = p2_balance + p1_balance;
	}
	return 0;
}

//TODO
//Finish the following function
//If one player cannot pay rent to another player, this function should return 0. 
//The rest of the players will not get chances to play when this happens 

int one_round(int m, int n, TPlayer p[], TProperty prop[])
{
	for(int i = 0; i < m; i++)
	{
		int steps = rand() % 6 + 1 + rand() % 6 + 1;
 
		// Check if player passed over the starting property line
		int current_loc = p[i].loc;
		if ((current_loc + steps) >= n) {
			long current_balance = p[i].balance;
			p[i].balance = current_balance + n;
		}

		// Update location of player
		int new_loc = (current_loc + steps) % n;
		p[i].loc = new_loc;

		// Check if this property is already owned
		if (prop[new_loc].owner_id != -1) {
			TPlayer *owner = &p[prop[new_loc].owner_id];
			TPlayer *current = &p[i];

			int success = transaction(current, owner, prop[new_loc].rent);

			if (success == 0) {
				return 0;
			}
		} else {
			// Set the owner of the property to be the current player
			prop[new_loc].owner_id = i;
		}
	}
	return 1;
}

//used for printing out results
void print_result(int m, TPlayer p[])
{
	printf("      id    balance\n");
	for(int i = 0; i < m; i++)
	{
		printf("%8d %8ld\n", p[i].id, p[i].balance);
	}
	long sum = 0;
	long max = 0;
	for(int i = 0; i < m; i++)
	{
		sum += p[i].balance;
		if(p[i].balance > max) max = p[i].balance;
	}
	printf("average: %f max: %ld, max/average = %lf\n", (double)sum/m, max, (double)max*m/sum); 
}

//max_rounds is needed because the game may never finish
void monopoly(int m, int n, TPlayer p[], TProperty prop[], int max_rounds)
{
	srand(12345);
	int rounds = 1;
	while(one_round(m, n, p, prop) && rounds < max_rounds)
	{
        rounds ++;
	}

	print_result(m, p);
	printf("after %d rounds\n", rounds);
}

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("Usage: %s m n rounds\n", argv[0]);
		return -1;
	}
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	int rounds = atoi(argv[3]);
	assert(n >= 13);
	assert(m >= 1);
	assert(rounds >= 1);

	
	TPlayer p[m];
	TProperty prop[n];

	for(int i = 0; i < n; i++)
	{
		prop[i].id = i;
		prop[i].owner_id = -1;
		prop[i].rent = i + 1;
	}

	for(int j = 0; j < m; j++)
	{
		p[j].id = j;
		p[j].loc = 0;
		p[j].balance = n;
	}
	monopoly(m, n, p, prop, rounds);
	return 0;	
}