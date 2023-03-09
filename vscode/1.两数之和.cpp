/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;
/*
复杂度分析 O(N*2)
//主要是找 target - x的复杂度 从 N 优化到常数项1
find 方法的使用
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> hashtable;//数字----》下标
        for(size_t i = 0; i < nums.size(); ++i)
        {
            unordered_map<int,int>::iterator it = hashtable.find(target - nums[i]);// 对于每个数，我要找的是target - nums[i]
            if(it!=hashtable.end())
            {
                result.push_back(i);
                result.push_back(it->second);//加入hahs的value
            }
            else 
            {
                hashtable[nums[i]]=i;
            }
        }
        return result;
    }
};
// @lc code=end

vector<int> twoSum(vector<int>& nums, int target) {
    // 双指针解法 
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    vector<int> result(2);
    while(left < right)
    {
        int sum = nums[left] + nums[right];
        if(sum == target)
        {
            result[0] = nums[left];
            result[1] = nums[right];
            return result;
        }
        else if(sum < target)
        {
            ++left;
        }
        else if(sum > target)
        {
            --right;
        }
    }
    return result;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(11);
    arr.push_back(15);

    for(vector<int>::iterator i=arr.begin();i!=arr.end();i++)
    {
        cout<<*i<<endl;
    }

    Solution s;
    s.twoSum(arr,9);
    return 0;
}
