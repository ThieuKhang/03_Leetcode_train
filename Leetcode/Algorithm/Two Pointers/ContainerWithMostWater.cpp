#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    bool check_height(double height, int previous_area, int width) {
        if (width == 0) {
            // Handle the case where width is zero (avoid division by zero)
            return false;
        }

        double at_least = static_cast<double>(previous_area) / width;
        
        if (height >= std::ceil(at_least)) {
            return true;
        }
        return false;
    }
    int maxArea(std::vector<int> &data) {
        std::ios::sync_with_stdio(0); 
        std::cin.tie(0); 
        std::cout.tie(0);
        int left = 0;
        int right = data.size() - 1;

        int width = right - left;
        int height = (data[left] < data[right]) ? data[left] : data[right];

        while(left < right) {
            double current_height = 0.0;
            int current_width = right - left;
            if(data[left] < data[right]) {
                left++;            
            } else {
                right--;
            }
            current_height = (data[left] < data[right]) ? data[left] : data[right];
            current_width--;
            if(current_height > height && check_height(current_height,height*width,current_width)) {
                height = current_height;
                width = current_width;
            }

        }
        return height*width;
    }
};
int main() {
    Solution Mar2;
    std::vector<int> data {1,8,6,2,5,4,8,3,7};
    int output = Mar2.maxArea(data);
    std::cout << output << std::endl;
    return 0;
}