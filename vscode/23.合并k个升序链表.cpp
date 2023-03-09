/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
#include<queue>
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
    // 小根堆的比较器
    struct minCostCompare{
        bool operator()( ListNode *h1,  ListNode *h2)
        {
            return (h1->val) > (h2->val);
        }    
    };
    priority_queue<ListNode*, vector<ListNode*>, minCostCompare> heap;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 构造一个优先级队列 只存放头结点 每次pop的时候 新加入一个next节点
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        // 将k个链表的头结点push进小根堆
        for(auto head:lists)
        {
            if(head != nullptr)
            {
                heap.push(head);
            }
        }

        while(!heap.empty())
        {
            // temp节点
            ListNode * temp = heap.top();
            if(temp->next != nullptr)
            {
                heap.push(temp->next);
            }
            temp->next = nullptr;
            heap.pop();
            curr->next = temp;
            curr = curr->next;
        }
        return dummy->next;
    }
};
// @lc code=end

