#include <bits/stdc++.h>
using namespace std;

int main()
{
    using namespace std;
    string a = "abac";
    string b = "cab";

    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1));

    for (int m = 1; m < dp.size(); m++)
    {
        for (int n = 1; n < dp[0].size(); n++)
        {
            if (a[m - 1] == b[n - 1])
            {
                dp[m][n] = dp[m - 1][n - 1] + 1;
            }
            else
            {
                dp[m][n] = max(dp[m - 1][n], dp[m][n - 1]);
            }
        }
    }
    std::cout << "Length of longest common sunseq: " << dp[dp.size() - 1][dp[0].size() - 1];

    //priting the longest common subseq;
    int r = dp.size() - 1;
    int c = dp[0].size() - 1;
    stack<char> st;
    while (r != 0 && c != 0)
    {
        if (a[r - 1] == b[c - 1])
        {
            st.push(a[r - 1]);
            r--;
            c--;
        }
        else
        {
            if (dp[r - 1][c] > dp[r][c - 1])
            {
                r--;
            }
            else
            {
                c--;
            }
        }
    }
    std::cout << "\nThe subSeq is: ";
    while (!st.empty())
    {
        std::cout << st.top();
        st.pop();
    }

    //longest common sub string
    a = "ac";
    b = "ca";
    vector<vector<int>> DP(a.length() + 1, vector<int>(b.length() + 1));

    for (int m = 1; m < DP.size(); m++)
    {
        for (int n = 1; n < DP[0].size(); n++)
        {
            if (a[m] == b[n])
            {
                DP[m][n] = DP[m - 1][n - 1] + 1;
            }
        }
    }

    int ans = INT_MIN;
    int R, C;
    for (int i = 0; i < DP.size(); i++)
    {
        for (int j = 0; j < DP[0].size(); j++)
        {
            if (DP[i][j] > ans)
            {
                ans = DP[i][j];
                R = i;
                C = j;
            }
        }
    }
    string ansd = "";
    while (R != 0 && C != 0)
    {
        if (DP[R][C] != 0)
        {
            ansd += a[R - 1];
            R--;
            C--;
        }
        else
        {
            break;
        }
    }
    std::cout << "\n\nLongest common Sub String is: " << ans << " " << ansd;
    return 0;
}