/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
/*
dummyhead:
prev:头插法的起始节点
curr:当前的节点 永远不变

使用头插法的思想将当前节点插入到prev的后面
            1.ListNode *temp = new ListNode;
            2.temp = curr->next;
            3.curr->next = temp->next;
            4.temp->next = prev->next;!!!!这一步注意 头插法
            5.prev->next = temp;

            头插法：
                temp->next = head->next;
                head->next = temp;
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        int i,j;
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;
        // left指向
        for(i=0;i<left-1;i++)
        {
            curr = curr->next;
            prev = prev->next;
        }
        // 反转right-left 次
        for(i=0;i<right-left;i++)
        {
            // 头插法
            ListNode *temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return dummy->next;
    }
};



// @lc code=end

