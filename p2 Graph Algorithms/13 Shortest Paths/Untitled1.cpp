// Shortest Paths
/*
*/

#include<bits/stdc++.h>

using namespace std;


void bellman_ford(int x)
{
	for (int i = 0; i < n; i++)
		distance[i] = INF;
	distance[x] = 0;

	// (n-1) rounds as maximum length cycle of n nodes
	for (int i = 0; i < n-1; i++)
	{
		for (auto e : edges)
		{
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a]+w);
		}
	}
}

int main()
{
	return 0;
}
