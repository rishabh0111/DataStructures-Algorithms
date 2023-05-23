#include <iostream>
#include <math.h>
using namespace std;

int count_digits(int n) {
   int x = n; int count = 0;
   while(x != 0) {
       x = x / 10;
       count++;
   }
   return count;
}

int main() {
   int n = 12345;
   cout<< "Number of digits in "<< n <<" is " << count_digits(n) << endl;
   // Or
   int cnt = (int)(log10(n) + 1);
   cout << "Number of digits:" << cnt << endl;
   return 0;
}

// Time Complexity: O(log10(N))