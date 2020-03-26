/*
Author: Tony Hsiao
Date: 2020/03/26
Topic: 36. Valid Sudoku
Speed: 12 ms, 7.2 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, cols[9][9] = {0}, nine[9][9] = {0};
        for (int r=0; r<9; ++r) {
            for (int c=0; c<9; ++c) {
                if (board[r][c] == '.')
                  continue;
                int num = board[r][c] - 49, bd;
                bd = r/3*3 + c/3;
                row[r][num]++;
                cols[c][num]++;
                nine[bd][num]++;
                if (row[r][num] > 1 || cols[c][num] > 1 || nine[bd][num] > 1)
                    return false;
            }
        }
        return true;

    }
};