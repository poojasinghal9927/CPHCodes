// Working with Numbers
#include<bits/stdc++.h>

using namespace std;

int main()
{
	
	/*
	DATA-TYPES
	short and long, are not just extensions, but datatypes itself, int is one of them
	which does depends on who implements the compiler, long long requires speficier
	*/
	long long exm_var = 123456789123456789LL;
	
	// Below is a common mistake as a*a will be evaluated as int experssion
	int a = 123456789;
	long long b = a*a;
	cout << b << "\n"; // -1757895751
	
	// __int128_t is available somewhere
	
	
	/*
	Modular Arithmetic
	(a+b) mod m = (a mod + b mod m) mod m
	(a-b) mod m = (a mod - b mod m) mod m
	(a*b) mod m = (a mod * b mod m) mod m
	*/
	
	// Finding Modular of some factorial
	
	puts("\nMOD Factorial\nEnter an integer n and m"); // puts adds \n by itself in printing, but for strings only
	int n,m;
	cin >> n >> m;
	long long x = 1;
	for (int i = 2; i <= n; i++)
	{
		x = (x*i)%m;
	}
	if (x < 0) x += m; // This line is if number is negative modulus, which is common
	cout << "Factorial mod "<< m << " is " << x%m << "\n";
	
	
	/*
	FLOATING POINT NUMBERS
	32-bit float, 64-bit double, 80-bit long double
	printf is generic with %f, %e, %g
	scanf requires precision to be given to take input
	Integer upto 2**53 can be accurately represented using double(64-bit)
	*/
	double f1 = 0.3*3+0.1; // Demo for loss of precision
	printf("%.20f\n", f1); // 0.99999999999999988898
	
	// Due to this rounding errors, don't use equality to compare
	if (abs((f1-0.1)/3-0.3) < 1e-9) // Something like this could work
		puts("Better way to compare for equality");
		
	
	
	return 0;
}
