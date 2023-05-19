#include <iostream>

// Function using pass by value
void incrementByValue(int num) {
    num += 10;
    std::cout << "Inside incrementByValue: " << num << std::endl;
}

// Function using pass by reference
void incrementByReference(int& num) {
    num += 10;
    std::cout << "Inside incrementByReference: " << num << std::endl;
}

int main() {
    int num = 5;
    
    std::cout << "Before function calls: " << num << std::endl;
    
    // Call the function using pass by value
    incrementByValue(num);
    std::cout << "After function calls: " << num << std::endl;
    
    // Call the function using pass by reference
    incrementByReference(num);
    
    std::cout << "After function calls: " << num << std::endl;
    
    return 0;
}
