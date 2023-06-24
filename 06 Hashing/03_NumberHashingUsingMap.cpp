#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    map<int, int> mpp;
    for(int i = 0; i < n; i++)
        mpp[arr[i]]++;
    
    for(auto it : mpp)
        cout << it.first << "->" << it.second << endl;

    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;
        //fetch
        cout << mpp[number] << endl;
    }
    
    return 0;
}

/*
Time Complexity for storing & fetching:
> For Ordered Map: 
Best/Worst/Average case: O(logN)
where N is no. of elements in map
> For Unordered Map:
Best / Average Case: O(1)
Worst Case: O(N)
*/