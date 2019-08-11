// Basics of Console Input-Output
#include<bits/stdc++.h>

using namespace std;

int main()
{
	// Faster Input-Output
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a,b;
	string c,d;
	
	/*
	You can use scanf & printf from C language always
	Automatic input type conversion, unlike using %d, %s explicitly
	try 12 35hello
	You will see Lexical Analyzer works for getting input
	*/
	cin >> a >> b >> c;

	// Getting whole line, possibly containing spaces, like input() of Python
	// If you press ENTER after value of <string c>, <string d> will be just  "\n"
	
	// https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/ , last solution from
	// Discards the input buffer and intial white spaces of string 
    cin >> ws; // you can try experimenting after removing this	
	getline(cin,d);
	
	// Using endl at end of cout causes flush, which makes it a bit slow
	cout << "Value of a is : " << a << '\n' ;
	cout << "Value of b is : " << b << '\n' ;
	cout << "Value of c is : " << c << '\n' ;
	cout << "Value of d is : " << d << '\n' ;
	
	
	/*
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	Above lines can be used for setting std stream handles to some files,
	as stream handles are also nothing but file pointers,
	This helps in some contests where we have IO from files, instead of console
	*/
	
	return 0;
}
