#include <iostream>
using namespace std;

void funcLinear(int i, int n) {
    if(i < 1) return;
    funcLinear(i-1, n);
    cout << i << endl;
}

void funcReverse(int i, int n) {
    if(i > n) return;
    funcReverse(i+1, n);
    cout << i << endl;
}

int main() {
    int n = 4;
    funcLinear(n,n);
    cout << "--" << endl;
    funcReverse(1,n);
    return 0;
}

/*
                  funcLinear(4, 4)
                 /               \
        funcLinear(3, 4)         cout << 4
        /              \
  funcLinear(2, 4)     cout << 3
  /               \
funcLinear(1, 4)   cout << 2
  /              \
funcLinear(0, 4)  cout << 1      
(base case, return)
*/

/*
                   funcReverse(1, 4)
                 /                    \
          funcReverse(2, 4)      cout << 1
           /               \
    funcReverse(3, 4)   cout << 2
      /              \
funcReverse(4, 4)     cout << 3
   /              \
funcReverse(5, 4)  cout << 4      
(base case, return)
*/