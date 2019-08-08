// Sorting
/*
Easier to solve sometimes if data is sorted
1. Check if array has any repeated element
2. Find Mode (element with maximum occurence/frequency)

General complexity is O(n*log(n)),
which is for many algos using sorting also


Note: Below are discussed to sort on Ascending Order


O(n**2) Algorithms

1. Bubble Sort
from left to right, swap consecutive elements if in wrong order,
Again, we have to do this upto 2nd last, as last element is largest after 1st pass
<Note>: A useful concept when analyzing sorting algorithms is an inversion:
a pair of array elements (array[a],array[b]) such that
a < b and array[a] > array[b], i.e., the elements are in the wrong order.
- Each swapping removes one inversion
- Best case we have 0 inversions, worst case we have 1+2+...+(n-2)+(n-1) = (n*(n-1))/2

2. Selection Sort
Select minimum element, swap it with 1st element, making 1st as smallest
On next pass, you have to find minimum in array fron 2nd element onwards and so on

3. Insertion Sort
Suppose we have a sorted left hand side(start from single element),
now have to insert current element in this sorted left hand side,
find position, shift each element right to that position by one to right
put current element at that vacant position, store current in TEMP variable before shifts



O(n*log(n)) Algorithms

1. Merge Sort
Recursive no compute Subdivision, computation at merging two parts into sorted orded
MERGE function complexity is equal to O(a+b), a & b are length of subarrays to merge

2. Heap Sort
	a. Build Max-heap [ O(n) if done in bottom-up, O(n*log(n)) if done by insertion & max-heapify ]
	b. Exchange max element with last of heap
	c. remove last(max now after swap)
	d. Run Max-heapify from top, repeat step (b.) until heap is empty

3. Quick Sort
No merging cost, computation is done at time of division, chose pivot, <= to LEFT, > to RIGHT
Three way qucik sort, can avoid worst case of all same elements, with  <  to LEFT, > to RIGHT



LOWER Bound on COMPARISON based SORTING O(n*log(n))
Let sorting be a decision tree, wjhere we take two elements x,y and compare x < y
There are n! leaves of this tree, as any way is possible to arrange any input to get sorted output
log2(n!) >= (n/2)*log2(n/2) ; which is lower bound on height of decision tree (number of steps)


Non-Comparison based Algorithms

1. Counting Sort 
elements upto max value C, take array of length C, create frequency array in O(n) time
create array back of length N using this array, with repeating each element by its frequency

2. Radix Sort
Perform Counting sort, for multi digit representation,
starting from right (least significant) to left (most significant)

3. Bucket Sort
For floating point numbers, make 10 buckets, based on 1st digit after decimal part (period .), sort each list



In-place sorting
Sorting which does not require extra (input size dependent) memory
All O(n**2) algorithms, Heap Sort and Quick sort are inplace
Merge sort, Counting (also Radix then), Bucket sort are not inplace

Stable Sorting
Order of same elements are kept same
say two people with same name pass their luggage at airport which changes order during sorting on name of owner
passenger 1 will get luggage of passenger 2, and vice versa, if data has to go from two branches, and merge, stability needed
*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
	return 0;
}
