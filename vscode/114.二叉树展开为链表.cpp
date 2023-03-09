/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
using namespace std;
/*
重点关注递归函数的作用，而不是跳进递归细节

1.把左侧展开
  把右侧展开

2.把左侧接上root
3.把右侧再接上左侧
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
    void flatten(TreeNode* root) {
        if(root == nullptr)
        {
            return ;
        }
        flatten(root->left);
        flatten(root->right);
        // 后序 分解问题
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        // 1.把左边置空 并把左边接到右边
        root->left = nullptr;
        root->right = left;
        // 2.把右边原来的放到1.的后面
        TreeNode *curr = root;
        while(curr->right != nullptr)// 找到最后一个节点
        {
            curr = curr->right;
        }
        curr->right = right; 
    }
};

// @lc code=end

