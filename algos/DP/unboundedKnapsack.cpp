#include <bits/stdc++.h>
using namespace std;

int minCoin(vector<int> &v, int sum) //this return the minimum number of coins required to get to the sum
{
    if (sum == 0)
        return 0;
    vector<vector<int>> DP(v.size() + 1, vector<int>(sum + 1, INT_MAX - 10));
    for (int i = 0; i < DP.size(); i++)
    {
        DP[i][0] = 0;
    }

    for (int n = 1; n < DP.size(); n++)
    {
        for (int s = 1; s < DP[0].size(); s++)
        {
            if (v[n - 1] > s)
            {
                DP[n][s] = DP[n - 1][s];
            }
            else
            {
                DP[n][s] = min(DP[n - 1][s], 1 + DP[n][s - v[n - 1]]);
            }
        }
    }

    int ans = DP[DP.size() - 1][DP[0].size() - 1];
    if (ans == INT_MAX - 10)
        return -1;
    return (ans == 0) ? -1 : ans;
}

int main()
{
    using namespace std;
    vector<int> v = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> l = {1, 2, 3, 4, 5, 6, 7, 8};
    int lengthOfRod = 8;
    vector<vector<int>> dp(l.size() + 1, vector<int>(l.size() + 1));

    // for (int i = 1; i < dp.size(); i++)
    // {
    //     for (int j = 1; j < dp[0].size(); j++)
    //     {
    //         if (l[i - 1] > j)
    //         {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //         else
    //         {
    //             dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i][j - l[i - 1]]);
    //         }
    //     }
    // }
    for (int n = 1; n < dp.size(); n++)
    {
        for (int b = 1; b < dp[0].size(); b++)
        {
            if (l[n - 1] <= b)
                dp[n][b] = max(v[n - 1] + dp[n][b - l[n - 1]], dp[n - 1][b]);
            else
                dp[n][b] = dp[n - 1][b];
        }
    }
    std::cout << dp[dp.size() - 1][dp[0].size() - 1];

    //coin change this is to count the total number of ways to get the sum of coins equal to the target

    v = {1, 2, 5};
    int sum = 11;
    vector<vector<int>> DP(v.size() + 1, vector<int>(sum + 1));
    for (int i = 0; i < DP.size(); i++)
    {
        DP[i][0] = 1;
    }

    for (int n = 1; n < DP.size(); n++)
    {
        for (int s = 1; s < DP[0].size(); s++)
        {
            if (v[n - 1] > s)
            {
                DP[n][s] = DP[n - 1][s];
            }
            else
            {
                DP[n][s] = DP[n - 1][s] + DP[n][s - v[n - 1]];
            }
        }
    }
    std::cout << "\n\n"
              << DP[DP.size() - 1][DP[0].size() - 1];

    std::cout << "\nMininmum number of coins: " << minCoin(v, sum);
    return 0;
}