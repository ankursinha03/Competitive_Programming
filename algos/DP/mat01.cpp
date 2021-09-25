#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    queue<pair<int, int>> q;
    const int m = mat.size();
    const int n = mat[0].size();
    bool visited[m][n];

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        if (i + 1 < m)
        {
            if (visited[i + 1][j] == false && mat[i + 1][j] != 0)
            {
                mat[i + 1][j] = mat[i][j] + 1;

                visited[i + 1][j] = true;
                q.push({i + 1, j});
            }
        }
        if (i - 1 >= 0)
        {
            if (visited[i - 1][j] == false && mat[i - 1][j] != 0)
            {
                mat[i + 1][j] = mat[i][j] + 1;
                visited[i - 1][j] = true;
                q.push({i - 1, j});
            }
        }
        if (j + 1 < n)
        {
            if (visited[i][j + 1] == false && mat[i][j + 1] != 0)
            {
                mat[i + 1][j] = mat[i][j] + 1;
                visited[i][j + 1] = true;
                q.push({i, j + 1});
            }
        }
        if (j - 1 >= 0)
        {
            if (visited[i][j - 1] == false && mat[i][j - 1] != 0)
            {
                mat[i + 1][j] = mat[i][j] + 1;
                visited[i][j - 1] = true;
                q.push({i, j - 1});
            }
        }
    }
    return mat;
}
int main()
{
    using namespace std;
    vector<vector<int>> v = {{1, 0, 0}, {1, 1, 1}, {1, 1, 1}};
    updateMatrix(v);
    return 0;
}

// [[1,0,0,0,1,1,1,1,0,1],[1,1,1,1,1,1,1,0,1,0],[1,1,1,1,0,1,0,0,1,1]]