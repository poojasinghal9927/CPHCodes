// Bit Manipulation
/*
Note: This will be an intruging chapter, if you have not experience before, refer book before codes

There are many applications & also Bit level are faster & less complex in computers
signed -x representation is is unsigned (2**n - x)
There is wrap around of numbers due to overflow, which comes in both signed and unsigned


AND logic
X & (1<<k-1) = 0 // Divisbiel by 2**k
X | (1<<k)       // Setting k bit to 1
X & ~(1<<k)      // Setting k bit to 0
X & (X-1)        // Setting last 1 bit to 0, power of two, if results is 0
X & -X           // Sets all 1 bits of X to 0, except last
X | (X-1)        // Inverst all bits after last 1 bit

Additional functions

__builtin_clz(x): the number of zeros at the beginning of the number
__builtin_ctz(x): the number of zeros at the end of the number
__builtin_popcount(x): the number of ones in the number
__builtin_parity(x): the parity (even or odd) of the number of ones

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	
	int x = (1<<2)|(1<<5)|(1<<3)|(1<<9)|(1<<15)|(1<<17);
	int b = 0;
	do {
		// process subset b
		for( int i=0; i<sizeof(x)*8 ; i++ )
			if(b&(1<<i))
				cout << i << ' ';
		cout << '\n';
	} while (b=(b-x)&x);

	return 0;
}
