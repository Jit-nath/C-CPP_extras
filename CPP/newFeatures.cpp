#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

// Lambda function
auto add = [](int a, int b) { return a + b; };

// Range-based for loop
void printVector(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Smart pointers
void useSmartPointer() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    std::cout << "Smart pointer value: " << *ptr << std::endl;
}

int main() {
    // Auto keyword
    auto x = 5;
    auto y = 10;
    std::cout << "Sum: " << add(x, y) << std::endl;

    // Range-based for loop
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    printVector(numbers);

    // Smart pointers
    useSmartPointer();

    return 0;
}