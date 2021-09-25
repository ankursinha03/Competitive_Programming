#include <bits/stdc++.h>
using namespace std;

int ans;
int SRC;
int dst;
int max_count;
void dfs(int node, int cost, int jump, vector<pair<int, int>> adj[], bool visited[])
{
    visited[node] = 1;
    if (jump > max_count)
        return;
    if (cost > ans)
        return;
    if (node == dst)
    {
        ans = min(ans, cost);
    }
    for (auto n : adj[node])
    {
        if (!visited[n.first])
        {
            int c = cost + n.second;
            dfs(n.first, c, jump + 1, adj, visited);
        }
    }
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int _dst, int k)
{
    vector<pair<int, int>> adj[n];
    //making of adjacency list
    SRC = src;
    for (auto f : flights)
    {
        adj[f[0]].push_back({f[1], f[2]});
    }
    dst = _dst;
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    ans = INT_MAX;
    max_count = 2 * k;

    dfs(src, 0, 0, adj, visited);
    return ans;
}

int main()
{
    using namespace std;
    vector<vector<int>> flights{
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}};
    findCheapestPrice(3, flights, 0, 2, 1);
    return 0;
}