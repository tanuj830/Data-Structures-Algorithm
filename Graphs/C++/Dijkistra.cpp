#include <bits/stdc++.h>
using namespace std;

void dijkistra(vector<pair<int, int>> adjlist[], int v, int s)
{
    vector<int>visited(v, 0);
    vector<int>dist(v, INT_MAX);
    set<pair<int, int>>set;
    
    set.insert({0, s});
    dist[s] = 0;
    
    while(!set.empty())
    {
        auto node = *set.begin();
        int v = node.second;
        int wt = node.first;
        set.erase(set.begin());
        
        if(visited[v] == 1)continue;
        visited[v] = 1;
        
        for(auto node : adjlist[v])
        {
            int child_v = node.first;
            int child_wt = node.second;

            if(dist[v] + child_wt < dist[child_v])
            {
                dist[child_v] = dist[v] + child_wt;
                set.insert({dist[child_v], child_v});
            }
        }
    }
    
    for(auto val : dist)cout << val << " ";
}

int main()
{
    int v, e;
    cout << "enter total no of verticies and edges: ";
    cin >> v >> e;
    
    vector<pair<int, int>>adjlist[v];
    
    for(int i=0;i<e;i++)
    {
        int s, d, wt;
        cin >> s >> d >> wt;

        adjlist[s].push_back({d, wt}); 
        adjlist[d].push_back({s, wt}); 
    }
    
    dijkistra(adjlist, v, 0);
    return 0;
}