/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0 || s.size()==1)
        {
            return true;
        }
        string s_judge;
        for(const auto &c : s)
        {
            if(isalnum(c))
            {
                s_judge += tolower(c);
            }
        }
        // cout<<s_judge<<endl;
        int left=0;
        int right=s_judge.size()-1;
        while(left<right)
        {
            if(s_judge[left]!=s_judge[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.isPalindrome("A man, a plan, a canal: Panama");
}

