/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<iostream>
using namespace std; 

struct ListNode {
int val;
ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //不要改变原有的数据
        ListNode *dummy = new ListNode;
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        ListNode *p = dummy;
        while(p1!=nullptr && p2!=nullptr)
        {
            if(p1->val <= p2->val)
            {
                p->next = p1;
                p1 = p1 -> next;
            }
            else 
            {
                p->next = p2;
                p2 = p2 -> next;
            }
            p = p->next;
        }
        if(p1!=nullptr)
        {
            p->next = p1;
        }
        if(p2!=nullptr) 
        {
            p->next = p2;
        }
        return dummy->next;
    }
};
// @lc code=end

