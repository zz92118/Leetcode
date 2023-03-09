/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return count_dfs(1, n);
    }

    vector<TreeNode*> count_dfs(int low,int high)
    {
        vector<TreeNode*> res;
        if(low > high)
        {
            //base case 
            res.push_back(nullptr);
            return res;
        }
        for(int i = low; i <= high; ++i)
        {
            auto lefts = count_dfs(low, i - 1);
            auto rights = count_dfs(i + 1, high);
            // 排列组合左右子树
            for(auto left : lefts)
            {
                for(auto right : rights)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;   
    }
};
// @lc code=end

