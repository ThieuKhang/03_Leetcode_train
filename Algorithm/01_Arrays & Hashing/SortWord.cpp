#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> myMap;
        std::string word;
        std::vector<std::vector<std::string>> output;

        for(const auto &str : strs) {
            word = str;
            std::sort(word.begin(), word.end());
            myMap[word].push_back(str);
        }

        for(const auto &element : myMap) {
            output.push_back(element.second);
        }

        return output;
    }
};

int main() {
    Solution Aug1;
    std::vector<std::string> input {"eat", "ate", "bat", "tan", "tea", "nat"};
    std::vector<std::vector<std::string>> output = Aug1.groupAnagrams(input);
    for(const auto &listWord : output) {
        for(const auto &word : listWord) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}