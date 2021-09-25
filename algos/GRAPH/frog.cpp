#include <bits/stdc++.h>
using namespace std;

double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
{
    vector<vector<int>> adj(n + 1);
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<bool> visited(n + 1);
    queue<pair<int, double>> q;
    q.push({1, 1.0});

    int time = -1;
    while (!q.empty())
    {
        time++;
        if (time > t)
            return 0;
        int size = q.size();
        while (size--)
        {
            auto p = q.front();
            q.pop();
            int node = p.first;
            visited[node] = 1;
            double probab = p.second;

            double k = 0;
            for (int n : adj[node])
            {
                if (!visited[n])
                    k++;
            }

            if (node == target)
                return probab;

            for (int n : adj[node])
            {
                if (!visited[n])
                {
                    double pro = (double)(1 / k);
                    q.push({n, pro * probab});
                }
            }
        }
    }

    return 0;
}
int main()
{
    using namespace std;
    string k = "alkneaz";
    std::cout << k.end()[-1];

    vector<int> v = {7, 8, 9, 12, 15, 20, 25, 30};

    auto itr = lower_bound(v.begin(), v.end(), 12);
    std::cout << itr[0];
    // vector<vector<int>> edges{{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}};
    // frogPosition(7, edges, 2, 4);
    return 0;
}