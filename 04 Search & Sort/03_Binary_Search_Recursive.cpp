#include <iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int x) {
  if(s <= e) {
    int mid = s + (e - s) / 2;
    // if x is present at mid
    if(arr[mid] == x)
      return mid;
    // if x smaller, ignore right half
    else if(arr[mid] > x)
      return binarySearch(arr, s, mid - 1, x);
    // if x greater, ignore left half
    else
      return binarySearch(arr, mid + 1, e, x);
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
Auxiliary Space: O(log n)
Algorithmic Paradigm: Divide and Conquer
*/