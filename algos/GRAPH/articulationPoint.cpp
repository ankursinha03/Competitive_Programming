#include <bits/stdc++.h>
using namespace std;
class acculationPoint
{
    void dfs(int node, int parent, int &timer, bool visited[], int tin[], int low[], set<int> &AP, vector<int> adj[])
    {
        visited[node] = 1;
        int child = 0;
        tin[node] = low[node] = timer++;
        for (int n : adj[node])
        {
            if (!visited[n])
            {
                child++;
                dfs(n, node, timer, visited, tin, low, AP, adj);
                low[node] = min(low[n], low[node]);
                if (low[n] >= tin[node] && parent != -1)
                {
                    AP.insert(node);
                }
            }
            else
            {
                low[node] = min(low[node], tin[n]);
            }
        }
        if (parent == -1 and child > 1)
        {
            AP.insert(node);
        }
    }

public:
    void findAp(vector<vector<int>> edgeList, int V)
    {
        vector<int> adj[V];

        for (auto e : edgeList)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        bool visited[V];
        int tin[V];
        int low[V];
        set<int> AP;
        memset(visited, 0, sizeof(visited));
        memset(tin, -1, sizeof(tin));
        memset(low, -1, sizeof(low));
        int timer = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i, -1, timer, visited, tin, low, AP, adj);
        }

        for (int n : AP)
        {
            std::cout << n << "\n";
        }
    }
};

class edge
{
    void dfs(int node, int parent, bool vis[], int tin[], int low[], int &time, const vector<int> adj[], map<int, int> &m)
    {
        vis[node] = 1;
        low[node] = tin[node] = time++;

        for (int n : adj[node])
        {
            if (n == parent)
                continue;
            if (!vis[n])
            {
                dfs(n, node, vis, tin, low, time, adj, m);
                low[node] = min(low[node], low[n]);
                if (low[n] > tin[node])
                {
                    m.insert({node, n});
                }
            }
            else
            {
                low[node] = min(low[node], tin[n]);
            }
        }
    }

public:
    void findEdges(vector<vector<int>> connections, int n)
    {
        vector<int> adj[n];
        for (auto e : connections)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        bool vis[n];
        int tin[n];
        int low[n];
        map<int, int> m;

        memset(vis, 0, sizeof(vis));
        memset(tin, -1, sizeof(tin));
        memset(low, -1, sizeof(low));

        int time = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, time, adj, m);
            }
        }

        for (auto x : m)
        {
            std::cout << x.first << "->" << x.second << "\n";
        }
    }
};

int main()
{
    using namespace std;
    vector<vector<int>> edgeList{
        {0, 1},
        {1, 2},
        {2, 0},
        {2, 3},
        {3, 4},
        {4, 7},
        {4, 5},
        {5, 6},
        {6, 4},
        {6, 7}};
    acculationPoint ap;
    ap.findAp(edgeList, 8);
    edge eg;
    printf("\n");
    printf("\n");
    eg.findEdges(edgeList, 8);
    return 0;
}