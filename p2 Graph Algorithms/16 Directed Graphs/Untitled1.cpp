// Directed Graphs
/*
We will discuss
Acyclic Graphs  : 
Successor Graph : 
*/

#include<bits/stdc++.h>

using namespace std;

// adjancency list representation
map<int,vector<int>> adj;
vector<int> visited;
vector<int> dfs_order;

bool dfs(int s)
{
	bool exist=1;
	if (visited[s])
	{
		//puts("IF");
		exist = ((visited[s]==1)?false:true);
		//cout << s << ' ' << visited[s] << ' ' << exist << '\n';
	}
	else
	{
		//puts("ELSE");
		visited[s] = 1;
		//cout << s << ' ' << visited[s] << ' ' << exist << '\n';
		// process node s
		for (auto u: adj[s])
		{
			exist = (!dfs(u))?false:exist;
			//cout << u << ' ' << visited[u] << ' ' << exist << '\n';
		}
		visited[s] = 2;
		//cout << s << ' ' << visited[s] << ' ' << exist << '\n';
		dfs_order.push_back(s);
	}
	return exist;
}

int main()
{
	int N;

	cout << "Enter number of vertices" << '\n';
	cin >> N;

	for(int i=0;i<N;i++)
	{
		visited.push_back(0);
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
	bool top_exist=true;
	for(int i=0;i<N;i++)
		if(!visited[i])
			top_exist = dfs(i);
	if(top_exist)
	{
		puts("\n\nTopolocgial sort order");
		for( auto x=dfs_order.rbegin() ; x!=dfs_order.rend() ; x++ )
			cout << *x << ' ';
	}
	else
		puts("\n\nNO Topolocgial order exist");

	return 0;
}
