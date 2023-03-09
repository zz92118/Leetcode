/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==0)
        {
            return ;
        }
        int left=0;
        int right = s.size()-1;
        while(left<right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return ;
    }
};
// @lc code=end

