/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
/*
最简单的方法就是中序遍历然后找K 先做一遍
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

class Solution {
public:
    int res = 0;
    int rank = 0;
    int kthSmallest(TreeNode* root, int k) {
        tranverse(root, k);
        return res;
    }
    void tranverse(TreeNode* root, int k)
    {
        if(root == nullptr)
        {
            return ;
        }
        tranverse(root->left, k);
        // 中序位置
        ++rank;
        if(rank == k)// 找到了第k大的元素并记录下来
        {
            res = root->val;
        }
        tranverse(root->right, k);
    }
};

// @lc code=end

// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> result;
//         result = inorder(root,result);

//         return result[k-1];
//     }
//     vector<int> inorder(TreeNode *root,vector<int> &result)
//     {
//         if(root==nullptr)
//         {
//             return result;
//         }
//         inorder(root->left,result);
//         result.push_back(root->val);
//         inorder(root->right,result);
//         return result;
//     }

// };