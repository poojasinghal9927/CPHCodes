// Problem 2: Unweighted Job Scheduling
#include<bits/stdc++.h>

using namespace std;


bool comp( pair<int,int> a , pair<int,int> b)
{ //Sorting on second element
	if(a.second < b.second)
		return true;
	else if((a.second == b.second)&&(a.first < b.first))
		return true;
	else
		return false;
}

int main()
{
	int n;
	cout << "Enter number of Jobs" << '\n';
	cin >> n ;
	
	vector<pair<int,int>> jobs(n,make_pair(0,0));

	cout << "Enter Starting & End Times of Jobs" << '\n';
	for(int i=0;i<n;i++)
		cin >> jobs[i].first >> jobs[i].second ;
		
	sort(jobs.begin(),jobs.end(),comp);
	
	cout << "Scheduled Jobs are\n";
	int last_end = 0;
	for(pair<int,int> x:jobs)
	{
		if(x.first>=last_end)
		{
			cout << x.first << ' ' << x.second << '\n';
			last_end = x.second;
		}
	}
	
	return 0;
}
