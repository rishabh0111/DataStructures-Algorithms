#include <iostream>
#include <deque>
using namespace std;

/*
Deque is a shorthand for doubly ended queue. 
Deque allows fast insertion and deletion at both ends of the queue.
*/

int main() {
  	int a[] = { 1,5,8,9,3 };
	deque<int> dq(a, a+5);
	// creates s deque with elements 1,5,8,9,3 
	
	dq.push_back(10);
	// now dq is : 1,5,8,9,3,10
	
	dq.push_front(20);
	// now dq is : 20,1,5,8,9,3,10 
	
	deque<int>::iterator i;
	
	i=dq.begin()+2;
	// i points to 3rd element in dq
	
	dq.insert(i,15);
	// now dq 20,1,15,5,8,9,3,10 
	
	int a1[]={7,7,7,7};
	
	dq.insert(dq.begin() , a1 , a1+4 );
	// now dq is 7,7,7,7,20,1,15,5,8,9,3,10 

	dq.pop_back();
	// now dq is 7,7,7,7,20,1,15,5,8,9,3

	dq.pop_front();
	// now dq is 7,7,7,20,1,15,5,8,9,3

	//empty(), size(), max_size(), & swap() are same
	return 0;
}