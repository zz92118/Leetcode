/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution {

public:
    ListNode *head;
public:
    // Solution();
    // void out(ListNode* head);
    bool isPalindrome(ListNode* head);
    bool isPalindrome2(ListNode* head);
    bool isPalindrome3(ListNode* head);
};

bool Solution::isPalindrome(ListNode* head)
{
    //慢指针指向中点后一个（基于）
    //1 2 3 2 1
    //      * 
    //1 2 3 3 2 1
    //      * 
    if(head==nullptr || head->next == nullptr)
    {
        return true;
    }
    ListNode *slow,*fast;
    slow = head;
    fast = head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast!=nullptr)
    {
        slow = slow->next;// 确保指向中间的后一个节点 或者后一个节点
    }
    
    // reverse list
    ListNode *curr = slow ;
    ListNode *prev = nullptr;
    while(curr != nullptr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    //prev返回
    ListNode *left = head;
    ListNode *right = prev;
    while(right != nullptr)
    {
        if(left->val != right->val)
        {
            return false;
        }
        right = right->next;
        left = left->next;
    }
    return true;
}

// bool Solution::isPalindrome(ListNode* head)
// {
//     //慢指针指向中点后一个或者中点后一个
//     //1 2 3 2 1
//     //    *
//     //1 2 3 3 2 1
//     //      *
//     //base case
//     if(head==nullptr || head->next==nullptr)
//     {
//         return true;
//     }
//     ListNode *slow = head;
//     ListNode *fast = head;
//     ListNode *curr = head;
//     stack<ListNode*> s;
//     while(fast != nullptr && fast->next!=nullptr)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     slow = head;
//     while(slow != nullptr)
//     {
//         s.push(slow);
//         slow = slow->next;
//     }

//     while(!s.empty())
//     {
//         ListNode* temp = s.top();
//         s.pop();
//         if(temp->val != curr->val)
//         {
//             return false;
//         }
//         curr = curr->next;
//     }
//     return true;
// }



// void Solution::out(ListNode* head)
// {
//     ListNode *p;
//     p=head;
//     while(p!=nullptr)
//     {
//         cout<<p->val<<" ";
//         p=p->next;
//     }
//     cout<<endl;
// }



// @lc code=end

int main()
{
    Solution s;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    ListNode *head = new ListNode;
    ListNode *curr;
    for(vector<int>::iterator i=a.begin();i<a.end();i++)
    {
        ListNode *p,*temp;
        p = new ListNode;
        temp = new ListNode;
        p=head;
        //heda 存储数据
        if(i==a.begin())
        {
            head->val=*i;
            head->next=nullptr;
            curr=head;
        }
        else
        {
            ListNode *temp;
            temp=new ListNode;
            temp->val=*i;
            temp->next=nullptr;
            curr->next=temp;
            curr=temp;
        }


    }
    // s.out(s.head);
    // cout<<s.isPalindrome(s.head)<<endl;
    // cout<<s.isPalindrome2(s.head)<<endl;
    cout<<s.isPalindrome3(s.head)<<endl;
    // s.out(s.head);
    return 0;
}




// bool Solution::isPalindrome2(ListNode* head)
// {
//     //慢指针指向中点后一个或者中点后一个
//     //1 2 3 2 1
//     //      *
//     //1 2 3 3 2 1
//     //      *
//     //base case
//     if(head==nullptr || head->next==nullptr)
//     {
//         return true;
//     }
//     ListNode *slow,*fast;
//     slow = head;
//     fast = head;
//     stack<ListNode*> s;
//     while(fast!=nullptr && fast->next!=nullptr)
//     {
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     ListNode *curr=head;
//     while(slow!=nullptr)
//     {
//         s.push(slow);
//         slow=slow->next;
//     }
//     while(!s.empty())
//     {
//         if((s.top())->val!=curr->val)
//         {
//             return false;
//         }
//         s.pop();
//         curr=curr->next;
//     }
//     return true;
// }

// bool Solution::isPalindrome(ListNode* head)
// {

//     stack<ListNode> s;
//     ListNode *current;
//     current=head;
//     while(current)
//     {
//         s.push(*current);
//         current=current->next;
//     }
//     current=head;
//     while(current)
//     {
//         if( (current->val)!=(s.top().val) )
//         {
//             return false;
//         }
//         s.pop();
//         current=current->next;
//     }
//     return true;

// }