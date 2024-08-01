#include <iostream>
#include <algorithm>
#include <string>

int main() {
    // Input strings
    std::string word1 = "eat";
    std::string word2 = "mad";

    // Sort the characters in each string
    std::sort(word1.begin(), word1.end());
    std::sort(word2.begin(), word2.end());

    // Print the sorted strings
    std::cout << "Sorted 'eat': " << word1 << std::endl; // Output: "aet"
    std::cout << "Sorted 'mad': " << word2 << std::endl; // Output: "adm"

    return 0;
}