 
#include<bits/stdc++.h>
using namespace std;

void findAllPermu(string s, int n, int i)
{
    if(i == n)
    {
        cout << s << " ";
        return;
    }
    for(int j=i;j<n;j++){
    swap(s[i], s[j]);

    findAllPermu(s,n, i+1);
    swap(s[i], s[j]);
    }
}

int main()
{
    string s = "abc";

    findAllPermu(s, s.size(), 0);
}