#include<bits/stdc++.h>
using namespace std;

int noOfWays(int n, int i, vector<int> &dp)
{
    if(i == n)return 1;
    if(i > n)return 0;
    if(dp[i] != 0)return dp[i];

    int left = dp[i] = noOfWays(n, i+1, dp);
    int right = dp[i] = noOfWays(n, i+2, dp);

    return (left + right);
}

int main()
{
    int n;
    cout << "enter no of stairs" << endl;
    cin >> n;

    vector<int> dp(n,0);
    cout << noOfWays(n, 0, dp);
}