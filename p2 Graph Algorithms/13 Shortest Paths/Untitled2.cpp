// Shortest Paths
/*
Floyd Warshall Algorithm
*/

#include<bits/stdc++.h>

using namespace std;

int n; // Number of Nodes
// DS where distances will be stored
vector<vector<int>> source_distance;
// adjancency list representation
map<int,map<int,int>> adj;


void floyd_warshall()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				source_distance[i][j] = 0;
			else if (adj[i].count(j))
				source_distance[i][j] = adj[i][j];
			else
				source_distance[i][j] = INFINITY;
		}
	// o(n**3) time complexity comes from this loop
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				source_distance[i][j] = min( source_distance[i][j], source_distance[i][k]+source_distance[k][j] );
 }

int main()
{
	cout << "Enter number of nodes" << '\n';
	cin >> n;

	for(int i=0;i<n;i++)
	{
		source_distance.push_back(vector<int>(n,0));
		adj[i] = map<int,int> ();
	}

	for(int i=0,k;i<n;i++)
	{
		cout << "Enter |Edges| from " << i << '\n';
		cin >> k;
		cout << "Enter " << k << " edges" << '\n';
		for(int j=0,t,w;j<k;j++)
		{
			cin >> t >> w;
			adj[i][t] = w ;
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


	floyd_warshall();

	puts("Distance Matrix After Floyd-Warshall");
	for (int i = 0; i < n; printf("\n"),i++)
		for (int j = 0; j < n; printf(" "),j++)
			cout << source_distance[i][j];

	return 0;
}
