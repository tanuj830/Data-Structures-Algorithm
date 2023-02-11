// Count of subsets with sum equal to X

// Input: arr[] = {1, 2, 3, 3}, X = 6 
// Output: 3 
// All the possible subsets are {1, 2, 3}, 
// {1, 2, 3} and {3, 3}

// Input: arr[] = {1, 1, 1, 1}, X = 1 
// Output: 4 

#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> &nums, int sum, int i, int n, vector<vector<int>> &dp)
{
    if(i == n)
    {
        if(sum == 0)return 1;
        return 0;
    }
    if(dp[i][sum] != -1)return dp[i][sum];

    if(sum >= nums[i])
    {
        return dp[i][sum] = countSubsets(nums, sum - nums[i], i+1, n, dp) + countSubsets(nums, sum, i+1, n, dp);
    }
    else 
        return dp[i][sum] = countSubsets(nums, sum, i+1, n, dp);
}

int main()
{
    vector<int>nums = { 1, 2, 3, 4, 5 };
    int sum = 10;
    vector<vector<int>>dp(nums.size(), vector<int>(sum+1, -1));

    
    cout << countSubsets(nums, sum, 0, nums.size(), dp);
}