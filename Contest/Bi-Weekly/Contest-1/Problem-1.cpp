// 2566. Maximum Difference by Remapping a Digit
// User Accepted:10428
// User Tried:11737
// Total Accepted:10889
// Total Submissions:19445
// Difficulty:Easy
// You are given an integer num. You know that Danny Mittal will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
// Return the difference between the maximum and minimum values Danny can make by remapping exactly one digit in num.

// Input: num = 11891
// Output: 99009
// Explanation: 
// To achieve the maximum value, Danny can remap the digit 1 to the digit 9 to yield 99899.
// To achieve the minimum value, Danny can remap the digit 1 to the digit 0, yielding 890.
// The difference between these two numbers is 99009.

// Input: num = 90
// Output: 99
// Explanation:
// The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
// Thus, we return 99.
#include <bits/stdc++.h>

using namespace std;

int minMaxDifference(int num) {
    
    string nums = to_string(num);
    int index;
    char val;
    
    for(int i=0;i<nums.length();i++)
    {
        if(nums[i] != '9')
        {
            index = i;
            val = nums[i];
            break;
        }
    }
    
    string maxStr = "", minStr = "";
    
    for(int i=0;i<nums.length();i++)
    {
        if(nums[i] == val)maxStr.push_back('9');
        else maxStr.push_back(nums[i]);
    }
    
    for(int i=0;i<nums.length();i++)
    {
        if(nums[i] == nums[0])minStr.push_back('0');
        else minStr.push_back(nums[i]);
    }

    int high = stoi(maxStr);
    int low = stoi(minStr);

    return (high - low);
}

int main()
{
    int num;
    cin >> num;
    cout << minMaxDifference(num);
    return 0;
}