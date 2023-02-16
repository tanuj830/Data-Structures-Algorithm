// given rod of length n, we have to cut rod in different lengths as shown in length array also there is corroseponding price of cutted length
// Task is to maximize profit

#include <bits/stdc++.h>

using namespace std;


int findMaxProfit(vector<int>length, vector<int>price, vector<vector<int>> &dp, int wt, int i)
{
    if(i == length.size())return 0;
    if(dp[i][wt] != -1)return dp[i][wt];
    
    if(wt >= length[i])
    {
        return dp[i][wt] = max((price[i] + findMaxProfit(length, price, dp, wt-length[i], i)) , findMaxProfit(length, price, dp, wt, i+1));
    }
    else return dp[i][wt] = findMaxProfit(length, price, dp, wt, i+1);
}

int main()
{
    vector<int>length = {1,2,3,4};
    vector<int>price = {1, 1,1,6};
    int n = 4;
    vector<vector<int>> dp(length.size() + 1, vector<int>(n + 1, -1));
    
    cout << findMaxProfit(length, price, dp, n, 0); // output: 6
    return 0;
}