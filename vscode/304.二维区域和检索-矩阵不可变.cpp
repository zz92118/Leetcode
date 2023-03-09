/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class NumMatrix {
public:
    vector<vector<int> > preSum;

    NumMatrix(vector<vector<int> >& matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            preSum.resize(m + 1, vector<int>(n + 1, 0));
            for(size_t i = 1; i <= m; ++i)
            {
                for(size_t j = 1; j <= n; ++j)
                {
                    preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i-1][j-1] - preSum[i-1][j-1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row1][col2 + 1] - preSum[row2 + 1][col1] + preSum[row1][col1];
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

