#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *leftArray = new int[len1];
    int *rightArray = new int[len2];

    // Copy first-half of arr to leftArray 
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        leftArray[i] = arr[mainArrayIndex++];
    }

    // Copy second-half of arr to rightArray
    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        rightArray[i] = arr[mainArrayIndex++];
    }

    // Sort and merge two halves
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2)
        if(leftArray[index1] < rightArray[index2])
            arr[mainArrayIndex++] = leftArray[index1++];
        else
            arr[mainArrayIndex++] = rightArray[index2++];

    while(index1 < len1)
        arr[mainArrayIndex++] = leftArray[index1++];

    while(index2 < len2 )
        arr[mainArrayIndex++] = rightArray[index2++];

    // Free memory
    delete []leftArray;
    delete []rightArray;
}

void mergeSort(int *arr, int s, int e) {
    // base case
    if(s >= e)
        return;
    
    int mid = s + (e - s) / 2;
    // Sort left half
    mergeSort(arr, s, mid);
    // Sort right half
    mergeSort(arr, mid+1, e);
    // Merge them
    merge(arr, s, e);
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n-1);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

/*
Time Complexity: O(Nlog(N)) : each pass takes N time & there are log(n) passes
Auxiliary Space: 0(N)
Algorithmic Paradigm: Divide and Conquer
Stable: Yes
*/