// Dynamic Programming

#include<bits/stdc++.h>

using namespace std;


int min_price(int **price, int n, int k)
{	/*
	Finding minimum total price of items, when only one can be brought on a given day
	Prices of each on each day is given, buy all and find minimum total price
	price has dimensions of rows contains items, columns as days
	
	total(S,d) = min( total(S,d-1), for all x in S min( (total(S \ x,d-1)+price[x][d]) )
	*/
	for (int x = 0; x < k; x++)
	{ // inital first day entries
		total[1<<x][0] = price[x][0];
	}
	for (int d = 1; d < n; d++)
	{
		for (int s = 0; s < (1<<k); s++)
		{
			total[s][d] = total[s][d-1];
			for (int x = 0; x < k; x++)
			{
				if (s&(1<<x))
				{
					total[s][d] = min(total[s][d],
					total[s^(1<<x)][d-1]+price[x][d]);
				}
			}
		}
	}
	return total[(1<<k)-1][d-1];
}


int main()
{
	return 0;
}
