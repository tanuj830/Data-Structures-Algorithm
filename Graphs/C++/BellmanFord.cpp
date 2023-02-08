// Bellman Ford algorithm is used to find the single source shortest path.
// Limitation: Can't work when you have negative cycle in an graph becz distance keeps on decreasing as we go with n-1 iterations.
// Dijkistra is faster than Bellman Ford.
#include<bits/stdc++.h>
using namespace std;

void BellmanFordUtil(vector<pair<int,int>>adjlist[], vector<int>&dist, int s, int n )
{

    for(int i = 0;i<n;i++)
    {
        for(auto child : adjlist[i])
        {
            int v = child.first;
            int wt = child.second;

            if(dist[i] + wt < dist[v])
               dist[v] = dist[i] + wt;
        }
    }
}

void BellmanFord(vector<pair<int,int>>adjlist[], int s, int n )
{
    vector<int>dist(n, INT16_MAX);
    dist[s] = 0;

// for(int i=0;i<n;i++)
    BellmanFordUtil(adjlist, dist, s, n);

for(int i=0;i<n;i++)
cout << dist[i] << " ";
}

int main()
{
    int n,e;

    cin >> n >> e;
    vector<pair<int,int>>adjlist[n];

    for(int i=0;i<e;i++)
    {
        int s,d,wt;

        cin >> s >> d >> wt;
        
        adjlist[s].push_back({d,wt});
        // adjlist[d].push_back({s,wt});
    }
    BellmanFord(adjlist, 0, n);
}