// Finding a path between two specified nodes, u and v, of an unweighted graph
#include<bits/stdc++.h>
using namespace std;

int i=0;

void DFS(vector<int>adjlist[], int s, int d, vector<int>&dist,  list<vector<int>>&path)
{
    // visited[s] = true;
    
    dist.push_back(s);

    if(s == d)
    {
         for(auto vecto : dist)
         cout << vecto << " ";
         path.push_back(dist);
    return;
    }
    
    vector<int>::iterator i;
    for(i = adjlist[s].begin(); i!=adjlist[s].end(); i++)
    {
       
            // dist.push_back(*i);
            DFS(adjlist, *i, d, dist, path);
    }
        dist.pop_back();
        
}

void FindPath(vector<int>adjlist[], int n, int s, int d)
{
    vector<int>dist;
    dist.push_back(s);
   list<vector<int>>path;


DFS(adjlist, s, d, dist, path);

          vector<int>c;
      for(auto vecto : path)
      {
          c=vecto;
             for(auto i : c)
    {
        cout << i << " ";
    }
    cout << "\n";
      }

}

int main()
{
      int n=4,e=6-1;

    // cin >> n >> e;
    vector<int>adjlist[n];

    // for(int i=0; i<e; i++)
    // {
    //     int s,d;
    //   cin >> s >> d;
    //   adjlist[0].push_back(1);
    //   adjlist[1].push_back(0);

            adjlist[0].push_back(2);
    //   adjlist[2].push_back(0);

            adjlist[0].push_back(3);
    //   adjlist[3].push_back(0);

            adjlist[2].push_back(0);
    //   adjlist[0].push_back(2);

        adjlist[2].push_back(1);
    //   adjlist[1].push_back(2);

         adjlist[1].push_back(3);
    //   adjlist[3].push_back(1);
    // }
    FindPath(adjlist, n, 0, 1);
}