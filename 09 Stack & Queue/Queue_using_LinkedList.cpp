#include <iostream>
using namespace std;

class QNode {
	public:
	int data;
	QNode* next;
	QNode(int d) {
		data = d;
		next = NULL;
	}
};

class Queue {
	public:
	QNode *front, *rear;
	Queue() {front = rear = NULL;}

	void enQueue(int x);
	void deQueue();
};

// Insert element at rear:
void Queue::enQueue(int x) {
	QNode *temp = new QNode(x);
	if (rear == NULL) {
		front = rear = temp;
		return;
	}
	rear -> next = temp;
	rear = temp;
}

// Remove element at front:
void Queue::deQueue() {
	if (front == NULL)
		return;

	QNode *temp = front;
	front = front -> next;

	if (front == NULL)
		rear = NULL;

	delete(temp);
}


int main() {
  Queue q;
	q.enQueue(11);
	q.enQueue(22);
	q.deQueue();
	q.enQueue(33);
	q.enQueue(44);
	q.enQueue(55);
	q.deQueue();
	cout << "Queue front: " << (q.front) -> data << endl;
	cout << "Queue Rear: " << (q.rear) -> data;

	return 0;
}