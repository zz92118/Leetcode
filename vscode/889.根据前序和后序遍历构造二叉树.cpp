/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
#include<unordered_map>
using namespace std;
/*
1.找到postorder和preorder的根节点
2.递归的构建左右子树
3.确定需要的变量 posStart posEnd Root inStart inEnd index
4. 辅助函数build的函数原型
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
    unordered_map<int, int> m;// 找到rootVal的位置

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(size_t i = 0; i < postorder.size(); ++i)
        {
            m[postorder[i]] = i;
        }
        TreeNode * root = build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
        return root;
    }

    TreeNode* build(vector<int> preorder, int preStart, int preEnd, vector<int> postorder, int posStart, int posEnd)
    {
        if(preStart > preEnd)
        {
            return nullptr;
        }
        if(preStart == preEnd)
        {
            return new TreeNode(preorder[preStart]); // 特殊的basecase
        }        // 找到rootval，以及后续位置的根节点
        int rootVal = preorder[preStart];
        int leftRootVal = preorder[preStart + 1];// 因为有这句话，所以比起前两题要加上特殊的basecase 否则会在这里访问越界（即没有左子树了）
        auto it = m.find(leftRootVal);
        int index = it->second;
        // 确定左子树长度
        int leftSize = index - posStart + 1;
        // 递归构建
        TreeNode * root = new TreeNode(rootVal);
        root->left = build(preorder, preStart + 1, preStart + 1 + leftSize - 1, postorder, posStart, index);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, postorder, index + 1, posEnd - 1);
        return root;
    }
};
// @lc code=end

