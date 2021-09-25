#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void solve(int s, int e, int size, vector<int> v)
{

    if (s > e)
        return;
    if (v.size() == size)
    {
        ans.push_back(v);
        return;
    }

    if (v.size() > size)
    {
        return;
    }

    for (int i = s; i <= e; i++)
    {
        v.push_back(i);
        solve(v.back() + 1, e, size, v);
        v.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    ans.clear();
    vector<int> temp;
    solve(1, n, k, temp);

    return ans;
}

int main()
{
    using namespace std;
    combine(4, 2);
    return 0;
}