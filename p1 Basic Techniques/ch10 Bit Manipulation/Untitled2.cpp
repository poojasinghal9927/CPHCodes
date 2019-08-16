// Bit Optimization

#include<bits/stdc++.h>

using namespace std;


int hamming(int a, int b)
{ // Instead of loop based optimization
	return __builtin_popcount(a^b);
}

int count_grids()
{
	// number of subgrids whose all corners are black
	int count = 0; // Unoptimized version
	for (int i = 0; i < n; i++)
		if (color[a][i] == 1 && color[b][i] == 1) count++;

	/*
	Store matrix as bitsets, and process per cacheline size
	*/	
	int count = 0; // Optimized version, upto cache line size
	for (int i = 0; i <= n/N; i++)
		count += __builtin_popcount(color[a][i]&color[b][i]);
}


int main()
{
	return 0;
}
