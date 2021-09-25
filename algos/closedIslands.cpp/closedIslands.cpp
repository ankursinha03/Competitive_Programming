#include <bits/stdc++.h>
using namespace std;

int R;
int C;

void sink(int i, int j, vector<vector<int>> &grid, bool &flag)
{
    if (i < 0 || j < 0 || i >= R || j >= C)
        return;

    if (grid[i][j] == 1)
        return;

    if (i == 0 || j == 0 || i == R - 1 || j == C - 1)
        flag = true;
    grid[i][j] = 1;
    sink(i + 1, j, grid, flag);
    sink(i - 1, j, grid, flag);
    sink(i, j + 1, grid, flag);
    sink(i, j - 1, grid, flag);
}

int closedIsland(vector<vector<int>> &grid)
{
    R = grid.size();
    C = grid[0].size();
    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (!grid[i][j])
            {
                bool flag = false;
                sink(i, j, grid, flag);
                if (!flag)
                    ans++;
            }
        }
    }
    return ans;
}

int main()
{
    using namespace std;
    vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0}};

    return 0;
}