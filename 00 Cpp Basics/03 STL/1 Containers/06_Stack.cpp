#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st1;
	st1.push(1);
	st1.push(2);
	st1.push(3);

	st1.pop();

	cout << st1.top() << endl;

	cout << st1.size() << endl;

	if(st1.empty()){
		cout << "Stack is empty" << endl;
	}
	else{
		cout << "Non-empty stack" << endl;
	}

	stack<int> st2;
	st2.swap(st1);
	cout << st2.top() << endl;

	return 0;
}

/*
Function    | Time Complexity | Space Complexity
-------------------------------------------------
s.top( )    | O(1)            | O(1)
s.pop( )    | O(1)            | O(1)
s.empty( )  | O(1)            | O(1)
s.push(x)   | O(1)            | O(1)
*/