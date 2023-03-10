/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

/*
利用快慢指针的思想
slow 修改后数组的指针
fast 当nums[fast]!=nums[low] 指向下一个元素
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        int slow=0,fast=0;
        while(fast<nums.size())
        {
            if(nums[slow]!=nums[fast])
            {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
};
// @lc code=end

