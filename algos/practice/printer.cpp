#include <bits/stdc++.h>
using namespace std;

void makeZero(int a, int b, int &m, int &n, int point, vector<vector<int>> &targetGrid)
{
    if (a >= m || b >= n || a < 0 || b < 0)
        return;
    else if (targetGrid[a][b] != point)
        return;
    else
    {
        targetGrid[a][b] = 0;
        makeZero(a, b + 1, m, n, point, targetGrid);
        makeZero(a + 1, b, m, n, point, targetGrid);
        makeZero(a, b - 1, m, n, point, targetGrid);
        makeZero(a - 1, b, m, n, point, targetGrid);
    }
}
bool isPrintable(vector<vector<int>> &targetGrid)
{
    set<int> s;
    s.insert(0);
    int m = targetGrid.size();
    int n = targetGrid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (targetGrid[i][j] != 0)
            {
                int point = targetGrid[i][j];
                if (s.find(point) != s.end())
                {
                    continue;
                }
                s.insert(point);
                targetGrid[i][j] = 0;
                makeZero(i, j + 1, m, n, point, targetGrid);
                makeZero(i + 1, j, m, n, point, targetGrid);
                makeZero(i, j - 1, m, n, point, targetGrid);
                makeZero(i - 1, j, m, n, point, targetGrid);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (targetGrid[i][j] != 0)
            {
                count++;
                if (count > 1)
                {
                    break;
                }
            }
        }
    }
    if (count > 1)
    {
        return false;
    }
    return true;
}
int main()
{
    using namespace std;
    vector<vector<int>> targetGrid = {{1, 2, 1}, {2, 1, 2}, {1, 2, 1}};
    isPrintable(targetGrid);
    return 0;
}