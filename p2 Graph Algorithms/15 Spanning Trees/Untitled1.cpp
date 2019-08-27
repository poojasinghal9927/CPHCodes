//  Spanning Trees
/*
Spanning tree is tree over a graph with all nodes & subset of edges from graph
Weight of spanning tree is sum of edges of tree, Minimum Spanning Tree (MST)
Hecne has minimum weight sum, and it not a unique, as other graph substructures
Also, we can have maximum spanning set

Kruskal Algorithm
Initially begin with all nodes and no edges,
each edge from sorted order by weight added, if led to no cycle
Initially all nodes belong to different components,
Algorithms terminates when all components are connected
Sorting takes O(m*log(m)) time on edge list representation
for (...)
{
	if (!same(a,b)) unite(a,b);
}
One possibility is to use a to b path detection using DFS (or BFS)
O(n+m) is itself complexity and for each node, will be horribly slow
Hence we will use UNION-FIND which does both same() and unite()
in O(log(n)), hence we will have O(m*log(n)) complexity
Total complexity O(m*log(m)) + O(m*log(n))


Union Find Structure
Maintains a collection of disjoint sets, 
unite(x,y) merges two sets x and y
find(x) find out the reprsentative of set containing x
Both are O(log(n)) operations

Connect representative of smaller set, to representative of larger set
make random choice, is equal, this keeps chain length O(logn(n))



Prim's Algorithm
First add an arbitrary node to tree, then check for any new edge
which can add a node to pre-existing tree

Note: Prim�s algorithm resembles Dijkstra�s algorithm. The difference is that
Dijkstra�s algorithm always selects an edge whose distance from the starting
node is minimum, but Prim�s algorithm simply selects the minimum weight edge
that adds a new node to the tree.

Like Dijkstra, Prim's can be implemented efficiently using Priority Queue
Which will contain all nodes that can be connected using a single edge to 
present tree, minimum weight first edges are given high priority

Time Complexiy using Binary    Heap O(m*log(n))
Time Complexiy using Fibonacci Heap O(m+n*log(n)) [suggested by CLRS 3rd Ed.]

Note: Time complexity given in this books for Dijkstra & Prims are incorrect
m & n are interchanged in both formulae, & author did try to justify that :p
*/

#include<bits/stdc++.h>

using namespace std;


int n; // Number of Nodes
// adjancency list representation
map<int,vector<pair<int,int>>> adj;
//edges list reprsentation for Bellman-Ford
vector<tuple<int,int,int>> edges;

// Edges to be stored representingg MSTs
vector<tuple<int,int,int>> k_mst,p_mst;


void init_union_find()
{
	for (int i = 0; i < n; i++)
	{
		link[i] = i;
		size[i] = 1;
	}
}

int find(int x)
{
	while (x != link[x])
		x = link[x];
	return x;
}

bool same(int a, int b)
{
	return find(a) == find(b);
}

void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (size[a] < size[b])
		swap(a,b);
	size[a] += size[b];
	link[b] = a;
}

void kruskal()
{
	
}

void prims()
{
	
}

int main()
{
	int u,v,w;
	cout << "Enter number of nodes" << '\n';
	cin >> n;
	
	for(int i=0,k;i<n;i++)
	{
		adj[i] = vector<pair<int,int>> ();
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

	kruskal();
	puts("\nMST by Kruskal Algorithsm is");
	for(auto x:k_mst)
	{
		tie(u,v,w) = x;
		cout << '(' << u << ',' << v << ',' << w << ')' << '\n';
	}
	
	
	prims();
	puts("\nMST by Prim's Algorithsm is");
	for(auto x:p_mst)
	{
		tie(u,v,w) = x;
		cout << '(' << u << ',' << v << ',' << w << ')' << '\n';
	}


	return 0;
}
