#include <bits/stdc++.h>
using namespace std;

void 0-1BFS(vector<pair<int, int>> adjlist[], int v, int s)
{
    vector<int>dist(v, INT_MAX);
    deque<int>queue;
    
    queue.push_back(0);
    dist[s] = 0;
    
    while(!queue.empty())
    {
        int v = queue.front();
        queue.pop_front();
        
        for(auto node : adjlist[v])
        {
            int child_v = node.first;
            int child_wt = node.second;

            if(dist[v] + child_wt < dist[child_v])
            {
                dist[child_v] = dist[v] + child_wt;
                
                if(child_wt == 0)queue.push_front(child_v);
                else queue.push_back(child_v);
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
    
    0-1BFS(adjlist, v, 0);
    return 0;
}