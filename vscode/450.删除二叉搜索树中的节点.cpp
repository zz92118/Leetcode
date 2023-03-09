/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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

函数定义： 给出一个节点，一个要删除的节点的值，删除该节点，并返回删除后的该节点

情况 1 删除节点左右子树都是null,则直接删除root节点 
情况 2 左右子树有一个是null，就直接把非空的接上
情况 3 左右子树都为非空 ， 找到左子树的最大节点 或者右子树的最小节点

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case 进行删除操作
        if(root == nullptr)
        {
            return nullptr;
        }
        if(root->val == key)
        {
            // 情况1和情况2
            if(root->left == nullptr) return root->right;
            if(root->right == nullptr) return root->left;
            // 情况3 找到右侧的最小节点
            TreeNode *minNode = getmin(root->right);
            root->right = deleteNode(root->right, minNode->val);// 先删除右侧最小节点
            //然后把右侧的最小节点接到root上
            minNode->left = root->left;
            minNode->right = root->right; 
            root = minNode;
            return root;
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
    TreeNode* getmin(TreeNode* root)
    {
        TreeNode *curr=root;
        while(curr->left!=nullptr)
        {
            curr=curr->left;
        }
        return curr;
    }
};
// @lc code=end

