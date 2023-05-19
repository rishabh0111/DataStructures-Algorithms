#include <iostream>
#include <string>

int main() {
    using namespace std;

    // Integer data types
    int age = 25;  // Range: -2,147,483,648 to 2,147,483,647
    short int shortAge = 20;  // Range: -32,768 to 32,767
    long int longAge = 30;  // Range: -2,147,483,648 to 2,147,483,647
    long long int longLongAge = 40;  // Range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
    unsigned int unsignedAge = 35;  // Range: 0 to 4,294,967,295
    
    // Floating-point data types
    float weight = 65.5f;
    // The range and precision of float values are implementation-dependent
    
    double height = 175.8;
    // The double data type offers higher precision than float.
    // It can represent a larger range of values and has more significant digits.
    
    long double distance = 12345.6789;  // Range: 3.3621e-4932 to 1.18973e+4932
    
    // Character data type
    char grade = 'A';  // Range: -128 to 127 (or 0 to 255 for unsigned)
    
    // Boolean data type
    bool isStudent = true;  // Range: true or false
    
    // String data type
    string name;
    
    // Input using getline()
    cout << "Enter your name: ";
    getline(cin, name);
    
    // Output
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Short Age: " << shortAge << endl;
    cout << "Long Age: " << longAge << endl;
    cout << "Long Long Age: " << longLongAge << endl;
    cout << "Unsigned Age: " << unsignedAge << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Height: " << height << " cm" << endl;
    cout << "Distance: " << distance << " units" << endl;
    cout << "Grade: " << grade << endl;
    cout << "Is Student? " << boolalpha << isStudent << endl;

    return 0;
}
