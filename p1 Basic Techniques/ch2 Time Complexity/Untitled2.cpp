// Maximum Sum Sub-Array
/*
Sub-Array is contiguous always, Subsequence can be non-contigous
3 appraoches, discussed below, check how each works

Note: we also have, min, max function in c++, you'll see them also
*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
	int array[] = { -1 , 2 , 4 , -3 , 5 , 2 , -5 , 2 };
	int n = sizeof(array)/sizeof(int);
	cout << "Length of Array by sizeof() method is " << n << '\n';

	int best , sum; //best & present sum storage variables


	// Method 1 : Brute-Force trivial approach
	best = 0;
	for (int a = 0; a < n; a++)
	{ // Take starting point a
		for (int b = a; b < n; b++)
		{ // Take ending point b
			sum = 0;
			for (int k = a; k <= b; k++)
			{ // Find Sum and check if it is better
				sum += array[k];
			}
			best = max(best,sum);
		}
	}
	cout << "\nAnswer from O(n**3) brute-force approach is\n"<< best << "\n";

	
	// Method 2 : Cumulative/Progressive Sum Approach
	best = 0;
	// Observe no redeclaration error, as above variables are local to scope of for loop
	for (int a = 0; a < n; a++)
	{ // Take starting point a
		sum = 0;
		for (int b = a; b < n; b++)
		{ // On same starting point, vary ending point
		  // So sum upto prev length can be used for finding present sum, by just adding present element
			sum += array[b];
			best = max(best,sum);
		}
	}
	cout << "\nAnswer from O(n**2) cumulative/progressive sum approach is\n"<< best << "\n";
	

	// Method 3 : Kadane Algorithms, as Linear, no best than this, as you have to traverse once
	/*
	Consider the subproblem of finding the maximum-sum subarray that ends at position k.
	There are two possibilities:
		1. The subarray only contains the element at position k.
		2. The subarray consists of a subarray that ends at position k¡1, followed by
		the element at position k.
	*/
	best = 0;
	sum = 0;
	for (int k = 0; k < n; k++)
	{
		// Do we need to consider previous or not ?
		sum = max(array[k],sum+array[k]);
		// Is present sum also the best value
		best = max(best,sum);
	}
	cout << "\nAnswer from O(n) Kadane Algorithm sum approach is\n"<< best << "\n";

	
	return 0;
}
