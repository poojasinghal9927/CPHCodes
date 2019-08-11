// 2-Sum problem
/*
Given an ARRAY, can we find two elements, such that a[i]+a[j]==SUM, which is give

Sol: sort array first, then start one pointer from left & other from right
Note: in below two while loops, change either or < OR > with <= OR >= respectively
Observe results on having multiple answers, change both, it'll go in INFINITE loop
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,sum;
	
	cout << "Enter Length of Array" << '\n';
	cin >> n;
	
	int array[n];
	cout << "Enter Array Elements" << '\n';
	for(int i=0;i<n;i++)
		cin >> array[i];
	
	cout << "Enter Sum Value to be constructed" << '\n';
	cin >> sum;
	
	// Sorting makes life easier here
	sort(array,array+n);

	int l=0,r=n-1;
	while(l<r)
	{
		if (array[l] + array[r] == sum) 
        	break; 
        else if (array[l] + array[r] < sum) 
            l++; 
        else // array[i] + array[j] > sum 
            r--; 
	}
	if(array[l]+array[r]==sum)
		cout << "2 SUM at index " << l << ' ' << r << '\n';
	else
		cout << "2 SUM doesn't exist'" << '\n';

	return 0;
}
