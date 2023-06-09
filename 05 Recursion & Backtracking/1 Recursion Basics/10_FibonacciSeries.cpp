#include <iostream>
using namespace std;

int fib(int n){
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2); // Mulitple recursion calls
}

void printFib(int n) {
    for (int i = 0; i < n; i++)
        cout << fib(i) << " ";
    cout << endl;
}

int main() {
    int count = 10;
    printFib(count);
    return 0;
}

// Time Complexity ~ O(2^n)