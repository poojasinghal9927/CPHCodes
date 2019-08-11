// Problem 3: Tasks & Deadlines
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout << "Enter number of Jobs" << '\n';
	cin >> n ;
	
	vector<pair<int,int>> jobs(n,make_pair(0,0));

	cout << "Enter Duration & Deadlines of Jobs" << '\n';
	for(int i=0;i<n;i++)
		cin >> jobs[i].first >> jobs[i].second ;
		
	sort(jobs.begin(),jobs.end());
	
	puts("Scheduled Jobs are");
	int last_end = 0, profit = 0;
	for(pair<int,int> x:jobs)
	{
		if(x.second > last_end) // if deadline is not missed
		{
			cout << x.first << ' ' << x.second << '\n';
			last_end += x.first; // updating present clock
			profit += (x.second - last_end);
		}
	}
	cout << "Net Profit is " << profit << '\n';
	
	return 0;
}
