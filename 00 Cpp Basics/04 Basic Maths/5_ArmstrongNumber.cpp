#include <iostream>
using namespace std;

string armstrongNumber(int n){
    int dup = n, sum = 0;
    while(n != 0) {
        int ld = n % 10;
        sum += ld*ld*ld;
        n = n / 10;
    }
    if (sum == dup) return "Yes";
    else return "No";
}

int main() {
    int n;
    cin >> n;
    cout << armstrongNumber(n) << endl;
    return 0;
}