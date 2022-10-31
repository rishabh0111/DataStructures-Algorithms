#include <iostream>
using namespace std;

class StackNode {
	public:
	int data;
	StackNode* next;

	bool push(int x);
	int pop();
	bool isEmpty();
	int peek();
	void display();
} *top;

// Insert element at top:
bool StackNode::push(int x) {
	StackNode* temp = new StackNode();
	if(!temp) {
		cout << "Stack Overflow" << endl;
		return false;
	}
	temp -> data = x;
	temp -> next = top;
	top = temp;
	cout << x << " pushed into stack" << endl;
	return true;
}

bool StackNode::isEmpty() {
	return (top == NULL);
}

// Returns top element:
int StackNode::peek() {
	if(!isEmpty())
		return top -> data;
	else
		return 0;
}

// Remove element at top:
int StackNode::pop() {
	StackNode* temp;

	if (top == NULL) {
		cout << "Stack Underflow" << endl;
		return 0;
	}
	else{
		temp = top;
		top = top -> next;
		int x = temp -> data;
		free(temp);
		return x;
	}
}

// Prints stack:
void StackNode::display() {
	StackNode* temp = new StackNode();

	if(top == NULL) {
		cout << "Stack Underflow" << endl;
	}
	else {
		temp = top;
		while(temp != NULL) {
			cout << temp -> data << " ";
			temp = temp -> next;
		}
		cout << endl;
	}
}

int main() {
    StackNode s;
	s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);

	s.display();

	cout << "Top element is " << s.peek() << endl;

	s.pop();
	s.pop();

	s.display();

	cout << "Top element is " << s.peek() << endl;

	return 0;
}