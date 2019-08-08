// Binary Search O(log(n)) if data is sorted
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int array[] = {2,3,3,4,5,5,8};
	int n = 7 ;
	int x=5; //Key to be searched using Binary search

	// Method 1: changing Lower(a) & upper(b) limits of search range
	int a = 0, b = n-1;
	while (a <= b)
	{
		int k = (a+b)/2;
		if (array[k] == x)
		{
			// x found at index k
			puts("Found key via Method 1");
			break;
		}
		else if (array[k] > x)
			b = k-1;
		else a = k+1;
	}
	if(a>b)
		puts("Not found key via Method 1");
	/*
	The algorithm halves the size of the region at each step,
	so the time complexity is O(logn).
	*/
	
	
	// Method 2: Changing step sizes, as we get closer to target
	int k = 0;
	for (int b = n/2; b >= 1; b /= 2) // changing step sizes from here
	{ // Nested loops doen't alwasy account quadratic of parameters complexity
		while (k+b < n && array[k+b] <= x) k += b; // while we are less than x
	}
	if (array[k] == x)
	{ // Note this if outside both loops
		// x found at index k
		puts("Found key via Method 2");
	}
	else
		puts("Not found key via Method 2");
	/*
	The time complexity of the algorithm is O(logn),
	because the code in the while loop is performed at most twice for each jump length.
	
	Note: Using above mentioned step size changing method

	Problem 1. find lowest poosible solution for a function
	FFFFFFFFFFFTTTTTTTTTTTTTTTTTTTTTTTTTTT, to find where 1st T occur
	int x = -1;
	for (int b = z; b >= 1; b /= 2)
	{
		while (!ok(x+b)) x += b;
	}
	int k = x+1;
	
	Problem 2. find position k, such that f(x) if peak of function, assume all distinct
	int x = -1;
	for (int b = z; b >= 1; b /= 2)
	{
		while (f(x+b) < f(x+b+1)) x += b;
	}
	int k = x+1;
	
	*/


	return 0;
}
