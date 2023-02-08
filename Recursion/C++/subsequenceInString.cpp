// Printing all subsequence
#include<bits/stdc++.h>
using namespace std;


void findSubseq(string str, int n, int i, string helper)
{
    if(i == n)
    {
        cout << helper << " ";
        return;
    }

    helper.push_back(str[i]);
    findSubseq(str, n, i+1, helper);
    helper.pop_back();
    findSubseq(str, n, i+1, helper);
}

int main()
{
    string str  = "abc";
    string auxStr;
    findSubseq(str, str.size(), 0, auxStr);
    
}





// Storing all subsequence than printing
#include<bits/stdc++.h>
using namespace std;

void subsequenceOfString(string str,  string helperStr, vector<string>& finalStr, int i)
{
    if(i >= str.size())
    {
        finalStr.push_back(helperStr);
        return;
    }

    subsequenceOfString(str, helperStr, finalStr, i+1);

    helperStr.push_back(str[i]);
    subsequenceOfString(str, helperStr, finalStr, i+1);

}

int main()
{
    string str = "abc";
    string helperStr;
    vector<string> finalStr;

    subsequenceOfString(str, helperStr, finalStr, 0);

     for (int i = 0; i < finalStr.size(); i++) {
            cout << "'" << finalStr[i] << "'" << " ";
    }
}

