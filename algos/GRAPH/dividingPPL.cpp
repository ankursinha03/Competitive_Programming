#include <bits/stdc++.h>
using namespace std;
bool isBiGraph(vector<int> adj[], int colour[], int i)
{
    queue<int> q;
    q.push(i);

    colour[i] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int n : adj[node])
        {
            if (colour[n] == -1)
            {
                q.push(n);
                if (colour[node] == 1)
                    colour[n] = 2;
                else
                    colour[n] = 1;
            }
            else if (colour[n] == colour[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    vector<int> adj[n + 1];
    for (auto p : dislikes)
    {
        adj[p[0]].push_back(p[1]);
    }
    int colour[n + 1];
    for (int i = 0; i <= n; i++)
    {
        if (colour[i] == -1)
            if (!isBiGraph(adj, colour, i))
                return false;
    }

    return true;
}

vector<string> findItinerary(vector<vector<string>> &tickets)
{
    unordered_map<string, multiset<string>> adj;
    vector<string> ans;
    int n = tickets.size();
    //Make graph
    for (int i = 0; i < n; ++i)
        adj[tickets[i][0]].insert(tickets[i][1]);

    stack<string> mystack;
    mystack.push("JFK"); //JFK is our fixed starting point
    while (!mystack.empty())
    {
        string src = mystack.top();
        if (adj[src].size() == 0) //No further travel possible
        {
            ans.push_back(src);
            mystack.pop();
        }
        else
        {
            auto dst = adj[src].begin();
            mystack.push(*dst);
            adj[src].erase(dst);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    using namespace std;
    vector<vector<int>> v;
    v = {{1, 2}, {3, 4}, {5, 6}, {6, 7}, {8, 9}, {7, 8}};
    std::cout << possibleBipartition(10, v);

    vector<vector<string>> tickets;
    tickets = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    findItinerary(tickets);
    return 0;
}