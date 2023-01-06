#include <iostream>
using namespace std;

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

/*
"Pushes largest elements to end"
Worst and Average Case Time Complexity: O(N^2). The worst case occurs when an array is reverse sorted.
Best Case Time Complexity: O(N). The best case occurs when an array is already sorted.
Auxiliary Space: O(1)
*/