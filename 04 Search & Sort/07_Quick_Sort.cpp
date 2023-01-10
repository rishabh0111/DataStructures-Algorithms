#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s];

    int cnt = 0;
    for (int  i = s+1; i <= e; i++)
        if (arr[i] <= pivot)
            cnt++;
    
    // Place pivot at correct position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;

    // Swap and sort left and right halves
    while (i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    // Base case
    if(s >= e)
        return;
    
    // Partition
    int p = partition(arr, s, e);

    // Sort left half
    quickSort(arr, s, p-1);
    // Sort right half
    quickSort(arr, p+1, e);
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[6] = {2, 4, 1, 6, 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n-1);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}