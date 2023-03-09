/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int nums = 0;
    int totalNQueens(int n) {
        vector<int> records(n, 0);// records[i]代表了i行皇后的列号
        dfs(0, n, records);
        return nums;
    }
    bool canSet(int row, int col,vector<int> records)
    {
        for(int i = 0; i < row; ++i)// 检查和第i行有没有重复
        {
            int j = records[i];
            if((j == col) || (abs(row - i) == abs(col - j)))
            {
                return false;
            }
        }
        return true;
    }
    void dfs(int depth, int n, vector<int> &records)
    {
        if(depth >= n)
        {
            ++nums;
            return ;
        }
        for(int j = 0; j < n; ++j)
        {
            if(canSet(depth, j, records))
            {
                records[depth] = j;//depth行皇后的列坐标为j
                dfs(depth + 1, n, records);
                // 没有回溯撤销的地方
            }
        }
    }
};
// @lc code=end

