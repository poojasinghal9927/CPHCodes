// Sub-array Sum
/*
Given ARRAY of positive integers, and SUM to obtain in any subarray
Find out from where to where it does exist as subarray, using two-pointer

Sol: subarray of interval index [i,j], now j is incremented until val>=sum
if val exceed sum, then i is incremented, hence each pointer can move right only
complexity if O(n)l yipee linear
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

	int i=0,j=0,val = array[0];
	while(1)
	{
		if(val==sum)
		{
			cout << "Desired Sum Value range " << i << ',' << j <<'\n';
			for(int k2=i;k2<=j;k2++)
				cout << array[k2] << ' ';
			cout << '\n';
		}

		if(j+1==n)
			break;

		val = val+array[j+1];
		j = j+1;

		while(1)
		{
			if((val>=sum)||(j+1==n))
				break;
			val = val+array[j+1];
			j =  j+1;
		}

		while(1)
		{
			if(val<=sum)
				break;
			if(i<=j)
			{
				val = val-array[i];
				i = i+1;				
			}
		}
	}

	return 0;
}
