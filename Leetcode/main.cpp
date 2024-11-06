#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>

class Solution {
public:
    bool isConvertibleToInt(const std::string& str) {
        try {
            std::size_t pos;
            std::stoi(str, &pos);
            // Check if the entire string was used in the conversion
            return pos == str.length();
        } catch (std::invalid_argument& e) {
            return false; // Not a valid integer
        } catch (std::out_of_range& e) {
            return false; // Out of int range
        }
    }
    void add(std::stack<int>& myStack) {
        if (myStack.size() < 2) return; // Ensure there are enough elements
        int b = myStack.top(); myStack.pop();
        int a = myStack.top(); myStack.pop();
        myStack.push(a + b);
    }

    void minus(std::stack<int>& myStack) {
        if (myStack.size() < 2) return;
        int b = myStack.top(); myStack.pop();
        int a = myStack.top(); myStack.pop();
        myStack.push(a - b);
    }

    void times(std::stack<int>& myStack) {
        if (myStack.size() < 2) return;
        int b = myStack.top(); myStack.pop();
        int a = myStack.top(); myStack.pop();
        myStack.push(a * b);
    }

    void divide(std::stack<int>& myStack) {
        if (myStack.size() < 2) return;
        int b = myStack.top(); myStack.pop();
        int a = myStack.top(); myStack.pop();
        if (b == 0) {
            myStack.push(-1); // Handle divide-by-zero by pushing -1
        } else {
            double result = static_cast<double>(a) / b;
            myStack.push(static_cast<int>(std::round(result))); // Push rounded result
        }
    }
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> myStack;
        for(const auto& token : tokens) {
                if (token == "+") {
                    add(myStack);
                } else if (token == "-") {
                    minus(myStack);
                } else if (token == "*") {
                    times(myStack);
                } else if (token == "/") {
                    divide(myStack);
                } else {
                    if (isConvertibleToInt(token)) {
                        int num = std::stoi(token);

                        if (!myStack.empty() && myStack.top() == -1) return 0;
                        myStack.push(num);
                    }
                }
            }
        return myStack.top();
    }
};

int main() {
    Solution Nov624;
    std::vector<std::string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int output = Nov624.evalRPN(tokens);
    std::cout << output << std::endl;
    return 0;
}