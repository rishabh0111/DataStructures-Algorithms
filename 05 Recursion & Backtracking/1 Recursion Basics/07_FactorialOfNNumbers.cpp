#include <iostream>
using namespace std;

int factrl(int n){
    if(n == 0) return 1;
    return(n * factrl(n-1));
}

int main() {
    int n = 5;
    cout << factrl(n) << endl;
    return 0;
}