/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root==nullptr)
        {
            return res;
        }
        q.push(root);
        while(!q.empty())
        {
            int maxval = INT_MIN;
            size_t size = q.size();
            for(size_t i = 0; i < size; ++i)
            {
                TreeNode *curr = q.front();
                q.pop();
                if( (curr->val) > maxval)
                {
                    maxval = curr->val;
                }
                if(curr->left != nullptr)
                {
                    q.push(curr->left);
                }
                if(curr->right != nullptr)
                {
                    q.push(curr->right);
                }
            }
            res.push_back(maxval);
        }
        return res;
    }
};
// @lc code=end

