#include<bits/stdc++.h>
using namespace std;

bool visitedGraph(vector<bool>visited, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == false)           return false;
    }
    return true;
}

bool MotherVertex(vector<int>adjlist[], vector<bool>&visited, int s, int n)
{
    visited[s] = true;
    
    vector<int>::iterator i;
    for(i = adjlist[s].begin(); i != adjlist[s].end(); i++)
    {
        if(!visited[*i])
          MotherVertex(adjlist, visited, *i, n);
    }

    if(visitedGraph(visited, n))
       return true;
    return false;
}

int main()
{
    int n, e;

    cin  >> n >> e;

    vector<int> adjlist[n];
    vector<bool>visited(n, false);
    
    for(int i = 0; i < e; i++)
    {
        int s, d, wt;
        cin >> s >> d;
         adjlist[s].push_back(d);
        //  adjlist[d].push_back(s);
    }

    for(int i = 0; i < n; i++)
    {
        if(MotherVertex(adjlist, visited, i, n))
        {
            cout << "mother-vertex: " << i << endl;
            // return 0;
        }

        for(int j = 0; j < visited.size(); j++)
            visited[j] = false;
    }
}














// //Mother vertex
// #include<bits/stdc++.h>
// using namespace std;

// bool DFS(vector<int> adjlist[], vector<bool> &visited, int s, int n)
// {
//     visited[s] = true;

//     for(auto child : adjlist[s])
//     {
//         if(!visited[child])
//         DFS(adjlist, visited, child, n);
//     }
//     return true;
// }

// bool checkVisited(vector<bool> visited,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(visited[i] != true)            return false;
//     }

//     return true;
// }

// bool isMotherVertex(vector<int> adjlist[], int n)
// {
      
//       vector<bool> visited(n,false);

//       for(int i = 0; i < n; i++)
//       {  
//               DFS(adjlist, visited, i, n);

//               if(checkVisited(visited, n))
//                  cout << i << " ";
             
//              for(int i=0;i<n;i++)
//              visited[i] = false;
                 
// }
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
//         // adjlist[d].push_back(s);
//     }

//     isMotherVertex(adjlist, n);
// }