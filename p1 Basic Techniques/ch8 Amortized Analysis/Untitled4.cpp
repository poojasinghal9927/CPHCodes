// Nearest Minimum in left part of each of array element
/*
Use stack, & pop all large elements than present value in stack, return top is exist on stack else false
O(1) time algorithm again
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,sum;
	stack<int> min_ele_stack;
	vector<pair<bool,int>> answer;

	cout << "Enter Length of Array" << '\n';
	cin >> n;
	
	int array[n];
	cout << "Enter Array Elements" << '\n';
	for(int i=0;i<n;i++)
		cin >> array[i];
	
	for(int i=0;i<n;i++)
	{
		while(min_ele_stack.size())
		{
			if( min_ele_stack.top() > array[i] )
				min_ele_stack.pop();
			else
				break;

		}
		if(min_ele_stack.size())
			answer.push_back(make_pair(true,min_ele_stack.top()));
		else
			answer.push_back(make_pair(false,0));
		min_ele_stack.push(array[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		if(answer[i].first)
			cout <<  "True "  << ' ' << answer[i].second << '\n';
		else
			cout <<  "False"  << ' ' << '\n';
	}

	return 0;
}
