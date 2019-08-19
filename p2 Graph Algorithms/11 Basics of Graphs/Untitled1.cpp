// Basics of Graphs
/*
n be number of nodes/vertices
m be number of edges

"path" from a to b, is sequence of edges form a to b, through graph edges
"length" of path is number of edges in it
"cycle" if first & last node is same
"simple" path in which each node appears only once

Connectivity

"connected"  is path between any two nodes
"component"  is each connected part of graph
"tree"       is connected graph, with unique path between any two nodes & n-1 edges
"directed"   egde can be traversed in only one direction
"weighted"   edge has weight for each edge
"shortest"   path has minimum weight, or length for un-weighted graph
"neighbors"  or "adjacent" nodes have edges between them
"degree"     is number of edges adjacent to node, in & out degree
Sum of degree is always even, as each edge contributes two sides
"regular"    graph has constant degree for each node, complete if n-1
"coloring"   is assignment of color, such that no adjacent nodes has same color
"bipartitie" if possible to color with 2 color, no odd length cycle
"simple"     graph has no self loops & multiple edges
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N = 5;
	
	// Directed unweighted Adjacency Representation
	vector<int> duw_adj[N];
	duw_adj[1].push_back(2);
	duw_adj[2].push_back(3);
	duw_adj[2].push_back(4);
	duw_adj[3].push_back(4);
	duw_adj[4].push_back(1);

	// Undirected Unweighted Adjacency Representation
	vector<int> uuw_adj[N];
	uuw_adj[1].push_back(2); uuw_adj[2].push_back(1);
	uuw_adj[2].push_back(3); uuw_adj[3].push_back(2);
	uuw_adj[2].push_back(4); uuw_adj[4].push_back(2);
	uuw_adj[3].push_back(4); uuw_adj[4].push_back(3);
	uuw_adj[4].push_back(1); uuw_adj[1].push_back(4);


	// Directed Weighted Adjacency Representation
	vector<pair<int,int>> dw_adj[N];
	dw_adj[1].push_back(make_pair(2,5));
	dw_adj[2].push_back(make_pair(3,7));
	dw_adj[2].push_back(make_pair(4,6));
	dw_adj[3].push_back(make_pair(4,5));
	dw_adj[4].push_back(make_pair(1,2));
	
	// Traversing Edges adjacent only from node s
	for (auto u : adj[s])
	{
		// process node u
	}


	// Adjacency Matrix on other hand require N**2 space
	int adj[N][N];
	
	
	// Edge List representation, if edges from each vertex doesn't matter, but edges has to be processed
	vector<pair<int,int>> edges; // For Unweighted graph
	edges.push_back(make_pair(1,2));
	edges.push_back(make_pair(2,3));
	edges.push_back(make_pair(2,4));
	edges.push_back(make_pair(3,4));
	edges.push_back(make_pair(4,1));
	
	return 0;
}
