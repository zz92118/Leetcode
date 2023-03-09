/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
#include<algorithm>
using namespace std;
/*
树形dp 问题分解
*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        else 
        {
            //左右的信息
            int left_depth=maxDepth(root->left);
            int right_depth=maxDepth(root->right);
            //加工整合
            int maxdepth=max(left_depth,right_depth)+1;
            //返回
            return maxdepth;
        }
    }
};

// 递归遍历的思路
// class Solution {
// public:
//     int curr_depth = 0;
//     int max_depth = 0;
//     int maxDepth(TreeNode* root) {
//         Tranverse(root);
//         return max_depth;
//     }

//     void Tranverse(TreeNode *root)
//     {
//         if(root == nullptr)
//         {
//             return ;
//         }
//         ++curr_depth;// 前序进入的位置增加深度
//         max_depth = max(curr_depth,max_depth);// 更新最大深度
//         Tranverse(root->left);
//         Tranverse(root->right);
//         --curr_depth;// 后序退出的位置 减小深度
//     }
// };

// @lc code=end

