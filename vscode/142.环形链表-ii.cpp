/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>
#include<unordered_set>
using namespace std;
/*
设slow 和 fast相遇为 p
相遇节点和入换节点之间的距离为m
则 slow 走了 k，fast走了 2k
slow=head之后 继续走k-m
slow 和 fast相遇 return slow
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 使用set的简易版本
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        if(head==nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        ListNode * curr = head;
        while(curr != nullptr)
        {
            // 在set中 找到了相应的节点
            if(s.count(curr) > 0)
            {
                return curr;
            }
            s.insert(curr);
            curr = curr->next;
        }
        return nullptr;
    }
};

// 快慢指针版本
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr)
        {
            return nullptr;
        }

        ListNode *slow,*fast;

        slow=head;
        fast=head;

        while(fast!=nullptr && fast->next!=nullptr) // 空指针保护
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast)//经过走之后 slow和fast相交
            {
                break;
            }
        }
        //无环 fast 指向了 null就是五环
        if(fast==nullptr || fast->next==nullptr)
        {
            return nullptr;
        }
        
        slow = head;
        while(fast!=slow)
        {
            slow=slow->next;
            fast=fast->next;
        }

        return slow;
    }
};
// @lc code=end

