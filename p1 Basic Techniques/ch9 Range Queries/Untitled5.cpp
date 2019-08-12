// Min, Max on static array

/*
O(n*log(n)) pre-processing, after which O(1) time query answer

minq(a,b) = min(minq(a,a+w-1),minq(a+w,b)),
w = (b-a+1)/2

Note: formula for w in code is much improved & expressive that what author does
*/
#include<bits/stdc++.h>

using namespace std;

map<pair<int,int>,int> sparse_table;

int range_min(int a,int b)
{
	int w;
	if(a==b)
		return sparse_table[make_pair(a,b)];
	w = 1<<(((int)ceil(log2(b-a+1)))-1);
	return min(sparse_table[make_pair(a,a+w-1)],sparse_table[make_pair(b-w+1,b)]);
}

void build_sparse_table(vector<int> array)
{
	int min_width=1,max_width = ceil(log2(array.size()));
	int width;

	// Making Vector Size Exact power of 2
	for(int i=array.size();i<(1<<max_width);i++)
		array.push_back(INFINITY);
		
	// Creating Trivial Entries in Map
	for(int i=0;i<array.size();i++)
		sparse_table[make_pair(i,i)] = array[i];
	
	for(int i=min_width;i<=max_width;i++)
	{
		width = 1<<i;
		for(int j=0;j+width<=array.size();j++)
			sparse_table[make_pair(j,j+width-1)] = range_min(j,j+width-1);
	}
}

int main()
{
	int i,n,q;
	
	cout << "Enter length of array N, and number of queries Q" << '\n';
	cin >> n >> q;

	vector<int> array(n);
	vector<pair<int,int>> queries(q);

	cout << "Enter array elements" << '\n';
	for(i=0;i<n;i++)
		cin >> array[i];

	build_sparse_table(array);

	cout << "Enter queries" << '\n';
	for(i=0;i<q;i++)
		cin >> queries[i].first >> queries[i].second;
	/*
	cout << "Sparse Table Itself" << '\n';
	for(auto x:sparse_table)
		cout << x.first.first << ' ' << x.first.second << ' ' << x.second << '\n';
	*/
	cout << "Minimum Values from Queries" << '\n';
	for(auto x:queries)
		cout << x.first << ' ' << x.second << ' ' << range_min(x.first,x.second) << '\n';	


	return 0;
}
