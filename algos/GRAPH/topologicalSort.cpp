#include <bits/stdc++.h>
using namespace std;

class DFS_soln
{
    void dfs(int node, vector<int> &ans, bool visited[], vector<int> adj[])
    {
        visited[node] = 1;
        for (int n : adj[node])
        {
            if (!visited[n])
                dfs(n, ans, visited, adj);
        }
        ans.push_back(node);
    }

    bool checkCycle(int node, bool visited[], set<int> &stack, vector<int> adj[])
    {
        visited[node] = 1;
        stack.insert(node);

        for (int n : adj[node])
        {
            if (!visited[n])
            {
                if (checkCycle(n, visited, stack, adj))
                    return 1;
            }
            else
            {
                if (stack.find(n) != stack.end())
                    return 1;
            }
        }
        stack.erase(node);
        return 0;
    }

public:
    void findTopologicalSort(vector<vector<int>> edgeList, int V)
    {
        vector<int> adj[V];
        for (auto e : edgeList)
        {
            adj[e[0]].push_back(e[1]);
        }
        vector<int> ans;
        bool visited[V];
        memset(visited, 0, sizeof(visited));
        set<int> stack;

        for (int n = 0; n < V; n++)
        {
            if (!visited[n])
                if (checkCycle(n, visited, stack, adj))
                {
                    cout << "ITS NOT DAG\n";
                    return;
                }
        }
        memset(visited, 0, sizeof(visited));
        for (int n = 0; n < V; n++)
        {
            if (!visited[n])
                dfs(n, ans, visited, adj);
        }
        reverse(ans.begin(), ans.end());
        for (int x : ans)
        {
            std::cout << x << " ";
        }
    }
};

class Khans_algo
{
public:
    void findTopo(vector<vector<int>> edgeList, int V)
    {
        int inDegree[V];
        memset(inDegree, 0, sizeof(inDegree));
        vector<int> adj[V];
        for (auto e : edgeList)
        {
            adj[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        if (q.empty())
        {
            std::cout << "\nNOT DAG!";
            return;
        }
        int count = 0;
        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            count++;
            for (int n : adj[k])
            {
                inDegree[n]--;
                if (inDegree[n] == 0)
                {
                    q.push(n);
                }
            }
            ans.push_back(k);
        }
        printf("\n");
        for (int n : ans)
        {
            std::cout << n << " ";
        }
    }
};
int main()
{
    using namespace std;
    vector<vector<int>> edgeList{
        {0, 1},
        {1, 3},
        {0, 2},
        {2, 3}};

    // {
    // {0, 1},
    // {1, 3},
    // {2, 0},
    // {3, 2}};
    DFS_soln dfs_soln;
    dfs_soln.findTopologicalSort(edgeList, 4);

    Khans_algo ka;
    ka.findTopo(edgeList, 4);
    return 0;
}