#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    // Prompt the user for input
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Perform calculations
    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;

    // Display the output
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;

    return 0;
}
