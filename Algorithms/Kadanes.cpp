#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int >nums={2,3,-10,4,2};
    int maxSum = INT_MIN, sum=0;

    for(int i=0;i<nums.size();i++)
    {
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if(sum < 0)sum = 0;
    }
    cout << maxSum;
    
    return 0;
}

