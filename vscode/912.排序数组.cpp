/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector> 
#include <random>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        shuffle(begin(nums), end(nums), default_random_engine(random_device()()));//所及打乱数组
        quicksort(nums,0,nums.size()-1);
        return nums;
    }

    void mergesort(vector<int>& nums, int low, int high);
    void merge(vector<int>& nums, int low, int high);
    void quicksort(vector<int>& nums, int low, int high);
    int partition(vector<int>& nums, int low, int high);
    void bubblesort(vector<int>& nums, int low, int high);
};

void Solution::quicksort(vector<int>& nums, int low, int high)
{
    if(low<high)
    {
        int par = partition(nums,low,high);
        quicksort(nums,low,par-1);
        quicksort(nums,par+1,high);
    }
}

int Solution::partition(vector<int>& nums, int low, int high)
{
    int i=low;
    int j=low-1; //小于区的右侧边界 
    int k=high+1; //大于区的左侧边界 
    // 中间是等于的区域
    int pivot=nums[low];
    while(i<k)
    {
        if(nums[i]<pivot)
        {
            swap(nums[i],nums[j+1]);
            ++i,++j;
        }
        else if(nums[i]==pivot)
        {
            ++i;
        }
        else if(nums[i]>pivot)
        {
            swap(nums[i],nums[k-1]);
            --k;
        }
    }
    return j+1;
}



void Solution::mergesort(vector<int>& nums, int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,high);
    }
}
void Solution::merge(vector<int>& nums, int low, int high)
{
    int mid = (low + high)/2;
    int i=low,j=mid+1,k=0;
    vector<int> temp(high-low+1); // 只拷贝low-high的部分
    while(i<=mid && j<=high)
    {
        if(nums[i] < nums[j])
        {
            temp[k] = nums[i];
            ++i;
        }
        else 
        {
            temp[k] = nums[j];
            ++j;
        }
        ++k;
    }
    // 剩余部分
    while(i<=mid)
    {
        temp[k] = nums[i];
        ++i,++k;
    }
    while(j<=high)
    {
        temp[k] = nums[j];
        ++j,++k;
    }
    // 拷贝临时数组
    for(int i = 0; i < temp.size(); ++i)
    {
        nums[i+low] = temp[i];
    }
}


// 每一轮排完之后会在末尾的到一个最大的数
void Solution::bubblesort(vector<int>& nums, int low, int high)
{
    int i,j;
    int size = high-low+1;
    for(i=low;i<size -1 ;++i)
    {
        for(j=0;j<size - i -1 ;++j)
        {
            if(nums[j]>nums[j+1])
            {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

// @lc code=end

int main()
{
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(1);

    Solution s;
    s.sortArray(arr);
    return 0;
}
