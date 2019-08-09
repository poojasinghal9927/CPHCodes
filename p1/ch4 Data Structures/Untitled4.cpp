// Map structures
/*
map is a key->value mapping
C++ offers:
"map"           based on balanced binary search, so O(log(n)) operations
"unordered_map" based on hashing, so O(1) operations
Some functions are not available on unordered_map, due to non-ordering

On similar lines, we have multimap & unordered_multimap (this we need to use at least once)

*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	map<string,int> m;
	m["monkey"] = 4;
	m["banana"] = 3;
	m["harpsichord"] = 9;
	cout << m["banana"] << "\n"; // 3
	// Non-existing key is initialized by default value
	cout << m["aybabtu"] << "\n"; // 0

	// Function to check existence of key in map
	if (m.count("aybabtu"))
	{
		// key exists
	}

	// Printing all Key-value pairs in Map
	for (auto x : m)
		cout << x.first << " " << x.second << "\n";

	return 0;
}
