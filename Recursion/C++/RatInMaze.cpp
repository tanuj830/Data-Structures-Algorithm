#include <bits/stdc++.h>
using namespace std;



bool isSafe(int maze[][4], int x, int y, int n, vector<vector<bool>> &visited)
{
    if (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && visited[x][y] == false)
        return true;

    return false;
}

void findPath(int maze[][4], int x, int y, int n, vector<vector<bool>> &visited, string &s, vector<string>&allPaths)
{

    if (x == n - 1 && y == n - 1)
    {
        allPaths.push_back(s);
        return;
    }

    if (isSafe(maze, x + 1, y, n, visited))
    {
        visited[x][y] = true;
        s.push_back('D');
        findPath(maze, x + 1, y, n, visited, s, allPaths);
        visited[x][y] = false;
        s.pop_back();
    }

    if (isSafe(maze, x, y + 1, n, visited))
    {
        visited[x][y] = true;
        s.push_back('R');
        findPath(maze, x, y + 1, n, visited, s, allPaths);
        visited[x][y] = false;
        s.pop_back();
    }

    if (isSafe(maze, x - 1, y, n, visited))
    {
        visited[x][y] = true;
        s.push_back('L');
        findPath(maze, x - 1, y, n, visited, s, allPaths);
        visited[x][y] = false;
        s.pop_back();
    }

    if (isSafe(maze, x, y - 1, n, visited))
    {
        visited[x][y] = true;
        s.push_back('L');
        findPath(maze, x, y - 1, n, visited, s, allPaths);
        visited[x][y] = false;
        s.pop_back();
    }
}

int main()
{
    int n = 4;
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string s;
vector<string> allPaths;

    findPath(maze, 0, 0, n, visited, s, allPaths);
    for (int i = 0; i < n; i++)
        cout << allPaths[i] << " ";
}