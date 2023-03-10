/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
/*
相当给你一个 S 和一个 T，
请问你 S 中是否存在一个子串，包含 T 中所有字符且不包含其他字符？
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need,window;
        for(auto c : s1)
        {
            ++need[c];
        }
        int valid_char_nums = 0;
        int right = 0, left = 0;
        while(right < s2.size())
        {
            char c = s2[right];
            ++right;
            if(need.count(c))
            {
                ++window[c];
                if(need[c] == window[c])
                {
                    ++valid_char_nums;
                }
            }

            while(right - left >= s1.size()) //需要维护一个定长窗口（因为是排列）
            {
                // 是否找到了合法字符串
                if(valid_char_nums == need.size())
                {
                    return true;
                }
                char d = s2[left];
                ++left;
                if(need.count(d))
                {
                    if(need[d] == window[d])
                    {
                        --valid_char_nums;
                    }
                    --window[d];
                }
            }
        }
        return false;
    }
};
// @lc code=end

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need,window;
        int i;
        //need
        for(i=0;i<s1.length();i++)
        {
            need[s1[i]]++;
        }
        int left=0;
        int right=0;
        int valid_char_nums=0;//表示一个字符匹配上

        while(right<s2.size())
        {
            char c=s2[right];
            right++;
            //窗口数据更新
            if(need.count(c))
            {
                window[c]++;
                if(window[c]==need[c])
                {
                    valid_char_nums++;//表示某个字符已经匹配上
                }
            }

            //判断左侧是否需要收缩
            while( right - left == s1.size() )
            {
                //找到了可以的排列
                if(valid_char_nums==need.size())
                {
                    return true;
                }
                char d=s2[left];
                left++;
                //窗口数据更新
                if(need.count(d))
                {
                    if(window[d]==need[d])
                    {
                        valid_char_nums--;
                    }
                    window[d]--;
                }

            }
        }
        return false;
    }
};