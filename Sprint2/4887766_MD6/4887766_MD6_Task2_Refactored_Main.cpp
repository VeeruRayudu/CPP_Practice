#include <iostream>
#include <functional>

int main() {
    int x = 5;
    int y = 20;

    // Capture x by value
    auto addValueCapture = [x](int val) {
        return x + val;
    };

    x = 10;
    // Capture x by reference
    auto addReferenceCapture = [&x](int val) {
        return x + val;
    };

    y = 10;
    // Capture all by value
    auto addDefaultCapture = [=](int z) {
        return x + y + z;
    };

    // Capture all by reference
    auto addReferenceDefaultCapture = [&](int z) {
        return x + y + z;
    };

    x = 5;
    y = 5;
    // Mixed capture: x by value, y by reference
    auto add = [x, &y](int a, int b) {
        return a + b + x + y;
    };

    // Output results
    std::cout << "addValueCapture(2): " << addValueCapture(2) << "\n";
    std::cout << "addReferenceCapture(2): " << addReferenceCapture(2) << "\n";
    std::cout << "addDefaultCapture(2): " << addDefaultCapture(2) << "\n";
    std::cout << "addReferenceDefaultCapture(2): " << addReferenceDefaultCapture(2) << "\n";
    std::cout << "add(2, 3): " << add(2, 3) << std::endl;

    return 0;
}