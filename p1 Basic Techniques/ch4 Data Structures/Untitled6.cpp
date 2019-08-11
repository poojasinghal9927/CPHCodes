// Other Structures
#include<bits/stdc++.h>

using namespace std;

int main()
{
	/* bitset, to occupy less memory for boolean arrays*/
	puts("BITSET");
	bitset<10> s;
	s[1] = 1;
	s[3] = 1;
	s[4] = 1;
	s[7] = 1;
	cout << s[4] << "\n"; // 1
	cout << s[5] << "\n"; // 0
	
	bitset<10> s2(string("0010011010")); // from right to left
	cout << s2[4] << "\n"; // 1
	cout << s2[5] << "\n"; // 0
	// Returning numbers of bits set to ON
	cout << s.count() << "\n"; // 4
	
	
	bitset<10> a(string("0010110110"));
	bitset<10> b(string("1011011000"));
	cout << (a&b) << "\n"; // 0010010000
	cout << (a|b) << "\n"; // 1011111110
	cout << (a^b) << "\n"; // 1001101110
	
	
	/* Dequeue, another Dynamic array*/
	puts("DEQUEUE");
	deque<int> d;
	d.push_back(5); // [5]
	d.push_back(2); // [5,2]
	d.push_front(3); // [3,5,2]
	d.pop_back(); // [3,5]
	d.pop_front(); // [5]
	/*Slower than vector due to complex implementations, average still O(1)*/
	
	/* Stack, should be non-contiguous internally*/
	puts("STACK");
	stack<int> st;
	st.push(3);
	st.push(2);
	st.push(5);
	cout << st.top() << "\n"; // 5
	st.pop(); // pop from top
	cout << st.top() << "\n"; // 2
	
	/* QUEUE, only removal from front & adding to end allowed*/
	puts("QUEUE");
	queue<int> q;
	q.push(3);
	q.push(2);
	q.push(5);
	cout << q.front() << "\n"; // 3
	q.pop(); // removal from beginning
	cout << q.front() << "\n"; // 2

	/* PRIORITY-QUEUE, Insertion and removal takes O(log(n)) time, retrieval(peek) is O(1)*/
	// Ordered set can be used, but this has smaller constants
	puts("PRIORITY QUEUE");
	priority_queue<int> pq; // This has max element at top
	// priority_queue<int,vector<int>,greater<int>> pq; // This has min element at top
	pq.push(3);
	pq.push(5);
	pq.push(7);
	pq.push(2);
	cout << pq.top() << "\n"; // 7
	pq.pop();
	cout << pq.top() << "\n"; // 5
	pq.pop();
	pq.push(6);
	cout << pq.top() << "\n"; // 6
	pq.pop();
	
	// Note : here I am skipping Policy-based Data Structures
	
	return 0;
}
