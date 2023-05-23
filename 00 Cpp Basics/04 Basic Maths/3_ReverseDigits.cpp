/*
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
*/

#include <iostream>
using namespace std;

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int lastDigit = x % 10;
        if (rev < INT32_MIN/10 || rev > INT32_MAX/10)
            return 0;
        rev = rev * 10 + lastDigit;
        x = x / 10;
    }
    return rev;
}

int main() {
    int n;
    cin >> n;
    int x = reverse(n);
    cout << x << endl;
    return 0;
}