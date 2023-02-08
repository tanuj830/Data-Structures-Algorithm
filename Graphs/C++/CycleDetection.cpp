

// METHOD 2: BY DFS
#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<int>adjlist[], int s, int parent, vector<int>&visited)
{
    visited[s] = true;

    for(auto node : adjlist[s])
    {
        if(!visited[node])
        {
            isCycle(adjlist, node, s, visited);
        }
        
        else if(node != parent)
        return true;
    }
    return false;
}

bool CycleDetectionByDFS(vector<int>adjlist[], int n)
{
     vector<int>visited(n, false);

     for(int i = 1; i < n ;i++)
     {
        if(!visited[i])
        {
            if(isCycle(adjlist, i, -1, visited))           return true;
        }
     }
     return false;
}

int main()
{
   int n = 5 , e = 5  ;
    vector<int> adjlist[n];

    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        adjlist[s].push_back(d);
        adjlist[d].push_back(s);
    }

    CycleDetectionByDFS(adjlist, n) ? cout << "Cycle Detected " : cout << "Cycle Not Detected";
}