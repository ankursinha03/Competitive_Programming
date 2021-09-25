#include <bits/stdc++.h>
using namespace std;

int R;
int C;
int A;
int B;
bool outside(int i, int j)
{
    if (i < 0 || j < 0 || i >= R || j >= C)
        return true;
    return 0;
}
bool isEnd(int i, int j, const vector<vector<char>> &grid)
{
    if (i < 0 || j < 0 || i >= R || j >= C)
        return false; // out of bound
    if (grid[i][j] != '.')
        return false; // if not a wall

    if (i == 0 || j == 0 || i + 1 == R || j + 1 == C)
        return true; // lies on the edge

    return false;
}

int find(int i, int j, int count, vector<vector<char>> &grid)
{
    if (i == A && j == B)
        return INT_MAX;
    if (outside(i, j))
        return INT_MAX;
    if (grid[i][j] == '+')
        return INT_MAX;
    if (isEnd(i, j, grid))
        return ++count;
    int ans = INT_MAX;
    int a = find(i - 1, j, count + 1, grid);
    int b = find(i + 1, j, count + 1, grid);
    int c = find(i, j - 1, count + 1, grid);
    int d = find(i, j + 1, count + 1, grid);

    ans = min(ans, min(min(a, b), min(c, d)));
    return ans;
}

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    R = maze.size();
    C = maze[0].size();

    int ans = INT_MAX;
    int i = entrance[0];
    int j = entrance[1];
    A = i;
    B = j;
    int a = find(i - 1, j, 0, maze);
    int b = find(i + 1, j, 0, maze);
    int c = find(i, j - 1, 0, maze);
    int d = find(i, j + 1, 0, maze);

    ans = min(ans, min(min(a, b), min(c, d)));

    if (ans = INT_MAX)
        return -1;
    return ans;
}

int main()
{
    using namespace std;
    vector<int> v = {1, 2};
    vector<vector<char>> maze{{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    nearestExit(maze, v);
    return 0;
}