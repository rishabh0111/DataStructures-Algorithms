#include <iostream>
using namespace std;

void print(int n) {
    // First Half
    for (int i=0; i < n; i++){
        //star
        for (int j = 0; j < n-i; j++){
            cout << "*";
        }
        //space
        for (int j = 0; j < 2*i; j++) {
            cout << " ";
        }
        //star
        for (int j = 0; j < n-i; j++){
            cout << "*";
        }
        cout << endl;
    }
    // Second Half
    for (int i=0; i < n; i++){
        //star
        for (int j = 0; j <= i; j++){
            cout << "*";
        }
        //space
        for (int j = 0; j < 2*n-2*i-2; j++) {
            cout << " ";
        }
        //star
        for (int j = 0; j <= i; j++){
            cout << "*";
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
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/