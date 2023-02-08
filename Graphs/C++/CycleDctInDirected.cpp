#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<int>adjlist[], int n, int s, vector<bool>dfsvisited,vector<bool>&visited)
{
    visited[s] = true;
    dfsvisited[s] = true;
    
    for(auto node : adjlist[s])
    {
        if(!visited[node])
        {
            DFS(adjlist,n,node,dfsvisited,visited);
        }
        else if(dfsvisited[node])
        return true;
    }

    dfsvisited[s] = false;
    return false;
}

bool isCycle(vector<int>adjlist[], int n)
{
    vector<bool>visited(false,n);
    vector<bool>dfsvisited(false,n);

    for(int i=0;i<n;i++)
    {
        if(!visited[i]){

        visited[i] = true;

        if(DFS(adjlist,n,i,dfsvisited,visited))
        return true;  

        }
    }
    return false;
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>adjlist[n];
    
    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;
        
        adjlist[s].push_back(d);
    }
    isCycle(adjlist,n) ? cout << "yes" : cout << "no"; 
}