#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string str = "123";
    int num;
    std::istringstream(str) >> num;
    std::cout << "Converted integer: " << num << std::endl;
    return 0;
}
