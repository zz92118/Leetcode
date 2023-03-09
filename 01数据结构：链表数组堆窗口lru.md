[左程云课程链接](https://shimo.im/docs/68cd6h3TwygPwx8W/read%E7%AC%94%E8%AE%B0%E4%BC%A0%E9%80%81%E9%97%A8)

[算法小超github传送门]()

* 注意空指针保护问题`while (p != nullptr)` 或者 `if(p != nullptr)`
* 在遍历每个链表的时候，设置一个遍历的指针 明明为 `curr1,curr2` 或者 `p1,p2`


# 链表

* 数组：
  由于是紧凑连续存储,可以随机访问，通过索引快速找到对应元素，而且相对节约存储空间。但正因为连续存储，内存空间必须一次性分配够，所以说数组如果要扩容，需要重新分配一块更大的空间，再把数据全部复制过去，时间复杂度 O(N)；而且你如果想在数组中间进行插入和删除，每次必须搬移后面的所有数据以保持连续，时间复杂度 O(N)。

* 链表：因为元素不连续，而是靠指针指向下一个元素的位置，所以不存在数组的扩容问题；如果知道某一元素的前驱和后驱，操作指针即可删除该元素或者插入新元素，时间复杂度 O(1)。但是正因为存储空间不连续，你无法根据一个索引算出对应元素的地址，所以不能随机访问；而且由于每个元素必须存储指向前后元素位置的指针，会消耗相对更多的储存空间。
1. 回文链表

 * [21. 合并两个有序链表（简单）](https://leetcode-cn.com/problems/merge-two-sorted-lists/submissions/) [本地链接](vscode/21.合并两个有序链表.cpp)

 
 * [环形链表（简单）](https://leetcode-cn.com/problems/linked-list-cycle)[本地链接](vscode/141.环形链表.cpp)

 * [环形链表II（简单）](https://leetcode-cn.com/problems/linked-list-cycle-ii)[本地链接](vscode/142.环形链表-ii.cpp)

 * [链表的中间结点（简单）用于解决链表的归并排序问题]() [本地链接](vscode/876.链表的中间结点.cpp)


 * [160.相交链表（简单）](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) [本地连接](vscode/160.相交链表.cpp)：确保A B相交 或者同时指向nullptr while（A！=B）

 * [删除链表的倒数第 N 个结点（中等）](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)[本地链接](vscode/19.删除链表的倒数第-n-个结点.cpp) : 使用快慢指针 fast先走n步
  
 ## 链表排序问题
    使用归并排序的时候 要时刻注意排序问题的区间
    [low,mid) [mid.high)的区间进行归并排序
    链表插入排序、链表反转等问题，涉及到插入节点（反转节点）前一个节点的问题，需要使用prev指针，记录下curr前一个节点的位置
    dummy哑结点，最后 return dummy->next;

 * [143. 重拍链表](https://leetcode.cn/problems/reorder-list/) [本地连接](vscode/143.重排链表.cpp)
  
    思路就是先找到中点，然后将后半段逆序，然后合并两个链表

 * [147. 链表插入排序](https://leetcode-cn.com/problems/insertion-sort-list/) [本地链接](vscode/147.对链表进行插入排序.cpp)

    维护一个已经排好序的链表 最后一个是 *Tail表示排好序的链表的尾部节点

    if curr->val < tail->val 在head到tail的区域找到插入的节点 ，用prev指针表示插入节点的前一个节点
 
    else curr->val >= tail->val 在tail尾部插入

    每一步都要注意tail尾结点的next

 * [148. 链表归并排序]((https://leetcode-cn.com/problems/sort-list/)) [本地链接](vscode/148.排序链表.cpp)

 ## 反转链表问题
 ```
 1.翻转链表的两种方法：递归实现和迭代实现 

 2.curr prev 指针迭代实现 

 3.链表是一种具有递归性质的数据结构 表现为 reverse时，问题规模变小，问题性质不变

 4.！！！！后面的这些节点也是一条链表，而且规模（长度）比原来这条链表小，这就叫子问题。



 ```
 * [206. 反转链表（简单）](https://leetcode-cn.com/problems/reverse-linked-list/) [本地连接](vscode/206.反转链表.cpp) 
    
    curr prev 指针在合适的时间更新

    //迭代实现 最基础的模板，之后所有的版本基本都可以在此基础上修改
    ```cpp
        ListNode *curr = head;
        ListNode *prev = nullptr;// 最后一个节点 指向nullptr
        while(curr!=nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    ```

 * [92. 反转链表II（中等）](https://leetcode-cn.com/problems/reverse-linked-list-ii/)  [本地连接](vscode/92.反转链表-ii.cpp) 
    
    左右边界的反转链表 加入dummyHead 确定curr和prev的初始位置即可

    ```cpp
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
    ```

    另一种可行的方法是,给定head和tail的区间进行翻转
    ```cpp
    ListNode* reverse(ListNode* head,ListNode* tail)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while(curr!=tail)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ```
 * [25. K个一组翻转链表（困难）](https://leetcode-cn.com/problems/reverse-nodes-in-k-group) [本地连接](vscode/25.k-个一组翻转链表.cpp)


    我们可以把原先的 head 指针移动到后面这一段链表的开头，然后继续递归调用 reverseKGroup(head, 2)，因为子问题（后面这部分链表）和原问题（整条链表）的结构完全相同，这就是所谓的递归性质。

    base case 的处理是不足k个直接return nullptr（这里就是递归出口）

    <div align=center>
    <image src="fig/01/01-k-reverse.jpg"  width="50%" height="50%">
    </div>

    中间也要用到`ListNode* reverse(ListNode* head,ListNode* tail)`这个函数
## dummy head 虚拟头结点
****
* 当你需要创造一条新链表的时候，可以使用虚拟头结点简化边界情况的处理。

* 虚拟头节点是真的好用, 凡是需要考虑左右边界的问题, 加个虚拟头节点准没错.

****

  * [147. 链表插入排序](https://leetcode-cn.com/problems/insertion-sort-list/) [本地链接](vscode/147.对链表进行插入排序.cpp)

  * [92. 反转链表II（中等）](https://leetcode-cn.com/problems/reverse-linked-list-ii/)[本地连接](vscode/92.反转链表-ii.cpp)

 * [21. 合并两个有序链表（简单）](https://leetcode-cn.com/problems/merge-two-sorted-lists/submissions/) [本地链接](vscode/21.合并两个有序链表.cpp)
 * [86. 分隔链表](https://leetcode.cn/problems/partition-list/) [本地连接](vscode/86.分隔链表.cpp)

    - 分隔链表是合并链表的逆操作，把原链表一分为二。解决的方法是使用两个虚拟头结点，最后连接两个链表。可以使用一个`Listnode *temp`的中间变量，在遍历到节点的时候新建临时节点，（我觉得更加方便理解）
 * [23. 合并k个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/) [本地链接](vscode/86.分隔链表.cpp)
        
    构造一个优先级队列 只存放头结点 每次pop的时候 新加入一个next节点

    将k个链表的头结点push进小根堆, 

    while(!q.empty()) ，依次得到升序的节点，同时push进next节点

  * [19. 删除链表的倒数第 N 个结点（中等）](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list)[本地链接](vscode/19.删除链表的倒数第-n-个结点.cpp)       

    这里要用到dummy 节点是因为：删除第N个，在不使用prev指针的情况下则需要找到倒数n+1个节点，防止找到空指针。

    


## 头插法注意事项 
```
    1.ListNode *temp = new ListNode;
    2.temp = curr->next;
    3.curr->next = temp->next;
    4.temp->next = prev->next;!!!!这一步注意 头插法
    5.prev->next = temp;

    头插法：
        temp->next = head->next; temp变成头结点
        head->next = temp!;头结点接上temp
```

 ## 双指针问题


 * 链表问题：双指针问题 判断条件防止链表空节点的访问 

 * 数组问题：也可以用于原地修改数组 


* 双指针的四种题型 fast slow 指针初始化的时候都是head!!!!!
  
  ***


0.   **特殊题目**




      * [160.相交链表（简单）](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) [本地连接](vscode/160.相交链表.cpp)
        
        ：确保A B相交 或者同时指向nullptr while（A！=B）


        <div align=center>
        <image src="fig/01/04-intersection2.png"  width="50%" height="50%">
        </div>

        <div align=center>
        <image src="fig/01/04-intersection.jpeg"  width="50%" height="50%">
        </div>
        
            


 1. **slow 和 fast 一起走 ，遇到题目给定的case时，fast继续走，slow停**

    * [83. 删除排序链表中的重复元素（简单)](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/) [本地链接](vscode/83.删除排序链表中的重复元素.cpp)
        
        ```cpp
            while(fast!=nullptr)
            {
                if(slow->val != fast->val)
                {
                    // 跳过中间相等的节点
                    slow->next = fast;
                    slow = slow->next;
                }
                fast = fast->next;
            }
            slow->next = nullptr;//断开连接
        ```

   
 2. **fast先走n步**
   
    * [19. 删除链表的倒数第 N 个结点（中等）](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list)[本地链接](vscode/19.删除链表的倒数第-n-个结点.cpp)        

         考虑要删除的节点是链表的头结点的情况 使用一个dummy，找到倒数n+1个节点，这样就不会访问到空指针了。


    <div align=center>
    <image src="fig/01/02-k-last-node.jpeg"  width="50%" height="50%">
    </div>
    

 3. **fast走两步 slow走一步 注意空指针的保护问题！！**

    ```C++
        // 注意空指针保护

        while(fast!=nullptr && fast->next!=nullptr)
        {
            
        }
    ```

    *  [链表的中间结点（简单）用于解决链表的归并排序问题](https://leetcode.cn/problems/middle-of-the-linked-list/) [本地链接](vscode/876.链表的中间结点.cpp)
  
        这个是最基础的 

   
    *   [环形链表（简单）](https://leetcode-cn.com/problems/linked-list-cycle)[本地链接](vscode/141.环形链表.cpp) 

        slow一次走一步 fast一次走两步
        fast和slow最终相交在一个点

    *   [环形链表II（返回入换节点）](https://leetcode-cn.com/problems/linked-list-cycle-ii)[本地链接](vscode/142.环形链表-ii.cpp)

        可以用快慢指针的方法（看题解吧 走到交点之后slow返回到head，之后slow和fast再次相交的地方就是入环节点），也可以用hashset做
       
    * [234.回文链表](https://leetcode-cn.com/problems/palindrome-linked-list) [本地连接](vscode/234.回文链表.cpp)

        确保slow指向中间节点的后一个位置
        <div align=center>
        <image src="fig/01/03-palindrome2.jpg"  width="50%" height="50%">
        </div>
        
        使用翻转链表的方法判定回文链表

        <div align=center>
        <image src="fig/01/03-palindrome.jpg"  width="50%" height="50%">
        </div>
        



****
****
****



# 堆算法

* [相对有序数组排序](https://blog.csdn.net/qq_39716995/article/details/120491062)

```C++
priority_queue <int,vector<int>,greater<int> >q;// 小根堆
priority_queue <int,vector<int>,less<int> >q;//大根堆

//比较器
class MinCostCompare
{
public:
    bool operator ()(const Project* n1,const Project* n2) const
    {
        return n1->cost > n2->cost;
    }
};

// 操作:
// heap_insert
// heapify
```

# 栈和队列
两个栈实现队列 

两个队列实现栈的算法重新刷一遍 

整理

用环形数组和双向链表进行实现

逆波兰式 

括号匹配

# 字符串相关算法
## KMP
* [找出字符串中第一个匹配项的下标](https://leetcode-cn.com/problems/implement-strstr/)  [本地链接](vscode/28.实现-str-str.cpp)


next[]数组：记录前缀后缀的长度

看代码吧 多写几遍就会了核心思想是从str1！=str2的点开始，，利用next【】把str2往后推


## Manacher
* [5最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)  [本地链接](刷题刷题/KMP_Manacher/manacher.cpp)

* 将所有字符用#进行扩充，不然无法匹配偶数长度的字符串
* 数据结构：
```
int arr[]回文半径长度数组

int R ：扩充到当前位置的可以形成回文的最右的右边界
int C ：扩充到当前位置的可以形成回文的最右的中心点
```
* 两种可能的情况
```C++
    1.index+arr[index]>r :暴力扩充

    2.index+arr[index]>=r
        2.1 index_的回文区域在L和R的内部 不更新
        2.2 index_的回文区域在L和R的外部 不更新
        2.3 index_的回文区域在L和R的边界 更新

    代码合并：
        for(i=0;i<str.length();i++)
        {
            //设置不用验证的区域

            //需要验证的区域ß
            while(i+radis_arr[i]<str.length() && i-radis_arr[i]>-1)
            {
                //可以继续扩充 对应情况1和2.3
                if(str[i+radis_arr[i]]==str[i-radis_arr[i]])
                {
                    radis_arr[i]++;
                }
                //对应情况2.2和2.1 不能继续扩充
                else 
                {
                    break;
                }
            }
            //更新r和c同步更新，更新最大值
            length=max(length,radis_arr[i]);
        }
```

## [滑动窗口（字符串问题）](https://labuladong.gitee.io/algo/2/21/56/)
 滑动窗口算法的思路是这样：

  1. 我们在字符串 S 中使用双指针中的左右指针技巧，初始化 left = right = 0，把索引左闭右开区间 [left, right) 称为一个「窗口」。

  2. 我们先不断地增加 right 指针扩大窗口 [left, right)，直到窗口中的字符串符合要求（包含了 T 中的所有字符）。

  3. 此时，我们停止增加 right，转而不断增加 left 指针缩小窗口 [left, right)，直到窗口中的字符串不再符合要求（不包含 T 中的所有字符了）。同时，每次增加 left，我们都要更新一轮结果。

  4. 重复第 2 和第 3 步，直到 right 到达字符串 S 的尽头。

  * 这个思路其实也不难，第 2 步相当于在寻找一个「可行解」，然后第 3 步在优化这个「可行解」，最终找到最优解，也就是最短的覆盖子串。左右指针轮流前进，窗口大小增增减减，窗口不断向右滑动，这就是「滑动窗口」这个名字的来历。

 下面画图理解一下，needs 和 window 相当于计数器，分别记录 T 中字符出现次数和「窗口」中的相应字符的出现次数。

  [传送门](https://labuladong.gitee.io/algo/2/21/56/)

  区间 [left, right) 是左闭右开的，

  * [76.最小覆盖子（hard）](https://leetcode-cn.com/problems/minimum-window-substring/)
  [本地链接](vscode/76.最小覆盖子串.cpp)


  * [567字符串的排列（中等）](https://leetcode-cn.com/problems/permutation-in-string/)
  [本地链接](vscode/567.字符串的排列.cpp)

* [438.找到字符串中所有字母异位词（中等）](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)
[本地链接](vscode/438.找到字符串中所有字母异位词.cpp)


* [3.无重复字符的最长子串（中等）](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)
[本地链接](vscode/3.无重复字符的最长子串.cpp)


```C++
#include<unordered_map>
void slidingwindows(string s1,string s2)
{

    unordered_map<char,int> need,window;
    int left=0;
    int right=0;
    int valid=0;//记录匹配上的字符的个数;排列问题只需要解决匹配字符的个数就行了

    //初始化need数组目标匹配字符串每个字符的个数
    for(i=0;i<s2.size();i++)
    {
        need[s2[i]]++;
    }

    while( right < s1.size() )
    {
        char c = s2[right];
        right++;
        //滑动窗口的更新操作:注意一下每个语句是什么意思
        if(need.cout(c))//窗口的R匹配到了需要的字符char
        {
            windows[c]++;
            if(windows[c]==need[c])//如果这个字符c 刚好和需要的字符数量相等
            {
                valid++;//在一个字符上匹配成功
            }
        }
        //判断左口是否需要收缩
        while(valid==need.size())//代表是一个解了，但不一定是最优解，通过收缩left更新最优解
        {
            if(判断条件)
            {
                更新
            }

            char d = s1[left];
            left++;
            //滑动窗口更新的操作 和右侧更新的操作相反，注意顺序
            if(need.count[d])
            {
                if(windows[d]==need[d])
                {
                    valid--;
                }
                windows[d]--;
            }

            if(判断条件)
            {
                //也有可能是在这里更新题目的答案
            }
        }
        
    }
    return ans;
}
```


# 数学相关题目
## 取余数的问题
[回文数](https://leetcode-cn.com/problems/palindrome-number/) : while循环中计算余数和除数



# 哈希函数哈希表

## 布隆过滤器
只有add和check操作，没有delete

适用于黑名单爬虫

存在一定失误率

# morris便利

# 位运算
讲解视频在moriios便利那个视频

# 有序表AVLSB黑红 
暴力递归（下）的视频


# 前缀树
 短的视频 看得多的那个 《暴力递归》
# 图算法

# 二叉树
 后序遍历的非递归实现
 ```
 先序: root left right
 怎么改后序： preorder 的left 和 right 交换，变成 root right left

 然后逆序就成了 left right root

 ```



 ## 位图BitMap
int a[10] 表示 10*32=320个位的状态

## RandomPool

针对insert我们可以实现二个map同步操作，

针对delete操作，我们确实可以直接在(key, index)进行操作，

针对getRandom，虽然Hash表返回的是近似等概论的，

## 一致性哈希原理
解决负载不均衡问题,按照比例和机器的性能,通过虚拟节点管理负载
[传送门](https://blog.csdn.net/kefengwang/article/details/81628977)


## LRU算法

 * [146. LRU算法cache](https://leetcode.cn/problems/lru-cache/) [本地链接](vscode/146.lru-缓存.cpp)
  
  lru作为cache，核心数据结构是双向链表+哈希表
  
  * 为什么要用哈希表（提供基本的kv存储功能）：将key---(key,value)的映射，就是kv存储的核心 哈希表，根据key找到value
  * 为什么要用双向链表（提供cache缓存功能，并记录时间）：LRU找到最近未使用的节点放在表头（通过这个表示时间），最近使用的放在表尾

双向链表提供：addLast，remove，removeFirst，getsize功能

```C++
LRUCache(int capacity) {
    cap=capacity;
    //cache和map两个数据结构同时操作
    cache = new DoubleList();
    map = new unordered_map<int,Node*>;
}
```

向上提供统一的接口API，同时操作cache和map两个数据结构（不然get和put的逻辑层会很混乱）
* makeRecently：将这个key设置为最近使用的
* addrecently：添加元素，并设置为最近使用
* deletekey：删除一个key（需要紧接着addrecently）
* removeleastrecently：删除最久未使用的

然后put和get封装这两种操作
