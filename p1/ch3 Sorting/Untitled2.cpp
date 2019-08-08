// Sorting in C++
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n = 7; // Array size
	int a[] = {4,2,5,3,5,8,3};
	// Sorting in Ascending Order
	sort(a,a+n); // Passing Pointers for array to sort
	// Sorting in Descending Order
	sort(a+n-1,a-1); // Passing Pointers for array to sort


	vector<int> v = {4,2,5,3,5,8,3};	
	// Sorting in Ascending Order
	sort(v.begin(),v.end()); //Passing iterators (kind of pointers)
	// Sorting in Descending Order, see 
	sort(v.rbegin(),v.rend());
	
	
	// Sorting a string, might be you'll see some application sometime
	string s = "monkey";
	sort(s.begin(), s.end()); //Strings also have iterators, will see them soon


	// Comparison Operator is needed and is in-built for most datatypes
	vector<tuple<int,int,int>> v2;
	v2.push_back({2,1,4});
	v2.push_back({1,5,3});
	v2.push_back({2,1,3});
	sort(v2.begin(), v2.end());
	// Sorted on 1st, 2nd, 3rd respectively, order of the tuples is (1,5,3), (2,1,3) and (2,1,4)


	// User defined structs and their sorting
	struct P
	{
		int x, y;
		// To be defined as "operator<" function (hey we can have functions also in structures, also in C)
		bool operator<(const P &p)
		{ // has to return TRUE is x<=y , this <= operatos is what we are defining in this function
			if (x != p.x)
				return x < p.x;
			else
				return y < p.y;
		}
	};

	
	// Custom comparision operator, which can be passed
	bool comp(string a, string b)
	{
		if (a.size() != b.size())
			return a.size() < b.size();
		return a < b; // we don't need an ELSE, as reachable only IF doesn't execute
	}
	// Below line can sort vector of strings if created in variable vs
	// sort(vs.begin(), vs.end(), comp);
	
	
	return 0;
}
