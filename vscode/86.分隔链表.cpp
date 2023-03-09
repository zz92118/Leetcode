/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
// 用两个虚拟节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr)
        {
            return nullptr;
        }
        // 两个 虚拟头结点
        ListNode *dummy1 = new ListNode;
        ListNode *dummy2 = new ListNode;
        ListNode * p1 = dummy1;
        ListNode * p2 = dummy2;
        ListNode * p = head;
        while(p!=nullptr)
        {
            // 建立一个临时节点 好理解一些
            ListNode *temp = new ListNode;
            temp->val = p->val;
            temp->next = nullptr;
            if(temp->val < x)
            {
                p1->next = temp;
                p1 = p1->next;
            }
            else 
            {
                p2->next = temp;
                p2 = p2->next;
            }
            p = p->next;
        }
        p1->next = dummy2->next;

        return dummy1->next;
    }
};
// @lc code=end
int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(4);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(2);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(2);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    Solution s;

    auto ps = s.partition(n1,3);

    ps;
    
}
