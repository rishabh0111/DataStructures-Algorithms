#include<iostream>
using namespace std;

// Bruteforce approach
bool isPrime(int N) {
  for (int i = 2; i < N; i++)
    if (N % i == 0)
      return false;
  return true;
}
// Time Complexity: O(N)

// Optimised Approach
bool issPrime(int N) {
    for (int i = 2; i*i < N; i++)
        if (N%i == 0)
            return false;
    return true;
}
// Time Complexity: O(logN)

int main() {
    int n = 11;
    bool ans = isPrime(n);
    if (n != 1 && ans == true)
        cout << n << " is prime Number" << endl;
    else
        cout << n << " is non Prime Number" << endl;

    ans = issPrime(n);
    if (n != 1 && ans == true)
        cout << n << " is prime Number" << endl;
    else
        cout << n << " is non Prime Number" << endl;
  return 0;
}