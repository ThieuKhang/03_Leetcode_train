#include <iostream>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        std::ios::sync_with_stdio(0); 
        std::cin.tie(0); 
        std::cout.tie(0);
        int n = height.size();
        if (n < 3) // There must be at least three bars to trap water
            return 0;

        int left = 0;
        int right = n - 1;
        int left_max = 0;
        int right_max = 0;
        int trapped_water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max)
                    left_max = height[left];
                else
                    trapped_water += left_max - height[left];
                left++;
            } else {
                if (height[right] >= right_max)
                    right_max = height[right];
                else
                    trapped_water += right_max - height[right];
                right--;
            }
            std::cout << trapped_water << " ";
        }

        return trapped_water;
    }
};

class Solution_2 {
public:
    int trap(std::vector<int>& height) {
        std::ios::sync_with_stdio(0); 
        std::cin.tie(0); 
        std::cout.tie(0);
        int n = height.size();
        if (n < 3) // There must be at least three bars to trap water
            return 0;

        std::vector<int> left_max(n);
        std::vector<int> right_max(n);

        // Precompute maximum heights from left
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = std::max(left_max[i - 1], height[i]);
        }

        // Precompute maximum heights from right
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = std::max(right_max[i + 1], height[i]);
        }

        int trapped_water = 0;
        // Calculate trapped water for each index
        for (int i = 0; i < n; ++i) {
            int min_height = std::min(left_max[i], right_max[i]);
            trapped_water += std::max(0, min_height - height[i]);
            std::cout << trapped_water << " ";
        }

        return trapped_water;
    }
};

class Solution_3 {
public:
    int trap(std::vector<int> &data) {
        int left = 0;
        int right = data.size() - 1;

        int current_height = (data[left] < data[right]) ? data[left] : data[right];
        int width = right - left - 1;
        int area = current_height*width;
        
        int update_height = 0;


        while(left < right) {
            if(data[left] < data[right]) {
                left++;

                if(data[left] > current_height) {
                    area -= current_height;
                } else {
                    area -= data[left];
                }

            } else {
                right--;

                if(data[right] > current_height) {
                    area -= current_height;
                } else {
                    area -= data[right];
                }
            }
            update_height = (data[left] < data[right]) ? data[left] : data[right];
            width--;

            if(update_height > current_height) {
                area += (update_height - current_height)*width;
                current_height = update_height;
            }
            std::cout << area << " ";
        }

        return area;
    }
};

int main() {
    Solution_3 Mar3;
    std::vector<int> height {1,2,3,1,0,2,0,3,0,2,4,2,0,1,2,4,2,0,0,1,2};
    int output = Mar3.trap(height);
    std::cout << "\n=================\n" << std::endl;
    std::cout << output << std::endl;
    return 0;
}

