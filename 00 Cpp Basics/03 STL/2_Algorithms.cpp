#include <iostream>
#include <algorithm>
#include <vector>

// Comparator for descending order using pair
bool descendingComparator(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first > b.first;
}

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 6};

    // Sorting in ascending order using sort algorithm
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Ascending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sorting in descending order using sort algorithm with greater<int>
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    std::cout << "Descending order using greater<int>: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sorting a vector of pairs in descending order using custom comparator
    std::vector<std::pair<int, int>> pairs = {{5, 2}, {8, 4}, {1, 6}, {3, 1}};
    std::sort(pairs.begin(), pairs.end(), descendingComparator);
    std::cout << "Pairs sorted in descending order using custom comparator: ";
    for (const auto& pair : pairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;

    // Using __builtin_popcount to count the number of set bits in a number
    int num = 42;
    std::cout << "Number of set bits in " << num << ": " << __builtin_popcount(num) << std::endl;

    // Generating permutations using next_permutation algorithm
    std::cout << "Permutations of {1, 2, 3}: ";
    std::vector<int> permutation = {1, 2, 3};
    do {
        for (int num : permutation) {
            std::cout << num << " ";
        }
        std::cout << "| ";
    } while (std::next_permutation(permutation.begin(), permutation.end()));
    std::cout << std::endl;

    // Finding the maximum element using max_element algorithm
    std::vector<int> values = {10, 3, 8, 5, 12};
    auto maxElement = std::max_element(values.begin(), values.end());
    if (maxElement != values.end()) {
        std::cout << "Maximum element: " << *maxElement << std::endl;
    }

    return 0;
}
