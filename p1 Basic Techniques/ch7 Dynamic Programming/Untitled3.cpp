// Longest Common Subsequence (Bottom-Up standard version)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	string L1,L2,L3;

	cout << "Enter two string" << '\n';

	getline(cin,L1);
	getline(cin,L2);

	cout << L1 << '\n' << L2 << '\n';
	
	int array[L1.size()+1][L2.size()+1];
	for( int i=0 ; i<L2.size()+1 ; i++ )
		array[0][i] = 0;
	for( int i=0 ; i<L1.size()+1 ; i++ )
		array[i][0] = 0;
	
	for(int i=1;i<L1.size()+1;i++)
		for(int j=1;j<L2.size()+1;j++)
		{
			if( L1[i-1]==L2[j-1] )
			{
				array[i][j] = 1 + array[i-1][j-1];
				L3.push_back(L1[i-1]);
			}
			else
			{
				array[i][j] = max(array[i-1][j],array[i][j-1]);
			}
		}

	cout << "Length of Longest Common Subsequence is "<< array[L1.size()][L2.size()] << '\n';
	return 0;
}
