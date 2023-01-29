#include <iostream>
using namespace std;

class MaxHeap {
    public:
    int* arr;
    int maxSize;
    int heapSize;
    
    MaxHeap(int maxSize) {
        heapSize = 0;
        this->maxSize = maxSize;
        arr = new int[maxSize];
    }

    int parent(int i) { return (i-1) / 2; }
    int lChild(int i) { return (2 * i + 1); }
    int rChild(int i) { return (2 * i + 2); }
    int getMax() {return arr[0];}
    int curSize() {return heapSize;}
    void insert(int key);
    void MaxHeapify(int i);
    int removeMax();
    void remove(int key);
    void print();
};

void MaxHeap::insert(int key) {
    if (heapSize == maxSize) {
        cout << "Overflow" << endl;
        return;
    }

    // new key initially inserted at end
    heapSize++;
    int i = heapSize - 1;
    arr[i] = key;

    // If max heap property voilation occurs, it is restored
    while (i != 0 && arr[parent(i)] < arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}
/*
For insertion:
Time Complexity: O(logN)
*/

// Restores the property of Max Heap
void MaxHeap::MaxHeapify(int i){
    int l = lChild(i);
    int r = rChild(i);
    int largest = i;
    if (l < heapSize && arr[l] > arr[i])
        largest = l;
    if (r < heapSize && arr[r] > arr[i])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(largest);
    }
}
/*
For heapify:
Time Complexity: O(logN)
*/

int MaxHeap::removeMax() {
    if(heapSize <= 0)
        return INT32_MIN;
    if(heapSize == 1) {
        heapSize--;
        return arr[0];
    }

    // storing max element to remove it
    int root = arr[0];
    arr[0] = arr[heapSize-1];
    heapSize--;

    // restore the property of max heap
    MaxHeapify(0);

    return root;
}


void MaxHeap::remove(int i) {
    // Increase the value of the key to infinity
    arr[i] = INT32_MAX;
    while( i != 0 && arr[parent(i)] < arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
    
    // Remove the maximum element
    removeMax();
}

void MaxHeap::print() {
    for (int i = 0; i < heapSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    MaxHeap h(15);
    
    cout << "Entered 6 keys:- 3, 10, 12, 8, 2, 14" << endl;
    h.insert(3);
    h.insert(10);
    h.insert(12);
    h.insert(8);
    h.insert(2);
    h.insert(14);

    h.print();
    cout << "Size after insertion: " << h.curSize() << endl;
    cout << "The current maximum element is " << h.getMax() << endl;    
    
    // removing key at index 2
    h.remove(2);
    h.print();
    cout << "Size after removal: " << h.curSize() << endl;   

    return 0;
}