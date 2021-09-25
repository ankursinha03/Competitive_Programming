#include <bits/stdc++.h>
using namespace std;

class Prims
{
    vector<vector<int>> adj;
    int n;

public:
    Prims(int N)
    {
        n = N;

        vector<vector<int>> t(n, vector<int>(n, INT_MAX));
        adj = t;
    }
    void fill(vector<vector<int>> edgeList)
    {
        for (auto p : edgeList)
        {
            adj[p[0]][p[1]] = p[2];
            adj[p[1]][p[0]] = p[2];
        }
    }
    void computeMST(int node)
    {
        vector<bool> MST(n, 0);
        vector<int> parent(n, -1);
        vector<int> key(n, INT_MAX);
        key[node] = 0;
        int count = 0;
        while (count < n)
        {
            //pick minimum key node

            int node;
            int KEY = INT_MAX;
            for (int k = 0; k < n; k++)
            {
                if (key[k] < KEY && !MST[k])
                {
                    node = k;
                    KEY = key[k];
                }
            }
            MST[node] = 1;
            count++;
            for (int i = 0; i < n; i++)
            {
                if (adj[node][i] < key[i] && !MST[i])
                {
                    key[i] = adj[node][i];
                    parent[i] = node;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == -1)
            {
                std::cout << i << "-"
                          << "-NA"
                          << " ";
                continue;
            }
            std::cout << i << "-" << parent[i] << "-" << adj[i][parent[i]] << " ";
        }
    }
};

class Krushkal
{
    int FIND_DJ(vector<int> &parent, vector<int> &rank, int a)
    {
        if (parent[a] == -1)
        {
            return a;
        }
        parent[a] = FIND_DJ(parent, rank, parent[a]);
        return parent[a];
    }

    int UNION_DJ(vector<int> &parent, vector<int> &rank, int a, int b)
    {
        int pa = FIND_DJ(parent, rank, a);
        int pb = FIND_DJ(parent, rank, b);
        if (pa == pb)
        {
            return 0;
        }
        if (rank[pa] == rank[pb])
        {
            parent[pa] = pb;
            rank[pb]++;
        }
        else
        {
            if (rank[pa] > rank[pb])
            {
                parent[pb] = pa;
            }
            else
            {
                parent[pa] = pb;
            }
        }
        return 1;
    }

public:
    void computeMST(vector<vector<int>> edgeList, const int V)
    {
        vector<int> parent(V, -1);
        vector<int> rank(V, 0);
        vector<vector<int>> ans;
        sort(edgeList.begin(), edgeList.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });
        int count = 0;
        for (auto k : edgeList)
        {
            int status = UNION_DJ(parent, rank, k[0], k[1]);
            if (status)
            {
                ans.push_back(k);
                count++;
            }
            if (count == V)
            {
                break;
            }
        }

        for (auto v : ans)
        {
            std::cout << "\n"
                      << v[0] << " " << v[1] << " - " << v[2];
        }
    }
};

int main()
{
    using namespace std;
    vector<vector<int>> edgeList{
        {0, 1, 4},
        {0, 2, 6},
        {1, 2, 6},
        {3, 1, 3},
        {1, 4, 4},
        {2, 3, 1},
        {3, 4, 2},
        {3, 5, 3},
        {4, 5, 7}};
    Prims p(6);
    p.fill(edgeList);
    p.computeMST(3);
    Krushkal krushkal;
    printf("\n");
    krushkal.computeMST(edgeList, 6);
    return 0;
}