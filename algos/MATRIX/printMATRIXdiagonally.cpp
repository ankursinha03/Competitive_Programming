#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void DISPLAY_DIAGONALLY(vector<vector<int>> v)
{
    vector<vector<int>> ans(v.size() + v[0].size() - 1);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            ans[i + j].push_back(v[i][j]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = ans[i].size() - 1; j >= 0; j--)
            cout << ans[i][j] << " ";

        cout << endl;
    }
}
vector<int> nextPermutation(vector<int> &A)
{
    int br = 0;
    for (int i = A.size() - 1; i > 0; i--)
    {
        if (A[i - 1] >= A[i])
            continue;
        else
        {
            br = i;
            break;
        }
    }
    if (br == 0)
    {
        sort(A.begin() + br, A.end());
        return A;
    }
    int swapPOS;
    for (int i = A.size() - 1; i >= br; i--)
    {
        if (A[i] > A[br - 1])
        {
            swapPOS = i;
            break;
        }
    }
    int t;

    t = A[br - 1];
    A[br - 1] = A[swapPOS];
    A[swapPOS] = t;
    sort(A.begin() + br, A.end());
    return A;
}

int main()
{
    using namespace std;

        vector<vector<int>> v = {
        {1, 2, 3, 10},
        {4, 5, 6, 11},
        {7, 8, 9, 12}};
    DISPLAY_DIAGONALLY(v);

    return 0;
}
