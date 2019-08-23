// Shortest Paths
/*
Floyd Warshall Algorithm
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


void floyd_warshall(int x)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				distance[i][j] = 0;
			else if (adj[i][j])
				distance[i][j] = adj[i][j];
			else
				distance[i][j] = INFINITY;
		}
	// o(n**3) time complexity comes from this loop
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				distance[i][j] = min( distance[i][j], distance[i][k]+distance[k][j] );
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
