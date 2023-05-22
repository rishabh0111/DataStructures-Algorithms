#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue <int> qu1;
	qu1.push(1);
	qu1.push(2);
	qu1.push(3);

	cout << qu1.front() << endl;
	cout << qu1.back() << endl;

	qu1.pop();
	cout << qu1.front() << endl;
	cout << qu1.back() << endl;

	//size(), empty(), swap() are same
}

/*
Function    | Time Complexity | Space Complexity
-------------------------------------------------
q.push(x)   | O(1)            | O(1)
q.pop( )    | O(1)            | O(1)
q.front( )  | O(1)            | O(1)
q.back( )   | O(1)            | O(1)
q.empty( )  | O(1)            | O(1)
q.size( )   | O(1)            | O(1)
*/