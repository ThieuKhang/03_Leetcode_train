#include <iostream>
#include <vector>

int main() {
    // Create a vector of 10 zeros
    std::vector<int> vec(10, 0);

    // Optional: Print the elements to verify
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}