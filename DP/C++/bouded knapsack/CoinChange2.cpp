// Find minimum number of coins that make a given value

// Given a value V, if we want to make a change for V cents, and we have an infinite supply of each of C = { C1, C2, .., Cm} valued coins, what is the minimum number of coins to make the change? If it’s not possible to make a change, print -1.

// Examples:  

// Input: coins[] = {25, 10, 5}, V = 30
// Output: Minimum 2 coins required We can use one coin of 25 cents and one of 5 cents 

// Input: coins[] = {9, 6, 5, 1}, V = 11
// Output: Minimum 2 coins required We can use one coin of 6 cents and 1 coin of 5 cents

// APPROACH: We can take coin and as well as not take that coin but the catch is we have to take care of that,
// If im TAKING COIN then dont increment index because we can take that coin unlimited times
// If im NOT TAKING COIN then increment index because i'm not intrested in that coin
// And parallely increment no of coins if you are taking coin.
// T.C => O(N) , S.C => O(N)
#include <bits/stdc++.h>

using namespace std;

int minNofWays(vector<int> nums, vector<vector<int>> &dp, int sum, int &minCoins, int i, int noOfCoins)
{
    if(i == nums.size())return 0;
    if(sum == 0)
    {
        minCoins = min(minCoins, noOfCoins);
        return 1;
    }
    if(dp[i][sum] != -1)return dp[i][sum];
    if(sum >= nums[i])
    {
        return dp[i][sum] = min(minNofWays(nums, dp, sum - nums[i], minCoins, i, noOfCoins + 1) , minNofWays(nums, dp, sum, minCoins, i + 1, noOfCoins));
    }
    else return dp[i][sum] = minNofWays(nums, dp, sum, minCoins, i + 1, noOfCoins);
}

int main()
{
    vector<int> nums = { 1, 3, 5 };
    int sum = 11;
    int minCoins = INT_MAX;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));

    minNofWays(nums, dp, sum, minCoins, 0, 0);
    cout << minCoins;
    return 0;
}