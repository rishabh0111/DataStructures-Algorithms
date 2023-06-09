#include <iostream>
using namespace std;

// Parameterised
void sumP(int i, int s){
    if (i < 1){
        cout << s << endl;
        return;
    }
    sumP(i-1,s+i);
}

// Functional
int sumF(int n){
    if(n == 0) return 0;
    return (n + sumF(n-1));
}

int main() {
    int n = 4;
    sumP(n,0);
    cout << sumF(n) << endl;
    return 0;
}