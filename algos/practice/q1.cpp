#include <bits/stdc++.h>
using namespace std;

vector<int> find(int k, vector<vector<int>> &reverse)
{
    int i = 0;
    int j = reverse.size() - 1;
    int mid;
    while (i != j)
    {
        mid = (i + j) / 2;
        if (reverse[mid][1] == k)
        {
            return reverse[mid];
        }
        if (k < reverse[mid][1])
        {
            j = mid - 1;
        }
        else if (k > mid)
        {
            i = mid + 1;
        }
    }
    return reverse[j];
}
vector<vector<int>> answer(int maxDistance, vector<vector<int>> forward, vector<vector<int>> reverse)
{

    sort(reverse.begin(), reverse.end(), [&](vector<int> a, vector<int> b)
         { return a[1] < b[1]; });
    sort(forward.begin(), forward.end(), [&](vector<int> a, vector<int> b)
         { return a[1] < b[1]; });
    int mx = 0;
    vector<vector<int>> ans;
    vector<vector<int>> possible_ans;
    for (int i = 0; i < forward.size(); i++)
    {
        int diff = (maxDistance - forward[i][1]);
        auto it = find(diff, reverse);

        if (forward[i][1] + it[1] > maxDistance)
        {
            continue;
        }
        else if (forward[i][1] + it[1] == maxDistance)
        {
            possible_ans.clear();
            mx = forward[i][1] + it[1];
            ans.push_back({forward[i][0], it[0]});
        }
        else if (forward[i][1] + it[1] > mx)
        {
            mx = forward[i][1] + it[1];
            possible_ans.clear();
            possible_ans.push_back({forward[i][0], it[0]});
        }
        else if (forward[i][1] + it[1] == mx)
        {
            possible_ans.push_back({forward[i][0], it[0]});
        }
        else
        {
            break;
        }
    }
    if (possible_ans.size() == 0)
        return ans;
    else
        return possible_ans;
}
int main()
{
    using namespace std;
    vector<vector<int>> f = {{1, 2000}, {2, 4000}, {3, 60000}};
    vector<vector<int>> b = {{1, 2000}};
    vector<vector<int>> a = answer(7000, f, b);
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i][0] << " " << a[i][1] << endl;
    }

    return 0;
}