#include <iostream>
using namespace std;

int main() {
    int temperature = 25;
    bool isRaining = false;

    // If - else statements
    if (temperature >= 30 && !isRaining) {
        cout << "It's hot and not raining. Time for a swim!" << endl;
    } else if (temperature >= 20 && !isRaining) {
        cout << "It's a nice day for outdoor activities." << endl;
    } else if (temperature < 20 || isRaining) {
        cout << "It's better to stay indoors." << endl;
    } else {
        cout << "Weather conditions are unknown." << endl;
    }

    // Switch statements
    int choice;
    cout << "Enter a number between 1 and 3: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You entered 1." << endl;
            break;
        case 2:
            cout << "You entered 2." << endl;
            break;
        case 3:
            cout << "You entered 3." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }

    return 0;
}
