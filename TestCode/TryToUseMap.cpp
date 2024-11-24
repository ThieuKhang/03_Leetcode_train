#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    // Create a multimap with some key-value pairs
    std::map<std::string, std::vector<int>> myMap;
    myMap.insert({"aet",{}});
    myMap.insert({"ant",{}});
    myMap.insert({"abt",{}});

    myMap["aet"].push_back(1);

    for(const auto &name : myMap) {
        std::cout << name.first << " ";
        for(const auto &elements : name.second) {
            std::cout << elements << " ";
        }
        std::cout << std::endl;
    }
    

    return 0;
}