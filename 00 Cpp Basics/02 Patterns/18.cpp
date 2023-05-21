#include <iostream>
using namespace std;

void print(int n) {
    for (int i=0; i < n; i++){
        char ch =  'A' + n - 1 ;
        for (char c = ch-i; c <= ch; c++){
            cout << c << " ";
        }
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
E 
D E 
C D E 
B C D E 
A B C D E
*/