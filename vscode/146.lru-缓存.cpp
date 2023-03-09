/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include<iostream>
#include<unordered_map>
using namespace std;
// 借助两个数据结构 nodelist和node来实现lru的内部结构

class LRUCache {
public:
// 双向Node 构建双向链表
//key-->(key,val) kv存储
//访问时间用双向链表的头尾节点来记录 
    class Node{
    public:
        int key;//key
        int val;//访问时间
        Node *prev,*next;
        Node(int k,int v)
        {
            key = k;
            val = v;
        }
    };
// double list 提供addLast，remove，removefirst(头部的数据是最久没有被使用的)
    class DoubleList{
    private:
        Node *head,*tail;
        int size ;

    public:
        DoubleList()
        {
            //初始化
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addLast(Node *x)
        // head n1 n2 ...... x tail
        {
            x->prev=tail->prev;
            x->next=tail;
            tail->prev->next=x;
            tail->prev=x;
            size++;
        }

        void remove(Node *x)
        {
            x->prev->next=x->next;
            x->next->prev=x->prev;
            size--;
        }

        Node* removefirst()//删除链表的第一个节点并返回
        {
            if(head->next==tail)
            {
                return nullptr;
            }
            Node *first = head->next;
            remove(first);
            return first;
        }

        int getsize()
        {
            return size;
        }
        
    };

    int cap;//容量
    DoubleList *cache;
    unordered_map<int,Node*> *map;//key-->(key,val)

    LRUCache(int capacity) {
        cap=capacity;
        //cache和map两个数据结构同时操作
        cache = new DoubleList();
        map = new unordered_map<int,Node*>;
    }
    //找到最近使用的节点，移动到链表尾部
    void makeRecently(int key)
    {
        Node *x = (*map)[key];
        (*cache).remove(x);
        (*cache).addLast(x);
    }
    //添加最近使用的元素
    void addrecently(int key,int val)
    {
        Node *x = new Node(key,val);
        (*cache).addLast(x);
        //放在map中
        (*map)[key]=x;
    }
    //删除一个key
    void deletekey(int key)
    {
        Node *x = (*map)[key];
        (*cache).remove(x);
        (*map).erase(key);
    }
    //删除最久没有使用的
    void removeLeastRecently()
    {
        Node *delete_node = (*cache).removefirst();
        int delete_key=delete_node->key;
        (*map).erase(delete_key);
    }


    int get(int key) {
        auto it = (*map).find(key);
        //不在
        if(it==(*map).end())
        {
            return -1;
        }

        // recently
        makeRecently(key);
        return (it->second)->val;
    }
    
    void put(int key, int value) {
        auto it = (*map).find(key);
        // 如果在map中，删除旧的数据，然后插入新的数据
        if(it != (*map).end())
        {
            deletekey(key);
            addrecently(key,value);
            return ;
        }

        //不在map中
        if(cap == (*cache).getsize())
        {
            removeLeastRecently();
        }

        addrecently(key,value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end




int main()
{
    // Node *n1= new Node(2,5);
    // cout<<n1->key;
    int x = 2;
    LRUCache c=LRUCache(2);
    c.put(1,1);
    c.put(2,2);
    c.get(1);
    c.put(3,3);
    cout<<c.get(2);
    return 0;
}

