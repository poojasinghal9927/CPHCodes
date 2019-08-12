// Range Queries
/*
Following two out of static arrays are considered in this chapter:

O(nq) is running time if naive approach used is used

For static query, prefix/cumulative/progressive sum if
sum(a,b) = sum(0,b) - sum(0,a-1)
sum((x1,y1),(x2,y2)) = sum((0,0),(x2,y2)) - sum((0,0),(x1-1,y2-1)) - sum((0,0),(x2-1,y1-1)) + sum((0,0),(x1-1,y1-1))

Element Update, Range Query
Range Update,   Element Query

A query can min,max,sum or anything similar
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	return 0;
}
