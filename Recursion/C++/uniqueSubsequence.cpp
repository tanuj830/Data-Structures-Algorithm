#include<bits/stdc++.h>
using namespace std;

void checkUniqueString(vector<string> &vOfStr, string helper)
{
    for(int i=0;i<vOfStr.size();i++)
    {
        if(vOfStr[i] == helper)   return;
    }

    vOfStr.push_back(helper);
    return;
}

void uniqueSubsequence(string str, int n, int i, vector<string>& vOfStr, string helper)
{
    if(i == n)
    {
        checkUniqueString(vOfStr, helper);
        return;
    }

    helper.push_back(str[i]);
    uniqueSubsequence(str, n, i+1, vOfStr, helper);
    helper.pop_back();
    uniqueSubsequence(str, n, i+1, vOfStr, helper);
}

int main()
{
  vector<string>vOfStr;
  string str = "aaa";
  string helper;
  uniqueSubsequence(str, str.size(), 0, vOfStr, helper);  

  for(int i=0;i<vOfStr.size();i++)
  cout << vOfStr[i] << " ";
}