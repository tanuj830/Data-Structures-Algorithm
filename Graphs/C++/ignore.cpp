// // Detect cycle using bfs and dfs.
// #include<bits/stdc++.h>
// using namespace std;

// bool BFS(vector<int> adjlist[], vector<bool> &visited, int s, int n, int parent)
// {
//      queue<int> q;

//      q.push(s);
//      visited[s] = true;

//      while(!q.empty())
//      {
//          int front = q.front();
//          q.pop();

//          for(auto child : adjlist[front])
//          {
//              if(!visited[child])
//              {
//                  visited[child] = true;
//                  q.push(child);
//              }
//              else if(child != parent)
//                  return true;
//             parent = front;
//          }
//      }
//      return false;
// }

// bool isCycle(vector<int> adjlist[], int n)
// {

//       vector<bool> visited(n,false);

//       for(int i = 0; i < n; i++)
//       {
//           if(visited[i] == false)
//           {
//               if(BFS(adjlist, visited, i, n, -1))
//                  return true;
//           }
//       }
//       return false;
// }

// int main()
// {
//     int n, e, s, d;

//     cin >> n >> e;

//     vector<int>adjlist[n];

//     for(int i = 0; i < e; i++)
//     {
//         cin >> s >> d;
//         adjlist[s].push_back(d);
//         adjlist[d].push_back(s);
//     }

//     isCycle(adjlist, n) ? cout << "cycle detected" : cout << "cycle not detected";
// }

// // DFS.
// #include<bits/stdc++.h>
// using namespace std;

// bool DFS(vector<int> adjlist[], vector<bool> &visited, int s, int n, int parent)
// {
//      visited[s] = true;

//          for(auto child : adjlist[s])
//          {
//              if(!visited[child])
//              {
//                  DFS(adjlist, visited, child, n, s);
//              }
//              else if(child != parent)
//                  return true;
//          }

//      visited[s] = false;
//      return false;
// }

// bool isCycle(vector<int> adjlist[], int n)
// {

//       vector<bool> visited(n,false);

//       for(int i = 0; i < n; i++)
//       {
//           if(visited[i] == false)
//           {
//               if(DFS(adjlist, visited, i, n, -1))
//                  return true;
//           }
//       }
//       return false;
// }

// int main()
// {
//     int n, e, s, d;

//     cin >> n >> e;

//     vector<int>adjlist[n];

//     for(int i = 0; i < e; i++)
//     {
//         cin >> s >> d;
//         adjlist[s].push_back(d);
//         adjlist[d].push_back(s);
//     }

//     isCycle(adjlist, n) ? cout << "cycle detected" : cout << "cycle not detected";
// }

// Dijkistra
// #include<bits/stdc++.h>
// using namespace std;

// void path(vector<pair<int,int>>adjlist[], int n, int s)
// {
//      vector<int>dist(n,INT16_MAX);
//      set<pair<int,int>>set;

//      dist[s] = 0;
//     set.insert({0,s});

//     while(!set.empty())
//     {
//         auto node = *set.begin();
//         int v = node.second;
//         int wt = node.first;
//         set.erase(set.begin());

//         for(auto child : adjlist[v])
//         {
//             int v_child = child.first;
//             int wt_child = child.second;

//             if(dist[v] + wt_child < dist[v_child])
//                {
//                    dist[v_child] = dist[v] + wt_child;
//                    set.insert({dist[v_child], v_child});
//                }
//         }
//     }
//     for(int i=0; i< n; i++)
//     cout << dist[i] << " ";
// }

// int main()
// {
//     int n, e, s, d, wt;

//     cin >> n >> e;

//     vector<pair<int,int>>adjlist[n];

//     for(int i=0;i<e;i++)
//     {
//         cin >> s >> d >> wt;
//         adjlist[s].push_back({d,wt});
//         adjlist[d].push_back({s,wt});
//     }

//     path(adjlist, n, 0);
// }

// Cycle detection in graph by BFS.
// #include<bits/stdc++.h>
// using namespace std;

// bool isCycleUtil(vector<int>adjlist[], vector<bool>& visited, vector<bool>& dfsvisited, int s, int n)
// {
//     visited[s] = true;
//     dfsvisited[s] = true;

//     for(auto child : adjlist[s])
//     {
//         if(!dfsvisited[child])
//         {
//             isCycleUtil(adjlist, visited, dfsvisited, child, n);
//         }
//          if(dfsvisited[child] == true )
//         {
//             return true;
//         }
//     }
//     dfsvisited[s]=false;
//     return false;
// }

// bool isCycle(vector<int> adjlist[], int n)
// {
//     vector<bool > visited(n, false);
//     vector<bool > dfsvisited(n, false);

//     for(int i=0; i<n; i++)
//     {
//         if(!visited[i])
//          if(isCycleUtil(adjlist, visited, dfsvisited, i, n))  return true;
//     }
//     return false;
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     vector<int> adjlist[n];

//     for(int i=0; i<e; i++)
//     {
//         int s, d;
//         cin >> s >> d;

//         adjlist[s].push_back(d);
//     }

//     isCycle(adjlist, n) ? cout << "1" : cout << "0";
// }


// #include<bits/stdc++.h>
// using namespace std;


// bool isCycle(vector<int>adjlist[], int n)
// {
//     for(auto node : adjlist[0])
//     {
//         cout << node << " ";
//     }
// }
// int main()
// {
//     int n,e;
//     cin>>n>>e;
//     vector<int>adjlist[n];

//     for(int i=0;i<e;i++)
//     {
//         int s,d;
//         cin>>s>>d;
//     adjlist[s].push_back(d);
//     adjlist[d].push_back(s);
//     }

//     isCycle(adjlist, n) ? cout << "cycle found" : cout << "cycle not found";
// }


// #include<bits/stdc++.h>
// using namespace std;

// void topologicalSortUtil(vector<int>adjlist[], int s, int n, vector<bool>&visited,stack<int>&stack)
// {
//     visited[s] = true;
    
//     for(auto node : adjlist[s])
//     {
//         if(!visited[node])
//         topologicalSortUtil(adjlist, node, n, visited,stack);
//     }
//     stack.push(s);
// }

// void topologicalSort(vector<int>adjlist[],int n)
// {
//     vector<bool>visited(n,false);
//     stack<int>stack;
    
//     for(int i=0;i<n;i++)
//     {
//         if(!visited[i])
//         topologicalSortUtil(adjlist,i,n,visited,stack);
        
//     }
//     while(!stack.empty())
//     {
//         cout<<  stack.top() << " ";
//         stack.pop();
//     }
// }

// int main()
// {
//     int n,e;
//     cin>>n>>e;
//     vector<int>adjlist[n];
    
//     for(int i=0;i<e;i++)
//     {
//         int s,d;
//         cin>>s>>d;
        
//         adjlist[s].push_back(d);
//     }
//     topologicalSort(adjlist,n);
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define inf 10000

// int main()
// {
//     int n,e;
//     cin >> n >> e;

//     int dist[n][n];

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(i==j)
//             dist[i][j] = 0;

//             else
//             dist[i][j] = inf;
//         }
//     }

//     for(int i=0;i<e;i++)
//     {
//         int s, d,wt;
//         cin >>s>>d>>wt;
//         dist[s][d] = wt;
//     }

//     for(int k=0;k<n;k++)
//     {
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(dist[i][j] > dist[i][k] + dist[k][j])
//                 {
//                     dist[i][j] = dist[i][k] + dist[k][j];
//                 }
//             }
//         }
//     }

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(dist[i][j] == inf)
//             cout << "INF" << " ";

//             else
//             cout << dist[i][j] << " ";
//         }
//         cout << endl;
//     }

// }



#include<bits/stdc++.h>
using namespace std;

void prims(vector<pair<int,int>>adjlist[],int n)
{
   vector<int>parent(n,-1),weight(n,INT16_MAX);
   vector<bool>visited(n,false);

   weight[0] = 0;

   for(int u=0;u<n-1;u++)
   {
    // find minimum in weight array
   int min = INT16_MAX, p;
   for(int i=0;i<n;i++)
   {
    if(weight[i] < min && !visited[i])
    {
        min = weight[i];
        p = i;
    }
   }

    visited[p] = true;

   // exploring neighbours of min
   for(auto node : adjlist[p])
   {
    int v = node.first;
    int wt = node.second;

        if(!visited[v] && weight[v] > wt)
        {
            parent[v] = p;
            weight[v] = wt;
        }
   }
   }

   for(int i=0;i<n;i++)
   cout << parent[i] << " ";
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>adjlist[n];
    
    for(int i=0;i<e;i++)
    {
        int s,d,wt;
        cin>>s>>d>>wt;
        
        adjlist[s].push_back({d,wt});
                adjlist[d].push_back({s,wt});

    }
    prims(adjlist,n);
}
