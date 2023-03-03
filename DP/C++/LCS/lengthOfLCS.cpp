#include <bits/stdc++.h>

using namespace std;

// Function for finding length of longest common subsequence
int  lcs(string p, string q, vector<vector<int>> &dp, int i, int j)
{
    if(i >= p.length() || j >= q.length())return 0;
    if(dp[i][j] != -1)return dp[i][j];
    if(p[i] == q[j])return dp[i][j] = (1 + lcs(p, q, dp, i+1, j+1));
    else return dp[i][j] = max(lcs(p, q, dp, i, j+1), lcs(p, q, dp, i+1, j));
}

int main()
{
    string p = "AGGTAB";
    string q = "GXTXAYB";
    
    vector<vector<int>>dp(p.length(), vector<int>(q.length(), -1));
    
    cout << lcs(p, q, dp, 0, 0); // 4
    return 0;
}