#include <bits/stdc++.h>
using namespace std;

void dfs(int node, string s, string &ans, vector<vector<int>> &nxt, vector<bool> &is_terminal)
{
    if (s.length() > ans.length())
    {
        ans = s;
    }
    for (int c = 0; c < 26; c++)
    {
        int t = nxt[node][c];
        if (t != 0 && is_terminal[t])
        {
            dfs(t, s + char('a' + c), ans, nxt, is_terminal);
        }
    }
}
string longestWord(vector<string> &words)
{
    vector<bool> is_terminal(1);
    vector<vector<int>> nxt(1, vector<int>(26));
    int N = 0;
    for (auto s : words)
    {
        int node = 0;
        for (auto c : s)
        {
            if (nxt[node][c - 'a'] == 0)
            {
                nxt.push_back(vector<int>(26));
                is_terminal.push_back(false);
                nxt[node][c - 'a'] = ++N;
            }
            node = nxt[node][c - 'a'];
        }
        is_terminal[node] = true;
    }

    string ans;
    dfs(0, "", ans, nxt, is_terminal);
    return ans;
}
int main()
{
    using namespace std;
    vector<int> v;
    return 0;
}