#include <bits/stdc++.h>
using namespace std;

class Kosaraju
{
    int V;

protected:
    void DFS(vector<int> adj[], int node, stack<int> &st, bool visited[])
    {
        visited[node] = 1;
        for (int n : adj[node])
        {
            if (!visited[n])
                DFS(adj, n, st, visited);
        }
        st.push(node);
    }

    void DFS_Transpose(vector<int> adj[], int node, vector<int> &SCC, bool visited[])
    {
        visited[node] = 1;
        for (int n : adj[node])
        {
            if (!visited[n])
                DFS_Transpose(adj, n, SCC, visited);
        }
        SCC.push_back(node);
    }

public:
    Kosaraju(int n)
    {
        V = n;
    }

    void FindStronglyConnectedComponent(vector<pair<int, int>> edgeList)
    {
        // adjacency list of actual graph

        vector<int> adj_original[V];
        vector<int> adj_Transpose[V];

        for (auto p : edgeList)
        {
            adj_original[p.first].push_back(p.second);
            adj_Transpose[p.second].push_back(p.first);
        }

        bool visited[V];
        memset(visited, 0, sizeof(visited));
        stack<int> st;

        for (int n = 0; n < V; n++)
        {
            if (!visited[n])
                DFS(adj_original, n, st, visited);
        }

        vector<vector<int>> SCC;
        memset(visited, 0, sizeof(visited));
        vector<int> v;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            v.clear();
            if (!visited[node])
            {
                DFS_Transpose(adj_Transpose, node, v, visited);
                SCC.push_back(v);
            }
        }
        for (auto c : SCC)
        {
            for (auto n : c)
            {
                std::cout << n << " ";
            }
            printf("\n");
        }
    }
};

int main()
{
    using namespace std;
    vector<pair<int, int>> edgeList{
        {0, 1},
        {1, 2},
        {2, 0},
        {3, 0},
        {4, 3}};

    edgeList = {
        {1, 0},
        {0, 2},
        {2, 1},
        {0, 3},
        {3, 4},
    };
    Kosaraju raju(5);
    raju.FindStronglyConnectedComponent(edgeList);
    return 0;
}