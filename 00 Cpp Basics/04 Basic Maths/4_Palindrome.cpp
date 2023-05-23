#include <iostream>
using namespace std;

string is_palindrome(int n) {
    int dup = n;
    int rev = 0;
    while (n != 0) {
        int ld = n % 10;
        rev = rev*10 + ld;
        n = n / 10;
    }
    if (rev == dup) return "Yes";
    else return "No";
}

int main() {
    int n;
    cin >> n;
    cout << is_palindrome(n) << endl;
    return 0;
}