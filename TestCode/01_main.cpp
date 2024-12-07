#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calculate(const vector<int>& piles, int pointer) {
        return -1;
    }
    int findInGap(const vector<int>& piles, int head, int tail) {
        return -1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.empty()) return -1;

        sort(piles.begin(), piles.end());                 
                                           
        int head = 0;                                                                                                                                        
        int tail = piles.size() - 1;            
        int mid = (tail + head)/2;                            
                                                                
        int time = -1;
          
        while(true) {                                                                                                                                               
            time = calculate(piles, piles[mid]);                                           
            if(time < h) {
                tail = mid;
                mid = (tail + head)/2; 
            } else if(time > h) {
                head = mid;
                mid = (tail + head)/2 + 1; 
            } else if(time == h) {
                return mid;                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
            } else {
                return findInGap(piles, head, tail);
            }
        }
        

        return -1;
    }
};

int main() {
    Solution Dec724;
    vector<int> piles {5,6,7,8,9};
    int time = 5;
    int output = Dec724.minEatingSpeed(piles, time);

    cout << output << endl;

    return 0;
}