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

Note: Prim’s algorithm resembles Dijkstra’s algorithm. The difference is that
Dijkstra’s algorithm always selects an edge whose distance from the starting
node is minimum, but Prim’s algorithm simply selects the minimum weight edge
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
// for Union find
vector<int> link, size;
//edges list reprsentation for Kruskal
vector<tuple<int,int,int>> edges;
// vector for taken in major component by prims
vector<bool> taken;
// Edges to be stored representingg MSTs
vector<tuple<int,int,int>> k_mst,p_mst;


void init_union_find()
{
	for (int i = 0; i < n; i++)
	{
		link.push_back(i);
		size.push_back(1);
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

int unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (size[a] < size[b])
		swap(a,b);
	size[a] += size[b];
	link[b] = a;
	return a;
}

bool edge_comp(tuple<int,int,int> a, tuple<int,int,int> b)
{
	return get<2>(a) < get<2>(b);
}


void kruskal()
{
	int u,v,w;
	sort(edges.begin(),edges.end(),edge_comp);
	for(auto x:edges)
	{ //Iterate over all edges sorted in ascending order of weights
		tie(u,v,w)=x;
		if(!same(u,v))
		{ // if both are from different components, use edge
			int top = unite(u,v);
			k_mst.push_back(x);
			if(size[top]==n)
			{ // If everything is in one component
				break;
			}
			
		}
	}
}

void prims()
{
	int u,v,w,component_size = 1;
	taken[0] = true;
	priority_queue<tuple<int,int,int>> pq;
	for(auto x:adj[0]) // (w,u,v) for pq storage
		pq.push(make_tuple(-1*x.second,0,x.first));
	
	while(1)
	{
		tie(w,u,v) = pq.top();
		cout << '(' << -1*w << ',' << u << ',' << v << ')' << '\n';
		pq.pop();
		if( (taken[u]) && (!taken[v]) )
		{ // if v is not in present component already
			taken[v] = true;
			puts("taken");
			component_size += 1;
			p_mst.push_back(make_tuple(u,v,-1*w));
			for(auto x:adj[v]) // (w,u,v) for pq storage
				if(!taken[x.first])
					pq.push(make_tuple(-1*x.second,v,x.first));
		}
		if(component_size==n)
			break;
	}
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

	init_union_find();
	kruskal();
	puts("\nMST by Kruskal Algorithm is");
	for(auto x:k_mst)
	{
		tie(u,v,w) = x;
		cout << '(' << u << ',' << v << ',' << w << ')' << '\n';
	}
	
	for(int i=0;i<n;i++)
		taken.push_back(false);
	prims();
	puts("\nMST by Prim's Algorithm is");
	for(auto x:p_mst)
	{
		tie(u,v,w) = x;
		cout << '(' << u << ',' << v << ',' << w << ')' << '\n';
	}


	return 0;
}
