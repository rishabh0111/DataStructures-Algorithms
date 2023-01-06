#include <iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int x) {
    while(s <= e) {
        int m = s + (e - s) / 2;

        // if x is present at mid
        if(arr[m] == x)
            return m;
        // if x greater, ignore left half
        else if(arr[m] < x)
            s = m + 1;
        // if x smaller, ignore right half
        else
            e = m - 1;
    }

    // if element was not present
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    
    (result == -1)
        ? cout << "Element is not present in array" << endl
        : cout << "Element is present at index " << result << endl;
    
    return 0;
}

/*
Time Complexity: O(log n)
Auxiliary Space: O(1)
Algorithmic Paradigm: Decrease and Conquer
*/