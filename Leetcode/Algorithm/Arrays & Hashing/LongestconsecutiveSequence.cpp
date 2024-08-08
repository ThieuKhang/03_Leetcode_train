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
class Solution_2 {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 1;

        for (const auto& num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLength = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }

                maxLength = std::max(maxLength, currentLength);
            }
        }

        return maxLength;
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
// int a[100000];

// int init = [] {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     ofstream out("user.out");
//     for (string s; getline(cin, s); out << '\n') {
//         if (s.length() == 2) {
//             out << 0;
//             continue;
//         }
//         int n = 0;
//         for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
//             bool _neg = false;
//             if (s[_i] == '-') ++_i, _neg = true;
//             int v = s[_i++] & 15;
//             while ((s[_i] & 15) < 10) v = v * 10 + (s[_i++] & 15);
//             if (_neg) v = -v;
//             a[n++] = v;
//         }
//         sort(a, a + n);
//         int ans = 0;
//         for (int i = 0; i < n;) {
//             int i0 = i;
//             for (++i; i < n && a[i - 1] + 1 >= a[i]; ++i);
//             ans = max(ans, a[i - 1] - a[i0] + 1);
//         }
//         out << ans;
//     }
//     out.flush();
//     exit(0);
//     return 0;
// }();

// class Solution {
// public:
//     int longestConsecutive(vector<int>) { return 999; }
// };