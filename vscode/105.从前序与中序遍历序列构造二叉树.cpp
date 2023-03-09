/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
1.preorder的根节点rootVal
  inorder的根节点 遍历inorder数组
2.递归的构建左右子树
3.确定需要的变量 rootVal preStart preEnd  inStart inEnd index
4. 辅助函数build的函数原型
左右子树的起始终止位置要确定 前序不要出现index 
前序的信息只要和prestart preend leftsize有关
中序的信息 instart inend index 

最后return
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
    unordered_map<int, int> m;// val --- index 的映射
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 先构造哈希表做查找 因为没有重复的节点
        for(size_t i = 0; i < inorder.size(); ++i)
        {
            m[inorder[i]] = i;
        }
        TreeNode *root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd)
    {
        if(inStart > inEnd)
        {
            return nullptr;
        }
        // 找到root节点的索引和元素值
        int rootVal = preorder[preStart];
        auto it = m.find(rootVal);
        int index = it->second;
        int leftSize = index - inStart;
        TreeNode *root = new TreeNode(rootVal);
        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, index - 1);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, index + 1, inEnd);
        return root;
    }

};
// @lc code=end

