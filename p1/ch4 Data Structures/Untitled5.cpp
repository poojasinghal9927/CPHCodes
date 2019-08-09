// Iterators & Ranges
/*
An iterator is a variable that points to an element in a data structure

Check difference with pointers (iterator can walk a non-contiguous collection)
https://stackoverflow.com/questions/31128055/what-is-difference-between-iterators-and-pointers
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	// Range defined by iterator is half open, .end() is one outside of DS
	random_shuffle(v.begin(), v.end());
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	// Accesing element via iterator
	set<int>s = {2,3,3,5,6,6,8};
	set<int>::iterator it = s.begin(); //initialized to smallest element of set
	// auto it = s.begin(); //Another way of declaring, let C++ decide the type
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << "\n";
	it = s.end(); it--; // After this, it is at largest element of set
	
	// Following code finds the element nearest to x
	auto it = s.lower_bound(x);
	if (it == s.begin())
	{
		cout << *it << "\n";
	}
	else if (it == s.end())
	{
		it--;
		cout << *it << "\n";
	}
	else
	{ // Element nearest to x is either element that corresponds to it or previous element
		int a = *it; it--;
		int b = *it;
		if (x-b < a-x)
			cout << b << "\n";
		else
			cout << a << "\n";
	}
	
	return 0;
}
