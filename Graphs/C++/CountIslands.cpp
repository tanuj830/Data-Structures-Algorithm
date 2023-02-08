#include<bits/stdc++.h>
using namespace std;

int n = 0; // no. of islands

bool isSafe(vector<vector<int>> world, int i, int j)
{
    if(world[i][j] == 1 && world[i][j] != 2)     return true;
    
    else 
    return false;
}

void countIslandsUtil(vector<vector<int>> &world, int i, int j)
{
    if(i >= 0 && j >= 0 && i < 4 && j < 5)       return;

    if(world[i][j] == 0)   return;

    // down
    if(isSafe(world, i+1, j))
    {
      world[i][j] = 2;
              countIslandsUtil(world, i+1, j);
    }

    // right
     if(isSafe(world, i, j+1))
    {
world[i][j] = 2;
        countIslandsUtil(world, i, j+1);
    }

    // left
     if(isSafe(world, i, j-1))
    {
world[i][j] = 2;
        countIslandsUtil(world, i, j-1);
    }

    // up
     if(isSafe(world, i-1, j))
    {
world[i][j] = 2;
        countIslandsUtil(world, i-1, j);
    }
}

int countIslands(vector<vector<int> > world)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(world[i][j] == 1){
                cout << "tanu ";
            countIslandsUtil(world, i, j);
            n++;
            }
        }
    }
}

int main()
{
    vector<vector<int>> world = {
                     {1,1,0,0,0},
                     {1,1,0,0,0},
                     {0,0,1,0,0},
                     {0,0,0,1,1}
                     };
    
    countIslands(world);
    cout << n;
}