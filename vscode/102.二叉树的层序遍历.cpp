/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
 #include<queue>
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root==nullptr)
        {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            size_t size = q.size();
            for(size_t i = 0; i < size; ++i)
            {
                //bfs 操作
                TreeNode *curr = q.front();
                q.pop();
                level.push_back(curr->val);

                if(curr->left != nullptr)// 空指针保护
                {
                    q.push(curr->left);
                }
                if(curr->right != nullptr)// 空指针保护
                {
                    q.push(curr->right);
                }
            }
            // max(level.begin(), level.end());
            res.push_back(level);
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int> > levelOrder(TreeNode* root) {
//         vector<vector<int> > res;
//         if(root==nullptr)
//         {
//             return res;
//         }
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty())
//         {
//             vector<int> level;
//             int size = q.size();
//             while(size--)
//             {
//                 TreeNode * curr = q.front();
//                 q.pop();
//                 level.push_back(curr->val);
//                 if(curr->left)
//                 {
//                     q.push(curr->left);
//                 }
//                 if(curr->right)
//                 {
//                     q.push(curr->right);
//                 }
//             }
//             res.push_back(level);
//             level.clear();
//         }
//         return res;
//     }
// };
// @lc code=end

