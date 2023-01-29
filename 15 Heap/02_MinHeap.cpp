#include <iostream>
using namespace std;

class MinHeap {
    public:
    int* arr;
    int maxSize;
    int heapSize;
    
    MinHeap(int maxSize) {
        heapSize = 0;
        this->maxSize = maxSize;
        arr = new int[maxSize];
    }

    int parent(int i) { return (i-1) / 2; }
    int lChild(int i) { return (2 * i + 1); }
    int rChild(int i) { return (2 * i + 2); }
    int getMin() {return arr[0];}
    int curSize() {return heapSize;}
    void insert(int key);
    void MinHeapify(int i);
    int removeMin();
    void remove(int key);
    void print();
};

void MinHeap::insert(int key) {
    if (heapSize == maxSize) {
        cout << "Overflow" << endl;
        return;
    }

    // new key initially inserted at end
    heapSize++;
    int i = heapSize - 1;
    arr[i] = key;

    // If max heap property voilation occurs, it is restored
    while (i != 0 && arr[parent(i)] > arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}
/*
For insertion:
Time Complexity: O(logN)
*/

// Restores the property of Max Heap
void MinHeap::MinHeapify(int i){
    int l = lChild(i);
    int r = rChild(i);
    int smallest = i;
    if (l < heapSize && arr[l] < arr[i])
        smallest = l;
    if (r < heapSize && arr[r] < arr[i])
        smallest = r;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        MinHeapify(smallest);
    }
}
/*
For heapify:
Time Complexity: O(logN)
*/

int MinHeap::removeMin() {
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
    MinHeapify(0);

    return root;
}


void MinHeap::remove(int i) {
    // Increase the value of the key to infinity
    arr[i] = INT32_MIN;
    while( i != 0 && arr[parent(i)] > arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
    
    // Remove the maximum element
    removeMin();
}

void MinHeap::print() {
    for (int i = 0; i < heapSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    MinHeap h(15);
    
    h.insert(5);
    h.insert(3);
    h.insert(17);
    h.insert(10);
    h.insert(84);
    h.insert(19);
    h.insert(6);
    h.insert(22);
    h.insert(9);


    h.print();
    cout << "Size after insertion: " << h.curSize() << endl;
    cout << "The current minimum element is " << h.getMin() << endl;    
    
    // removing key at index 2
    h.remove(2);
    h.print();
    cout << "Size after removal: " << h.curSize() << endl;   

    return 0;
}