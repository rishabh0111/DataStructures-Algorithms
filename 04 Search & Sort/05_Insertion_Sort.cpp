#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = temp;
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

/*
Worst and Average Case Time Complexity: O(N^2). The worst case occurs when an array is reverse sorted.
Best Case Time Complexity: O(N). The best case occurs when an array is already sorted.
Auxiliary Space: O(1)
Algorithmic Paradigm: Incremental Approach
Stable: Yes
*/