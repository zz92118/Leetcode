/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        dfs(nums, 0, result);
        return result;
    }
    void dfs(vector<int>& nums, int depth, vector<vector<int> > &res)
    {
        // base case  回溯条件
        if(depth >= nums.size())
        {
            res.push_back(nums);
            return ;
        }
        for(int i = depth; i < nums.size(); ++i)
        {
            swap(nums[i], nums[depth]);// 做选择（先序位置）
            dfs(nums, depth + 1, res);
            swap(nums[i], nums[depth]);// 撤销选择（后序位置）
        }
    }
};
// @lc code=end

// @lc code=start
// class Solution {
// public:
//     vector<vector<int> > permute(vector<int>& nums);
    
//     void dfs(vector<int> &nums,int index,vector<vector<int> >& result);
// };

// vector<vector<int> > Solution::permute(vector<int>& nums)
// {
//     vector<vector<int> > res;
//     dfs(nums,0,res);
//     return res;
// }

// void Solution::dfs(vector<int> &nums,int index,vector<vector<int> > &result)
// {
//     if(index>=nums.size())
//     {
//         result.push_back(nums);
//     }
//     else 
//     {
//         int j;
//         //在index往后的位置做交换
//         for(j=index;j<nums.size();j++)
//         {
//             swap(nums[index],nums[j]);
//             dfs(nums,index+1,result);
//             swap(nums[index],nums[j]);
//         }
//     }
// }


