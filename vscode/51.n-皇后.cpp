/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
/*
通过行列的绝对值计算的canset函数设计
回溯的时候不用清洗
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> records(n, 0);// records[i]代表了i行皇后的列号
        dfs(0, n, records);
        return result;
    }
    void setOne(int n, vector<int> &records)
    {
        vector<string> board(n, string(n,'.'));
        for(size_t i = 0; i < n; ++i)
        {
            board[i][records[i]] = 'Q';
        }
        result.push_back(board);
    }
    bool canSet(int row, int col,vector<int> records)// 检查depth行上那一列可以放置
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
            setOne(n, records);
            return;
        }
        for(int j = 0; j < n; ++j)
        {
            if(canSet(depth, j, records))// 检查depth行上那一列可以放置
            {
                records[depth] = j;//depth行皇后的列坐标为j, // records[i]代表了i行皇后的列号
                dfs(depth + 1, n, records);
                // 没有回溯撤销的地方
            }
        }
    }
};
// @lc code=end

