#include <iostream>
#include <list>
using namespace std;

list<int> digitExtract(int n) {
    list<int> digits;
    while(n > 0) {
        int lastDigit = n%10;
        digits.push_front(lastDigit);
        n = n/10;
    }
    return digits;
}

int main() {
    int n;
    cin >> n;
    list<int> digits = digitExtract(n);
    for (auto i : digits)
        cout << i << " ";
    cout << endl;
    return 0;
}