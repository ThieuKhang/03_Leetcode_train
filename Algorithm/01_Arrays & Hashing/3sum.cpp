#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
private:
    void twoSum(const vector<int>& nums, int target, int last, vector<vector<int>>& result) {
        int i = 0;
        int j = last;

        while(i < j) 
        {
            int sum = nums[i] + nums[j];
            if(sum == target) {
                result.push_back({nums[last + 1], nums[i], nums[j]});
                ++i;
                --j;

                while (i < j and nums[i] == nums[i - 1]) {
                    ++i;
                }

                while (i < j and nums[j] == nums[j + 1]) {
                    --j;
                }
            }
            else if(sum < target) {
                ++i;
            }
            else {
                --j;
            }
        }
    }

    void threeSumImpl(const vector<int>& nums, int index, int target, vector<vector<int>>& result)
    {
        if(index <= 1) {
            return;
        }
        
        int n = nums.size() - 1;
        if (index < n and nums[index] == nums[index + 1]) {
            // Skip duplicates for the current index
            threeSumImpl(nums, index - 1, target, result);
        }
        else
        {
            int newTarget = target - nums[index];
            twoSum(nums, newTarget, index - 1, result);
            threeSumImpl(nums, index - 1, target, result);
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int target = 0;
        sort(begin(nums), end(nums));

        vector<vector<int>> result{};
        threeSumImpl(nums, nums.size() - 1, target, result);
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int target = 0;
        std::vector<std::vector<int>> output;
        std::set<std::vector<int>> s;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() ; i++) {
            int head = i + 1;
            int tail = nums.size() - 1;
            while(head < tail) {
                int sum = nums.at(i) + nums.at(head) + nums.at(tail);
                if(sum == target) {
                    s.insert({nums.at(i),nums.at(head),nums.at(tail)});
                    head++;
                    tail--;
                } else if(sum > target) {
                    tail--;
                } else {
                    head++;
                }
            }
        }
        for(auto data : s) {
            output.push_back(data);
        }
        return output;
    }
};

int main() {

    return 0;
}