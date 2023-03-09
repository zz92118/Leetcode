/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need,window;
        //needs 和 window 相当于计数器，分别记录 T(需要匹配的字符) 中字符出现次数和「窗口」中的相应字符的出现次数。
        for(auto c : t)
            ++need[c]; //need 中每个字符出现的次数就是string t 要匹配的字符s
        int left = 0, right = 0;
        int valid_char_nums = 0; // valid_char_nums = need.size() 进行收缩条件的判断
        int len = INT_MAX;// 记录窗口长度（初始化为最大，因为这里是minwindow）
        int start = 0;//记录返回的起始位置 所以再循环结束之后，滑动窗口虽然变了，但记录的start和len并没有变，所以能返回正确的数值
        while(right < s.size())
        {
            // 读取字符并扩大窗口
            char c = s[right];
            ++right;
            if(need.count(c))
            {
                ++window[c];
                if(window[c] == need[c]) // 恰好完成了匹配
                {
                    ++valid_char_nums;
                }
            }
            // 判断左侧是否需要收缩 表示可以收缩
            while(valid_char_nums == need.size())
            {
                // 更新最小覆盖子串
                if(right - left < len)
                {
                    start = left;
                    len = right - left;
                }
                char d = s[left];// 移除窗口的字符
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
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};
// @lc code=end

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        //left 左开 right右闭
        int left=0;
        int right=0;
        int valid_char_nums=0;//代表
        //记录最小串的索引和长度s
        int start =0;
        int len=INT_MAX;
        //初始化need数组
        for(int i=0;i<t.length();i++)
        {
            need[t[i]]++;
        }
        //一直到数组右边届  
        while(right<s.size())
        {
            //获取当前字符 
            char c=s[right];
            //窗口右移
            right++;
            //窗口数据更新
            if(need.count(c))
            {
                window[c]++;//如果没有这条记录,对应的map char-->int 为0
                if(window[c]==need[c])
                {
                    valid_char_nums++;//有一个字符得到了匹配
                }
            }

            // debug: 
            // cout<<left<<right<<endl;

            //判断left窗口收缩 
            while(valid_char_nums==need.size())//说明T可以被覆盖
            {
                //更新最小覆盖字符串
                if( right - left < len )
                {
                    start=left;
                    len = right-left;
                }
                //获取当前字符
                char d = s[left];
                //左移窗口
                left++;
                if(need.count(d))//只有d和需要得到的字符串有关的时候才更新window
                {
                    if(window[d] == need[d])
                    {
                        valid_char_nums--;
                    }
                    window[d]--;
                }

            }
        }
        if(len==INT_MAX)
        {
            return "";
        }
        else 
        {
            return s.substr(start,len);
        }

    }
};

int main()
{
    Solution s;
    cout<<s.minWindow("ADOBECODEBANC","ABC");
}

