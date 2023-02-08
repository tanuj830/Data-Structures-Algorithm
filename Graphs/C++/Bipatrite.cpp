// // Check if graph is bipatrite or not using BFS.
// // Bipatrite Graph is a graph whose adjacent vertices should be of different colour.
// #include<bits/stdc++.h>
// using namespace std;

// bool BFS(vector<int>adjlist[], vector<int>&coloured, int s, int col, int n)
// {
//     queue<int>q;

//     q.push(s);
//     if(coloured[s] == -1)
//         coloured[s] = 0;

//     while(!q.empty())
//     {
//         int elem = q.front();
//         q.pop();
        
//       for(auto child : adjlist[elem])
//       {
//           if(coloured[child] == -1)
//           {
//               if(coloured[elem] == 1)
//               {      
//                   coloured[child] = 0;
//                   q.push(child);
//               }
//               else if(coloured[elem] == 0)
//               {      
//                   coloured[child] = 1;
//                   q.push(child);
//               }
//           }

//           // if not colured.
//           else if(coloured[elem] == coloured[child])       return false;
//       }
//     }
//     return true;
// }

// bool isBipatrite(vector<int>adjlist[], int n)
// {
//     vector<int>coloured(n,-1);

//     for(int i = 0; i < n; i++)
//     {
//         if(!BFS(adjlist, coloured, i, -1, n))    return false;
//     }

//     return true;
// }

// int main()
// {
//      int n , e;
    
//     cin >> n >> e;
//     vector<int> adjlist[n];

//     for (int i = 0; i < e; i++)
//     {
//         int s, d;

//         cin >> s >> d;
//         adjlist[s].push_back(d);
//         adjlist[d].push_back(s);
//     }

//     isBipatrite(adjlist, n) ? cout << "graph is bipatrite" : cout << "graph is not bipatrite";
// }







// // ---------------------------------------------------------------------------------------------------------------------------------------
// // using DFS.
// #include<bits/stdc++.h>
// using namespace std;

// bool DFS(vector<int>adjlist[], vector<int>&coloured, int s, int col, int n)
// {
//     // if(coloured[s] == -1)
//     //    coloured[s] = 0;
            
//     if(coloured[s] == col)   return false;

//      for(int child : adjlist[s])
//      {
//          if(coloured[child] == -1)
//          {
//              if(coloured[s] == 1)
//              coloured[child] = 0;

//         //  DFS(adjlist, coloured, child, 0, n);
         
//          else if(coloured[s] == 0)
//          coloured[child] = 1;

//          DFS(adjlist, coloured, child, coloured[child], n);
//          }
//      }

//      return true;
// }

// bool isBipatrite(vector<int>adjlist[], int n)
// {
//     vector<int>coloured(n,-1);

//     for(int i = 0; i < n; i++)
//     {
//         if(!DFS(adjlist, coloured, i, -1, n))    return false;
//     }

//     return true;
// }

// int main()
// {
//      int n , e;
    
//     cin >> n >> e;
//     vector<int> adjlist[n];

//     for (int i = 0; i < e; i++)
//     {
//         int s, d;

//         cin >> s >> d;
//         adjlist[s].push_back(d);
//         adjlist[d].push_back(s);
//     }

//     isBipatrite(adjlist, n) ? cout << "graph is bipatrite" : cout << "graph is not bipatrite";
// }



















// Check if graph is bipatrite or not using BFS.
// Bipatrite Graph is a graph whose adjacent vertices should be of different colour.
#include<bits/stdc++.h>
using namespace std;

bool BFS(vector<int>adjlist[], vector<int>&coloured, int s, int n)
{
    queue<int>queue;

    if(coloured[s] == -1)
    coloured[s] = 0;

    queue.push(s);

    while(!queue.empty()){
         
         int res = queue.front();
         queue.pop();
         
    for(auto node : adjlist[res])
    {
        if(coloured[node] == -1)
        {
            if(coloured[res] == 1)
            {
                coloured[node] = 0;
                queue.push(node);
            }

            
            else if(coloured[res] == 0)
            {
                coloured[node] = 1;
                queue.push(node);
            }
        }

        else if(coloured[node] == coloured[res])
        return false;
    }
    }

    return true;
}

bool isBipatrite(vector<int>adjlist[], int n)
{
    vector<int>coloured(n,-1);

    for(int i = 0; i < n; i++)
    {
      if(BFS(adjlist,coloured,i,n));
    }

    return true;
}

int main()
{
     int n , e;
    
    cin >> n >> e;
    vector<int> adjlist[n];

    for (int i = 0; i < e; i++)
    {
        int s, d;

        cin >> s >> d;
        adjlist[s].push_back(d);
        adjlist[d].push_back(s);
    }

    isBipatrite(adjlist, n) ? cout << "graph is bipatrite" : cout << "graph is not bipatrite";
}




