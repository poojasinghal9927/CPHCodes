// Backtracking & search pruning
/*
Recursively finding all solutions, while root is called with empty instance
N-queen is popular, finding number of configurations, on baord such that no queen attack other

Search pruning can be done, to effectively reduce computattion, so that algorithms
detect early that partial solution cannont be extended to a complete solution

Problem1: Find number of paths from top-left corner to bottom-right corner or 2D array
No-Optimization :(76B)
Optimization1   :(38B) Symmetric solution, decide always start with left or going down on 1st step
Optimization2   :(20B) Stop when, path reaches bottom-right, before visiting all squares
Optimization3   :(221M) Stop when, path collides with any boundary
Optimization4   :(69M) Stop when, path collides with itself

Problem2: Meet-in-the-middle generate two solutions that will be merged
Sol: divide list into two parts, find lists of sums of subsets from each part
since two sum lists are sorted, check if there is solution in both sum lists
L = [2,4,5,9] ; X = 15    ==>    L1 = [2,4] ;  L2 = [5,9]
S1 = [0,2,4,6] ; S2 = [0,5,9,14]
Now it is easy to check is X=15 can be formed, in O(2**(n/2))==O(sqrt(2**n)) complexity
*/
#include<bits/stdc++.h>

using namespace std;

int n,mycount; // User input taken in this variable
vector<int> column, diag1, diag2;

void search(int y)
{ // y is index of ROW in which queen need to be placed
	if (y == n)
	{
		mycount++;
		return;
	}
	for (int x = 0; x < n; x++)
	{ /*
		"column" contain entry of columns having queen
		"diag1"  contain entry of diagonals at 45 degree (y=x)
		"diag2"  contain entry of diagonals at 135 degree (y=-x)
	   */
		if (column[x] || diag1[x+y] || diag2[x-y+n-1])
		{
			continue;
		}
		
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
		search(y+1);
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
	}
}


int main()
{
	puts("Enter N for which number of solutions of N-queen need to be searched");
	cin >> n ;
	for(int i=0;i<n;i++)
	{
		column.push_back(0);
	}
	for(int i=0;i<2*(n-1)+1;i++)
	{
		 diag1.push_back(0);
		 diag2.push_back(0);
	}
	search(0);
	cout << "Number of Solutions is " << mycount ;
	return 0;
}
