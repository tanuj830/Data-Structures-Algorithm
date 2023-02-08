#include<bits/stdc++.h>
using namespace std;

void totalPaths(int maze[2][3], int n, int m, int i, int j, int &count)
{
    if(i == n-1 && j == m-1)
    {
        count++;
        return;
    }
    if(maze[i+1][j] == 0)    totalPaths(maze, n, m, i+1, j, count);
    if(maze[i][j+1] == 0)    totalPaths(maze, n, m, i, j+1, count);
}

int main()
{
    int count = 0;
    int n = 2, m = 3;
    int maze[2][3] = {0};

    totalPaths(maze, n, m, 0, 0, count);
    cout << count;
}