// Generating Permutations
#include<bits/stdc++.h>

using namespace std;

int n=3;
vector<int> permutation;
vector<bool> chosen(n,false);

void search()
{// Method 1: Recursion to use each element or not
	if (permutation.size() == n)
	{
		// process permutation
		for(int i:permutation)
			cout << i << ' ';
		puts("");  // Just printing a new line
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (chosen[i])
				continue;
			chosen[i] = true;
			permutation.push_back(i);
			search();
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}


int main()
{
	puts("Method 1");
	// Calling Method 1
	search();// Search begins when 1st called with no parameters


	puts("Method 2");
	// Method 2: permuting in-built vector
	vector<int> permutation;
	for (int i = 0; i < n; i++)
	{
		permutation.push_back(i);
	}
	// Also, try if can permute random ordered strings(NO, will miss starting ones, as generate next)
	//vector<string> permutation {"DATA","ALSO","ENGG"};
	do{
		// process permutation
		for(int i:permutation)
			cout << i << ' ';
		puts("");  // Just printing a new line
	}while (next_permutation(permutation.begin(),permutation.end()));


	return 0;
}
