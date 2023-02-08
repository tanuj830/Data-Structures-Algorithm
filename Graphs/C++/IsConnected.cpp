// Undirected graph is connected or not by dfs
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int>adjlist[], vector<bool> &visited, int n, int s)
{
    visited[s]=true;
        for(auto node : adjlist[s])
        {
            if(!visited[node])
            DFS(adjlist,visited,n,node);
        }
 
}

bool isConnectedGraph(vector<int>adjlist[], int n)
{
    vector<bool>visited(n,false);

    DFS(adjlist, visited, n, 0);

    for(auto node : visited)
    {
        if(node == false)
        return false;
        cout << node << " ";
    }
    return true;
}

int main()
{
    int n,e;
    cin>> n >> e;

    vector<int>adjlist[n];

    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>> s >> d;
         adjlist[s].push_back(d);
         adjlist[d].push_back(s);
    }

    isConnectedGraph(adjlist,n) ? cout << "connected" : cout <<"disconnected";
}




// Undirected graph is connected or not by BFS
#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int>adjlist[], vector<bool> &visited, int n, int s)
{
   queue<int>queue;
   queue.push(s);
   visited[s] = true;

   while(!queue.empty())
   {
       int pop_elm = queue.front();
       queue.pop();

       for(auto node : adjlist[pop_elm])
       {
           if(!visited[node])
           {
               queue.push(node);
               visited[node] = true;
           }
       }
   }
 
}

bool isConnectedGraph(vector<int>adjlist[], int n)
{
    vector<bool>visited(n,false);

    BFS(adjlist, visited, n, 0);

    for(auto node : visited)
    {
        if(node == false)
        return false;
        cout << node << " ";
    }
    return true;
}

int main()
{
    int n,e;
    cin>> n >> e;

    vector<int>adjlist[n];

    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>> s >> d;
         adjlist[s].push_back(d);
         adjlist[d].push_back(s);
    }

    isConnectedGraph(adjlist,n) ? cout << "connected" : cout <<"disconnected";
}












