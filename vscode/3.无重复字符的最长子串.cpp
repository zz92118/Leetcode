/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<string>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;
        int left = 0;
        int right = 0;
        int len = 0;// 初始化为0 因为要找到最大的长度
        while(right < s.size())
        {
            char c = s[right];
            right++;
            window[c]++;
            while(window[c] > 1) // 有重复的判断 该缩小了
            {
                char d = s[left];
                left++;
                window[d]--;
            }
            len = max(len, right - left); // 更新len在收缩完成之后，保证len的答案不包含任何重复元素。
        }
        return len; 
    }
};
// @lc code=end

