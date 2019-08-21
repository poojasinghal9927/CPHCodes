// Shortest Paths
/*
*/

#include<bits/stdc++.h>

using namespace std;


void bellman_ford(int x)
{
	// Edge List representation assumed
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
	/*
	Note: an improvement to bellmann ford (SPFA), you can use a queue
	to place target of the relax edges in that queue, next time	edges
	starting from those target vertices should be tried for	relaxation,
	not all vertices.
	Worst case will still be O(m*n)
	*/
}

void dijkstra(int x)
{
	queue<pair<int,int>> q;
	// Adjacency list representation a -> [(b,w),] assumed
	for (int i = 0; i < n; i++)
		distance[i] = INF;
	distance[x] = 0;
	q.push(make_pair(0,x));
	while (!q.empty())
	{
		int a = q.top().second; q.pop();
		if (processed[a])
			continue;
		processed[a] = true;
		for (auto u : adj[a])
		{
			int b = u.first, w = u.second;
			if (distance[a]+w < distance[b])
			{
				distance[b] = distance[a]+w;
				q.push({-distance[b],b});
			}
		}
	}
}

int main()
{
	return 0;
}
