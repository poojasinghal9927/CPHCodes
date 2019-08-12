// Segment Tree
/*
Dunamic version of prefix sum approach
O(log(n)) range query and element update

Note1: Much general Data structure, can solve any divisible & merge query like SUM, MIN, MAX< GCD
Note2: 0 based indexing from user end, 1 empty position at begining due to n-1 leaf nodes

*/
#include<bits/stdc++.h>

using namespace std;


vector<int> tree;

int sum(int a, int b)
{
	a += tree.size()/2; b += tree.size()/2;
	int s = 0;
	while (a <= b)
	{
		if (a%2 == 1) s += tree[a++];
		if (b%2 == 0) s += tree[b--];
		a /= 2; b /= 2;
	}
	return s;
}

void add(int k, int x)
{
	k += tree.size()/2;
	tree[k] += x;
	for (k /= 2; k >= 1; k /= 2)
	{
	tree[k] = tree[2*k]+tree[2*k+1];
	}
}

int main()
{
	int n,sq,uq,temp;
	cout << "Enter length of Array\nNumber of Range Sum Queries\nNumber of Element Updates" << '\n';
	cin >> n >> sq >> uq;
	
	// Creating tree to be power of 2, aso double of that, if n is 7, we create 16 
	for(int i=0;i<(1<<(((int)ceil(log2(n)))+1));i++)
		tree.push_back(0);

	// Initializing Dynamic 2D vector
	vector<vector<int>> queries(sq+uq,vector<int>(3,0));
	
	cout << "Enter Elements of Array" << '\n';
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		add(i,temp);
	}

	cout << "Initial Segment Tree" << '\n';
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
			cout << "Sum "<< x[1] << ' ' << x[2] << ' ' << sum(x[1],x[2])  << '\n';
	}

	return 0;
}
