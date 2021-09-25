#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> soln;

void solve(const vector<int> &v, int k, const int &target, int sum, int index, vector<int> ans)
{
    if (sum == target && k == 0)
    {
        cout << index;
        soln.push_back(ans);
    }
    if (index >= v.size())
        return;
    if (sum > target)
        return;
    if (k < 0)
        return;
    ans.push_back(v[index]);
    solve(v, k - 1, target, sum + v[index], index + 1, ans);
    ans.pop_back();
    solve(v, k, target, sum, index + 1, ans);
}

vector<vector<int>> combinationSum3(int k, int n)
{
    soln.clear();
    vector<int> v;
    vector<int> temp;
    for (int i = 1; i <= 9; i++)
        v.push_back(i);
    solve(v, k, n, 0, 0, temp);

    return soln;
}

int main()
{
    using namespace std;
    combinationSum3(3, 7);
    vector<int> v;
    return 0;
}