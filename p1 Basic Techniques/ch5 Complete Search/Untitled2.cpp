// Generating subsets
#include<bits/stdc++.h>

using namespace std;

int n=3;
vector<int> subset;

void search(int k)
{ // Method 1: Recursion to use each element or not
	if (k == n)
	{
		// process subset
		for(int i:subset)
			cout << i << ' ';
		puts("");  // Just printing a new line
	}
	else
	{
		search(k+1); // Search without including k
		subset.push_back(k);
		search(k+1); // Search with including k
		subset.pop_back();
	}
}

int main()
{
	puts("Method 1");
	// Calling Method 1
	search(0);// Search begins when called with 0


	puts("Method 2");
	// Method 2: Just by iterating over bits, of integer upto 2**n, as 2**n subsets
	// Better as subsets generated in order, and no recursion overhead
	for (int b = 0; b < (1<<n); b++)
	{
		// local declaration will override global, also notice, it resets vector each time to empty
		vector<int> subset; 
		for (int i = 0; i < n; i++)
			if(b&(1<<i))subset.push_back(i);
		for(int i:subset)
			cout << i << ' ';\
		puts("");  // Just printing a new line
	}
	
	return 0;
}
