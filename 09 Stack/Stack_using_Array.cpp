#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
	private:
		int top;
	public:
		int a[MAX]; // Maximum size of Stack
		Stack(){top = -1;};
		bool push(int x);
		int pop();
		int peek();
		bool isEmpty();
		void display();
};

// Insert element at top:
bool Stack::push(int x) {
	if (top >= MAX - 1) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		cout << x << " pushed into stack" << endl;
		return true;
	}
}

// Remove element at top:
int Stack::pop() {
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}

// Returns top element:
int Stack::peek() {
	if ( top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty() {
	return (top < 0);
}

// Prints stack:
void Stack::display() {
	cout << "Elements present in stack: ";
	while(!this->isEmpty())
		{
			cout << this->peek() << " ";
			this->pop();
		}
	cout << endl;
}

int main() {
    Stack s;
	s.push(11);
	s.push(22);
	s.push(33);

	cout << s.pop() << " popped from stack" << endl;
	cout << "Top element is: " << s.peek() << endl;

	s.display();
	return 0;
}

/* 
Advantages:
1. Easy to implement.
2. Memory is saved as pointers are not used.
Disadvantages:
1. It is not dynamic (does not grow or shrink).
*/