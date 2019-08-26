// Shortest Paths
/*
This will will provdie code of Bellman Ford & Dijkstra Algorithm
Another will have floyd warshall algorithm
*/

#include<bits/stdc++.h>

using namespace std;

int n; // Number of Nodes
// DS where distances will be stored
vector<int> source_distance;
// To be used by Dijkstra Algorithm
vector<bool> processed;
// adjancency list representation
map<int,vector<pair<int,int>>> adj;
//edges list reprsentation for Bellman-Ford
vector<tuple<int,int,int>> edges;


void bellman_ford(int x)
{
	// Edge List representation assumed
	for (int i = 0; i < n; i++)
		source_distance[i] = INFINITY;
	source_distance[x] = 0;

	// (n-1) rounds as maximum length cycle of n nodes
	for (int i = 0; i < n-1; i++)
	{
		for (auto e : edges)
		{
			int a, b, w;
			tie(a, b, w) = e;
			source_distance[b] = min(source_distance[b], source_distance[a]+w);
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
		source_distance[i] = INFINITY;
	source_distance[x] = 0;
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
			if (source_distance[a]+w < source_distance[b])
			{
				source_distance[b] = source_distance[a]+w;
				q.push({-source_distance[b],b});
			}
		}
	}
	/*
	Complexity is O(m + n*log(n)), as each edge is processed once only
	Note: This book has swapped m & n, and tried to justify that :p
	*/
}

int main()
{
	cout << "Enter number of nodes" << '\n';
	cin >> n;

	for(int i=0;i<n;i++)
		source_distance.push_back(0);
	
	for(int i=0;i<n;i++)
	{
		processed.push_back(false);
		adj[i] = vector<pair<int,int>> ();
	}


	for(int i=0,k;i<n;i++)
	{
		cout << "Enter |Edges| from " << i << '\n';
		cin >> k;
		cout << "Enter " << k << " edges" << '\n';
		for(int j=0,t,w;j<k;j++)
		{
			cin >> t >> w;
			adj[i].push_back(make_pair(t,w));
			edges.push_back(make_tuple(i,t,w));
		}
	}
	
	puts("Adjaceny List is as follows");
	for(int i=0;i<n;i++)
	{
		cout << i << " : ";
		for(auto x:adj[i])
			cout << '(' << x.first << ',' << x.second << ')' << ' ';
		cout << '\n';
	}


	// Bellman-Ford Example
	bellman_ford(0);
	puts("\n\nBellman-Ford source_distance");
	for(int i=0;i<n;i++)
		cout << i << ',' << source_distance[i] << ' ';		

	// Dijkstra Example
	for(int i=0;i<n;i++)
		processed[i] = false;
	dijkstra(0);
	puts("\n\nBellman-Ford source_distance");
	for(int i=0;i<n;i++)
		cout << i << ',' << source_distance[i] << ' ';


	return 0;
}
