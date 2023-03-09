/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
快速排序每次确定一个数字的位置
如果一次partition为倒数第K个,那就找到

*/

class Solution {
public:
    // Solution();
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 0)
        {
            return -1;
        }
        return quick_select(nums,0,nums.size()-1,k);
    }
    int partition(vector<int>& nums,int low,int high);
    int quick_select(vector<int>& nums,int low,int high,int k);
};

int Solution::quick_select(vector<int>& nums,int low,int high,int k)
{
    if(low <= high)//这里是等于 因为要选择
    {
        int index = partition(nums, low, high);
        if(index == nums.size() - k)
        {
            return nums[index];
        }
        else 
        {
            return index < (nums.size()-k) ? quick_select(nums, index + 1, high, k) : quick_select(nums, low, index-1, k);
        }
    }
    return -1;// 没找到
}

int Solution::partition(vector<int>& nums,int low,int high)
{
    int i = low, j = low - 1, k = high + 1;
    int pivot = nums[low];
    while(i < k )
    {
        if(nums[i] < pivot)
        {
            swap(nums[i],nums[j+1]);
            ++i,++j;
        }
        else if(nums[i] == pivot)
        {
            ++i;
        }
        else 
        {
            swap(nums[i], nums[k-1]);
            --k;
        }
    }
    return j + 1;
}
// @lc code=end

