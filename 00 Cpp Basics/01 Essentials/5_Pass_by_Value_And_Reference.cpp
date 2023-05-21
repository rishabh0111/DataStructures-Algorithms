#include <iostream>
using namespace std;

// Function using pass by value
void incrementByValue(int n) {
    n += 10;
    cout << "Inside incrementByValue: " << n << endl;
}

// Function using pass by reference
void incrementByReference(int& n) {
    n += 10;
    cout << "Inside incrementByReference: " << n << endl;
}

int main() {
    int num = 5;
    
    cout << "Before function calls: " << num << endl;
    
    // Call the function using pass by value
    incrementByValue(num);
    cout << "After function calls: " << num << endl;
    
    // Call the function using pass by reference
    incrementByReference(num);
    
    cout << "After function calls: " << num << endl;
    
    return 0;
}
