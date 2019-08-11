// C++ Search functions based on Binary Search with assumption that data is sorted

/*
The C++ standard library contains the following functions that are based on
binary search and work in logarithmic time:
	• lower_bound
		returns a pointer to the first array element whose value is at least x.
	• upper_bound
		returns a pointer to the first array element whose value is larger than x.
	• equal_range
		returns both above pointers.

If there is no such element, the pointer points to the element after the last array element.
*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
	int array[] = {2,3,3,4,5,5,8};
	int n = 7 ;
	
	for(int x:array)
		cout << x << ' ' ;

	auto k1 = lower_bound(array,array+n,3)-array;
	auto k2 = lower_bound(array,array+n,6)-array;
	cout << "\n lower_bound of " << 3 << " is " <<array[k1] ;
	cout << "\n lower_bound of " << 6 << " is " <<array[k2] ;

	auto k3 = upper_bound(array,array+n,3)-array;
	auto k4 = upper_bound(array,array+n,6)-array;
	cout << "\n upper_bound of " << 3 << " is " <<array[k3] ;
	cout << "\n upper_bound of " << 6 << " is " <<array[k4] ;

	
	// Finding Frequency(Number of occurence) of element x
	int x = 6; // does occur in array

	auto k = lower_bound(array,array+n,x)-array;
	if (k < n && array[k] == x)
	{
		// x found at index k
		auto a = lower_bound(array, array+n, x);
		auto b = upper_bound(array, array+n, x);
		cout << "\n\nFrequency of element is " << b-a << '\n';
	}
	else
		cout << "\n\nFrequency of element is " << 0 << '\n';

	// Shortest Code for finding frequency of an element, after sorting
	auto r = equal_range(array, array+n, x);
	cout << "\nFrequency from Shorter Code is " << r.second-r.first << "\n";
	
	
	return 0;
}
