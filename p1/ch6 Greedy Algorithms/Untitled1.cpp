// Greedy Algorithms
/*
Always make choice, which looks best at the present moment
Property that Greedy does find optimal answer need to be proved

Problem 1: Coin change problem
Finding minimum number of coins to build a amount, any coin be taken any number of time
This depends on coins set given (1,3,4) to made 6 does not work with Greedy

Problem 2: Unweighted Scheduling problem
Maximize number of jobs, each with (st,et) which is starting time & end time
Sol1. Shortest Job First, (can block 2 long jobs by overlapping, NON-optimal)
Sol2. Least Starting Time First, (can be a very long job, NON-optimal)
Sol3. Least Ending Time First, (creates maximum room for remaining jobs, OPTIMAL)

Problem 3: Task & Deadlines
Similar to problem 2, just have gain of (given_deadline - finish_time), so have to complete ASAP
Sol1. Not based on deadline, but tasks of highest duration are to be put first

Problem 4: Binary Codec (Huffman Encoding)
Given string of characters, each to be represented with certain bits, which is greedy on frequency
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	return 0;
}
