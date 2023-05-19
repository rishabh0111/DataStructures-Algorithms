#include <iostream>

int main() {
    // Basic for loop
    std::cout << "Basic for loop:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Looping through an array
    std::cout << "Looping through an array:" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Looping in reverse
    std::cout << "Looping in reverse:" << std::endl;
    for (int i = 4; i >= 0; i--) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Skipping iterations with continue
    std::cout << "Skipping iterations with continue:" << std::endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Breaking out of a loop with break
    std::cout << "Breaking out of a loop with break:" << std::endl;
    for (int i = 1; i <= 5; i++) {
        if (i == 4) {
            break;  // Exit the loop when i is 4
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int count = 0;
    
    // Example of a while loop
    while (count < 5) {
        std::cout << "Count: " << count << std::endl;
        count++;
    }
    
    std::cout << "----------------------" << std::endl;
    
    // Example of a do-while loop
    count = 0; // Reset the count
    
    do {
        std::cout << "Count: " << count << std::endl;
        count++;
    } while (count < 5);
    
    return 0;
}
