/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include<iostream>
#include<vector>
using namespace std;

class NestedInteger
{
public:
    bool isInteger();
    vector<NestedInteger> getList();
    int getInteger();
};

class NestedIterator {
public:
    vector<int> result;
    vector<int>::iterator it;//是一个迭代器结构
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto nested : nestedList)
        {
            traverse(nested);
        }
        it = result.begin();
    }
    int next() {
        return *(it++);// return当前的value
    }
    bool hasNext() {
        return (it != result.end());
    }
    // 本质上是多叉树的遍历z
    void traverse(NestedInteger root)
    {
        if(root.isInteger())
        {
            result.push_back(root.getInteger());
            return ;
        }
        // 多叉树遍历
        for(auto node : root.getList())
        {
            traverse(node);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

