#include <iostream>
using namespace std;

void print(int n) {
    int count = 1;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << count++ << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    print(n);   
    return 0;
}

/*
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15
*/