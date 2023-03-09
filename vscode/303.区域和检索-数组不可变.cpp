/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;


class NumArray {
public:
    vector<int> preSum;
    NumArray(vector<int>& nums) {//构造前缀和数组
        preSum.resize(nums.size()+1);
        preSum[0] = 0;
        for(size_t i = 1; i < preSum.size(); ++i)
        {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right+1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

int main()
{
    vector<int> arr;
    arr.push_back(-2);
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(-5);
    arr.push_back(2);
    arr.push_back(-1);

    NumArray *n= new NumArray(arr);
}

