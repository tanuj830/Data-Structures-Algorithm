// // BY DFS
// #include<bits/stdc++.h>
// using namespace std;

// void DFS(vector<int>adjlist[], stack<int>&stack, vector<int>&visited, int n, int s)
// {
//       visited[s] = true;
      
//     //   vector<int> :: iterator i;1
//     //   for(i = adjlist[s].begin(); i!=adjlist[s].end(); i++)
//     for(auto i : adjlist[s])
//       {
//           if(!visited[i])
//           DFS(adjlist, stack, visited, n, i);
//       }
//       stack.push(s);
// }

// void TopologicalSort(vector<int>adjlist[], int n)
// {
//     stack<int>stack;
//     vector<int>visited(n,false);

//     for(int i = 0; i < n; i++)
//     {
//         if(!visited[i])
//         {
//         //   visited[i] = true;
//           DFS(adjlist, stack, visited, n, i);
//         }
//     }

//     while(!stack.empty())
//     {
//         cout << stack.top() << " ";
//         stack.pop();
//     }
// }

// int main()
// {
//     int n,e;

//     cin >> n >> e;
//     vector<int>adjlist[n];

// // Creating directed graph becz for topological sort it is compulsary that graph shold hold the DAG propertie.
//     for(int i=0; i<e; i++)
//     {
//         int s,d;
//       cin >> s >> d;
//       adjlist[s].push_back(d);
//     }

//     TopologicalSort(adjlist, n);
// }

// // // topological sort using BFS
// // #include <bits/stdc++.h>
// // using namespace std;

// // bool topologicalSort(vector<int> adjlist[], int n)
// // {

// //     queue<int> queue;
// //     vector<int> indegree(n, 0);

// // // finding in-degree of all vertices
// //     for (int i = 0; i < n; i++)
// //     {
// //         for (auto node : adjlist[i])
// //         {
// //             int temp = indegree[node];
// //             indegree[node] = temp + 1;
// //         }
// //     }

// // // pushing all vertices having in-degree 0
// //     for (int i = 0; i < n; i++)
// //     {
// //         if (indegree[i] == 0)
// //         {
// //             queue.push(i);
// //         }
// //     }

// // // while q not equal to empty 
// //     while (!queue.empty())
// //     {
// //         // popping from queue
// //         int front = queue.front();
// //         queue.pop();
// //         cout << front << " ";

// //         // Work 1: decrease indegree of adjacent vertices of popped element by 1
// //         // Work 2: if you find any vertecies having indegree 0, push into queue
// //         for (auto node : adjlist[front])
// //         {
// //             indegree[node]--;

// //             if (indegree[node] == 0)
// //             {
// //                 queue.push(node);
// //             }
// //         }
// //     }
// // }

// // int main()
// // {
// //     int n, e;
// //     cin >> n >> e;

// //     vector<int> adjlist[n];

// //     for (int i = 0; i < e; i++)
// //     {
// //         int s, d;
// //         cin >> s >> d;

// //         adjlist[s].push_back(d);
// //     }

// //     topologicalSort(adjlist, n);
// // }












#include<bits/stdc++.h>
using namespace std;

void topologicalSortUtil(vector<int>adjlist[], int s, int n, vector<bool>&visited,stack<int>&stack)
{
    visited[s] = true;
    
    for(auto node : adjlist[s])
    {
        if(!visited[node])
        topologicalSortUtil(adjlist, node, n, visited,stack);
    }
    // cout << s << "pushed" << endl;
    stack.push(s);
}

void topologicalSort(vector<int>adjlist[],int n)
{
    vector<bool>visited(false,n);
    stack<int>stack;
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        topologicalSortUtil(adjlist,i,n,visited,stack);
        cout << i;
    }
    while(!stack.empty())
    {
        cout<<  stack.top() << " ";
        stack.pop();
    }
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
    topologicalSort(adjlist,n);
}