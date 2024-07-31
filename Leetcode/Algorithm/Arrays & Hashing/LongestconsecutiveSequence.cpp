#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>

class Solution {
public:
    int max(const std::vector<int> &nums) {
        int num = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(num < nums[i]) {
                num = nums[i];
            }
        }
        return num;
    }
    int longestConsecutive(std::vector<int> &nums) {
        if(nums.empty()) {
            return 0;
        }
        std::set<int> mySet (nums.begin(), nums.end());
        std::vector<int> farmmer_count;
        int series = 1;
        while(!mySet.empty()) {
            auto start_it = mySet.begin();
            int start = *start_it;
            int numberNext = start + 1;
            auto it = mySet.find(numberNext);
            if(it != mySet.end()) {
                series++;
                numberNext++;
                it = mySet.find(numberNext);
            } else {
                farmmer_count.push_back(series);
                series = 1;
            }
            mySet.erase(start);
        }


        int output = max(farmmer_count);
        return output;
    }
};
//O(n^2)
int main() {
    std::vector<int> numss {3,5,6,4,13,12,11,10,1,9};
    std::vector<int> nums {1,3,4,5,6,9,10,11,12,13};
    Solution Feb18;
    
    std::cout << Feb18.longestConsecutive(nums) << std::endl;
    return 0;
}
