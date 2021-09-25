#include <bits/stdc++.h>
using namespace std;

string getLCS(string A, string B)
{
    int n = A.length();
    int m = B.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // return dp[n][m] for length
    string LCS;

    int i = n;
    int j = m;
    while (i != 0 and j != 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            LCS += A[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }

    return LCS;
}

int main()
{
    using namespace std;
    string A = "BANANA";
    string B = "ANANAB";
    std::cout << getLCS(A, B);
    return 0;
}