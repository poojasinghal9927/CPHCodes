// Set structures
/*
C++ offers:
"set"           based on balanced binary search, so O(log(n)) operations
"unordered_set" based on hashing, so O(1) operations
Some functions are not available on unordered_set(have to find out which), due to non-ordering
lower_bound(), upper_bound() are two such functions

On similar lines, we have multiset & unordered_multiset

*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	set<int> s;
	s.insert(3); // Placing entry in set
	s.insert(2);
	s.insert(5);
	cout << s.count(3) << "\n"; // 1 Always, return 1 or 0 based on existence
	cout << s.count(4) << "\n"; // 0

	s.erase(3); // Erasing entry from set
	s.insert(4);

	cout << s.count(3) << "\n"; // 0
	cout << s.count(4) << "\n"; // 1
	
	
	set<int> s2 = {6,2,5,6};
	cout << s2.size() << "\n"; // 4
	// Observe order of printing, due to binary tree
	for (auto x : s2)
		cout << x << "\n";
		
		
	// Duplicates are not there in SET
	set<int> s3;
	s3.insert(5);
	s3.insert(5);
	cout << s3.count(5) << "\n"; // 1


	// Creation of Multiset
	multiset<int> s4;
	s4.insert(5);
	s4.insert(5);
	s4.insert(5);
	cout << s4.count(5) << "\n"; // 3
	// Erases all entries from multiset
	s.erase(5);
	cout << s.count(5) << "\n"; // 0
	// Erases only one entry from multiset
	s.erase(s.find(5));
	cout << s.count(5) << "\n"; // 2
	
	return 0;
}
