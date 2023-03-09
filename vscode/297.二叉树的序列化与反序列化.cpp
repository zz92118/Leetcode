/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<sstream>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
/*
前序遍历的序列化 ： 依旧是采用前序的框架 在root=nullptr 加上应该加的字符串
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        serialize_pre(root,res);
        return res;
    }

    void serialize_pre(TreeNode* root,string &res)
    {
        // 在前序遍历的过程中序列化
        //base case
        if(root==nullptr)
        {
            res += "#,";
            return ;
        }
        // preorder
        res += to_string(root->val);
        res += ",";
        // 左右子树
        serialize_pre(root->left, res);
        serialize_pre(root->right, res);
    }
    //分割字符串的辅助函数
    queue<string> split(const string &str, const char pattern)
    {
        queue<string> res;
        stringstream input(str);   //读取str到字符串流中
        string temp;
        //使用getline函数从字符串流中读取,遇到分隔符时停止,和从cin中读取类似
        //注意,getline默认是可以读取空格的
        while(getline(input, temp, pattern))
        {
            res.push(temp);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> dataArray;
        dataArray = split(data,',');//分割成序列
        return deserialize_pre(dataArray);
    }

    TreeNode* deserialize_pre(queue<string>& sequence)
    {
        //消耗序列
        //base case
        if(sequence.front()=="#")
        {
            sequence.pop();
            return nullptr;
        }
        string strval = sequence.front();
        sequence.pop();
        int val = stoi(strval);
        TreeNode *curr = new TreeNode(val);// 前序位置
        curr->left=deserialize_pre(sequence);
        curr->right=deserialize_pre(sequence);
        return curr;// 后续位置return
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end


int main()
{
    TreeNode *n1= new TreeNode(1);
    TreeNode *n2= new TreeNode(2);
    TreeNode *n3= new TreeNode(3);
    TreeNode *n4= new TreeNode(4);
    TreeNode *n5= new TreeNode(5);
    // TreeNode *n6= new TreeNode(6);
    // TreeNode *n7= new TreeNode(7);
    n1->left=n2;
    n1->right=n3;
    // n3->left=n4;
    // n3->right=n5;
    // n3->left=n6;
    // n3->right=n7;
    TreeNode* root=n1;

    Codec c;
    string s = c.serialize(root);
    TreeNode *result = c.deserialize(s);

    return 0;
}


