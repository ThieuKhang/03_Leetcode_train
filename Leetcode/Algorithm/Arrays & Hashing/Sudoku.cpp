#include <iostream>
#include <unordered_map>
#include <vector>

const int N = 9;

class MySolution {
public:
    bool isBreakRule(const std::unordered_map<char, int> &scanMachine, char key) {
        // Check if the key exists in the map before accessing it
        auto it = scanMachine.find(key);
        return (it != scanMachine.end() && it->second > 1);
    }

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        if (board.empty()) return false;

        std::unordered_map<char, int> hScan;
        
        std::unordered_map<char, int> aFirst;
        std::unordered_map<char, int> aSecond;
        std::unordered_map<char, int> aThird;

        int aFrequent = 1;

        std::unordered_map<char, int> d;
        std::unordered_map<char, int> n;
        std::unordered_map<char, int> m;
        std::unordered_map<char, int> r;
        std::unordered_map<char, int> l;
        std::unordered_map<char, int> g;
        std::unordered_map<char, int> k;
        std::unordered_map<char, int> f;
        std::unordered_map<char, int> b;

        for(int i = 0; i < N; i++) {
            if(aFrequent > 3) {
                aFrequent = 1;
                aFirst.clear();
                aSecond.clear();
                aThird.clear();
            }
            for(int j = 0; j < N; j++) {
                char X = board[i][j];
                if(X == '.') 
                    continue;

                hScan[X]++;
                if(isBreakRule(hScan, X)) 
                    return false;
                
                switch (j)
                {
                case 0:
                    aFirst[X]++;
                    if(isBreakRule(aFirst, X))
                        return false;
                    d[X]++;
                    if(isBreakRule(d,X))
                        return false;
                    break;
                case 1:
                    aFirst[X]++;
                    if(isBreakRule(aFirst, X))
                        return false;
                    n[X]++;
                    if(isBreakRule(n,X))
                        return false;
                    break;
                case 2:
                    aFirst[X]++;
                    if(isBreakRule(aFirst, X))
                        return false;
                    m[X]++;
                    if(isBreakRule(m,X))
                        return false;
                    break;
                case 3:
                    aSecond[X]++;
                    if(isBreakRule(aSecond, X))
                        return false;
                    r[X]++;
                    if(isBreakRule(r,X))
                        return false;
                    break;
                case 4:
                    aSecond[X]++;
                    if(isBreakRule(aSecond, X))
                        return false;
                    l[X]++;
                    if(isBreakRule(l,X))
                        return false;
                    break;
                case 5:
                    aSecond[X]++;
                    if(isBreakRule(aSecond, X))
                        return false;
                    g[X]++;
                    if(isBreakRule(g,X))
                        return false;
                    break;
                case 6:
                    aThird[X]++;
                    if(isBreakRule(aThird, X))
                        return false;
                    k[X]++;
                    if(isBreakRule(k,X))
                        return false;
                    break;
                case 7:
                    aThird[X]++;
                    if(isBreakRule(aThird, X))
                        return false;
                    f[X]++;
                    if(isBreakRule(f,X))
                        return false;
                    break;
                case 8:
                    aThird[X]++;
                    if(isBreakRule(aThird, X))
                        return false;
                    b[X]++;
                    if(isBreakRule(b,X))
                        return false;
                    break;
                default:
                    break;
                }
            }
            aFrequent++;
            hScan.clear();
        }

       return true; 
    }
};

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        const int num = 9;

        // Initialize the boolean arrays to false
        bool row[num][num] = {false};
        bool col[num][num] = {false};
        bool subGrid[num][num] = {false};

        for (int r = 0; r < num; ++r) {
            for (int c = 0; c < num; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                int idx = board[r][c] - '0' - 1; // Convert char to int index
                int gridNum = (r / 3) * 3 + (c / 3);

                if (row[r][idx] || col[c][idx] || subGrid[gridNum][idx]) {
                    return false;
                }

                row[r][idx] = true;
                col[c][idx] = true;
                subGrid[gridNum][idx] = true;
            }
        }
        return true; // If no duplicates found, the Sudoku board is valid
    }
};

int main() {
    Solution Aug8;
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    for (const auto& row : board) {
        for (char chr : row) {
            std::cout << chr << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "====================" << std::endl;
    std::cout << Aug8.isValidSudoku(board) << std::endl;
    return 0;
}