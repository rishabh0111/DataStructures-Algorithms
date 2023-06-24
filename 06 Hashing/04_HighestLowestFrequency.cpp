#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute-Force approach
void countFreq(int arr[], int n){
    vector<bool> visited(n, false);
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    for(int i = 0; i < n; i++) {
        // Skip this element if already processed
        if(visited[i] == true)
            continue;
        
        // Count frequency
        int count = 1;
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]){
                visited[j] = true;
                count++;
            }
        }
        if (count > maxFreq){
            maxEle = arr[i];
            maxFreq = count;
        }
        if (count < minFreq){
            minEle = arr[i];
            minFreq = count;
        }
    }
    cout << "The highest frequeny element is: " << maxEle << endl;
    cout << "The lowest frequency element is: " << minEle << endl;
}
// Time Complexity: O(N*N), where N = size of the array. We are using the nested loop to find the frequency.
// Space Complexity:  O(N), where N = size of the array. It is for the visited array we are using.

void Frequency(int arr[], int n) {
    unordered_map<int, int> map;
    
    for (int i = 0; i < n; i++)
        map[arr[i]]++;
    
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;
    // Traverse through map to find the elements.
    for (auto it : map) {
        int count = it.second;
        int element = it.first;

        if (count > maxFreq) {
            maxEle = element;
            maxFreq = count;
        }
        if (count < minFreq) {
            minEle = element;
            minFreq = count;
        }
    }
    cout << "The highest frequeny element is: " << maxEle << endl;
    cout << "The lowest frequency element is: " << minEle << endl;
}
// Time Complexity: O(N), where N = size of the array. The insertion and retrieval operation in the map takes O(1) time.
// Space Complexity:  O(N), where N = size of the array. It is for the map we are using.

int main() {
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Brute-Force approach:" << endl;
    countFreq(arr, n);
    cout << "Optimal approach:" << endl;
    Frequency(arr, n);
    return 0;
}