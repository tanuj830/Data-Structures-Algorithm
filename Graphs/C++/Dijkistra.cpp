// #include<bits/stdc++.h>
// #define INF 456
// using namespace std;

// void dijkistra(vector<pair<int, int>> adjlist[], int n, int s)
// {
//     vector<int> dist(n, INF);
//     set<pair<int, int>> set;

//     set.insert({0, s});
//     dist[s] = 0;

//     while(!set.empty())
//     {
//         auto node = *set.begin(); // minimum pair of vertex and its distance
//         int v = node.second;
//         int wt = node.first;
//         set.erase(set.begin());

//         for(auto child : adjlist[v])
//         {
//             int present_v = child.first;
//             int present_wt = child.second;

//             if(dist[v] + present_wt < dist[present_v])
//             {
//                 dist[present_v] = dist[v] + present_wt;
//                 set.insert({dist[present_v], present_v});
//             }
//         }
//     }

//     for(auto node : dist)
//     cout << node << " ";
// }

// int main()
// {
//     int n, e;         cin >> n >> e;

//     vector<pair<int,int>> adjlist[n];

//     for(int i=0; i<e; i++)
//     {
//         int s, d, wt;
//         cin >> s >> d >> wt;

//         adjlist[s].push_back({d, wt});
//         adjlist[d].push_back({s, wt});
//     }
//     int s;
//     cin >> s;

//     dijkistra(adjlist, n, s);
// }




// #include<bits/stdc++.h>
// #define INF 1000
// using namespace std;

// void dijkistra(vector<pair<int, int>> adjlist[], int n, int s)
// {
//     set<pair<int,int>>set;
//     vector<int>dist(n,INF);
//     vector<bool>visited(n,false);

//     set.insert({0,s});
//     dist[s] = 0;

//     while(!set.empty())
//     {
//         auto node = *set.begin();
//         int v = node.second;
//         int wt = node.first;
//         set.erase(set.begin());

//         if(visited[v])  continue;
//         visited[v] = true;

//         for(auto child : adjlist[v])
//         {
//             int v_child  = child.first;
//             int wt_child = child.second;

//             if( dist[v] + wt_child < dist[v_child])
//             {
//                 dist[v_child] = dist[v] + wt_child;
//                 set.insert({dist[v_child],v_child});

//             }
//         }
//     }

//     for(int i=0;i<n;i++)
//         cout << dist[i] << " ";
// }

// int main()
// {
//     int n, e;         cin >> n >> e;

//     vector<pair<int,int>> adjlist[n];

//     for(int i=0; i<e; i++)
//     {
//         int s, d, wt;
//         cin >> s >> d >> wt;

//         adjlist[s].push_back({d, wt});
//         adjlist[d].push_back({s, wt});
//     }
//     // int s;
//     // cin >> s;

//     dijkistra(adjlist, n, 0);
// }



#include <bits/stdc++.h>
using namespace std;

void util(vector<int>adjlist[],int s, int n, vector<bool>&visited, stack<int>&stack){

    visited[s] = true;

    for(auto node : adjlist[s])
    {
        if(!visited[node])
        util(adjlist,node,n,visited,stack);
    }

    stack.push(s);
}

void TopologicalSort(vector<int>adjlist[], int n)
{
     stack<int>st;
     vector<bool>visited(n,false);

for(int i=0;i<n;i++)
if(!visited[i])
     util(adjlist,i, n, visited, st);
     

     while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    int n,e;
    cin >> n >> e;
    
    vector<int> adjlist[n];
    
    for(int i=0;i<e;i++)
    {
        int s,d;
        cin >> s>>d;
        
        adjlist[s].push_back(d);
        // adjlist[d].push_back(s);
    }

    TopologicalSort(adjlist, n);

    return 0;
}