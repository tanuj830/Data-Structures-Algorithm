#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> &nums, int sum, int i, int n)
{
    if(i == n)
    {
        if(sum == 0)return 1;
        return 0;
    }
    
    if(sum >= nums[i])
    {
        return countSubsets(nums, sum - nums[i], i+1, n) + countSubsets(nums, sum, i+1, n);
    }
    else 
        return countSubsets(nums, sum, i+1, n);
}

int main()
{
    vector<int>nums = { 1, 2, 3, 4, 5 };
    int sum = 10;
    
    cout << countSubsets(nums, sum, 0, nums.size());
}