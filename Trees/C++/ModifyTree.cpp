#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<int>adjlist[],vector<bool>&visited,int n,int s,int parent){

visited[s]=true;

//  vector<vector<int>>:: iterator i;  
for(auto node : adjlist[s])
{

    if(!visited[node])
    isCycle(adjlist,visited,n,node,s );
    
    else if(node!=parent)
      return true;
}
return false;
}

int main(){

int n, e;

cin>>n>>e ;
vector<int>adjlist[n];

int s,d;

for(int i=0;i<e;i++){
cin >> s >> d;
adjlist[s].push_back(d);
adjlist[d].push_back(s);

}
vector<bool>visited(n,false);

isCycle(adjlist,visited,n,0,-1)== true ? cout << "Cycle detected": cout << "Cycle not detected";

}