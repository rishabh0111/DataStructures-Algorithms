#include <iostream>
#include <queue>
using namespace std;

/* 
priority_queue is just like a normal queue except the element removed from the queue 
is always the greatest among all the elements in the queue, 
thus this container is usually used to replicate Max Heap
*/

int main() {
	priority_queue<int> pq1;

	pq1.push(30);  // inserts 30 to pq1 , now top = 30
	pq1.push(40);  // inserts 40 to pq1 , now top = 40 (maximum element)
	pq1.push(90);  // inserts 90 to pq1 , now top = 90
	pq1.push(60);	// inserts 60 to pq1 , top still is 90

	pq1.pop();  // removes 90 (greatest element in the queue)

	cout << pq1.top() << endl;

	// Min Heap can be implemented using the below syntax:
	priority_queue<int, vector<int>, greater<int>> pq2;

	//empty(), size(), & swap() are same

	return 0;
}

/*
Function   | Time Complexity | Space Complexity
-----------------------------------------------
Q.top()    | O(1)            | O(1)
Q.push()   | O(log n)        | O(1)
Q.pop()    | O(log n)        | O(1)
Q.empty()  | O(1)            | O(1)
*/