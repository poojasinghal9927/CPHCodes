// Dynamix Arrays(size can be changed at runtime) (vectors, strings)
// Note: by doubling allocation each time needed, insertion cost is O(1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(3); // [3]
	v.push_back(2); // [3,2]
	v.push_back(5); // [3,2,5]
	
	// Classical iteration using vector.size() method
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	// for each style loop for iteration
	for (int i : v)
		cout << i << "\n";

	// Functioning as a Stack (but contiguous !!)
	vector<int> v2;
	v2.push_back(5);
	v2.push_back(2);
	cout << v2.back() << "\n"; // 2
	v2.pop_back();
	cout << v2.back() << "\n"; // 5

	// Creating Static vector
	vector<int> v3 = {2,4,2,5,1};
	// size 10, initial value 0
	vector<int> v4(10);
	// size 10, initial value 5
	vector<int> v5(10, 5);


	// String type is also a Dynamic Array, with string functions and + as concatenation operator
	string a = "hatti";
	string b = a+a;
	cout << b << "\n"; // hattihatti
	b[5] = 'v';
	cout << b << "\n"; // hattivatti
	
	string c = b.substr(3,4);
	cout << c << "\n"; // tiva
	
	// Substring search, string matching, Finding 1st occurence of substring
	int start_pos = 0; // default starting position is anyway always 0
	cout << b.find("tiva",start_pos) << "\n"; 

	// npos below to check if find has retured valid value is declared as -1 in library
	static const size_t npos = -1;

	if (b.find("random") != string::npos) // If that substring string exist
		cout << b.find("random") << "\n"; 

	return 0;
}
