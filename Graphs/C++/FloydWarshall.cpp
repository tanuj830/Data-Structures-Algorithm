// This algorithm works with adjacency matrix only.
#include<bits/stdc++.h>
using namespace std;
#define INF 3267

void floydWarshall(int n)
{
    int dist[n][n] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };;


for(int v=0;v<n;v++)
{
    for(int j=0; j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(dist[j][v] + dist[v][i] < dist[j][i])
             dist[j][i] = dist[j][v] + dist[v][i];
        }
    }
}


 for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==INF)
            cout << "INF ";
            else
          cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n, e;

    cin  >> n;

    floydWarshall(n);

}