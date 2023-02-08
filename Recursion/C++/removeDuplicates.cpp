// Remove duplicates from string.
// Approach: By takking auxillary string.
#include<bits/stdc++.h>
using namespace std;

bool elmPresent(string newStr, char elm, int n)
{
    for(int i=0;i<n;i++)
    {
        if(elm == newStr[i])  return true;
    }
    return false;
}

void removeDuplicates(string str, int n, int i, string &newStr)
{
    if(i == n)   return;
    if(!elmPresent(newStr, str[i], newStr.size()))
    {
        newStr.push_back(str[i]);
    }

    removeDuplicates(str, n, i+1, newStr);
}

int main()
{
    string str  = "aabbccdeee";
    string newStr;
    removeDuplicates(str, str.size(), 0, newStr);
    
    cout << newStr;
}