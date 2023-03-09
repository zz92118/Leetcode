
```C++
//字符串 数字的相互转化
cout<<to_string(1)<<endl;
cout<<atoi("1")<<endl;

atoi()是C语言的方法 处理字符数组
stoi()是C++的方法 处理字符串
atoi(s.c_str())方法可以处理字符串

string[index] 得到的是

//输入


```


```C++
//常用STL 容易忘的
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<priority_queue>

using namespace std;

int main()
{
    unordered_map<int,string> Map;
    unordered_set<int> Set;
    //大根堆和小根堆第三个参数是相反的

    //map 存放
    Map[1]="string1";
    Map[2]="string2";
    //map 取
    cout<<Map[1]<<endl;
    Map.size();

    //set存放
    Set.insert(1);
    Set.insert(2);
    Set.insert(2);
    Set.insert(2);
    //set查询
    Set.size();
    cout<<Set.count(3)<<endl;;

    // !!!谁他妈能想到两数之和这道题我卡在这里
    unordered_map<int,int>::iterator it = hashtable.find(key);//获取迭代类型 
    it->first();//key
    it->second();//value 
    if(it!=hashtable.end())//判断hash中有没有key的记录

    for(unordered_map<int,int>::iterator i=hashtable.begin();i!=hashtable.end();i++)
    {
        //迭代器
    }

    Set.clear();
    vector.clear(); 清空

    //rbgein rend begin end
    for(vector<int>::iterator i=a.begin();i!=a.end();i++)
    {

    }

    for(vector<int>::iterator i=a.rbegin();i!=a.rend();i++)
    {
        
    }
}
```

```C++
// 比较器的写法
class MinCostCompare
{
public:
    bool operator ()(const Project* n1,const Project* n2) const
    {
        return n1->cost > n2->cost;
    }
};
class MaxProfitsCompare
{
public:
    bool operator ()(const Project* n1,const Project* n2)const{
        return n1->profit < n2->profit;
    }
}; 

``` 

```C++
//输入方法
// C++ 读一行字符串
    string str;
    getline(cin,str);
//大小写转化
    tolower(char c)


```

```C++
// dp数组初始化
```