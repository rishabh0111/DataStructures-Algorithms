#include <iostream>
using namespace std;

class Queue {
	public:
		int front, rear, size;
		unsigned capacity;
		int* array;

	Queue (unsigned capacity) {
		this->capacity = capacity;
		front = size = 0;
		rear = capacity - 1;
		array = new int[this->capacity];
	}

	bool isFull();
	bool isEmpty();
	bool enqueue(int item);
	int dequeue();
	int front_item();
	int rear_item();
};

bool Queue::isFull() {
		return (size == capacity);
	}

bool Queue::isEmpty() {
	return (size == 0);
}

// Insert element at rear:
bool Queue::enqueue(int item) {
	if(isFull())
		return false;
	rear = (rear + 1) % capacity;
	array[rear] = item;
	size++;
	cout << item << " enqueued to queue" << endl;
	return true;
}

// Remove element at front:
int Queue::dequeue() {
	if(isEmpty())
		return 0;
	int temp = array[front];
	front = (front + 1) % capacity;
	size--;
	return temp;
}

// Returns front element:
int Queue::front_item() {
	if(isEmpty())
		return 0;
	return array[front];
}

// Returns rear element:
int Queue::rear_item() {
	if(isEmpty())
		return 0;
	return array[rear];
}

int main() {
	Queue q(10);

	q.enqueue(11);
	q.enqueue(22);
	q.enqueue(33);

	cout << "Front item is " << q.front_item() << endl;
	cout << q.dequeue() << " dequeued from queue" << endl;
	cout << "Front item is " << q.front_item() << endl;
	
	cout << "Last item is " << q.rear_item() << endl;
	q.enqueue(44);

	return 0;
}