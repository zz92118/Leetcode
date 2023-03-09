/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        Difference d = Difference(res);
        for(auto book = bookings.begin(); book != bookings.end(); ++book)
        {
            int i = (*book)[0] - 1;//n - 1
            int j = (*book)[1] - 1;//n - 1
            int val = (*book)[2];
            d.increcment(i,j,val);
        }
        res = d.result();
        return res;
    }

// 内部类
public:
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
            for(size_t i = 1; i < nums.size(); ++i)
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
            for(size_t i = 1; i < diff.size(); ++i)
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


int main()
{

}
