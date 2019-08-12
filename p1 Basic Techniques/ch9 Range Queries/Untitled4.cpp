// Handling Range Updates

/*
Range Update & Element queries (opposite of what we have seen till now)
can be added to segment tree, by adding DIFFERENCE array to segment tree

ORG ARRAY:  3, 3 , 1, 1, 1, 5,  2, 2
DIFF ARRAY: 3, 0, -2, 0, 0, 4, -3, 0
Build Segment tree on top of diff array

TRICK: To increase range [a,b] by x,
On, diff array, increase position a by x, decrease position b+1 by x.

Implementation:
Range update is dealt as 2 elements update
Element update is dealt as Range query from beginning
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	return 0;
}
