#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> adjlist[], vector<int> &visited, int s)
{
    visited[s] = 1;
    cout << s << " ";
    
    for(int i=0; i<adjlist[s].size(); i++)
    {
        if(visited[i] == 0)helper(adjlist, visited, i);
    }
    
}

void DFS(vector<int> adjlist[], int v)
{
    vector<int>visited(v, 0);
    
    for(int i=0; i<v; i++)
    {
        if(visited[i] == 0)
        helper(adjlist, visited, i);
    }
}

int main()
{
    int v, e;
    cout << "enter total no of verticies and edges: ";
    cin >> v >> e;
    
    vector<int>adjlist[v];
    
    for(int i=0;i<e;i++)
    {
        int s, d, wt;
        cin >> s >> d >> wt;
        
        adjlist[s].push_back(d); 
        adjlist[d].push_back(s); 
    }
    
    DFS(adjlist, v);
    return 0;
}