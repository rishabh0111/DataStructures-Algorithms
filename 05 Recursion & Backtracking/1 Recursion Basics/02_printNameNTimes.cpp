#include <iostream>
using namespace std;

void func(int i, int n){
    if(i>n) return;
    cout << "Bob" << endl;
    func(i+1,n);
}

int main() {
    int n = 4;
    func(1,n);
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/