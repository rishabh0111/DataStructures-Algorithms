#include <iostream>
using namespace std;

// Bruteforce approach
int gcd_brute (int n1, int n2) {
    int ans = 1;
    for (int i = 1; i <= min(n1,n2); i++)
        if( n1 % i == 0 && n2 % i == 0)
            ans = i;
    return ans;
}
// Time Complexity: O(N)

// Using Euclidean’s theorem
int gcd (int n1, int n2) {
    if (n2 == 0)
        return n1;
    return gcd(n2, n1 % n2);
}
// Time Complexity: O(logɸmin(a,b)), where ɸ is 1.61.

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    
    cout << "gcd of given numbers is: " << gcd_brute(n1, n2) << endl;
    cout << "gcd of given numbers is: " << gcd(n1, n2) << endl;

    return 0;
}