#include <iostream>
using namespace std;

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void bubbleSort(int arr[], int n)
{
    // Base case
    if (n == 1)
        return;

    int count = 0;
    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            count++;
        }

    // if recursion/swapping happens or not
    if (count == 0)
        return;

    // Largest element is fixed, recur for remaining array
    bubbleSort(arr, n-1);
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

/*
Time Complexity: O(n*n)
Auxiliary Space: O(n)
Based on the number of comparisons in each method, the recursive bubble sort is better than the iterative bubble sort
Prefer iterative approach as of O(1) space
*/