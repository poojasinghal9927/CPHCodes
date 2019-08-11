// Coin exchange problem
#include<bits/stdc++.h>

using namespace std;

int n,val;
vector<int> coins;
unordered_map<int,int> memo;

int f(int present_val)
{
	// Not reached by recursion, but if user ask to build 0 value
	if(!present_val) 
		return present_val;

	if(memo.count(present_val))
	{
		;
	}
	else
	{
		//This is Macro defined internally
		int min_coins_needed = INFINITY;

		for(int coin:coins)
		{ // Try all coins
			if(coin<=present_val)
			min_coins_needed = min( min_coins_needed , 1+((coin<present_val)?(f(present_val-coin)):(0)) );
		}
		memo[present_val] = min_coins_needed ;
	}
	return memo[present_val];
	
}

int main()
{
	cout  << "Enter Number of Coins" << '\n';
	cin >> n ;
	cout  << "Enter Values of Coins" << '\n';
	for(int i=0,temp;i<n;i++)
	{
		
		cin >> temp;
		coins.push_back(temp);
	}
		
	cout  << "Enter Value to produce" << '\n';
	cin >> val ;

	f(val);

	cout  << "Minimum Coins Needed is " << memo[val] << '\n';
	
	
	return 0;
}
