#include <iostream>
using namespace std;

void func(int i, int n){
    if(i<1) return;
    cout << i << endl;
    func(i-1, n);
}

int main() {
    int n = 4;
    func(n,n);
    return 0;
}

/*
                 func(4, 4)
                /         \
        cout << 4    func(3, 4)
                        /      \
                cout << 3    func(2, 4)
                                /     \
                        cout << 2    func(1, 4)
                                        /      \
                                cout << 1    func(0, 4)
                                                (base case, return)

*/