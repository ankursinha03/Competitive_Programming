#include <bits/stdc++.h>
using namespace std;

class Dijkstra
{
    int n;

public:
    Dijkstra(int V)
    {
        n = V;
    }
    void computeShortestDist(vector<vector<int>> edgeList, int source)
    {

        // making adjaceny list
        vector<pair<int, int>> adj[n];
        for (auto p : edgeList)
        {
            adj[p[0]].push_back({p[1], p[2]});
            adj[p[1]].push_back({p[0], p[2]});
        }
        //adjacency list complete

        bool processed[n];
        memset(processed, 0, sizeof(processed));
        vector<int> key(n, INT_MAX);
        //index->node value->key and we need the min key everytime

        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        //even we have had used priority queue we would have needed to store the distance in an array
        key[source] = 0;
        ///minHeap.push({0,source});
        int count = 0;
        while (count < n)
        {
            int node;
            int val = INT_MAX;
            for (int k = 0; k < n; k++)
            {
                if (!processed[k] && key[k] < val)
                {
                    val = key[k];
                    node = k;
                }
            }

            processed[node] = 1;
            count++;
            for (auto p : adj[node])
            {
                bool a = key[p.first] > key[node] + p.second;
                bool b = !processed[p.first];
                if (a && b)
                {
                    key[p.first] = key[node] + p.second;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            std::cout << source << " - " << i << " " << key[i] << "\n";
        }
    }
};

class BellmanFord
{
    int V;

public:
    BellmanFord(int n)
    {
        V = n;
    }

    void computeShortestDis(vector<vector<int>> edgeList, int source)
    {

        vector<int> key(V, INT_MAX);
        key[source] = 0;

        for (int i = 0; i < V - 1; i++)
        {

            bool change = false;
            for (auto edge : edgeList)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if (key[v] > key[u] + w)
                {
                    key[v] = key[u] + w;
                    change = true;
                }
            }
            if (!change)
                break;
        }

        for (auto edge : edgeList)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (key[v] > key[u] + w)
            {
                key[v] = key[u] + w;
                std::cout << "\nTHERE IS A NEGATIVE EDGE WEIGHT CYCLE:";

                return;
            }
        }
        for (int i = 0; i < V; i++)
        {
            std::cout << source << " - " << i << " " << key[i] << "\n";
        }
    }
};

class FloydWarshall
{
    int V;

public:
    FloydWarshall(int n)
    {
        V = n;
    }
    void cal_AllPairShortestPath(vector<vector<int>> edgeList)
    {
        vector<vector<int>> adj(V, vector<int>(V, 10000));

        for (int i = 0; i < V; i++)
        {
            adj[i][i] = 0;
        }

        for (auto edge : edgeList)
        {
            adj[edge[0]][edge[1]] = edge[2];
        }

        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                std::cout << adj[i][j] << " ";
            }
            printf("\n");
        }
    }
};
int main()
{
    using namespace std;
    // vector<vector<int>> edgeList{
    //     {0, 1, 1},
    //     {0, 2, 4},
    //     {1, 2, 4},
    //     {1, 3, 2},
    //     {1, 4, 7},
    //     {2, 3, 3},
    //     {3, 4, 4},
    //     {3, 5, 6},
    //     {4, 5, 7}};
    // Dijkstra dj(6);
    // dj.computeShortestDist(edgeList, 0);
    // printf("\n");
    // printf("\n");
    // vector<vector<int>> eL{
    //     {0, 1, 6},
    //     {0, 2, 7},
    //     {1, 2, 8},
    //     {1, 3, -4},
    //     {2, 4, -3},
    //     {1, 4, 5},
    //     {4, 1, -2},
    //     {2, 3, 9},
    //     {3, 4, 7},
    //     {3, 0, 2},
    // };

    // BellmanFord bf(5);
    // bf.computeShortestDis(eL, 0);

    FloydWarshall fw(4);
    vector<vector<int>> edgeLists{
        {0, 1, 3},
        {1, 0, 2},
        {0, 3, 5},
        {1, 3, 8},
        {3, 2, 2},
        {2, 1, 1},
    };
    fw.cal_AllPairShortestPath(edgeLists);
    return 0;
}