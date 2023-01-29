// Priority Queue in STL can be used to implement Max and Min Heaps quickly

#include <iostream>
#include <queue>
using namespace std;

int main() {
    //maxheap
    priority_queue<int> maxHeap;
    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(3);

    cout << "Element at top, current max: " << maxHeap.top() << endl;
    maxHeap.pop();
    cout << "After deletion element at top, current max: " << maxHeap.top() << endl;
    cout << "Size is: " << maxHeap.size() << endl;
    if(maxHeap.empty())
        cout << "maxHeap is empty" << endl;
    else
        cout << "maxHeap is not empty" << endl;

    //minheap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout << "Element at top, current min: " << minHeap.top() << endl;
    minHeap.pop();
    cout << "After deletion element at top, current min: " << minHeap.top() << endl;
    cout << "Size is: " << minHeap.size() << endl;
    if(minHeap.empty())
        cout << "minHeap is empty" << endl;
    else
        cout << "minHeap is not empty" << endl;

    return 0;
}