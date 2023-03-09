/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */
#include<iostream>
#include<vector>
using namespace std;


// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> nums(1001);
        Difference d = Difference(nums);
        for(auto it = trips.begin(); it != trips.end(); ++it)
        {
            // 问题转化成在 [from, to - 1]的区间上进行差分检索
            int val = (*it)[0];
            int i = (*it)[1];
            int j = (*it)[2] - 1;
            d.increcment(i, j, val);
        }

        auto res = d.result();// 得到了每个站点的乘客数量

        for(auto i : res)
        {
            if(i > capacity)
            {
                return false;
            }
        }
        return true;

    }

    class Difference
    {
    public:
    // 构造函数
        Difference()
        {
            ///必须要写一个默认构造函数
        }
        Difference(vector<int> nums)
        {
            diff = vector<int>(nums.size());
            diff[0] = nums[0];
            for(size_t i = 1; i < nums.size(); i++)
            {
                diff[i] = nums[i] - nums[i-1];
            }
        }
        //频繁加减
        void increcment(int i, int j, int val)
        {
            diff[i] += val;
            if((j + 1) < diff.size())
            {
                diff[j + 1] -= val;
            }
        }
        // 返回结果数组
        vector<int> result()
        {
            vector<int> res(diff.size());
            res[0] = diff[0];
            for(size_t i = 1; i < diff.size(); i++)
            {
                res[i] = res[i-1] + diff[i];
            }
            return res;
        }

        void output()
        {
            for(auto i : diff)
            {
                cout<<i<<" ";
            }
        }
    private:
        vector<int> diff;
    };
};
// @lc code=end

