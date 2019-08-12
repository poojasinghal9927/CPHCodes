// Binary Indexed Tree or Fenwick Tree
/*
Dunamic version of prefix sum approach
O(n*log(n) range sum query and element update

Implementation of index 1 based is easier given in book
Code updated for 0 based indexing below
Note1: Queries also have to be given in 0 based index system, be a programmer :p
Note2: Fenwick tree can only support sum queries, Segment tree with twice memory supports all queries
*/
#include<bits/stdc++.h>

using namespace std;

// Initally index 0 should not be used
vector<int> tree;

int sum(int k)
{ //Finds sum(1,k)
	++k; // back converting to 1 based indexing
	int s = 0;
	while (k >= 1)
	{
		s += tree[k-1];  // little trick here
		k -= k&-k;
	}
	return s;
}


void add(int k, int x)
{ // Increments value at index k by x
	++k; // back converting to 1 based indexing
	while(k <= tree.size())
	{
		tree[k-1] += x;  // little trick here
		k += k&-k;
	}
}

int main()
{
	int n,sq,uq,temp;
	cout << "Enter length of Array\nNumber of Range Sum Queries\nNumber of Element Updates" << '\n';
	cin >> n >> sq >> uq;
	
	
	for(int i=0;i<n;i++)
		tree.push_back(0);
	// Initializing Dynamic 2D vector
	vector<vector<int>> queries(sq+uq,vector<int>(3,0));
	
	cout << "Enter Elements of Array" << '\n';
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		add(i,temp);
	}

	cout << "Initial Fenwick Tree" << '\n';
	for(auto x:tree)
		cout << x << ' ';
	cout << '\n';

	cout << "Enter Range Sum Queries" << '\n';
	for(int i=0;i<sq;i++)
	{
		queries[i][0] = 0; // Denoting Range Sum
		cin >> queries[i][1] >> queries[i][2];
	}
	cout << "Enter Element Update Queries" << '\n';
	for(int i=sq;i<sq+uq;i++)
	{
		queries[i][0] = 1; // Denoting Element Update
		cin >> queries[i][1] >> queries[i][2];
	}

	random_shuffle(queries.begin(),queries.end());

	for(auto x:queries)
	{
		if(x[0]) // Element Update Query
		{
			cout << "Add "<< x[1] << ' ' << x[2] << '\n';
			add(x[1],x[2]);
			for(auto e:tree)
				cout << e << ' ';
			cout << '\n';
		}
		else
			cout << "Sum "<< x[1] << ' ' << x[2] << ' ' << sum(x[2])-sum(x[1]-1)  << '\n';
	}

	return 0;
}
