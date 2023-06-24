#include <iostream>
using namespace std;

/*
    Maximum size of array of 
    type integer is 10^7,
    type bool is 10^8, 
    if globally declared
*/

int main() { 
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // precomputation
    int hash[13] = {0};
    /*
    Maximum size of array of 
    type integer is 10^6,
    type bool is 10^7, 
    inside main function
    */
    for(int i = 0; i < n; i++)
        hash[arr[i]]++;

    cout << "Enter number of queries: ";
    int q;
    cin >> q;
    while(q--){
        cout << "Enter query number: ";
        int number;
        cin >> number;
        // fetching
        cout << "count of " << number <<hash[number] << endl;
    }

    return 0;
}