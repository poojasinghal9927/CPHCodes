// Slding window minimu
/*
As name suggest array of length N & window of length W, find minimum after each slide
we maintain a Queue, where 1st element is smallest in window & further elements are larger than this

// Author uses Queue, but a vector will be better for more operations (stack can be used better way !!)
O(n) time algorithms
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int i,j;
	int n,w,min_val;
	vector<pair<int,int>> min_queue;
	vector<int> answer;

	cout << "Enter Length of Array, window size" << '\n';
	cin >> n >> w;
	
	int array[n];
	cout << "Enter Array Elements" << '\n';
	for(int i=0;i<n;i++)
		cin >> array[i];
	
	// 1st window initialization
	min_val = *min_element(array,array+w);
	for(i=w-1;i>=0;i--)
	{
		if(array[i]==min_val)
			break;
	
	}

	min_queue.push_back(make_pair(i,min_val));
	for(j=i+1;j<w;j++)
		if(array[j]>min_queue.back().second)
			min_queue.push_back(make_pair(j,array[j]));
	answer.push_back(min_val);

	// remaining windows processing
	for(int i=1;(i+w-1)<n;i++)
	{
		// Removing elements from starting not part of window
		while( (min_queue.size()) && (min_queue.front().first<i) )
			min_queue.erase(min_queue.begin());//pop_front();
		// Removing elements from end not small then newly added element
		while( (min_queue.size()) && (min_queue.back().second>=array[w+i-1]) )
			min_queue.pop_back();
		min_queue.push_back(make_pair(w+i-1,array[w+i-1]));
		
		min_val = INFINITY;
		for(auto x:min_queue)
		{
			if(x.second<min_val)
				min_val = x.second;
		}
		answer.push_back(min_val);
	}
	
	for(auto x:answer)
	{
		cout <<  x  << ' ' << '\n';
	}

	return 0;
}
