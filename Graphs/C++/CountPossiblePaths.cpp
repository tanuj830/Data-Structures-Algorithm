// Count all possible paths between two vertices
#include<bits/stdc++.h>
using namespace std;

void isPath(vector<int>adjlist[], vector<bool>&visited, int s, int d, int n, int *count)
{
    visited[s] = true;
    if(s == d)
    {
       (*count)++;
    
    }

    vector<int>::iterator i;
    for(i = adjlist[s].begin(); i != adjlist[s].end(); i++)
    {
        if(!visited[*i])
          isPath(adjlist, visited, *i, d, n, count);
    }

    visited[s] = false;
}

int main()
{
    int n, e, s, d;

    cin  >> n >> e;

    vector<int> adjlist[n];
    vector<bool>visited(n, false);
    
    for(int i = 0; i < e; i++)
    {
        cin >> s >> d;
         adjlist[s].push_back(d);
        //  adjlist[d].push_back(s);
    }

cout << "enter source and destination" << endl;
cin >> s >> d;

int count = 0;
int *c = &count;
       isPath(adjlist, visited, s, d, n, c);
        cout << *c ;
}