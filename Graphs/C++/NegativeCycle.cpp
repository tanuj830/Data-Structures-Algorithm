// Question 384
// Given directed graph
// A graph has negative cycle if the sum of all the edges is zero

#include<bits/stdc++.h>
using namespace std;

void DFS(vector<pair<int, int>>adjlist[], vector<bool>&visited, int n, int s, int &sum)
{
    visited[s] = true;

    for(auto node : adjlist[s])
    {
        int v = node.first;
        int wt = node.second;

        if(!visited[v])
        {
            sum = sum + wt;
            DFS(adjlist, visited, n, v, sum);
        }
    }
}

bool isNegativeCycle(vector<pair<int, int>>adjlist[], int n)
{
    vector<bool>visited(n,false);
    int sum = 0;

    for(int i=0;i<n;i++)
    {
if(!visited[i])

for(int ii=0;ii<visited.size();ii++)
{
  cout << visited[ii] << " ";
}
cout << endl;
    DFS(adjlist, visited, n, i, sum);

    }
cout << sum << " ";
    if(sum >= 0)
    return false;

    return true;
}

int main()
{
    int n,e;
    cin>> n >> e;

    vector<pair<int,int>>adjlist[n];

    for(int i=0;i<e;i++)
    {
        int s,d,wt;
        cin>> s >> d >> wt;
         adjlist[s].push_back({d,wt});
    }

    isNegativeCycle(adjlist, n) ? cout << "negative cycle exist            " : cout <<"negative cycle not exist";
} 
























