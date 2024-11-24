#include <iostream>
#include <unordered_map>
#include <queue>
#include <functional>
#include <vector>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> output;
        std::unordered_map<int, int> freMap;
        for(int i : nums) {
            freMap[i]++;
        }
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;
        for(const auto &entry : freMap) {
            minHeap.push({entry.second, entry.first});

            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        while(!minHeap.empty()) {
            output.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return output;
    }
};

int main() {
    std::vector<int> testVec {3,4,3,4,5,6,3,2};
    Solution July29;
    std::vector<int> output = July29.topKFrequent(testVec, 3);
    for(const auto &i : output) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}