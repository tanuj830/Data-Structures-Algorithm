// s1= amazon , s2 = axonam, after roating anticlockwise by 2 is s1 == s2 ?
#include<bits/stdc++.h>
using namespace std;

void reverse(int s, int e, string &st)
{
    char temp;

// cout << e-s << endl;

// int n=e-s;

// e--;
    while(s<e)
    {
        
         temp = st[s];
         st[s] = st[e];
         st[e] = temp;
         s++;
         e--;
    }
//   3 - 5  
}

int main()
{
    string s1 = "amazon";
    string s2 = "azonam"; // azonma -> nozama -> amazon
    
    int n = s2.length();

    reverse(0, n-2-1, s2);
        cout << s2 << endl;

    reverse(n-2, n-1, s2);
    cout << s2 << endl;

    reverse(0,s2.length()-1,s2);

    cout << s2 << endl;
    
}