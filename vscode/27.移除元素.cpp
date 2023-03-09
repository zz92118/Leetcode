/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start

#include<vector>
#include<iostream>
using namespace std;
/*
快慢指针
slow fast
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        if(nums.size()==0)
        {
            return 0;
        }
        while(fast<nums.size())
        {
            if(nums[fast]!=val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            //不相等的时候就不移动了
            fast++;
        }
        return slow;
    }
};
// @lc code=end

