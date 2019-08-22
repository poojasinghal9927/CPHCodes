// Shortest Paths
/*
*/

#include<bits/stdc++.h>

using namespace std;

int n;

// adjancency list representation
map<int,vector<int>> adj;
vector<bool> processed;
vector<tuple<int,int,int>> edges; //edges list reprsentation


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
	// Default version of Priority queue finds maximum, hence -ve used
	priority_queue<pair<int,int>> q;
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
	/*
	Complexity is O(m + n*log(n)), as each edge is processed once only
	*/
}

int main()
{
	cout << "Enter number of nodes" << '\n';
	cin >> n;
	for(int i=0;i<n;i++)
		distance.push_back(0);
	
	for(int i=0;i<N;i++)
	{
		visited.push_back(false);
		adj[i] = vector<int> ();
	}


	for(int i=0,n;i<N;i++)
	{
		cout << "Enter |Edges| from " << i << '\n';
		cin >> n;
		cout << "Enter " << n << " nodes" << '\n';
		for(int j=0,t,w;j<n;j++)
		{
			cin >> t >> w;
			adj[i].push_back(t);
			edges.push_back(make_tuple(i,t,w));
		}
	}
	
	puts("Adjaceny List is as follows");
	for(int i=0;i<N;i++)
	{
		cout << i << " : ";
		for(auto x:adj[i])
			cout << x << ' ';
		cout << '\n';
	}

	return 0;
}
