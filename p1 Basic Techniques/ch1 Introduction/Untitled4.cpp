// Shortening Codes & Macros
#include<bits/stdc++.h>

/*
Few macros to play with, not just constants
they are reg-ex based code replacement
generally kept capitals, for each reading
*/
#define F first
#define S second
#define PB push_back
#define MP make_pair
/*
macro style loop, does uses reg-ex matching to put a,b
this fails for sqr(x) x*x, as sqr(1+2) 1+2*1+2, better is to use sqr(x) ((x)*(x)), extra parenthesis everywhere
*/
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define RANGE(i,a,b,s) for (int i = a; ((s)>=0)?(i < b):(i>b); i+=(s))

using namespace std;

// This helps in shorter declaration, can be used with any data types & compostion of them
typedef long long ll;
typedef vector<int> vi; // vector is a empty array, elements can be added to it later
typedef pair<int,int> pi; // pair is simple 2-tuple
typedef vector<pi> vp; // vector of pair, can be written also as vector<pair<int,int>> vp;

int main()
{
	ll a = 123456789;
	ll b = 987654321;
	cout << a*b << "\n";
	
	vp v;
	v.PB(MP(1,2));
	v.PB(MP(3,4));
	for(pi x:v) // kind of for-each loop of java, or iterating element is Python fashion
		cout << x.F << x.S << '\n'; // Notice, there is no white-space by cout, you need to add ' '

	puts("\nREP macro from book");
	REP(x,1,3)
		cout << x << '\n';
	puts("\nRANGE similar to Python");
	RANGE(x,5,-1,-2)
		cout << x << '\n';
	
	return 0;
}
