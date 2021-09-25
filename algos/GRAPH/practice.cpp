#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int &person, int &noise, vector<int> adj[], vector<int> &quiet)
{
    if (quiet[node] < noise)
    {
        person = node;
        noise = quiet[node];
    }
    for (int n : adj[node])
    {
        dfs(n, person, noise, adj, quiet);
    }
}

vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
{
    int n;
    for (auto k : richer)
    {
        n = max(k[0], k[1]);
    }
    n++;

    vector<int> adj[n];

    for (auto r : richer)
    {
        adj[r[1]].push_back(r[0]);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int q = quiet[i];
        int p = i;
        dfs(i, p, q, adj, quiet);
        ans.push_back(p);
    }
    return ans;
}

int main()
{
    using namespace std;
    vector<vector<int>> connections{{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
    vector<int> v = {3, 2, 5, 4, 6, 1, 7, 0};
    loudAndRich(connections, v);
    return 0;
}