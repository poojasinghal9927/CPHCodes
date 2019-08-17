// Dynamic Programming, from permutations to subsets, n! to 2**n, complexity reduction
/*
Problem 2: Counting value of subsets

Given a mapping from subset to integer value

Find sum(S) = sum( x for x in subsets(S) )
*/

#include<bits/stdc++.h>

using namespace std;


int get_sum()
{
	int sum[1<<N];
	for (int s = 0; s < (1<<n); s++)
		sum[s] = value[s];

	// Limiting sum upto K, to be removed and restricted
	for (int k = 0; k < n; k++)
		for (int s = 0; s < (1<<n); s++)
			if (s&(1<<k))
				sum[s] += sum[s^(1<<k)];

}

int main()
{
	return 0;
}
