#include <iostream>
using namespace std;

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void selectionSort(int arr[], int n) {
    int min_idx;

    for(int i = 0; i < n - 1; i++) {
        min_idx = i;
        // Find minimum element in unsorted array
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        // Swap the found minimum element with the first element
        if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

/*
"Pushes smallest elements to start"
Time Complexity: O(N^2) -> two loops
Auxiliary Space: O(1) -> temporary variables
Stability -> The default implementation is not stable. However, it can be made stable.
*/