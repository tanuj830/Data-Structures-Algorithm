// Given an integer array of coins[ ] of size N representing different types of currency and an integer sum, The task is to find the number of ways to make sum by using different combinations from coins[].  
// Note: Assume that you have an infinite supply of each type of coin. 
// Input: coins[] = { 1, 2, 3 }, sum = 4
// Output: 4
#include <bits/stdc++.h>

using namespace std;

int noOfWays(vector<int>coins, vector<vector<int>> &dp, int sum, int i)
{
    if(i == coins.size())return 0;
    if(sum == 0)return 1;
    if(dp[i][sum] != -1)return dp[i][sum];
    
    if(sum >= coins[i])
    {
        return dp[i][sum] = (noOfWays(coins, dp, sum - coins[i], i) + noOfWays(coins, dp, sum, i + 1));
    }
    else return dp[i][sum] = noOfWays(coins, dp, sum, i + 1);
}

int main()
{
    vector<int>coins = {2, 5, 3, 6};
    int sum = 10;
    vector<vector<int>> dp(coins.size() + 1, vector<int>(sum + 1, -1));
    
    cout << noOfWays(coins, dp, sum, 0); // output: 5
    return 0;
}