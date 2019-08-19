// Graph Traversals
/*
Discussed for unweighted graphs, given a starting node, will visit possible all nodes

Depth First Search (DFS)
Follows a single path in graph as long as more nodes can be found on it
After which it returns to previous node & find if more can be visited
it also, keep track of visited nodes, so that each node be traversed only once

Breadth First Search (BFS)
Visits nodes in increasing order of level_difference from starting node
BFS is more complicated to implement than DFS, as nodes in different parts are traversed
Typical uses a Queue, 


Both algorithms have O(m+n) time complexity

Applications
Many properties can be checked using both DFS & BFS, prefer DFS in that case

1. Connectivity or Components finding, if all can be traversed using DFS

2. Cycle detection, DFS can be used, if next node,
is already on current path (for directed graphs)
is already visited node    (for undirected graphs)

3. Bipartite, coloring on the go, & checking for different colors whenever adjacent
for bipartite(2-color) we find k=2, for k=3 and beyond, problem is NP-Hard


*/

#include<bits/stdc++.h>

using namespace std;


map<int,vector<int>> adj;
vector<bool> visited;
vector<int> level_difference;
vector<int> bfs_order, dfs_order;

// Data Structure for BFS
queue<int> q;


void dfs(int s)
{
	if (visited[s])
		return;
	visited[s] = true;
	dfs_order.push_back(s);
	// process node s
	for (auto u: adj[s])
	{
		dfs(u);
	}
}

void bfs(int x)
{
	visited[x] = true;
	bfs_order.push_back(x);
	level_difference[x] = 0;
	q.push(x);
	while (!q.empty())
	{
		int s = q.front(); q.pop();
		// process node s
		for (auto u : adj[s])
		{
			if (visited[u])
				continue;
			visited[u] = true;
			bfs_order.push_back(u);
			level_difference[u] = level_difference[s]+1;
			q.push(u);
		}
	}
}


int main()
{
	
	int N;

	cout << "Enter number of vertices" << '\n';
	cin >> N;

	for(int i=0;i<N;i++)
	{
		visited.push_back(false);
		level_difference.push_back(0);
		adj[i] = vector<int> ();
	}
	
	for(int i=0,n;i<N;i++)
	{
		cout << "Enter |Edges| from " << i << '\n';
		cin >> n;
		cout << "Enter " << n << " nodes" << '\n';
		for(int j=0,t;j<n;j++)
		{
			cin >> t;
			adj[i].push_back(t);
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
	
	// DFS Example
	for(int i=0;i<N;i++)
		visited[i] = false;
	dfs(0);
	puts("\n\nDFS order of traversal");
	for(auto x:dfs_order)
		cout << x << ' ';


	// BFS Example
	for(int i=0;i<N;i++)
		visited[i] = false;
	bfs(0);
	puts("\n\nBFS order,distance of traversal");
	for(auto x:bfs_order)
	{
		cout << x << ',' << level_difference[x] << ' ';
	}
		


	return 0;
}
