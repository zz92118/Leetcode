/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
#include<string>
using namespace std;
/*

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
    unordered_map<string, int> m;
    vector<TreeNode*> res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }
    string traverse(TreeNode * root)
    {
        if(root == nullptr)
        {
            return "#";
        }
        string leftSubTree = traverse(root->left);
        string rightSubTree = traverse(root->right);
        // 通过分解子问题 加工得到子树
        string subTree =  leftSubTree + "," + rightSubTree + "," + to_string(root->val);//前序的序列化 需要后续遍历得到子树的信息
        // if(m.find(subTree) != m.end())
        if(m.find(subTree) != m.end())//判断有人和我重复了
        {
            if(m.count(subTree) == 1)
            {
                res.push_back(root);
            }
        }
        m[subTree]++;
        return subTree;
    }
};
// @lc code=end

int main()
{
    TreeNode * t1 = new TreeNode(1);
    TreeNode * t2 = new TreeNode(2);
    TreeNode * t3 = new TreeNode(3);
    TreeNode * t4 = new TreeNode(4);
    TreeNode * t5 = new TreeNode(2);
    TreeNode * t6 = new TreeNode(4);
    TreeNode * t7 = new TreeNode(4);

    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t3->left = t5;
    t3->right = t6;
    t5->left = t7;

    Solution s;
    s.findDuplicateSubtrees(t1);
    return 0;
}

