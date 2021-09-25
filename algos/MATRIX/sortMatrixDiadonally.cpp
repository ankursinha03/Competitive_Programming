#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
    vector<int> buff;
    int i = 0;
    int k = 0;
    for (int j = 0; j < mat[0].size(); j++)
    {
        i = 0;
        k = j;
        buff.clear();
        while (i < mat.size() && k < mat[0].size())
        {
            buff.push_back(mat[i][k]);
            i++;
            k++;
        }
        sort(buff.begin(), buff.end());
        i--;
        k--;
        while (i >= 0 && k >= i)
        {
            mat[i][k] = buff.back();
            buff.pop_back();
            k--;
            i--;
        }
    }
    k = 0;
    for (int q = 1; q < mat.size(); q++)
    {
        k = 0;
        i = q;
        buff.clear();
        while (i < mat.size() && k < mat[0].size())
        {
            buff.push_back(mat[i][k]);
            k++;
            i++;
        }
        sort(buff.begin(), buff.end());
        k--;
        i--;
        while (i >= q && k >= 0)
        {
            mat[i][k] = buff.back();
            buff.pop_back();
            k--;
            i--;
        }
    }

    return mat;
}
int main()
{
    using namespace std;
    vector<vector<int>> v = {{11, 25, 66, 1, 69, 7}, {23, 55, 17, 45, 15, 52}, {75, 31, 36, 44, 58, 8}, {22, 27, 33, 25, 68, 4}, {84, 28, 14, 11, 5, 50}};
    diagonalSort(v);
    return 0;
}