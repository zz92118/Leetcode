# 递归

/*
1.把问题转化为规模缩小了的同类的子问题

2.弟归终止条件

3.子问题的决策过程(向上翻回信息)

4.记录子问题的解（dp和暴力递归的区别）

*/


# DFS
## DFS 框架


1. 路径：也就是已经做出的选择。

2. 选择列表：也就是你当前可以做的选择。

3. 结束条件：也就是到达决策树底层，无法再做选择的条件。

- 做选择和撤销选择对应了前序和后序的遍历过程。
    <div align=center>
    <image src="fig/04/01.jpg"  width="70%" height="50%">
    </div>

    


    <div align=center>
    <image src="fig/04/01-2.jpg"  width="70%" height="50%">
    </div>

- DFS 算法的前序和后序位置应该在 for 循环外面，不过回溯算法和 DFS 算法略有不同
```C++
result = []

def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择:路径变化,index变化
        backtrack(路径, 选择列表)
        撤销选择 根据题目的要求回溯

    决策过程 max 或者 min的决策
```

## 几个重要的概念：
* 排列，
* 组合，
* 子集（是集合）
* 子串（KMP，Manacher），
* 子序列（DP）
```C++
子集和子序列：子序列的话内部是有序的，子集内部也是无序的 {1,4,4,4,1}为例


子集：{1,4}和{4,1}是一样的

子序列：{1,4}和{4,1}是不一样的

子串和子序列：子串是连续的，子序列可以不连续
```
1. 子集问题
   
    * [78. 子集（中等）](https://leetcode-cn.com/problems/subsets) [本地链接](vscode/78.子集.cpp)

    * [ 子集2（中等）](https://leetcode-cn.com/problems/subsets-ii) [本地链接](vscode/90.子集-ii.cpp)

2. 排列问题
   
    * [46. 全排列（中等）](https://leetcode-cn.com/problems/permutations) [本地链接](vscode/46.全排列.cpp)

    * [ 全排列2（中等）](https://leetcode-cn.com/problems/permutations-ii) [本地链接](vscode/47.全排列-ii.cpp)`

3. 组合问题

    * [77. 组合（中等）](https://leetcode-cn.com/problems/combinations) [本地链接](vscode/77.组合.cpp)

    * [组合总和](https://leetcode-cn.com/problems/combination-sum) [本地链接](vscode/39.组合总和.cpp)

4. 其他的的DFS问题
   
    * [37. 解数独（困难）](https://leetcode-cn.com/problems/sudoku-solver) [本地链接](vscode/37.解数独.cpp) 有点难 先刷行再刷列 index列表

    * [N皇后](https://leetcode-cn.com/problems/n-queens) [本地链接](vscode/51.n-皇后.cpp) 


        - dfs 的函数签名 `void dfs(int depth, int n, vector<int> &records)`
        ```cpp

            vector<int> records(n, 0);// records[i]代表了i行皇后的列号
            
            void dfs(int depth, int n, vector<int> &records)
            {
                if(depth >= n)
                {
                    setOne(n, records);
                    return;
                }
                for(int j = 0; j < n; ++j)
                {
                    if(canSet(depth, j, records)) // 检查depth行上那一列可以放置
                    {
                        records[depth] = j;//depth行皇后的列坐标为j  records[i]代表了i行皇后的列号
                        dfs(depth + 1, n, records);
                        // 没有回溯撤销的地方
                    }
                }
            }
        ```
    * [N皇后2](https://leetcode-cn.com/[problems](https://leetcode.cn/problems/n-queens-ii/)/n-queens) [本地链接](vscode/52.n皇后-ii.cpp)
 
    * [22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses) [本地链接](vscode/22.括号生成.cpp) : 这个题可变参数列表有两个!

   * [剑13 机器人运动路径](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof) [本地链接](vscode/剑13.机器人运动路径.cpp)



5. 等和子集问题(K个或者2个等和子集)
   
    * [698. 划分为k个相等的子集（中等）](https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/) [本地链接](vscode/698.划分为k个相等的子集.cpp)


    * [416. 分割等和子集 需要DP降低复杂度](https://leetcode-cn.com/problems/partition-equal-subset-sum) [本地链接](vscode/416.分割等和子集.cpp)

6. 岛屿问题
    
    思路是淹没每个岛屿相邻的陆地,变成海水,也可以用visited判断重复,不同就是淹没的数量 
    注意visited和dfs边界的问题

    返回值要注意 return 1+各种可能性


    * [200. 岛屿数量（中等](https://leetcode-cn.com/problems/number-of-islands) [本地链接](vscode/200.岛屿数量.cpp)

   * [1254. 统计封闭岛屿的数目（中等）](https://leetcode-cn.com/problems/number-of-closed-islands) [本地链接](vscode/1254.统计封闭岛屿的数目.cpp)

   * [1255. 飞地的数量（中等）](https://leetcode-cn.com/problems/number-of-enclaves) [本地链接](vscode/1020.飞地的数量.cpp)

   * [1256. 岛屿的最大面积（中等）](https://leetcode-cn.com/problems/max-area-of-island) [本地链接](vscode/695.岛屿的最大面积.cpp)

   * [1950. 统计子岛屿（中等）](https://leetcode-cn.com/problems/count-sub-islands) [本地链接](vscode/1905.统计子岛屿.cpp)

   * [1258. 不同的岛屿数量（中等）](https://leetcode-cn.com/problems/number-of-distinct-islands) 





解决排列、组合、子集、等和数组划分 集合划分（两个 K个） 

终止条件上的差别 

子集:选和不选

组合:i的便利并加入 终止条件：组合数组的size大小

排列:i的遍历和swap 终止条件：index的大小

可选参数列表


可变参数列表 right 和 left两个参数变化 , left< n ; right<n

分割等和子集问题:先把子集的和算出来嘛,筛选一些参数先

数独 27: return 的结果
```C++
if(dfs(board,i,j+1))
{
    return true;
}
```





很多时候需要的变量可以放在全局里面，减少递归的参数会让你减少错误，然后可以把递归函数设计成void类型。
比如dfs框架，基于归并排序的逆序对问题

关于dfs框架要不要回溯清洗的问题
1. 清洗的模型：背包的变体拆分成两个和相等的数组（修改了arr）；字符串交换 最后一定要swap回来！！
2. 不清洗：N皇后

DFS回溯
dfs加备忘录的DP数组 记忆化搜索
DP 根据状态转移方程写数组

```C++
// 递归算法的代码框架
//终止条件可能有两个??
 函数类型:   void int bool  dfs(int index)//各种参数列表 index表示递归的深度
    {
        if(终止条件:index越界和rest的值)
        {
            if(rest满足)
            {
                result++
                return ;
            }
            else if(rest不满足 || index越界)
            {
                return ;
            }
        }
        else
        {
            if( index)
            //dfs尝试各种可能结果
            for(i=0;i<各种可能性;i++)

            if(满足约束条件)
            {
                dfs(index+1);
                //有些要做清理工作 比如字符串全排列，划分两个等和数组 划分多个等和数组
                //有些不需要清洗，比如N皇后，因为本来就是基于records【】数组进行dfs
                max(取,不取)//决策过程
            }
        }
    }

```


从dfs>>>>>>>>备忘录>>>>>>>>dp

```C++
// 递归算法的代码框架
    dp备忘录数组初始化为-1 没有被访问到
    int dfs(int i,int j,int 其他固定的参数)//各种参数列表 index表示递归的深度
    {

        if(备忘录有结果)
        {
            返回查询到的结果;
            return dp[i][j];
        }

        else  备忘录没有结果
        {
            int ans;
            if(终止条件)
            {
                结果处理
                if(是一种可能的结果)
                {
                    ans =1
                }
            }
            else
            {
                //dfs尝试各种可能结果
                for(i=0;i<各种可能性;i++)

                if(满足约束条件)
                {
                    ans=dfs(i+-1,j+1);
                    //各种可能结果的和
                    //有些要做清理工作 比如字符串全排列，划分两个等和数组
                    //有些不需要清洗，比如N皇后，因为本来就是基于records【】数组进行dfs
                }
            }
            //return语句更新备忘录 然后再return
            dp[i][j]=ans;
            return dp[i][j];
        }

    }

```

```C++
int 动态规划方法(int N,int start,int K_steps,int end)
{   
    vector<vector<int> >dp=0; //备忘录数组 并进行初始化为0
    //一定要注意边界条件！！！！
    dp[end][0]=1;
    for(int rest=1;rest<K_steps+1;rest++)//边界值是N还是N+1很重要
    {
        填入边界值
        for(int curr=2;curr<N;curr++)
        {
            填入dp[i][j];
            //包括枚举优化
        }
        填入边界值
    }
    return dp[i][j];
}


```
先看dfs过程的依赖，决定从哪开始填表
考虑边界条件 
debug的时候优先考虑边界条件


暴力递归到动态规划
题目—》找到暴力递归写法（尝试）

—》把可变参数，不讲究组织的形式，做缓存，那就是记忆化搜索的方法（拥有重复解的前提下）

—》精细化组织----》那就是动态规划

如果暴力过程中没有枚举行为（即通过循环来求得值）

则记忆化搜索和动态规划的时间复杂度一致，没有必要从记忆化搜索再优化为动态规划

什么暴力递归可以继续优化?
有重复调用同一个子问题的解，这种递归可以优化
如果每一个子问题都是不同的解，无法优化也不用优化

暴力递归和动态规划的关系
某一个暴力递归，有解的重复调用，就可以把这个暴力递归优化成动态规划
任何动态规划问题，都一定对应着某-个有解的重复调用的暴力递归
但不是所有的暴力递归，都一定对应着动态规划

面试题和动态规划的关系
解决一个问题，可能有很多尝试方法
可能在很多尝试方法中，又有若干个尝试方法有动态规划的方式
一个问题可能有若干种动态规划的解法

如何找到某个问题的动态规划方式?
1)设计暴力递归:重要原则+4种常见尝试模型!重点!
2)分析有没有重复解:套路解决
3)用记忆化搜索->用严格表结构实现动态规划:套路解决
4)看看能否继续优化:套路解决

面试中设计暴力递归过程的原则
1)每一个可变参数的类型，一定不要比int类型更加复杂
2)原则1)可以违反，让类型突破到一维线性结构，那必须是唯一-可变参数 ()
3)如果发现原则1)被违反，但不违反原则2)，只需要做到记忆化搜索即可
4)可变参数的个数，能少则少

常见的4种尝试模型
1)从左往右的尝试模型(很多 排列 组合问题)
2)范围上的尝试模型(纸牌博弈)
3)多样本位置全对应的尝试模型(最长公共子序列)
4)寻找业务限制的尝试模型


1）你已经有了一个不违反原则的暴力递归，而且的确存在解的重复调用

2）找到哪些参数的变化会影响返回值，对每一个列出变化范围

3）参数间的所有的组合数量，意味着表大小

4）记忆化搜索的方法就是傻缓存，非常容易得到

5）规定好严格表的大小，分析位置的依赖顺序，然后从基础填写到最终解

6）对于有枚举行为的决策过程，进一步优化
————————————————
版权声明：本文为CSDN博主「严太白」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u011624267/article/details/119464422


1）空间压缩

2）状态化简

3）四边形不等式

4）其他优化技巧






二维数组中的dfs问题 岛屿问题 跳马 机器人路径:
```C++
    int dfs(int i,int j,vector<vector<bool> > &visited)
    {
        //岛屿问题的思路是淹没岛屿(利用visited访问过就算淹没 同时可以淹没来替代visited数组)
        if(越界检查) 
        {
            return ;
        }
        if(其他可能的限制条件)
        {
            return ;            
        }
        if(被访问过)
        {
            return ;
        }

        else 
        {
            visited[i][j]=true;//先对这个节点进行访问
            for(可能达到的下一步)
            {
                return 1+dfs(inext,jnext,visited);
            }
        }
    }
```



# 弟归 DP问题
 长的 视频1 视频4 次品转换 咖啡 先后手


# 动态规划 DP

## 基本框架和思路
先写basecase 先写basecase 先写basecase

明确 base case -> 明确「状态」-> 明确「选择」 -> 定义 dp 数组/函数的含义。

```C++
# 初始化 base case
dp[0][0][...] = base
# 进行状态转移
for 状态1 in 状态1的所有取值：
    for 状态2 in 状态2的所有取值：
        for ...
            dp[状态1][状态2][...] = 求最值(选择1，选择2...)

```
备忘录的DFS只不过这种解法是「自顶向下」进行「递归」求解，

动态规划代码是「自底向上」进行「递推」求解。
  



* [509. 斐波那契数（简单）](https://leetcode-cn.com/problems/fibonacci-number) [本地连接](vscode/509.斐波那契数.cpp) 状态转移方程 

return f(n - 1) + f(n - 2)，dp[i] = dp[i - 1] + dp[i - 2]

* [322. 零钱兑换（中等）](https://leetcode-cn.com/problems/coin-change) [本地连接](vscode/322.零钱兑换.cpp)