#include <bits/stdc++.h>
using namespace std;

void fill(vector<vector<int>> &m, int i, int j, const int &label, const int &newlabel)
{
    if (i < 0 || j < 0)
    {
        return;
    }
    if (i >= m.size() || j >= m[0].size())
        return;
    if (m[i][j] != label)
    {
        return;
    }
    m[i][j] = newlabel;
    fill(m, i, j + 1, label, newlabel);
    fill(m, i + 1, j, label, newlabel);
    fill(m, i, j - 1, label, newlabel);
    fill(m, i - 1, j, label, newlabel);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int label = image[sr][sc];
    fill(image, sr, sc, label, newColor);
    return image;
}
int main()
{
    using namespace std;
    vector<vector<int>> v;
    v = {{0, 0, 0}, {0, 1, 1}};
    floodFill(v, 1, 1, 1);
    return 0;
}