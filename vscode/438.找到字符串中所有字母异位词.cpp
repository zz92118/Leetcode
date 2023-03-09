/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> need,window;
        vector<int> result;
        for(auto c : p)
        {
            ++need[c];
        }
        int left = 0, right = 0;
        int valid_char_nums = 0;
        while(right < s.size())
        {
            char c = s[right];
            ++right;
            if(need.count(c))
            {
                ++window[c];
                if(window[c] == need[c])
                {
                    ++valid_char_nums;
                }
            }
            while(right-left >= p.size()) // 收缩条件
            {
                if(valid_char_nums == need.size())
                { 
                    result.push_back(left);// 和567只有这里不一样了
                }
                char d = s[left];
                ++left;
                if(need.count(d))
                {
                    if(window[d] == need[d])
                    {
                        --valid_char_nums;
                    }
                    --window[d];
                }

            }
        }
        return result;
    }
};
// @lc code=end

