/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return ;
        }
        ListNode * middle = middleList(head);
        ListNode * new_head = reverseList(middle);
        ListNode * curr = head;
        ListNode * curr2 = new_head;
        while(curr != nullptr && curr2 != nullptr)
        {
            ListNode *temp1 = curr->next;
            ListNode *temp2 = curr2->next;
            curr->next = curr2;
            curr = temp1;
            curr2->next = temp1;
            curr2 = temp2;
        }
        return ;
    }
    ListNode * reverseList(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode * prev = nullptr;
        ListNode * curr = head;
        while(curr != nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode * middleList(ListNode *head)
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode * slow = head, *fast = head->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// @lc code=end

