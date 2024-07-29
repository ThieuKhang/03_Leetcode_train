#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int> &heights) {
        int n = heights.size();
        std::stack<int> s;
        int maxArea = 0;
        
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || heights[i] < heights[s.top()])) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                maxArea = std::max(maxArea, h * w);
                // std::cout << maxArea << std::endl;
            }
            s.push(i);
        }
        
        return maxArea;
    }
};

int main() {
    std::vector<int> heights = {1,2,1,3,5,4,2,5,7,6,2};
    Solution Mar24;
    std::cout << Mar24.largestRectangleArea(heights) << std::endl;
    return 0;
}