#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int> &letter) {
        if(letter.empty()) return {};

        int bugs = 0;
        int bugsArea = -1;

        int start = 0;
        int end = letter.size();

        int gold = 1;

        while(start < end && bugs < 2) {
            if(letter[start] == 0) {
                bugs++;
                bugsArea = start;
                start++;
                continue;
            }
            gold *= letter[start];

            start++;
        }

        if(bugs > 1) {
            std::vector<int> aLotOfBugs (letter.size(), 0);
            return aLotOfBugs;
        } else if(bugs == 1) {
            std::vector<int> aBug (letter.size(), 0);
            aBug[bugsArea] = gold;
            return aBug;
        } else {
            std::vector<int> coppied {};
            for(const auto &i : letter) {
                coppied.push_back(gold/i);
            }
            return coppied;
        }

    }
};

int main() {
    Solution July31;
    std::vector<int> letter {-1,1,0,-3,3};
    std::vector<int> coppied = July31.productExceptSelf(letter);
    for(const auto &i : coppied) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}