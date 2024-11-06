#include <iostream>
#include <stack>


class Solution {
public:
    char closeToOpen(char c) {
        if(c == ')') {
            return '(';
        } else if(c == '}') {
            return '{';
        } else 
            return '[';
    }

    bool isOpen(char c) {
        if(c == '(' || c == '[' || c == '{')
            return true;
        return false;
    }

    bool isValid(std::string s) {
        std::stack<char> myStack;
        for(char c : s) {
            if(isOpen(c)) {
                myStack.push(c);
                continue;
            } else {
                if(myStack.empty()) {
                    return false;
                } else if(myStack.top() != closeToOpen(c)) {
                    return false;
                } else
                    myStack.pop(); 
                    continue;
            }
        }
        if(!myStack.empty()) {
            return false;
        }
        return true;
    }
};


int main() {
    Solution Dec19;
    std::string s = "}}";
    bool outPut = Dec19.isValid(s);
    std::cout << s << " " <<  outPut << std::endl;
    return 0;
}