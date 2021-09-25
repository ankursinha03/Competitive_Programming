#include <bits/stdc++.h>
using namespace std;

string longestPalindromicSubString(string a)
{
    int n = a.length();

    int start = 0;
    int len = 0;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        len = 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            dp[i][i + 1] = 1;
            len = 2;
            start = i;
        }
    }

    for (int l = 3; l <= n; l++)
    {
        for (int i = 0; i <= n - l; i++)
        {
            int j = i + l - 1;
            if (a[i] == a[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = 1;
                start = i;
                len = l;
            }
        }
    }
    return a.substr(start, len);
}

int main()
{
    using namespace std;
    // string s = "aaabbb";
    // std::cout << longestPalindromicSubString(s);
    vector<vector<int>> a = {{1, 5}, {2, 1}};
    vector<vector<int>> b = {{1, 2}, {2, 1}};

    set<vector<vector<int>>> s;
    s.insert(a);
    s.insert(b);

    for (auto x : s)
    {
        for (auto y : x)
        {
            for (int p : y)
                cout << p;
        }
        printf("\n");
    }
    return 0;
}