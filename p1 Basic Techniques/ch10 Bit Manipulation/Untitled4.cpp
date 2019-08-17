// Dynamic Programming, from permutations to subsets, n! to 2**n, complexity reduction
/*
Problem 1: Given N people, all have to go up in an elevator, with max limit K
find minimum number of rides.

O(N*N!) with all permutations and subset finding

O(N*2**N) with Dynamic Programming based approach

rides() functions finding minimum number of rides needed for a subset
last()  minimum wieght of sum fo all people in last ride
*/

#include<bits/stdc++.h>

using namespace std;


// Weight of n people, n itself, x is limit of each ride capacity
int opt_rides( int *weight, int n,int x)
{
	// for each subset S, will contain pair(rides(S),last(S))
	pair<int,int> best[1<<n];
	
	best[0] = make_pair(1,0);

	for (int s = 1; s < (1<<n); s++)
	{
		// initial value: n+1 rides are needed
		best[s] = make_pair(n+1,0);
		for (int p = 0; p < n; p++)
		{
			if (s&(1<<p))
			{
				auto option = best[s^(1<<p)];
				if (option.second+weight[p] <= x)
				{
					// add p to an existing ride
					option.second += weight[p];
				}
				else
				{
					// reserve a new ride for p
					option.first++;
					option.second = weight[p];
				}
				best[s] = min(best[s], option);
			}
		}
	}
	
	/*
	Note that the above loop guarantees that for any two subsets S1 and S2 such
	that S1 ½ S2, we process S1 before S2. Thus, the dynamic programming values
	are calculated in the correct order.
	*/
	return best[(1<<n)-1].first;
}


int main()
{
	int arr[] = {1,1,1,1,1};
	int x=3,n=5;

	cout << opt_rides(arr,n,x);
	return 0;
}
