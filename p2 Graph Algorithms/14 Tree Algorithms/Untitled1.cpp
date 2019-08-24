// Tree Algorithms
/*
Tree is a graph with n-1 edges, such that
removal of any edge makes graph disconnected
adding any edge does introduces a cycle
always exist a unique path between any two nodes

Leaves are nodes with degree one, also for a rooted
tree there exist a root with no parent, and comes parent-child relationship
*/

#include<bits/stdc++.h>

using namespace std;

void dfs(int cur, int prev)
{
	// process node s
	for (auto u : adj[cur)
	{
		if (u != prev)
			dfs(u, cur);
	}
}


void dfs(int s, int e)
{ // Counting Number of Nodes in any subtree using DP O(n)
	count[s] = 1;
	for (auto u : adj[s])
	{
		if (u == e)
			continue;
		dfs(u, s);
		count[s] += count[u];
	}
}


int diameter(int method)
{ // Maximum Length of path between two nodes

	if(method==1)
	{
		/*
		Maintaining two variables during search
		• toLeaf(x):    Maximum length of a path from x to any leaf
		• maxLength(x): Maximum length of a path whose highest point is x
		maxLength(x) = max(toLeaf(a)+toLeaf(b)) over any two childs of x
		*/
	}
	else if(method==2)
	{
		/*
		Starts a DFS from a arbitrary vertex a, and get farthest vertex b
		Start another DFS from b, and get farthest c, diameter(Tree) = dis(b,c)
		*/
	}
}


int all_longest_paths()
{
	
}

int main()
{
	//Initial Function Call
	dfs(root,0);

	return 0;
}
