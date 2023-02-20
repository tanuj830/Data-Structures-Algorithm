// 0-1 BFS is an variant of Dijkistra Algorithm: In 0-1 BFS instead of different-different weight(in Dijkistra), we have weights in zeros and ones and we have to calculate the shortest distance from the source to all destination

#include <bits/stdc++.h>
using namespace std;

void ZeroOneBFS(vector<pair<int, int>> adjlist[], int v, int s)
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
    
    ZeroOneBFS(adjlist, v, 0);
    return 0;
}