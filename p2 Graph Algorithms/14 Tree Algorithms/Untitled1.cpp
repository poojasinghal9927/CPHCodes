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

// Number of Nodes in Tree
int n,root,dia;
// Adjancency list representation
map<int,vector<int>> adj;
// Generic my_count vector used in many algorithms below
vector<int> my_count;


void reset_count()
{
	for(int i=0;i<n;i++)
		my_count[i] = 0;
}

void print_count()
{
	for(auto x:my_count)
		cout << x << ' ';
	cout << '\n';
}

void dfs(int cur, int prev)
{
	// process node s
	for (auto u : adj[cur])
	{
		if (u != prev)
			dfs(u, cur);
	}
}


void dfs_node_count(int cur, int prev)
{ // Counting Number of Nodes in any subtree using DP O(n)
	my_count[cur] = 1;
	for (auto u : adj[cur])
	{
		if (u == prev)
			continue;
		dfs(u, cur);
		my_count[cur] += my_count[u];
	}
}


void diameter(int cur, int prev, int method)
{ // Maximum Length of path between two nodes

	if(method==1)
	{
		/*
		Maintaining two variables during search
		• toLeaf(x):    Maximum length of a path from x to any leaf
		• maxLength(x): Maximum length of a path whose highest point is x
		maxLength(x) = max(toLeaf(a)+toLeaf(b)) over any two childs of x
		*/
		int toLeaf = -1;
		for (auto u : adj[cur])
		{	
			if (u == prev)
				continue;
			diameter(u, cur, method);
			toLeaf = max(toLeaf,my_count[u]);
		}
		my_count[cur] = toLeaf + 1;
	}
	else if(method==2)
	{
		/*
		Starts a DFS from a arbitrary vertex a, and get farthest vertex b
		Start another DFS from b, and get farthest c, diameter(Tree) = dis(b,c)
		*/
		for (auto u : adj[cur])
		{	
			if (u == prev)
				continue;
			my_count[u] = my_count[cur] + 1;
			diameter(u, cur, method);
		}
	}
}


void all_longest_paths(int cur, int prev)
{ // Length of longest path, that begins from each node
	/*
	Generalization of Diameter problem
	which is max of array to be computed from this problem
	
	This Method in book is doubtful & present implementation is incorrect
	
	*/
	int toLeaf = -1;
	for (auto u : adj[cur])
	{	
		if (u == prev)
			continue;
		all_longest_paths(u, cur);
		toLeaf = max(toLeaf,my_count[u]);
	}
	my_count[cur] = toLeaf + 1;
	// preprocessing after toLeaf computation

	if(cur==root)
	{
		// Queue for BFS
		queue<pair<int,int>> q;
		q.push(make_pair(root,root));
		// root_best_second_best_storage childs with toLeaf values
		map<int,pair<pair<int,int>,pair<int,int>>> rbsbs;
		// Map for finding parents
		map<int,int> parent;
		while(!q.empty())
		{
			// Processing Parents to Create Final Array
			auto front = q.front();
			cout << front.first << '\n';
			if( front.first != root )
			{// Nothing to be done for Root of Entire Tree
				pair<int,int> first_best , second_best;
				parent[front.first] = front.second;
				if(rbsbs.count(front.second))
				{ // entry Exists in map already	
					first_best  = rbsbs[front.second].first;
					second_best = rbsbs[front.second].second;
				}
				else
				{
					first_best  = make_pair(root,-1);
					second_best = make_pair(root,-1);
					for(auto x:adj[front.second])
					{
						if(x!=parent[front.second])
						{
							if(my_count[x] > first_best.second)
							{
								second_best = first_best;
								first_best = make_pair(x,my_count[x]);
							}
							else if(my_count[x] > second_best.second )
							{
								second_best = make_pair(x,my_count[x]);
							}
						}
					}
					rbsbs[front.second] = make_pair(first_best, second_best);
				}
				if(second_best.first!=root)
				{ // There exist more than one best element from parent
					if(front.first==first_best.first)
					{ // best goes from present element, use entry of second best
						my_count[front.first] += (second_best.second+1);
						puts("front.first == first_best.first");
					}
					else
					{ // best if not from present element & hence can be used directly
						my_count[front.first] += (first_best.second+1);
						puts("front.first != first_best.first");
					}
				}
				else
				{ // Either Longest path is below cur, if no path, then only
					my_count[front.first] = max(my_count[front.first],1);
					puts("second_best.first == root");
				}
			}
			
			// Adding Childs of present node to queue
			for(auto x:adj[front.first])
				if( x != front.second )
					q.push(make_pair(x,front.first));
			q.pop();
		}
	}
}

int main()
{	
	cout << "Enter number of vertices" << '\n';
	cin >> n;

	for(int i=0;i<n;i++)
	{
		my_count.push_back(0);
		adj[i] = vector<int> ();
	}
	
	for(int i=0,k;i<n;i++)
	{
		cout << "Enter |Edges| from " << i << '\n';
		cin >> k;
		cout << "Enter " << k << " nodes" << '\n';
		for(int j=0,t;j<k;j++)
		{
			cin >> t;
			adj[i].push_back(t);
		}
	}
	
	puts("Adjaceny List is as follows");
	for(int i=0;i<n;i++)
	{
		cout << i << " : ";
		for(auto x:adj[i])
			cout << x << ' ';
		cout << '\n';
	}
	
	reset_count();
	//Initial Function Call for DFS
	dfs(root,0);

	reset_count();
	//Initial Function Call for counting nodes in each subtree
	dfs_node_count(root,0);
	
	// Calling Method 1 to find diameter
	reset_count();
	diameter(root,root,1);
	int first_best=0, second_best=0;
	for(int i=0;i<n;i++)
	{
		if(count(adj[root].begin(),adj[root].end(),i))
		{
			if(my_count[i] > first_best)
			{
				second_best = first_best;
				first_best = my_count[i];
			}
			else if(my_count[i] > second_best)
				second_best = my_count[i];
		}
	}
	dia = first_best + second_best + ((adj[root].size()>2)?2:adj[root].size());
	cout << "Method 1 Diamater of Tree is " <<  dia << '\n';
	
	// Calling Method 2 to find diameter
	reset_count();
	diameter(root,root,2);
	int max_indx = max_element(my_count.begin(),my_count.end()) - my_count.begin();
	reset_count();
	diameter(max_indx,max_indx,2);
	dia = *max_element(my_count.begin(),my_count.end());
	cout << "Method 2 Diamater of Tree is " <<  dia << '\n';


	// All Longest paths
	reset_count();
	all_longest_paths(root,root);
	cout << "All Longest Paths" << '\n';
	print_count();

	
	return 0;
}
